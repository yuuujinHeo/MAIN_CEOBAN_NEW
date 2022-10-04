#include "DialogIceDispenser.h"
#include "ui_DialogIceDispenser.h"
#include "RBLAN2CAN.h"

extern RBLAN2CAN *plan;
extern Logger *plog;

DialogIceDispenser::DialogIceDispenser(QWidget *parent, DialogStock *_stock) :
    QDialog(parent), stock(_stock),
    ui(new Ui::DialogIceDispenser)
{
    ui->setupUi(this);


    FATAL_INFO_ICE_CONNECTION_ERROR_1 = 0;
    FATAL_INFO_ICE_DEVICE_ERROR_1 = 0;

    FORCE_FATAL_ERROR_ICE_CONNECTION = 0;
    FORCE_FATAL_ERROR_ICE_DEVICE = 0;

    m_serialPort = new QSerialPort();

    connect(m_serialPort,SIGNAL(readyRead()), this, SLOT(readData()));
    connect(m_serialPort,SIGNAL(errorOccurred(QSerialPort::SerialPortError)), this, SLOT(handleError(QSerialPort::SerialPortError)));

    m_serialPort->setPortName("ttyS6");
    m_serialPort->setBaudRate(QSerialPort::Baud9600);
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setStopBits(QSerialPort::OneStop);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);

    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(200);
}

DialogIceDispenser::~DialogIceDispenser()
{
    delete ui;
}

bool DialogIceDispenser::isOpenPort(){
    return m_serialPort->isOpen();
}
void DialogIceDispenser::readData(){
    QByteArray data = m_serialPort->readAll();

    if(data.size() < 6){
        plog->write("[ICE] LENGTH ERROR : " + data);
        return;
    }

    if(uchar(data.at(0)) == 0x02 && uchar(data.at(6)) == 0x03){
        ICE_DATA[0].connection_status = true;
        ICE_DATA[0].data_connection = true;
        connectionCount = 0;
        if(uchar(data.at(2)) == 0xA0){
            ICE_DATA[0].comm_mode = data.at(3);
        }else if(uchar(data.at(2)) == 0xB0){
            ICE_DATA[0].ice_out_count++;
            ICE_DATA[0].last_ice_out_time = data.at(3);
            ICE_DATA[0].last_water_out_time = data.at(4);
        }else if(uchar(data.at(2)) == 0xC0){

        }else if(uchar(data.at(2)) == 0xC1){
            ICE_DATA[0].setting_ambient_temp_low = data.at(3);
            ICE_DATA[0].setting_ambient_temp_high = data.at(4);
        }else if(uchar(data.at(2)) == 0xC2){
            ICE_DATA[0].ambient_temp = data.at(3);
        }else if(uchar(data.at(2)) == 0xC3){
            ICE_DATA[0].evaporator_temp = data.at(3);
            ICE_DATA[0].condensor_temp = data.at(4);
        }else if(uchar(data.at(2)) == 0xD0){
            ICE_DATA[0].timeout_sec = data.at(3)*60 + data.at(4);
        }else if(uchar(data.at(2)) == 0xE0){
        }else if(uchar(data.at(2)) == 0xE1){
            ICE_DATA[0].setting_ambient_temp_low = data.at(3);
            ICE_DATA[0].setting_ambient_temp_high = data.at(4);
        }else if(uchar(data.at(2)) == 0xCF){
            ICE_DATA[0].status.B[0] = data.at(3);
            ICE_DATA[0].status.B[1] = data.at(4);
        }else{
            plog->write("[ICE] Protocol command error : "+QString().sprintf("%c",data.at(2)));
        }
    }
}

void DialogIceDispenser::handleError(QSerialPort::SerialPortError error){
    if(error == QSerialPort::ResourceError){
        plog->write("[ICE] PORT CRITICAL ERROR");
        if(m_serialPort->isOpen())
            m_serialPort->close();
    }
}


