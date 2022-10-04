#include "DialogSlush.h"
#include "ui_DialogSlush.h"
#include "RBLAN2CAN.h"

extern RBLAN2CAN *plan;

DialogSlush::DialogSlush(QWidget *parent, DialogStock *_stock) :
    QDialog(parent), stock(_stock),
    ui(new Ui::DialogSlush)
{
    ui->setupUi(this);

    ui->GB_SLUSH->setStyleSheet("QGroupBox  {\n    margin-top: 10px;"
                                  "	font: 20pt \"함초롬돋움\";\n}\n\nQGroupBox::title  {"
                                                     "    subcontrol-origin: margin;"
                                                     "    subcontrol-position: top center;"
                                                     "    padding: 10px 8000px 10px 8000px;"
                                                     "    background-color: #FFC4D8;"
                                                     "    color: rgb(255, 255, 255);}"
                                                     "QLabel {\n	font: 10pt \"함초롬돋움\";\n}"
                                                    "QComboBox{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}\nQPushButton{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}"
                                                    "QLineEdit{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}");

    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(200);
}

DialogSlush::~DialogSlush()
{
    delete ui;
}

void DialogSlush::onTimer(){
    static unsigned int tt = 0;
    tt++;

    if(IS_UI_LOCK){
        ui->GB_SLUSH->setEnabled(false);
    }else{
        ui->GB_SLUSH->setEnabled(true);
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
        if(SLUSH_DATA[0].connection_status == 1){
            SetLEColor(ui->LE_SLUSH_CONNECTION, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_SLUSH_CONNECTION, COLOR_BAD);
        }


        ui->LE_DISPENSE_COUNT->setText(QString().sprintf("%d", SLUSH_DATA[0].out_count));

        if(SLUSH_DATA[0].last_error == 0){
            ui->LE_LAST_DISPENSE_ERROR->setText("정상");
            slush_error = "정상";
        }else{
            ui->LE_LAST_DISPENSE_ERROR->setText(QString().sprintf("E%d", SLUSH_DATA[0].last_error));
            slush_error = QString().sprintf("E%d", SLUSH_DATA[0].last_error);
        }

        if(SLUSH_DATA[0].out_state == 0){
            ui->LE_OP_STATE->setText("준비");
        }else{
            ui->LE_OP_STATE->setText("동작중");
        }


        ui->LE_LOADCELL_WEIGHT->setText(QString().sprintf("%d", SLUSH_DATA[0].loadcell[0].value));
        ui->LE_LOADCELL_SCALE->setText(QString().sprintf("%d", SLUSH_DATA[0].loadcell[0].calib_param));

        ui->LE_LOADCELL_WEIGHT_2->setText(QString().sprintf("%d", SLUSH_DATA[0].loadcell[1].value));
        ui->LE_LOADCELL_SCALE_2->setText(QString().sprintf("%d", SLUSH_DATA[0].loadcell[1].calib_param));

        ui->LE_LOADCELL_TOTAL_WEIGHT->setText(QString().sprintf("%d", LoadcellValue()));

        if(SLUSH_DATA[0].loadcell[0].error == 0){
            SetLEColor(ui->LE_LOADCELL_ERROR, COLOR_GOOD);
            ui->LE_LOADCELL_ERROR->setText("정상");
        }else{
            SetLEColor(ui->LE_LOADCELL_ERROR, COLOR_BAD);
            ui->LE_LOADCELL_ERROR->setText("에러");
        }

        if(SLUSH_DATA[0].loadcell[1].error == 0){
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
            if(tt%5 == 0 && SLUSH_DATA[0].connection_status == 1){
                if(SLUSH_DATA[0].loadcell[0].calib_param != LOADCELL_SCALE_SLUSH_1){
                    SetCalibParam(LOADCELL_SCALE_SLUSH_1, 0);
                }
                if(SLUSH_DATA[0].loadcell[1].calib_param != LOADCELL_SCALE_SLUSH_2){
                    SetCalibParam(LOADCELL_SCALE_SLUSH_2, 1);
                }
            }
        }
    }
    if(IsSlushAvailable() == false){
        stock->SetDeviceError("SLUSH");
    }else{
        stock->ClearDeviceError("SLUSH");
    }

}


