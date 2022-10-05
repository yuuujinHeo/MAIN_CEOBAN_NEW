#include "DialogSoda.h"
#include "ui_DialogSoda.h"
#include "RBLAN2CAN.h"

extern RBLAN2CAN *plan;

DialogSoda::DialogSoda(QWidget *parent, DialogStock *_stock) :
    QDialog(parent), stock(_stock),
    ui(new Ui::DialogSoda)
{
    ui->setupUi(this);

    ui->GB_SODA->setStyleSheet("QGroupBox  {\n    margin-top: 10px;"
                               "	font: 20pt \"함초롬돋움\";\n}\n\nQGroupBox::title  {"
                                                  "    subcontrol-origin: margin;"
                                                  "    subcontrol-position: top center;"
                                                  "    padding: 10px 8000px 10px 8000px;"
                                                  "    background-color: #595959;"
                                                  "    color: rgb(255, 255, 255);}"
                                                  "QLabel {\n	font: 10pt \"함초롬돋움\";\n}"
                                                 "QComboBox{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}\nQPushButton{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}"
                                                 "QLineEdit{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}");

    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(200);
}

DialogSoda::~DialogSoda()
{
    delete ui;
}

void DialogSoda::onTimer(){
    static unsigned int tt = 0;
    tt++;

    if(IS_UI_LOCK){
        ui->GB_SODA->setEnabled(false);
    }else{
        ui->GB_SODA->setEnabled(true);
    }

    if(plan->sockConnectionStatus == false){
        SetLEColor(ui->LE_SLUSH_CONNECTION, COLOR_NONE);

        ui->LE_DISPENSE_COUNT->setText("-");
        ui->LE_LAST_DISPENSE_ERROR->setText("-");
        ui->LE_OP_STATE->setText("-");

        ui->LE_LOADCELL_WEIGHT->setText("-");
        ui->LE_LOADCELL_SCALE->setText("-");
        ui->LE_LOADCELL_ERROR->setText("-");

        ui->LE_LOADCELL_WEIGHT_2->setText("-");
        ui->LE_LOADCELL_SCALE_2->setText("-");
        ui->LE_LOADCELL_ERROR_2->setText("-");
    }else{
        if(SODA_DATA[0].connection_status == 1){
            SetLEColor(ui->LE_SLUSH_CONNECTION, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_SLUSH_CONNECTION, COLOR_BAD);
        }


        ui->LE_DISPENSE_COUNT->setText(QString().sprintf("%d", SODA_DATA[0].out_count));

        if(SODA_DATA[0].last_error == 0){
            ui->LE_LAST_DISPENSE_ERROR->setText("정상");
            soda_error = "정상";
        }else{
            ui->LE_LAST_DISPENSE_ERROR->setText(QString().sprintf("E%d", SODA_DATA[0].last_error));
            soda_error = QString().sprintf("E%d", SODA_DATA[0].last_error);
        }

        if(SODA_DATA[0].out_state == 0){
            ui->LE_OP_STATE->setText("준비");
        }else{
            ui->LE_OP_STATE->setText("동작중");
        }


        ui->LE_LOADCELL_WEIGHT->setText(QString().sprintf("%d", SODA_DATA[0].loadcell[0].value));
        ui->LE_LOADCELL_SCALE->setText(QString().sprintf("%d", SODA_DATA[0].loadcell[0].calib_param));

        ui->LE_LOADCELL_WEIGHT_2->setText(QString().sprintf("%d", SODA_DATA[0].loadcell[1].value));
        ui->LE_LOADCELL_SCALE_2->setText(QString().sprintf("%d", SODA_DATA[0].loadcell[1].calib_param));

        ui->LE_LOADCELL_TOTAL_WEIGHT->setText(QString().sprintf("%d", LoadcellValue()));

        if(SODA_DATA[0].loadcell[0].error == 0){
            SetLEColor(ui->LE_LOADCELL_ERROR, COLOR_GOOD);
            ui->LE_LOADCELL_ERROR->setText("정상");
        }else{
            SetLEColor(ui->LE_LOADCELL_ERROR, COLOR_BAD);
            ui->LE_LOADCELL_ERROR->setText("에러");
        }

        if(SODA_DATA[0].loadcell[1].error == 0){
            SetLEColor(ui->LE_LOADCELL_ERROR_2, COLOR_GOOD);
            ui->LE_LOADCELL_ERROR_2->setText("정상");
        }else{
            SetLEColor(ui->LE_LOADCELL_ERROR_2, COLOR_BAD);
            ui->LE_LOADCELL_ERROR_2->setText("에러");
        }



        if(ui->CB_SCALE_TEST->isChecked()){
            // scale test mode
        }else{
            // loadcell scale factor set
            if(tt%5 == 0 && SODA_DATA[0].connection_status == 1){
                if(SODA_DATA[0].loadcell[0].calib_param != LOADCELL_SCALE_SODA_1){
                    SetCalibParam(LOADCELL_SCALE_SODA_1, 0);
                }
                if(SODA_DATA[0].loadcell[1].calib_param != LOADCELL_SCALE_SODA_2){
                    SetCalibParam(LOADCELL_SCALE_SODA_2, 1);
                }
            }
        }
    }
    if(IsSlushAvailable() == false){
        stock->SetDeviceError("SODA");
    }else{
        stock->ClearDeviceError("SODA");
    }

}