void DialogIceDispenser::CheckFatalError(){
    // FATAL INFORMATION=============================================
    if(ICE_DATA[0].connection_status == 0 || ICE_DATA[0].data_connection == 0){
        if(FATAL_INFO_ICE_CONNECTION_ERROR_1 == 0)
            plog->write("[ICE] ERROR : DISCONNECTED 1");
        FATAL_INFO_ICE_CONNECTION_ERROR_1 = 1;
    }else{
        FATAL_INFO_ICE_CONNECTION_ERROR_1 = 0;
    }


    if((ICE_DATA[0].status.B[1] & 0x0F) != 0){
        if(FATAL_INFO_ICE_DEVICE_ERROR_1 == 0)
            plog->write("[ICE] ERROR : DEVICE ERROR "+QString().sprintf("%d",ICE_DATA[0].status.B[1]));
        FATAL_INFO_ICE_DEVICE_ERROR_1 = 1;
    }else{
        FATAL_INFO_ICE_DEVICE_ERROR_1 = 1;
    }


//    // FATAL ERROR ===================================================
//    if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_STATE){
//        if(FATAL_INFO_ICE_CONNECTION_ERROR == 1){
//            FORCE_FATAL_ERROR_ICE_CONNECTION = 1;
//        }
//        if(FATAL_INFO_ICE_DEVICE_ERROR == 1){
//            FORCE_FATAL_ERROR_ICE_DEVICE = 1;
//        }
//    }


    // stock device error handling
    if(IsIceAvailable(0) == 0){
        stock->SetDeviceError("ICE");
    }else{
        stock->ClearDeviceError("ICE");
    }
}


