﻿#include "DialogIcecream.h"
#include "ui_DialogIcecream.h"
#include "RBLAN2CAN.h"

extern RBLAN2CAN *plan;

DialogIcecream::DialogIcecream(QWidget *parent, DialogStock *_stock) :
    QDialog(parent), stock(_stock),
    ui(new Ui::DialogIcecream)
{
    ui->setupUi(this);

    ui->GB_ICECREAM->setStyleSheet("QGroupBox  {\n    margin-top: 10px;"
                                  "	font: 20pt \"함초롬돋움\";\n}\n\nQGroupBox::title  {"
                                                     "    subcontrol-origin: margin;"
                                                     "    subcontrol-position: top center;"
                                                     "    padding: 10px 8000px 10px 8000px;"
                                                     "    background-color: #FFC4D8;"
                                                     "    color: rgb(255, 255, 255);}"
                                                     "QLabel {\n	font: 10pt \"함초롬돋움\";\n}"
                                                    "QComboBox{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}\nQPushButton{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}"
                                                    "QLineEdit{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}");

#ifdef ICECREAM_CYLINDER
    ui->FRAME_CYLINDER->setVisible(true);
    ui->FRAME_NONE->setVisible(false);
#else
    ui->FRAME_CYLINDER->setVisible(false);
    ui->FRAME_NONE->setVisible(true);
#endif
    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(200);

}

DialogIcecream::~DialogIcecream()
{
    delete ui;
}


void DialogIcecream::onTimer(){
    static unsigned int tt = 0;
    tt++;


    if(IS_UI_LOCK){
        ui->GB_ICECREAM->setEnabled(false);
    }else{
        ui->GB_ICECREAM->setEnabled(true);
    }

    if(plan->sockConnectionStatus == false){
        SetLEColor(ui->LE_ICECREAM_CONNECTION, COLOR_NONE);

        ui->LE_DISPENSE_COUNT->setText("-");
        ui->LE_LAST_DISPENSE_ERROR->setText("-");
        ui->LE_OP_STATE->setText("-");

        ui->LE_LOADCELL_WEIGHT->setText("-");
        ui->LE_LOADCELL_SCALE->setText("-");
        ui->LE_LOADCELL_ERROR->setText("-");
    }else{
        if(ICECREAM_DATA[0].connection_status == 1){
            SetLEColor(ui->LE_ICECREAM_CONNECTION, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_ICECREAM_CONNECTION, COLOR_BAD);
        }


        ui->LE_DISPENSE_COUNT->setText(QString().sprintf("%d", ICECREAM_DATA[0].out_count));

        if(ICECREAM_DATA[0].last_error == 0){
            ui->LE_LAST_DISPENSE_ERROR->setText("정상");
            icecream_error = "정상";
        }else{
            ui->LE_LAST_DISPENSE_ERROR->setText(QString().sprintf("E%d", ICECREAM_DATA[0].last_error));
            icecream_error = QString().sprintf("E%d", ICECREAM_DATA[0].last_error);
        }

        if(ICECREAM_DATA[0].out_state == 0){
            ui->LE_OP_STATE->setText("준비");
        }else{
            ui->LE_OP_STATE->setText("동작중");
        }


        ui->LE_LOADCELL_WEIGHT->setText(QString().sprintf("%d", ICECREAM_DATA[0].loadcell[0].value));
        ui->LE_LOADCELL_SCALE->setText(QString().sprintf("%d", ICECREAM_DATA[0].loadcell[0].calib_param));

        ui->LE_LOADCELL_WEIGHT_2->setText(QString().sprintf("%d", ICECREAM_DATA[0].loadcell[1].value));
        ui->LE_LOADCELL_SCALE_2->setText(QString().sprintf("%d", ICECREAM_DATA[0].loadcell[1].calib_param));

        ui->LE_LOADCELL_TOTAL_WEIGHT->setText(QString().sprintf("%d", LoadcellValue()));

        if(ICECREAM_DATA[0].loadcell[0].error == 0){
            SetLEColor(ui->LE_LOADCELL_ERROR, COLOR_GOOD);
            ui->LE_LOADCELL_ERROR->setText("정상");
        }else{
            SetLEColor(ui->LE_LOADCELL_ERROR, COLOR_BAD);
            ui->LE_LOADCELL_ERROR->setText("에러");
        }

        if(ICECREAM_DATA[0].loadcell[1].error == 0){
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
            if(tt%5 == 0 && ICECREAM_DATA[0].connection_status == 1){
//                qDebug() << ICECREAM_DATA[0].loadcell[0].calib_param << LOADCELL_SCALE_ICECREAM_1;
                if(ICECREAM_DATA[0].loadcell[0].calib_param != LOADCELL_SCALE_ICECREAM_1){
                    SetCalibParam(LOADCELL_SCALE_ICECREAM_1, 0);
                }
                if(ICECREAM_DATA[0].loadcell[1].calib_param != LOADCELL_SCALE_ICECREAM_2){
                    SetCalibParam(LOADCELL_SCALE_ICECREAM_2, 1);
                }
            }
        }
    }
    if(IsIcecreamAvailable() == false){
        stock->SetDeviceError("ICECREAM");
    }else{
        stock->ClearDeviceError("ICECREAM");
    }
}