//void DialogSlush::DispenseSlushByTime(int time_ms){
//    SLUSH_DATA[0].prev_out_count = SLUSH_DATA[0].out_count;
//    int time_100ms = time_ms/100;
//    plan->SendControlData(DEV_DIALOG_ID_SLUSH, 0, 0x00, 0, time_100ms);
//}
//void DialogSlush::DispenseSlushByWeight(int weight_g){
//    SLUSH_DATA[0].prev_out_count = SLUSH_DATA[0].out_count;
//    plan->SendControlData(DEV_DIALOG_ID_SLUSH, 0, 0x01, 0, weight_g);
//}



int DialogSlush::IsSlushAvailable(){
    if(plan->sockConnectionStatus == false)
        return false;

    if(SLUSH_DATA[0].connection_status == 1){
        // device available check
        if(SLUSH_DATA[0].loadcell[0].error == 0 && SLUSH_DATA[0].loadcell[1].error == 0){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
void DialogSlush::StartMeasure(int threshold){
    SLUSH_DATA[0].prev_out_count = SLUSH_DATA[0].out_count;
    plan->SendControlData(DEV_SEND_ID_SLUSH, 0, 0x01, 0, threshold);
}

void DialogSlush::RobotStop(){
    plan->SendControlData(DEV_SEND_ID_SLUSH, 0, 0x00, 0, 0);
}
void DialogSlush::Tare(){
    plan->SendControlData(DEV_SEND_ID_SLUSH, 0, 0x02, 0, 0);
}

void DialogSlush::SetCalibParam(int scale, int loadcell_id){
    plan->SendControlData(DEV_SEND_ID_SLUSH, 0, 0x03, loadcell_id, scale);
}

int DialogSlush::LoadcellValue(){
    return (SLUSH_DATA[0].loadcell[0].value + SLUSH_DATA[0].loadcell[1].value)/2;
}


void DialogSlush::on_BTN_DISPENSE_SLUSH_BY_TIME_clicked(){
//    DispenseSlushByTime(ui->LE_OUT_TIME->text().toFloat()*1000.0);
    plog->write("[UI OPERATION - SLUSH] 온수 배출(시간)");
}

void DialogSlush::on_BTN_DISPENSE_SLUSH_BY_WEIGHT_clicked(){
//    DispenseSlushByWeight(ui->LE_OUT_WEIGHT->text().toInt());
    plog->write("[UI OPERATION - SLUSH] 온수 배출(무게)");
}

void DialogSlush::on_BTN_TARE_clicked(){
    Tare();
    plog->write("[UI OPERATION - SLUSH] 영점");
}

void DialogSlush::on_BTN_SET_SCALE_clicked(){
    SetCalibParam(ui->LE_LOADCELL_SET_SCALE->text().toInt(), 0);
    plog->write("[UI OPERATION - SLUSH] Scale1 설정");
}

void DialogSlush::on_BTN_SET_SCALE_2_clicked(){
    SetCalibParam(ui->LE_LOADCELL_SET_SCALE_2->text().toInt(), 1);
    plog->write("[UI OPERATION - SLUSH] Scale2 설정");
}

void DialogSlush::on_BTN_START_MEASURE_clicked()
{
    StartMeasure(ui->LE_LOADCELL_THRESHOLD->text().toInt());
    plog->write("[UI OPERATION - SLUSH] 측정 시작 : "+ui->LE_LOADCELL_THRESHOLD->text());
}

void DialogSlush::on_BTN_ROBOT_STOP_clicked()
{
    RobotStop();
    plog->write("[UI OPERATION - SLUSH] 강제 종료");
}
