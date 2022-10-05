#include "DialogSyrup.h"
#include "ui_DialogSyrup.h"
#include "RBLAN2CAN.h"

extern RBLAN2CAN *plan;
extern Logger *plog;

DialogSyrup::DialogSyrup(QWidget *parent, DialogStock *_stock) :
    QDialog(parent), stock(_stock),
    ui(new Ui::DialogSyrup)
{
    ui->setupUi(this);

    SetButtonName();
    state_cleaning = 0;
    start_cleaning = false;

    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(200);
}

DialogSyrup::~DialogSyrup()
{
    delete ui;
}

void DialogSyrup::SetButtonName(){
    buttons_time.push_back(ui->BTN_DISPENSE_SYRUP_BY_TIME_1);
    buttons_time.push_back(ui->BTN_DISPENSE_SYRUP_BY_TIME_2);
    buttons_time.push_back(ui->BTN_DISPENSE_SYRUP_BY_TIME_3);
    buttons_time.push_back(ui->BTN_DISPENSE_SYRUP_BY_TIME_4);
    buttons_time.push_back(ui->BTN_DISPENSE_SYRUP_BY_TIME_5);
    buttons_time.push_back(ui->BTN_DISPENSE_SYRUP_BY_TIME_6);
    buttons_time.push_back(ui->BTN_DISPENSE_SYRUP_BY_TIME_7);
    buttons_time.push_back(ui->BTN_DISPENSE_SYRUP_BY_TIME_8);
    buttons_time.push_back(ui->BTN_DISPENSE_SYRUP_BY_TIME_9);
    buttons_time.push_back(ui->BTN_DISPENSE_SYRUP_BY_TIME_10);
    buttons_time.push_back(ui->BTN_DISPENSE_SYRUP_BY_TIME_11);
    buttons_time.push_back(ui->BTN_DISPENSE_SYRUP_BY_TIME_12);

    buttons_weight.push_back(ui->BTN_DISPENSE_SYRUP_BY_WEIGHT_1);
    buttons_weight.push_back(ui->BTN_DISPENSE_SYRUP_BY_WEIGHT_2);
    buttons_weight.push_back(ui->BTN_DISPENSE_SYRUP_BY_WEIGHT_3);
    buttons_weight.push_back(ui->BTN_DISPENSE_SYRUP_BY_WEIGHT_4);
    buttons_weight.push_back(ui->BTN_DISPENSE_SYRUP_BY_WEIGHT_5);
    buttons_weight.push_back(ui->BTN_DISPENSE_SYRUP_BY_WEIGHT_6);
    buttons_weight.push_back(ui->BTN_DISPENSE_SYRUP_BY_WEIGHT_7);
    buttons_weight.push_back(ui->BTN_DISPENSE_SYRUP_BY_WEIGHT_8);
    buttons_weight.push_back(ui->BTN_DISPENSE_SYRUP_BY_WEIGHT_9);
    buttons_weight.push_back(ui->BTN_DISPENSE_SYRUP_BY_WEIGHT_10);
    buttons_weight.push_back(ui->BTN_DISPENSE_SYRUP_BY_WEIGHT_11);
    buttons_weight.push_back(ui->BTN_DISPENSE_SYRUP_BY_WEIGHT_12);

    QStringList keys = stock->syrup_to_name.keys();
    for(int i=0; i<12; i++){
        buttons_time[i]->setEnabled(false);
        buttons_weight[i]->setEnabled(false);
    }
    for(int i=0; i<keys.size(); i++){
        QString str;
        str = stock->syrup_to_name[keys[i]] + "\n" + keys[i] + "\n" + "(Pump " + QString::number(stock->syrup_to_pump[keys[i]]) + ")";
        buttons_time[i]->setText(str);
        buttons_weight[i]->setText(str);
        buttons_time[i]->setEnabled(true);
        buttons_weight[i]->setEnabled(true);
    }
}

