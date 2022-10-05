#include "DialogError.h"
#include "ui_DialogError.h"

extern RBLAN2CAN *plan;
extern Logger *plog;

DialogError::DialogError(QWidget *parent, DialogStock *_stock, DialogRobot *_robot, DialogCupDispenser *_cup,
                         DialogCoffee *_coffee, DialogIceDispenser *_ice,
                         DialogSyrup *_syrup, DialogOutlet *_outlet,
                         DialogBarcode *_barcode, DialogMonitor *_monitor) :
QDialog(parent), stock(_stock), robot(_robot), cup(_cup),
coffee(_coffee), ice(_ice),
syrup(_syrup), outlet(_outlet),
barcode(_barcode), monitor(_monitor),
ui(new Ui::DialogError)
{
    ui->setupUi(this);
    UpdateMenuAvailable();
}

DialogError::~DialogError()
{
    delete ui;
}

void DialogError::UpdateMenuAvailable(){
}

int DialogError::UpdateError(){
    ui->LW_ERROR->clear();

    //ERROR - CAN (메인보드, 배출구, 시럽, 출입구센서, 컵) : (메인보드, 배출구, 출입구센서, 아이스크림, 컵, 슬러시)
    if(plan->sockConnectionStatus == false){
        ui->LW_ERROR->addItem("보드 연결 에러");
    }else{
        if(CUP_DATA[0].connection_status == 0){
            ui->LW_ERROR->addItem("컵 0번 연결 에러");
        }else{
            if(cup->FATAL_INFO_CUP_SENSOR_ERROR_1 == 1){
                ui->LW_ERROR->addItem("컵 0번 센서 연결 에러");
            }
            if(((CUP_DATA[0].status>>2)&0x01) == 0x01){
                ui->LW_ERROR->addItem("컵 0번 재고 없음");
            }
        }

        if(CUP_DATA[1].connection_status == 0){
            ui->LW_ERROR->addItem("컵 1번 연결 에러");
        }else{
            if(cup->FATAL_INFO_CUP_SENSOR_ERROR_2 == 1){
                ui->LW_ERROR->addItem("컵 1번 센서 연결 에러");
            }
            if(((CUP_DATA[1].status>>2)&0x01) == 0x01){
                ui->LW_ERROR->addItem("컵 1번 재고 없음");
            }
        }

        if(DOOR_DATA[0].connection_status == 0){
            ui->LW_ERROR->addItem("플랫폼 도어 연결 에러");
        }else{
            if(DOOR_DATA[0].platform_sensorA == 0 || DOOR_DATA[0].platform_sensorB == 0){
                ui->LW_ERROR->addItem("플랫폼 문 열림");
            }
        }

        if(OUTLET_DATA[0].connection_status == 0){
            ui->LW_ERROR->addItem("배출구 0번 연결 에러");
        }else{
            if(OUTLET_DATA[0].sonar_sensor_error == 1){
                ui->LW_ERROR->addItem("배출구 0번 센서 에러");
            }
            if(outlet->FATAL_INFO_OUTLET_1_SENSOR_WRONG_VALUE == 1){
                ui->LW_ERROR->addItem("배출구 0번 센서 값 에러");
            }
            if(outlet->FATAL_INFO_SPIN_1_CONTROL_ERROR == 1){
                ui->LW_ERROR->addItem("배출구 0번 디스크 에러");
            }
            if(outlet->FATAL_INFO_DOOR_1_CONTROL_ERROR == 1){
                ui->LW_ERROR->addItem("배출구 0번 도어 에러");
            }
        }

        if(OUTLET_DATA[1].connection_status == 0){
            ui->LW_ERROR->addItem("배출구 1번 연결 에러");
        }else{
            if(OUTLET_DATA[1].sonar_sensor_error == 1){
                ui->LW_ERROR->addItem("배출구 1번 센서 에러");
            }
            if(outlet->FATAL_INFO_OUTLET_2_SENSOR_WRONG_VALUE == 1){
                ui->LW_ERROR->addItem("배출구 1번 센서 값 에러");
            }
            if(outlet->FATAL_INFO_SPIN_2_CONTROL_ERROR == 1){
                ui->LW_ERROR->addItem("배출구 1번 디스크 에러");
            }
            if(outlet->FATAL_INFO_DOOR_2_CONTROL_ERROR == 1){
                ui->LW_ERROR->addItem("배출구 1번 도어 에러");
            }
        }



        if(SYRUP_DATA[0].connection_status == 0){
            ui->LW_ERROR->addItem("시럽 연결 에러");
        }else{
            if(SYRUP_DATA[0].loadcell.error == 1){
                ui->LW_ERROR->addItem("시럽 로드셀 에러");
            }
        }

    }

    //ERROR - LAN (메인보드, 로봇, 키오스크)
    if(robot->cmdConnectionStatus == false){
        ui->LW_ERROR->addItem("로봇 CMD 소켓 연결 에러");
    }
    if(robot->dataConnectionStatus == false){
        ui->LW_ERROR->addItem("로봇 DATA 소켓 연결 에러");
    }
    if(robot->FATAL_INFO_ROBOT_DATA_ERROR == 1){
        ui->LW_ERROR->addItem("로봇 DATA 입력 지연");
    }
    if(robot->FATAL_INFO_ROBOT_MISS_COMMAND_WORKING_CHECK == 1){
        ui->LW_ERROR->addItem("로봇 명령 무시 됨(3회)");
    }

    //ERROR - RS232 (제빙기, 바코드, 커피머신) : (바코드)
    if(barcode->m_serialPort->isOpen() == false){
        ui->LW_ERROR->addItem("바코드 포트 연결 에러");
    }
    if(coffee->port->isOpen() == false){
        ui->LW_ERROR->addItem("커피머신 포트 연결 에러");
    }else{
        if(coffee->coffee_connection == false){
            ui->LW_ERROR->addItem("커피머신 연결 에러");
        }else{
            if(coffee->coffee_data_connection == false){
                ui->LW_ERROR->addItem("커피머신 데이터 연결 에러");
            }else{
                if(coffee->machine_status.b.InfoMessageSet_e == 1){
//                    ui->LW_ERROR->addItem("커피머신 에러메시지 확인 필요");
                }
                if(coffee->module_status.coffee_L_status == notReady_e && coffee->coffee_detail_L == Undef_e){
                    ui->LW_ERROR->addItem("커피머신 준비 안됨(L)");
                }
//                if(coffee->module_status.coffee_R_status == notReady_e){
//                    ui->LW_ERROR->addItem("커피머신 준비 안됨(R)");
//                }
                if(coffee->module_status.water_status == notReady_e){
                    ui->LW_ERROR->addItem("커피머신 급수 에러");
                }
            }
        }
    }

    if(ice->m_serialPort->isOpen() == false){
        ui->LW_ERROR->addItem("제빙기 포트 연결 에러");
    }else{
        if(ICE_DATA[0].connection_status == 0){
            ui->LW_ERROR->addItem("제빙기 보드 연결 에러");
        }else{
            if(ICE_DATA[0].data_connection == 0){
                ui->LW_ERROR->addItem("제빙기 연결 에러");
            }else{
                if(ICE_DATA[0].status.B[1] & 0x0F == 1){
                    ui->LW_ERROR->addItem("제빙기 급수 불량");
                }else if(ICE_DATA[0].status.B[1] & 0x0F == 2){
                    ui->LW_ERROR->addItem("제빙기 배수 불량");
                }else if(ICE_DATA[0].status.B[1] & 0x0F == 3){
                    ui->LW_ERROR->addItem("제빙기 내부온도 저온");
                }else if(ICE_DATA[0].status.B[1] & 0x0F == 4){
                    ui->LW_ERROR->addItem("제빙기 내부온도 고온");
                }else if(ICE_DATA[0].status.B[1] & 0x0F == 5){
                    ui->LW_ERROR->addItem("제빙기 콘덴서 과열");
                }else if(ICE_DATA[0].status.B[1] & 0x0F == 6){
                    ui->LW_ERROR->addItem("제빙기 증발기 과냉");
                }else if(ICE_DATA[0].status.B[1] & 0x0F == 7){
                    ui->LW_ERROR->addItem("제빙기 제빙모터 이상");
                }else if(ICE_DATA[0].status.B[1] & 0x0F == 8){
                    ui->LW_ERROR->addItem("제빙기 제빙기능 불량");
                }else if(ICE_DATA[0].status.B[1] & 0x0F == 9){
                    ui->LW_ERROR->addItem("제빙기 정기점검 필요");
                }else if(ICE_DATA[0].status.B[1] & 0x0F == 15){
                    ui->LW_ERROR->addItem("제빙기 팬모터 이상");
                }
            }
        }
    }

    ui->LE_DEVICE_ERROR_COFFEE->move(390,260);
    ui->LE_DEVICE_ERROR_ICE_1->move(390,290);
    ui->label_149->move(310,260);
    ui->label_150->move(310,290);
    ui->BTN_ERROR_CLEAR_COFFEE->move(450,260);
    ui->BTN_ERROR_CLEAR_ICE_1->move(450,290);

    if(stock->IsDeviceError("COFFEE")){
        SetLEColor(ui->LE_DEVICE_ERROR_COFFEE, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_COFFEE, COLOR_GOOD);
    }

    if(stock->IsDeviceError("ICE_1")){
        SetLEColor(ui->LE_DEVICE_ERROR_ICE_1, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_ICE_1, COLOR_GOOD);
    }


    if(stock->IsDeviceError("PAPER_CUP_1")){
        SetLEColor(ui->LE_DEVICE_ERROR_PAPER_CUP_1, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_PAPER_CUP_1, COLOR_GOOD);
    }
    if(stock->IsDeviceError("PP_CUP_1")){
        SetLEColor(ui->LE_DEVICE_ERROR_PP_CUP_1, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_PP_CUP_1, COLOR_GOOD);
    }

    if(outlet->isError(0)){
        SetLEColor(ui->LE_DEVICE_ERROR_OUTLET_1, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_OUTLET_1, COLOR_GOOD);
    }

    if(outlet->isError(1)){
        SetLEColor(ui->LE_DEVICE_ERROR_OUTLET_2, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_OUTLET_2, COLOR_GOOD);
    }

    if(robot->isError()){
        SetLEColor(ui->LE_DEVICE_ERROR_ROBOT_1, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_ROBOT_1, COLOR_GOOD);
    }

    return ui->LW_ERROR->count();
}

