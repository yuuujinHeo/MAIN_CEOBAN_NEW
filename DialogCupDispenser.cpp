﻿#include "DialogCupDispenser.h"
#include "ui_DialogCupDispenser.h"
#include "RBLAN2CAN.h"

extern RBLAN2CAN *plan;
extern Logger   *plog;

DialogCupDispenser::DialogCupDispenser(QWidget *parent, DialogStock *_stock) :
    QDialog(parent), stock(_stock),
    ui(new Ui::DialogCupDispenser)
{
    ui->setupUi(this);


    FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_1 = 0;
    FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_2 = 0;
    FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_3 = 0;
    FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_4 = 0;

    FATAL_INFO_CUP_DISPENSER_ERROR_1 = 0;
    FATAL_INFO_CUP_DISPENSER_ERROR_2 = 0;
    FATAL_INFO_CUP_DISPENSER_ERROR_3 = 0;
    FATAL_INFO_CUP_DISPENSER_ERROR_4 = 0;

    FATAL_INFO_CUP_SENSOR_ERROR_1 = 0;
    FATAL_INFO_CUP_SENSOR_ERROR_2 = 0;
    FATAL_INFO_CUP_SENSOR_ERROR_3 = 0;
    FATAL_INFO_CUP_SENSOR_ERROR_4 = 0;

    SUPER_FATAL_ERROR_CUP_SENSOR_CONNECTION = 0;
    SUPER_FATAL_ERROR_CUP_SENSOR_ERROR = 0;

    PAUSE_FATAL_ERROR_CUP_DISPENSER = 0;
    PAUSE_FATAL_ERROR_CUP_SOLDOUT = 0;

    ui->GB_CUP->setStyleSheet("QGroupBox  {\n    margin-top: 10px;"
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

DialogCupDispenser::~DialogCupDispenser()
{
    delete ui;
}

void DialogCupDispenser::error_clear(){
    FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_1 = 0;
    FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_2 = 0;
    FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_3 = 0;
    FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_4 = 0;

    FATAL_INFO_CUP_DISPENSER_ERROR_1 = 0;
    FATAL_INFO_CUP_DISPENSER_ERROR_2 = 0;
    FATAL_INFO_CUP_DISPENSER_ERROR_3 = 0;
    FATAL_INFO_CUP_DISPENSER_ERROR_4 = 0;

    FATAL_INFO_CUP_SENSOR_ERROR_1 = 0;
    FATAL_INFO_CUP_SENSOR_ERROR_2 = 0;
    FATAL_INFO_CUP_SENSOR_ERROR_3 = 0;
    FATAL_INFO_CUP_SENSOR_ERROR_4 = 0;

    SUPER_FATAL_ERROR_CUP_SENSOR_CONNECTION = 0;
    SUPER_FATAL_ERROR_CUP_SENSOR_ERROR = 0;

    PAUSE_FATAL_ERROR_CUP_DISPENSER = 0;
    PAUSE_FATAL_ERROR_CUP_SOLDOUT = 0;
}
void DialogCupDispenser::CheckFatalError(){
    // FATAL INFORMATION=============================================
    if(CUP_DATA[0].connection_status == 0){
        if(FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_1 == 0)
            plog->write("[CUP] ERROR : Disconnected 1");
        FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_1 = 1;
    }else{
        FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_1 = 0;
    }
    if(CUP_DATA[1].connection_status == 0){
        if(FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_2 == 0)
            plog->write("[CUP] ERROR : Disconnected 2");
        FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_2 = 1;
    }else{
        FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_2 = 0;
    }
    if(CUP_DATA[2].connection_status == 0){
        if(FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_3 == 0)
            plog->write("[CUP] ERROR : Disconnected 3");
        FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_3 = 1;
    }else{
        FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_3 = 0;
    }
    if(CUP_DATA[3].connection_status == 0){
        if(FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_4 == 0)
            plog->write("[CUP] ERROR : Disconnected 4");
        FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_4 = 1;
    }else{
        FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_4 = 0;
    }


    if(((CUP_DATA[0].status>>1)&0x01) == 0x01){
        if(FATAL_INFO_CUP_SENSOR_ERROR_1 == 0)
            plog->write("[CUP] ERROR : Cup Sensor 1");
        FATAL_INFO_CUP_SENSOR_ERROR_1 = 1;
    }else{
        FATAL_INFO_CUP_SENSOR_ERROR_1 = 0;
    }
    if(((CUP_DATA[1].status>>1)&0x01) == 0x01){
        if(FATAL_INFO_CUP_SENSOR_ERROR_2 == 0)
            plog->write("[CUP] ERROR : Cup Sensor 2");
        FATAL_INFO_CUP_SENSOR_ERROR_2 = 1;
    }else{
        FATAL_INFO_CUP_SENSOR_ERROR_2 = 0;
    }
    if(((CUP_DATA[2].status>>1)&0x01) == 0x01){
        if(FATAL_INFO_CUP_SENSOR_ERROR_3 == 0)
            plog->write("[CUP] ERROR : Cup Sensor 3");
        FATAL_INFO_CUP_SENSOR_ERROR_3 = 1;
    }else{
        FATAL_INFO_CUP_SENSOR_ERROR_3 = 0;
    }
    if(((CUP_DATA[3].status>>1)&0x01) == 0x01){
        if(FATAL_INFO_CUP_SENSOR_ERROR_4 == 0)
            plog->write("[CUP] ERROR : Cup Sensor 4");
        FATAL_INFO_CUP_SENSOR_ERROR_4 = 1;
    }else{
        FATAL_INFO_CUP_SENSOR_ERROR_4 = 0;
    }



    // FATAL ERROR ===================================================
    if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_STATE){
        if(FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_1 == 1 && FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_2 == 1&& FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_3 == 1 && FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_4 == 1){
            SUPER_FATAL_ERROR_CUP_SENSOR_CONNECTION = 1;
        }
        if(FATAL_INFO_CUP_SENSOR_ERROR_1 == 1 && FATAL_INFO_CUP_SENSOR_ERROR_2 == 1&& FATAL_INFO_CUP_SENSOR_ERROR_3 == 1&& FATAL_INFO_CUP_SENSOR_ERROR_4 == 1){
            SUPER_FATAL_ERROR_CUP_SENSOR_ERROR = 1;
        }
        if(FATAL_INFO_CUP_DISPENSER_ERROR_1 == 1 && FATAL_INFO_CUP_DISPENSER_ERROR_2 == 1 && FATAL_INFO_CUP_DISPENSER_ERROR_3 == 1 && FATAL_INFO_CUP_DISPENSER_ERROR_4 == 1){
            PAUSE_FATAL_ERROR_CUP_DISPENSER = 1;
        }else if(((CUP_DATA[0].status>>2)&0x01) == 0x01 && FATAL_INFO_CUP_DISPENSER_ERROR_2 == 1){
            PAUSE_FATAL_ERROR_CUP_DISPENSER = 1;
        }else if(((CUP_DATA[1].status>>2)&0x01) == 0x01 && FATAL_INFO_CUP_DISPENSER_ERROR_1 == 1){
            PAUSE_FATAL_ERROR_CUP_DISPENSER = 1;
        }else if(((CUP_DATA[2].status>>2)&0x01) == 0x01 && FATAL_INFO_CUP_DISPENSER_ERROR_4 == 1){
            PAUSE_FATAL_ERROR_CUP_DISPENSER = 1;
        }else if(((CUP_DATA[3].status>>2)&0x01) == 0x01 && FATAL_INFO_CUP_DISPENSER_ERROR_3 == 1){
            PAUSE_FATAL_ERROR_CUP_DISPENSER = 1;
        }

        if(((CUP_DATA[0].status>>2)&0x01) == 0x01 && ((CUP_DATA[1].status>>2)&0x01) == 0x01){
            PAUSE_FATAL_ERROR_CUP_SOLDOUT = 1;
        }else if(((CUP_DATA[2].status>>2)&0x01) == 0x01 && ((CUP_DATA[3].status>>2)&0x01) == 0x01){
            PAUSE_FATAL_ERROR_CUP_SOLDOUT = 1;
        }
    }




    // stock device error handling
    if(IsCupAvailable(0) == 0){
        stock->SetDeviceError("PAPER_CUP_1");
    }else{
        stock->ClearDeviceError("PAPER_CUP_1");
    }
    if(IsCupAvailable(1) == 0){
        stock->SetDeviceError("PAPER_CUP_2");
    }else{
        stock->ClearDeviceError("PAPER_CUP_2");
    }
    if(IsCupAvailable(2) == 0){
        stock->SetDeviceError("PP_CUP_1");
    }else{
        stock->ClearDeviceError("PP_CUP_1");
    }
    if(IsCupAvailable(3) == 0){
        stock->SetDeviceError("PP_CUP_2");
    }else{
        stock->ClearDeviceError("PP_CUP_2");
    }
}

int DialogCupDispenser::IsCupAvailable(int dev){
    if(plan->sockConnectionStatus == false){   // 연결
        return 0;
    }
    if(CUP_DATA[dev].connection_status == 0){   // 연결
        return 0;
    }
    if(((CUP_DATA[dev].status>>1)&0x01) == 0x01){   // 컵 감지 센서 에러
        return 0;
    }
    if(((CUP_DATA[dev].status>>2)&0x01) == 0x01){ // 컵 재고 없음
        return 0;
    }
    return 1;
}




void DialogCupDispenser::onTimer(){
    if(IS_UI_LOCK){
        ui->GB_CUP->setEnabled(false);
    }else{
        ui->GB_CUP->setEnabled(true);
    }

    CheckFatalError();

    if(plan->sockConnectionStatus == false){
        SetLEColor(ui->LE_CUP_CONNECTION_1, COLOR_NONE);
        SetLEColor(ui->LE_CUP_CONNECTION_2, COLOR_NONE);
        SetLEColor(ui->LE_CUP_CONNECTION_3, COLOR_NONE);
        SetLEColor(ui->LE_CUP_CONNECTION_4, COLOR_NONE);

        SetLEColor(ui->LE_CUP_SENSOR_ERROR_1, COLOR_NONE);
        SetLEColor(ui->LE_CUP_SENSOR_ERROR_2, COLOR_NONE);
        SetLEColor(ui->LE_CUP_SENSOR_ERROR_3, COLOR_NONE);
        SetLEColor(ui->LE_CUP_SENSOR_ERROR_4, COLOR_NONE);

        SetLEColor(ui->LE_CUP_HAS_CUP_1, COLOR_NONE);
        SetLEColor(ui->LE_CUP_HAS_CUP_2, COLOR_NONE);
        SetLEColor(ui->LE_CUP_HAS_CUP_3, COLOR_NONE);
        SetLEColor(ui->LE_CUP_HAS_CUP_4, COLOR_NONE);


        SetLEColor(ui->LE_CUP_DETECTED_1, COLOR_NONE);
        SetLEColor(ui->LE_CUP_DETECTED_2, COLOR_NONE);
        SetLEColor(ui->LE_CUP_DETECTED_3, COLOR_NONE);
        SetLEColor(ui->LE_CUP_DETECTED_4, COLOR_NONE);

        ui->LE_CUP_ULTRA_SONIC_1->setText("-");
        ui->LE_CUP_ULTRA_SONIC_2->setText("-");
        ui->LE_CUP_ULTRA_SONIC_3->setText("-");
        ui->LE_CUP_ULTRA_SONIC_4->setText("-");

        ui->LE_CUP_CHECK_COUNT_1->setText("-");
        ui->LE_CUP_CHECK_COUNT_2->setText("-");
        ui->LE_CUP_CHECK_COUNT_3->setText("-");
        ui->LE_CUP_CHECK_COUNT_4->setText("-");

        ui->LE_CUP_LAST_DISPENSE_ERROR_1->setText("-");
        ui->LE_CUP_LAST_DISPENSE_ERROR_2->setText("-");
        ui->LE_CUP_LAST_DISPENSE_ERROR_3->setText("-");
        ui->LE_CUP_LAST_DISPENSE_ERROR_4->setText("-");

        ui->LE_CUP_OP_STATE_1->setText("-");
        ui->LE_CUP_OP_STATE_2->setText("-");
        ui->LE_CUP_OP_STATE_3->setText("-");
        ui->LE_CUP_OP_STATE_4->setText("-");

    }else{

        if(CUP_DATA[0].connection_status == 1){
            SetLEColor(ui->LE_CUP_CONNECTION_1, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_CUP_CONNECTION_1, COLOR_BAD);
        }
        if(CUP_DATA[1].connection_status == 1){
            SetLEColor(ui->LE_CUP_CONNECTION_2, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_CUP_CONNECTION_2, COLOR_BAD);
        }
        if(CUP_DATA[2].connection_status == 1){
            SetLEColor(ui->LE_CUP_CONNECTION_3, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_CUP_CONNECTION_3, COLOR_BAD);
        }
        if(CUP_DATA[3].connection_status == 1){
            SetLEColor(ui->LE_CUP_CONNECTION_4, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_CUP_CONNECTION_4, COLOR_BAD);
        }


        if(((CUP_DATA[0].status>>1)&0x01) == 0x01){
            SetLEColor(ui->LE_CUP_SENSOR_ERROR_1, COLOR_BAD);
        }else{
            SetLEColor(ui->LE_CUP_SENSOR_ERROR_1, COLOR_NONE);
        }
        if(((CUP_DATA[1].status>>1)&0x01) == 0x01){
            SetLEColor(ui->LE_CUP_SENSOR_ERROR_2, COLOR_BAD);
        }else{
            SetLEColor(ui->LE_CUP_SENSOR_ERROR_2, COLOR_NONE);
        }
        if(((CUP_DATA[2].status>>1)&0x01) == 0x01){
            SetLEColor(ui->LE_CUP_SENSOR_ERROR_3, COLOR_BAD);
        }else{
            SetLEColor(ui->LE_CUP_SENSOR_ERROR_3, COLOR_NONE);
        }
        if(((CUP_DATA[3].status>>1)&0x01) == 0x01){
            SetLEColor(ui->LE_CUP_SENSOR_ERROR_4, COLOR_BAD);
        }else{
            SetLEColor(ui->LE_CUP_SENSOR_ERROR_4, COLOR_NONE);
        }


        if(((CUP_DATA[0].status>>2)&0x01) == 0x01){
            SetLEColor(ui->LE_CUP_HAS_CUP_1, COLOR_BAD);
        }else{
            SetLEColor(ui->LE_CUP_HAS_CUP_1, COLOR_NONE);
        }
        if(((CUP_DATA[1].status>>2)&0x01) == 0x01){
            SetLEColor(ui->LE_CUP_HAS_CUP_2, COLOR_BAD);
        }else{
            SetLEColor(ui->LE_CUP_HAS_CUP_2, COLOR_NONE);
        }


        if((CUP_DATA[0].status&0x01) == 0x01){
            SetLEColor(ui->LE_CUP_DETECTED_1, COLOR_BLUE);
        }else{
            SetLEColor(ui->LE_CUP_DETECTED_1, COLOR_NONE);
        }
        if((CUP_DATA[1].status&0x01) == 0x01){
            SetLEColor(ui->LE_CUP_DETECTED_2, COLOR_BLUE);
        }else{
            SetLEColor(ui->LE_CUP_DETECTED_2, COLOR_NONE);
        }
        if((CUP_DATA[2].status&0x01) == 0x01){
            SetLEColor(ui->LE_CUP_DETECTED_3, COLOR_BLUE);
        }else{
            SetLEColor(ui->LE_CUP_DETECTED_3, COLOR_NONE);
        }
        if((CUP_DATA[3].status&0x01) == 0x01){
            SetLEColor(ui->LE_CUP_DETECTED_4, COLOR_BLUE);
        }else{
            SetLEColor(ui->LE_CUP_DETECTED_4, COLOR_NONE);
        }


        ui->LE_CUP_ULTRA_SONIC_1->setText(QString().sprintf("%d", CUP_DATA[0].ultra_sonic_data));
        ui->LE_CUP_ULTRA_SONIC_2->setText(QString().sprintf("%d", CUP_DATA[1].ultra_sonic_data));
        ui->LE_CUP_ULTRA_SONIC_3->setText(QString().sprintf("%d", CUP_DATA[2].ultra_sonic_data));
        ui->LE_CUP_ULTRA_SONIC_4->setText(QString().sprintf("%d", CUP_DATA[3].ultra_sonic_data));

        ui->LE_CUP_CHECK_COUNT_1->setText(QString().sprintf("%d", CUP_DATA[0].cup_out_count));
        ui->LE_CUP_CHECK_COUNT_2->setText(QString().sprintf("%d", CUP_DATA[1].cup_out_count));
        ui->LE_CUP_CHECK_COUNT_3->setText(QString().sprintf("%d", CUP_DATA[2].cup_out_count));
        ui->LE_CUP_CHECK_COUNT_4->setText(QString().sprintf("%d", CUP_DATA[3].cup_out_count));


        if(CUP_DATA[0].last_error == 0){
            ui->LE_CUP_LAST_DISPENSE_ERROR_1->setText("정상");
            cup_1_error = "정상";
        }else{
            ui->LE_CUP_LAST_DISPENSE_ERROR_1->setText(QString().sprintf("E%d", CUP_DATA[0].last_error));
            cup_1_error = QString().sprintf("E%d", CUP_DATA[0].last_error);
        }
        if(CUP_DATA[1].last_error == 0){
            ui->LE_CUP_LAST_DISPENSE_ERROR_2->setText("정상");
            cup_2_error = "정상";
        }else{
            ui->LE_CUP_LAST_DISPENSE_ERROR_2->setText(QString().sprintf("E%d", CUP_DATA[1].last_error));
            cup_2_error = QString().sprintf("E%d", CUP_DATA[1].last_error);
        }
        if(CUP_DATA[2].last_error == 0){
            ui->LE_CUP_LAST_DISPENSE_ERROR_3->setText("정상");
            cup_3_error = "정상";
        }else{
            ui->LE_CUP_LAST_DISPENSE_ERROR_3->setText(QString().sprintf("E%d", CUP_DATA[2].last_error));
            cup_3_error = QString().sprintf("E%d", CUP_DATA[2].last_error);
        }
        if(CUP_DATA[3].last_error == 0){
            ui->LE_CUP_LAST_DISPENSE_ERROR_4->setText("정상");
            cup_4_error = "정상";
        }else{
            ui->LE_CUP_LAST_DISPENSE_ERROR_4->setText(QString().sprintf("E%d", CUP_DATA[3].last_error));
            cup_4_error = QString().sprintf("E%d", CUP_DATA[3].last_error);
        }


        if(CUP_DATA[0].dispense_op_flag == 0){
            ui->LE_CUP_OP_STATE_1->setText("준비");
        }else{
            ui->LE_CUP_OP_STATE_1->setText("동작중");
        }
        if(CUP_DATA[1].dispense_op_flag == 0){
            ui->LE_CUP_OP_STATE_2->setText("준비");
        }else{
            ui->LE_CUP_OP_STATE_2->setText("동작중");
        }
        if(CUP_DATA[2].dispense_op_flag == 0){
            ui->LE_CUP_OP_STATE_3->setText("준비");
        }else{
            ui->LE_CUP_OP_STATE_3->setText("동작중");
        }
        if(CUP_DATA[3].dispense_op_flag == 0){
            ui->LE_CUP_OP_STATE_4->setText("준비");
        }else{
            ui->LE_CUP_OP_STATE_4->setText("동작중");
        }
    }
}



void DialogCupDispenser::DispenseCup(int target){
    plog->write("[CUP] Dispense Cup : "+QString().sprintf("%d",target));
    CUP_DATA[target].prev_out_count = CUP_DATA[target].cup_out_count;
    plan->SendControlData(DEV_SEND_ID_CUP_DISPENSER, target, 0x00, 0, 0);
}

void DialogCupDispenser::on_BTN_CUP_DISPENSE_1_clicked(){
    plog->write("[CUP] DISPENSE CUP 1");
    DispenseCup(0);
}
void DialogCupDispenser::on_BTN_CUP_DISPENSE_2_clicked(){
    plog->write("[CUP] DISPENSE CUP 2");
    DispenseCup(1);
}

void DialogCupDispenser::on_BTN_CUP_DISPENSE_3_clicked()
{
    plog->write("[CUP] DISPENSE CUP 3");
    DispenseCup(2);
}
void DialogCupDispenser::on_BTN_CUP_DISPENSE_4_clicked()
{
    plog->write("[CUP] DISPENSE CUP 4");
    DispenseCup(3);
}