void DialogSoda::DispenseSodaByTime(int type, int time_ms){
    SODA_DATA[0].prev_out_count = SODA_DATA[0].out_count;
    int time_100ms = time_ms/100;
    plan->SendControlData(DEV_DIALOG_ID_SODA, 0, 0x00, type, time_100ms);
}
void DialogSoda::DispenseSodaByWeight(int type, int weight_g){
    SODA_DATA[0].prev_out_count = SODA_DATA[0].out_count;
    plan->SendControlData(DEV_DIALOG_ID_SODA, 0, 0x01, type, weight_g);
}



int DialogSoda::IsSlushAvailable(){
    if(plan->sockConnectionStatus == false)
        return false;

    if(SODA_DATA[0].connection_status == 1){
        // device available check
        if(SODA_DATA[0].loadcell[0].error == 0 && SODA_DATA[0].loadcell[1].error == 0){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
void DialogSoda::StartMeasure(int threshold){
    SODA_DATA[0].prev_out_count = SODA_DATA[0].out_count;
    plan->SendControlData(DEV_SEND_ID_SODA, 0, 0x01, 0, threshold);
}

void DialogSoda::RobotStop(){
    plan->SendControlData(DEV_SEND_ID_SODA, 0, 0x00, 0, 0);
}
void DialogSoda::Tare(){
    plan->SendControlData(DEV_SEND_ID_SODA, 0, 0x02, 0, 0);
}

void DialogSoda::SetCalibParam(int scale, int loadcell_id){
    plan->SendControlData(DEV_SEND_ID_SODA, 0, 0x03, loadcell_id, scale);
}

int DialogSoda::LoadcellValue(){
    return (SODA_DATA[0].loadcell[0].value + SODA_DATA[0].loadcell[1].value)/2;
}


void DialogSoda::on_BTN_DISPENSE_SLUSH_BY_TIME_clicked(){
//    DispenseSlushByTime(ui->LE_OUT_TIME->text().toFloat()*1000.0);
    plog->write("[UI OPERATION - SODA] 온수 배출(시간)");
}

void DialogSoda::on_BTN_DISPENSE_SLUSH_BY_WEIGHT_clicked(){
//    DispenseSlushByWeight(ui->LE_OUT_WEIGHT->text().toInt());
    plog->write("[UI OPERATION - SODA] 온수 배출(무게)");
}

void DialogSoda::on_BTN_TARE_clicked(){
    Tare();
    plog->write("[UI OPERATION - SODA] 영점");
}

void DialogSoda::on_BTN_SET_SCALE_clicked(){
    SetCalibParam(ui->LE_LOADCELL_SET_SCALE->text().toInt(), 0);
    plog->write("[UI OPERATION - SODA] Scale1 설정");
}

void DialogSoda::on_BTN_SET_SCALE_2_clicked(){
    SetCalibParam(ui->LE_LOADCELL_SET_SCALE_2->text().toInt(), 1);
    plog->write("[UI OPERATION - SODA] Scale2 설정");
}

void DialogSoda::on_BTN_START_MEASURE_clicked()
{
    StartMeasure(ui->LE_LOADCELL_THRESHOLD->text().toInt());
    plog->write("[UI OPERATION - SODA] 측정 시작 : "+ui->LE_LOADCELL_THRESHOLD->text());
}

void DialogSoda::on_BTN_ROBOT_STOP_clicked()
{
    RobotStop();
    plog->write("[UI OPERATION - SODA] 강제 종료");
}

void DialogSoda::on_BTN_DISPENSE_SODA_BY_TIME_clicked()
{
    DispenseSodaByTime(0, ui->LE_OUT_TIME->text().toFloat()*1000.0);
    plog->write("[UI OPERATION - SODA] 탄산 배출(시간)");
}

void DialogSoda::on_BTN_DISPENSE_COLD_BY_TIME_clicked()
{
    DispenseSodaByTime(1, ui->LE_OUT_TIME->text().toFloat()*1000.0);
    plog->write("[UI OPERATION - SODA] 온수 배출(시간)");
}

void DialogSoda::on_BTN_DISPENSE_HOT_BY_TIME_clicked()
{
    DispenseSodaByTime(2, ui->LE_OUT_TIME->text().toFloat()*1000.0);
    plog->write("[UI OPERATION - SODA] 냉수 배출(시간)");
}

void DialogSoda::on_BTN_DISPENSE_SODA_BY_TIME_2_clicked()
{
    DispenseSodaByWeight(0, ui->LE_OUT_WEIGHT->text().toInt());
    plog->write("[UI OPERATION - SODA] 탄산 배출(무게)");
}

void DialogSoda::on_BTN_DISPENSE_COLD_BY_WEIGHT_clicked()
{
    DispenseSodaByWeight(1, ui->LE_OUT_WEIGHT->text().toInt());
    plog->write("[UI OPERATION - SODA] 온수 배출(무게)");
}

void DialogSoda::on_BTN_DISPENSE_HOT_BY_WEIGHT_clicked()
{
    DispenseSodaByWeight(2, ui->LE_OUT_WEIGHT->text().toInt());
    plog->write("[UI OPERATION - SODA] 냉수 배출(무게)");
}