void DialogError::on_BTN_CLOSE_clicked()
{
    this->close();
}

void DialogError::on_BTN_ERROR_CLEAR_PAPER_CUP_1_clicked()
{
    stock->ClearDeviceError("PAPER_CUP_1");
    plog->write("[SETTING - UI INPUT] Error Clear PAPER_CUP_1");
}
void DialogError::on_BTN_ERROR_CLEAR_PP_CUP_1_clicked(){
    stock->ClearDeviceError("PP_CUP_1");
    plog->write("[SETTING - UI INPUT] Error Clear PP_CUP_1");
}
void DialogError::on_BTN_ERROR_CLEAR_COFFEE_clicked(){
    stock->ClearDeviceError("COFFEE");
    plog->write("[SETTING - UI INPUT] Error Clear COFFEE");
}
void DialogError::on_BTN_ERROR_CLEAR_ICE_1_clicked(){
    stock->ClearDeviceError("ICE_1");
    plog->write("[SETTING - UI INPUT] Error Clear ICE_1");
}

void DialogError::on_BTN_ERROR_CLEAR_OUTLET_1_clicked()
{
    plog->write("[SETTING - UI INPUT] Error Clear OUTLET 1");
    outlet->ErrorClear();
}

void DialogError::on_BTN_ERROR_CLEAR_ROBOT_3_clicked()
{
    plog->write("[SETTING - UI INPUT] Error Clear ROBOT");
    robot->ErrorClear();
}