int DialogIcecream::IsIcecreamAvailable(){
    if(plan->sockConnectionStatus == false)
        return false;

    if(ICECREAM_DATA[0].connection_status == 1){
        // device available check
        if(ICECREAM_DATA[0].loadcell[0].error == 0 && ICECREAM_DATA[0].loadcell[1].error == 0){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

void DialogIcecream::DispenseIcecreamByWeight(int weight_g){
    ICECREAM_DATA[0].prev_out_count = ICECREAM_DATA[0].out_count;
    plan->SendControlData(DEV_SEND_ID_ICECREAM, 0, 0x01, 0, weight_g);
}


void DialogIcecream::StartMeasure(int threshold){
    ICECREAM_DATA[0].prev_out_count = ICECREAM_DATA[0].out_count;
    plan->SendControlData(DEV_SEND_ID_ICECREAM, 0, 0x01, 0, threshold);
}

void DialogIcecream::RobotStop(){
    plan->SendControlData(DEV_SEND_ID_ICECREAM, 0, 0x04, 0, 0);
}

void DialogIcecream::Tare(){
    plan->SendControlData(DEV_SEND_ID_ICECREAM, 0, 0x02, 0, 0);
}

void DialogIcecream::SetCalibParam(int scale, int loadcell_id){
    plan->SendControlData(DEV_SEND_ID_ICECREAM, 0, 0x03, loadcell_id, scale);
}


int DialogIcecream::LoadcellValue(){
    return (ICECREAM_DATA[0].loadcell[0].value + ICECREAM_DATA[0].loadcell[1].value)/2;
}


void DialogIcecream::on_BTN_SET_SCALE_clicked(){
    SetCalibParam(ui->LE_LOADCELL_SET_SCALE->text().toInt(), 0);
    plog->write("[UI OPERATION - ICECREAM] Scale1 설정");
}

void DialogIcecream::on_BTN_SET_SCALE_2_clicked(){
    SetCalibParam(ui->LE_LOADCELL_SET_SCALE_2->text().toInt(), 1);
    plog->write("[UI OPERATION - ICECREAM] Scale2 설정");
}


void DialogIcecream::on_BTN_TARE_clicked(){
    Tare();
    plog->write("[UI OPERATION - ICECREAM] 영점");
}

void DialogIcecream::on_BTN_DISPENSE_ICECREAM_BY_WEIGHT_clicked(){
    DispenseIcecreamByWeight(ui->LE_OUT_WEIGHT->text().toInt());
    plog->write("[UI OPERATION - ICECREAM] 아이스크림 배출");
}

void DialogIcecream::on_BTN_ICECREAM_CLEANING_START_clicked()
{
    plog->write("[UI OPERATION - ICECREAM] 청소 시작");
    plan->SendControlData(DEV_SEND_ID_ICECREAM, 0, 0x00, 1, 0);
}

void DialogIcecream::on_BTN_ICECREAM_CLEANING_STOP_clicked()
{
    plog->write("[UI OPERATION - ICECREAM] 청소 종료");
    plan->SendControlData(DEV_SEND_ID_ICECREAM, 0, 0x00, 0, 0);
}

void DialogIcecream::on_BTN_START_MEASURE_clicked()
{
    StartMeasure(ui->LE_LOADCELL_THRESHOLD->text().toInt());
    plog->write("[UI OPERATION - ICECREAM] 측정 시작 : "+ui->LE_LOADCELL_THRESHOLD->text());

}

void DialogIcecream::on_BTN_ROBOT_STOP_clicked()
{
    RobotStop();
    plog->write("[UI OPERATION - ICECREAM] 강제 종료");
}