void DialogSyrup::onTimer(){
    static unsigned int tt = 0;
    static unsigned int count_cleaning=0;
    tt++;

    if(IS_UI_LOCK){
        ui->GB_SYRUP->setEnabled(false);
    }else{
        ui->GB_SYRUP->setEnabled(true);
    }

    if(start_cleaning==true){
        if(count_cleaning == 0){
            QStringList keys = stock->syrup_to_name.keys();
            DispenseSyrupByTime(stock->syrup_to_pump[keys[state_cleaning]], ui->LE_SYRUP_OUT_TIME_2->text().toFloat()*1000.0);
        }

        if(count_cleaning > ui->LE_SYRUP_OUT_TIME_2->text().toFloat()*5 + 3){//5Hz , +600ms
            state_cleaning++;
            count_cleaning = 0;

            if(state_cleaning >= uint(stock->syrup_to_name.size())){
                start_cleaning = false;
            }
        }else{
            count_cleaning++;
        }
    }
    if(plan->sockConnectionStatus == false){
        SetLEColor(ui->LE_SYRUP_CONNECTION, COLOR_NONE);

        ui->LE_SYRUP_DISPENSE_COUNT->setText("-");
        ui->LE_LAST_DISPENSE_ERROR->setText("-");
        ui->LE_OP_STATE->setText("-");

        ui->LE_LOADCELL_WEIGHT->setText("-");
        ui->LE_LOADCELL_SCALE->setText("-");
        ui->LE_LOADCELL_ERROR->setText("-");
    }else{
        if(SYRUP_DATA[0].connection_status == 1){
            SetLEColor(ui->LE_SYRUP_CONNECTION, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_SYRUP_CONNECTION, COLOR_BAD);
        }


        ui->LE_SYRUP_DISPENSE_COUNT->setText(QString().sprintf("%d", SYRUP_DATA[0].out_count));

        if(SYRUP_DATA[0].last_error == 0){
            ui->LE_LAST_DISPENSE_ERROR->setText("정상");
            syrup_error = "정상";
        }else{
            ui->LE_LAST_DISPENSE_ERROR->setText(QString().sprintf("E%d", SYRUP_DATA[0].last_error));
            syrup_error = QString().sprintf("E%d", SYRUP_DATA[0].last_error);
        }

        if(SYRUP_DATA[0].out_state == 0){
            ui->LE_OP_STATE->setText("준비");
        }else{
            ui->LE_OP_STATE->setText("동작중");
        }


        ui->LE_LOADCELL_WEIGHT->setText(QString().sprintf("%d", SYRUP_DATA[0].loadcell.value));
        ui->LE_LOADCELL_SCALE->setText(QString().sprintf("%d", SYRUP_DATA[0].loadcell.calib_param));

        if(SYRUP_DATA[0].loadcell.error == 0){
            SetLEColor(ui->LE_LOADCELL_ERROR, COLOR_GOOD);
            ui->LE_LOADCELL_ERROR->setText("정상");
        }else{
            SetLEColor(ui->LE_LOADCELL_ERROR, COLOR_BAD);
            ui->LE_LOADCELL_ERROR->setText("에러");
        }


        if(ui->CB_SCALE_TEST->isChecked()){
            // scale test mode
        }else{
            // loadcell scale factor set
            if(tt%5 == 0 && SYRUP_DATA[0].connection_status == 1){
                if(SYRUP_DATA[0].loadcell.calib_param != LOADCELL_SCALE_SYRUP){
                    SetCalibParam(LOADCELL_SCALE_SYRUP);
                }
            }
        }

    }
}


void DialogSyrup::DispenseSyrupByTime(int pump_num, int time_ms){
    SYRUP_DATA[0].prev_out_count = SYRUP_DATA[0].out_count;
    int time_100ms = time_ms/100;
    plog->write("[SYRUP] DISPENSE BY TIME " + QString().sprintf("SYRUP(%d) : TIME(%d)",pump_num,time_ms));
    plan->SendControlData(DEV_SEND_ID_SYRUP, 0, 0x00, pump_num, time_100ms);
}
void DialogSyrup::DispenseSyrupByWeight(int pump_num, int weight_g){
    SYRUP_DATA[0].prev_out_count = SYRUP_DATA[0].out_count;
    plog->write("[SYRUP] DISPENSE BY WEIGHT " + QString().sprintf("SYRUP(%d) : WEIGHT(%d)",pump_num,weight_g));
    plan->SendControlData(DEV_SEND_ID_SYRUP, 0, 0x01, pump_num, weight_g);
}
void DialogSyrup::Tare(){
    plog->write("[SYRUP] TARE LOADCELL");
    plan->SendControlData(DEV_SEND_ID_SYRUP, 0, 0x02, 0, 0);
}