void DialogError::on_BTN_ERROR_CLEAR_PAPER_CUP_3_clicked()
{
    stock->ClearDeviceError("PAPER_CUP_1");
    plog->write("[SETTING - UI INPUT] Error Clear PAPER_CUP_1");
}

void DialogError::on_BTN_ERROR_CLEAR_PAPER_CUP_4_clicked()
{
    stock->ClearDeviceError("PP_CUP_1");
    plog->write("[SETTING - UI INPUT] Error Clear PP_CUP_1");
}

void DialogError::on_BTN_ERROR_CLEAR_OUTLET_2_clicked()
{
    plog->write("[SETTING - UI INPUT] Error Clear OUTLET 2");
    outlet->ErrorClear();
}

void DialogError::on_BTN_ERROR_CLEAR_ROBOT_2_clicked()
{
    plog->write("[SETTING - UI INPUT] Error Clear ROBOT");
    robot->ErrorClear();
}

void DialogError::on_BTN_ERROR_CLEAR_OUTLET_3_clicked()
{
    plog->write("[SETTING - UI INPUT] Error Clear OUTLET 1");
    outlet->ErrorClear();
}

void DialogError::on_BTN_ERROR_CLEAR_OUTLET_4_clicked()
{
    plog->write("[SETTING - UI INPUT] Error Clear OUTLET 2");
    outlet->ErrorClear();
}