int DialogIceDispenser::IsIceAvailable(int dev){
    if(isOpenPort() == false)
        return false;

    if(ICE_DATA[dev].connection_status == 1 && ICE_DATA[dev].data_connection == 1){
        // device available check
        if((ICE_DATA[dev].status.B[1] & 0x0F) == 0){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

void DialogIceDispenser::WriteData(const QByteArray &data){
    m_serialPort->write(data);
    m_serialPort->waitForBytesWritten(200);
}

void DialogIceDispenser::onTimer(){
    static int time_cnt = 0;
    static int error_clear_cnt = 0;
    time_cnt++;
    error_clear_cnt++;
    if(time_cnt > 10 && !m_serialPort->isOpen()){
        if(m_serialPort->open(QIODevice::ReadWrite)){
            plog->write("[ICE] SERIAL "+m_serialPort->portName() + " OPEN SUCCESS!");
        }else{
            plog->write("[ICE] SERIAL "+m_serialPort->portName() + " OPEN FAIL");
        }
        time_cnt = 0;
    }

    if(IS_UI_LOCK){
        ui->GB_ICE->setEnabled(false);
    }else{
        ui->GB_ICE->setEnabled(true);
    }

    CheckFatalError();
    if(m_serialPort->isOpen() == false){
        SetLEColor(ui->LE_ICE_CONNECTION, COLOR_NONE);
        ui->LB_STATUS_COMM_MODE->setText("-");

        ui->LB_STATUS_COMP_WORKING->setText("-");
        ui->LB_STATUS_GEAR_WORKING->setText("-");
        ui->LB_STATUS_OUT_SOL_DETECT->setText("-");
        ui->LB_STATUS_CUP_LEVER_DETECT->setText("-");
        ui->LB_STATUS_FULL_ICE->setText("-");
        ui->LE_ICE_ERROR->setText("-");
        ui->LB_ERROR_TYPE->setText("-");
        SetLEColor(ui->LE_ICE_ERROR, COLOR_NONE);
        ui->LB_STATUS_LAST_ICE_TIME->setText("-");
        ui->LB_STATUS_LAST_WATER_TIME->setText("-");

        ui->LB_STATUS_AMBIENT_TEMP_LOW->setText("-");
        ui->LB_STATUS_AMBIENT_TEMP_HIGH->setText("-");
        ui->LB_STATUS_AMBIENT_TEMP_NOW->setText("-");

        ui->LB_STATUS_EVAPORATOR_TEMP->setText("-");
        ui->LB_STATUS_CONDENSOR_TEMP->setText("-");
        ui->LE_ICE_CHECK_COUNT->setText("-");

    }else{
        if(connectionCount > 5){
            ICE_DATA[0].connection_status = false;
            ICE_DATA[0].data_connection = false;
        }
        connectionCount++;
        RequestStatus();


        if(ICE_DATA[0].connection_status == 1){
            SetLEColor(ui->LE_ICE_CONNECTION, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_ICE_CONNECTION, COLOR_BAD);
        }

        if(ICE_DATA[0].connection_status == 1 && ICE_DATA[0].data_connection == 1){
            SetLEColor(ui->LE_ICE_DATA_CONNECTION, COLOR_GOOD);

            if(ICE_DATA[0].status.b.comm_mode == 1){
                ui->LB_STATUS_COMM_MODE->setText("RS232");
            }else{
                ui->LB_STATUS_COMM_MODE->setText("일반모드");
            }

            if(ICE_DATA[0].status.b.comp_working == 1){
                ui->LB_STATUS_COMP_WORKING->setText("동작중");
            }else{
                ui->LB_STATUS_COMP_WORKING->setText("정지상태");
            }

            if(ICE_DATA[0].status.b.gear_motor_working == 1){
                ui->LB_STATUS_GEAR_WORKING->setText("동작중");
            }else{
                ui->LB_STATUS_GEAR_WORKING->setText("정지상태");
            }

            if(ICE_DATA[0].status.b.out_sol_detected == 1){
                ui->LB_STATUS_OUT_SOL_DETECT->setText("감지");
            }else{
                ui->LB_STATUS_OUT_SOL_DETECT->setText("미감지");
            }

            if(ICE_DATA[0].status.b.cup_lever_detected == 1){
                ui->LB_STATUS_CUP_LEVER_DETECT->setText("감지");
            }else{
                ui->LB_STATUS_CUP_LEVER_DETECT->setText("미감지");
            }

            if(ICE_DATA[0].status.b.full_ice == 1){
                ui->LB_STATUS_FULL_ICE->setText("만빙");
            }else{
                ui->LB_STATUS_FULL_ICE->setText("만빙아님");
            }


            ui->LE_ICE_ERROR->setText(QString().sprintf("%1d%1d%1d%1d", ICE_DATA[0].status.b.err_code_4, ICE_DATA[0].status.b.err_code_3, ICE_DATA[0].status.b.err_code_2, ICE_DATA[0].status.b.err_code_1));
            int temp_error = ICE_DATA[0].status.B[1] & 0x0F;
            if(temp_error != 0){
                QString temp_ice_string = "";
                switch(temp_error){
                case 1:
                    temp_ice_string += "급수불량 /";
                    break;
                case 2:
                    temp_ice_string += "배수불량 /";
                    break;
                case 3:
                    temp_ice_string += "내부온도저온 /";
                    break;
                case 4:
                    temp_ice_string += "내부온도고온 /";
                    break;
                case 5:
                    temp_ice_string += "콘덴서과열 /";
                    break;
                case 6:
                    temp_ice_string += "증발기과냉 /";
                    break;
                case 7:
                    temp_ice_string += "제빙모터이상 /";
                    break;
                case 8:
                    temp_ice_string += "제빙기능불량 /";
                    break;
                case 9:
                    temp_ice_string += "정기점검알람 /";
                    break;
                case 15:
                    temp_ice_string += "팬모터이상 /";
                    break;
                default:
                    temp_ice_string += "원인불명 /";
                    break;
                }
                SetLEColor(ui->LE_ICE_ERROR, COLOR_BAD);
                ui->LB_ERROR_TYPE->setText(temp_ice_string);
                if(temp_ice_string != ice_1_error){
                    plog->write("[ICE] ERROR : "+temp_ice_string);
                }
                ice_1_error = temp_ice_string;

                //Try to clear error
                if(error_clear_cnt > 2500){//10min
                    ClearStatus(0);
                    error_clear_cnt = 0;
                }

            }else{
                SetLEColor(ui->LE_ICE_ERROR, COLOR_GOOD);
                ui->LB_ERROR_TYPE->setText("에러없음");
                ice_1_error = "에러없음";
            }

            ui->LB_STATUS_LAST_ICE_TIME->setText(QString().sprintf("%.1f", float(ICE_DATA[0].last_ice_out_time/16*10 + ICE_DATA[0].last_ice_out_time%16)/10.0));
            ui->LB_STATUS_LAST_WATER_TIME->setText(QString().sprintf("%.1f", float(ICE_DATA[0].last_water_out_time/16*10 + ICE_DATA[0].last_water_out_time%16)/10.0));

            ui->LB_STATUS_AMBIENT_TEMP_LOW->setText(QString().sprintf("%d", ICE_DATA[0].setting_ambient_temp_low));
            ui->LB_STATUS_AMBIENT_TEMP_HIGH->setText(QString().sprintf("%d", ICE_DATA[0].setting_ambient_temp_high));
            ui->LB_STATUS_AMBIENT_TEMP_NOW->setText(QString().sprintf("%d", ICE_DATA[0].ambient_temp));

            ui->LB_STATUS_EVAPORATOR_TEMP->setText(QString().sprintf("%d", (char)(ICE_DATA[0].evaporator_temp)));
            ui->LB_STATUS_CONDENSOR_TEMP->setText(QString().sprintf("%d", ICE_DATA[0].condensor_temp));

            ui->LE_ICE_CHECK_COUNT->setText(QString().sprintf("%d", ICE_DATA[0].ice_out_count));
        }else{
            // device available check
            stock->SetDeviceError("ICE");

            ui->LB_STATUS_COMM_MODE->setText("-");

            ui->LB_STATUS_COMP_WORKING->setText("-");
            ui->LB_STATUS_GEAR_WORKING->setText("-");
            ui->LB_STATUS_OUT_SOL_DETECT->setText("-");
            ui->LB_STATUS_CUP_LEVER_DETECT->setText("-");
            ui->LB_STATUS_FULL_ICE->setText("-");
            ui->LE_ICE_ERROR->setText("-");
            ui->LB_ERROR_TYPE->setText("-");
            SetLEColor(ui->LE_ICE_ERROR, COLOR_NONE);
            ui->LB_STATUS_LAST_ICE_TIME->setText("-");
            ui->LB_STATUS_LAST_WATER_TIME->setText("-");

            ui->LB_STATUS_AMBIENT_TEMP_LOW->setText("-");
            ui->LB_STATUS_AMBIENT_TEMP_HIGH->setText("-");
            ui->LB_STATUS_AMBIENT_TEMP_NOW->setText("-");

            ui->LB_STATUS_EVAPORATOR_TEMP->setText("-");
            ui->LB_STATUS_CONDENSOR_TEMP->setText("-");
            ui->LE_ICE_CHECK_COUNT->setText("-");

            if(ICE_DATA[0].data_connection == 0){
                SetLEColor(ui->LE_ICE_DATA_CONNECTION, COLOR_BAD);
            }
        }
    }
}


void DialogIceDispenser::DispenseIceWater(int target, int ice_time_ms, int water_time_ms){
    plog->write("[ICE] Dispense : "+QString().sprintf("(%d) Ice(%d) Water(%d)",target,ice_time_ms,water_time_ms));
    ICE_DATA[target].prev_out_count = ICE_DATA[target].ice_out_count;

    QByteArray msg;
    msg[0] = 0x02;
    msg[1] = 0x01;
    msg[2] = 0xB0;
    msg[3] = (ice_time_ms/1000)<<4 | (ice_time_ms%1000)/100;
    msg[4] = (water_time_ms/1000)<<4 | (water_time_ms%1000)/100;
    msg[5] = msg[1]^msg[2]^msg[3]^msg[4];
    msg[6] = 0x03;

    qDebug() << msg;
    WriteData(msg);

//    plan->SendControlData(DEV_SEND_ID_ICE_DISPENSER, target, 0x00, ice_time_ms, water_time_ms);
}
void DialogIceDispenser::ChangeCommMode(int target, int comm_mode, int cup_ignore){
    plog->write("[ICE] Change Comm Mode : "+QString().sprintf("(%d) Mode(%d) CupIgnore(%d)",target,comm_mode,cup_ignore));
    QByteArray msg;
    msg[0] = 0x02;
    msg[1] = 0x01;
    msg[2] = 0xA0;
    msg[3] = comm_mode;
    msg[4] = 0x00;
    msg[5] = msg[1]^msg[2]^msg[3]^msg[4];
    msg[6] = 0x03;

    WriteData(msg);
//    plan->SendControlData(DEV_SEND_ID_ICE_DISPENSER, target, 0x01, comm_mode, cup_ignore);
}
void DialogIceDispenser::ClearStatus(int target){
    plog->write("[ICE] Clear Status : "+QString().sprintf("%d",target));
    QByteArray msg;
    msg[0] = 0x02;
    msg[1] = 0x01;
    msg[2] = 0xC0;
    msg[3] = 0x01;
    msg[4] = 0x00;
    msg[5] = msg[1]^msg[2]^msg[3]^msg[4];
    msg[6] = 0x03;

    WriteData(msg);
//    plan->SendControlData(DEV_SEND_ID_ICE_DISPENSER, target, 0x02, 0, 0);
}
void DialogIceDispenser::SetTimeout(int target, int timeout){
    plog->write("[ICE] Set Timeout : "+QString().sprintf("(%d) timeout(%d))",target,timeout));
    QByteArray msg;
    msg[0] = 0x02;
    msg[1] = 0x01;
    msg[2] = 0xD0;
    msg[3] = timeout/60;
    msg[4] = timeout%60;
    msg[5] = msg[1]^msg[2]^msg[3]^msg[4];
    msg[6] = 0x03;

    WriteData(msg);
//    plan->SendControlData(DEV_SEND_ID_ICE_DISPENSER, target, 0x03, timeout, 0);
}
void DialogIceDispenser::Reboot(int target){
    plog->write("[ICE] Reboot : "+QString().sprintf("%d",target));
    QByteArray msg;
    msg[0] = 0x02;
    msg[1] = 0x01;
    msg[2] = 0xE0;
    msg[3] = 0x00;
    msg[4] = 0x00;
    msg[5] = msg[1]^msg[2]^msg[3]^msg[4];
    msg[6] = 0x03;

    WriteData(msg);
//    plan->SendControlData(DEV_SEND_ID_ICE_DISPENSER, target, 0x04, 0, 0);
}
void DialogIceDispenser::SetAmbientTemperature(int target, int tempL, int tempH){
    plog->write("[ICE] Set Ambient Temp : "+QString().sprintf("(%d) tempL(%d) tempH(%d)",target,tempL,tempH));
    QByteArray msg;
    msg[0] = 0x02;
    msg[1] = 0x01;
    msg[2] = 0xE1;
    msg[3] = tempL;
    msg[4] = tempH;
    msg[5] = msg[1]^msg[2]^msg[3]^msg[4];
    msg[6] = 0x03;

    WriteData(msg);
//    plan->SendControlData(DEV_SEND_ID_ICE_DISPENSER, target, 0x05, tempL, tempH);
}


void DialogIceDispenser::RequestStatus(){
    static int count = 0;

    QByteArray msg;
    if(count == 0){
        msg[0] = 0x02;
        msg[1] = 0x01;
        msg[2] = 0xC1;
        msg[3] = 0x00;
        msg[4] = 0x00;
        msg[5] = msg[1]^msg[2]^msg[3]^msg[4];
        msg[6] = 0x03;
        count++;
    }else if(count == 1){
        msg[0] = 0x02;
        msg[1] = 0x01;
        msg[2] = 0xC2;
        msg[3] = 0x00;
        msg[4] = 0x00;
        msg[5] = msg[1]^msg[2]^msg[3]^msg[4];
        msg[6] = 0x03;
        count++;
    }else if(count == 2){
        msg[0] = 0x02;
        msg[1] = 0x01;
        msg[2] = 0xC3;
        msg[3] = 0x00;
        msg[4] = 0x00;
        msg[5] = msg[1]^msg[2]^msg[3]^msg[4];
        msg[6] = 0x03;
        count++;
    }else if(count == 3){
        msg[0] = 0x02;
        msg[1] = 0x01;
        msg[2] = 0xCF;
        msg[3] = 0x00;
        msg[4] = 0x00;
        msg[5] = msg[1]^msg[2]^msg[3]^msg[4];
        msg[6] = 0x03;
        count = 0;
    }
    WriteData(msg);
//    plan->SendControlData(DEV_SEND_ID_ICE_DISPENSER, target, 0x05, tempL, tempH);
}


void DialogIceDispenser::on_BTN_ICE_TEST_ICE_OUT_clicked(){
    plog->write("[ICE] ICE OUT 1 clicked");
    int ice_time = (int)(ui->LE_ICE_TEST_ICE_OUT_TIME->text().toFloat()*1000.0);
    int water_time = (int)(ui->LE_ICE_TEST_WATER_OUT_TIME->text().toFloat()*1000.0);
    DispenseIceWater(0, ice_time, water_time);
}

void DialogIceDispenser::on_BTN_ICE_CHANGE_COMM_MODE_clicked(){
    plog->write("[ICE] CHANGE COMM MODE clicked");
    int comm_mode = ui->CB_ICE_COMM_MODE->currentIndex();
    int cup_ignore = ui->CB_ICE_CUP_IGNORE->currentIndex();
    ChangeCommMode(0, comm_mode, cup_ignore);
}

void DialogIceDispenser::on_BTN_ICE_TEST_STATUS_CLEAR_clicked(){
    plog->write("[ICE] CLEAR STATUS clicked");
    ClearStatus(0);
}

void DialogIceDispenser::on_BTN_ICE_CHANGE_ICE_OUT_TIME_clicked(){
    plog->write("[ICE] CHANGE ICE OUT TIME clicked");
    int sec = ui->LE_ICE_SETTING_ICE_OUT_TIME_MIN->text().toInt()*60 + ui->LE_ICE_SETTING_ICE_OUT_TIME_SEC->text().toInt();
    if(sec > 255){
        sec = 255;
    }
    SetTimeout(0, sec);
}

void DialogIceDispenser::on_BTN_ICE_TEST_REBOOT_clicked(){
    plog->write("[ICE] REBOOT ICE clicked");
    Reboot(0);
}

void DialogIceDispenser::on_BTN_ICE_CHANGE_AMBIENT_TEMP_clicked(){
    plog->write("[ICE] CHANGE AMBIENT TEMP clicked");
    SetAmbientTemperature(0, ui->LE_ICE_SETTING_AMBIENT_TEMP_LOW->text().toInt(), ui->LE_ICE_SETTING_AMBIENT_TEMP_HIGH->text().toInt());
}