void DialogSyrup::SetCalibParam(int scale){
    plog->write("[SYRUP] SET CALIB PARAM : "+QString().sprintf("%d",scale));
    plan->SendControlData(DEV_SEND_ID_SYRUP, 0, 0x03, 0, scale);
}


int DialogSyrup::LoadcellValue(){
    return SYRUP_DATA[0].loadcell.value;
}


void DialogSyrup::UI_TimeDispense(int num){
    QStringList keys = stock->syrup_to_name.keys();
    DispenseSyrupByTime(stock->syrup_to_pump[keys[num]], ui->LE_SYRUP_OUT_TIME->text().toFloat()*1000.0);
    QString str;
}

void DialogSyrup::UI_WeightDispense(int num){
    QStringList keys = stock->syrup_to_name.keys();
    DispenseSyrupByWeight(stock->syrup_to_pump[keys[num]], ui->LE_SYRUP_OUT_WEIGHT->text().toInt());
    QString str;
}

void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_TIME_1_clicked(){
    plog->write("[USER INPUT] DISPENSE SYRUP BY TIME 1");
    UI_TimeDispense(0);
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_TIME_2_clicked(){
    plog->write("[USER INPUT] DISPENSE SYRUP BY TIME 2");
    UI_TimeDispense(1);
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_TIME_3_clicked(){
    plog->write("[USER INPUT] DISPENSE SYRUP BY TIME 3");
    UI_TimeDispense(2);
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_TIME_4_clicked(){
    plog->write("[USER INPUT] DISPENSE SYRUP BY TIME 4");
    UI_TimeDispense(3);
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_TIME_5_clicked(){
    plog->write("[USER INPUT] DISPENSE SYRUP BY TIME 5");
    UI_TimeDispense(4);
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_TIME_6_clicked(){
    plog->write("[USER INPUT] DISPENSE SYRUP BY TIME 6");
    UI_TimeDispense(5);
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_TIME_7_clicked(){
    plog->write("[USER INPUT] DISPENSE SYRUP BY TIME 7");
    UI_TimeDispense(6);
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_TIME_8_clicked(){
    plog->write("[USER INPUT] DISPENSE SYRUP BY TIME 8");
    UI_TimeDispense(7);
}


void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_WEIGHT_1_clicked(){
    plog->write("[USER INPUT] DISPENSE SYRUP BY WEIGHT 1");
    UI_WeightDispense(0);
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_WEIGHT_2_clicked(){
    plog->write("[USER INPUT] DISPENSE SYRUP BY WEIGHT 2");
    UI_WeightDispense(1);
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_WEIGHT_3_clicked(){
    plog->write("[USER INPUT] DISPENSE SYRUP BY WEIGHT 3");
    UI_WeightDispense(2);
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_WEIGHT_4_clicked(){
    plog->write("[USER INPUT] DISPENSE SYRUP BY WEIGHT 4");
    UI_WeightDispense(3);
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_WEIGHT_5_clicked(){
    plog->write("[USER INPUT] DISPENSE SYRUP BY WEIGHT 5");
    UI_WeightDispense(4);
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_WEIGHT_6_clicked(){
    plog->write("[USER INPUT] DISPENSE SYRUP BY WEIGHT 6");
    UI_WeightDispense(5);
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_WEIGHT_7_clicked(){
    plog->write("[USER INPUT] DISPENSE SYRUP BY WEIGHT 7");
    UI_WeightDispense(6);
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_WEIGHT_8_clicked(){
    plog->write("[USER INPUT] DISPENSE SYRUP BY WEIGHT 8");
    UI_WeightDispense(7);
}


void DialogSyrup::on_BTN_TARE_clicked(){
    plog->write("[USER INPUT] SYRUP TARE ");
    Tare();
}

void DialogSyrup::on_BTN_SET_SCALE_clicked(){
    plog->write("[USER INPUT] SYRUP SET SCALE : "+ui->LE_LOADCELL_SET_SCALE->text());
    SetCalibParam(ui->LE_LOADCELL_SET_SCALE->text().toInt());
}

void DialogSyrup::on_BTN_CLEANING_clicked()
{
    plog->write("[USER INPUT] START CLEANING SYRUP");
    state_cleaning = 0;
    start_cleaning = true;
}
