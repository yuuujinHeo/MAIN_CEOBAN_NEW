#include "DialogNotice.h"
#include "ui_DialogNotice.h"
#include "Logger.h"
#include "RBLAN2CAN.h"
#include "Scheduler.h"

extern RBLAN2CAN    *plan;
extern Logger *plog;
extern Scheduler *pschedule;

DialogNotice::DialogNotice(QWidget *parent, DialogStock *_stock, DialogRobot *_robot, DialogCupDispenser *_cup,
                           DialogCoffee *_coffee, DialogIceDispenser *_ice,
                           DialogSyrup *_syrup, DialogOutlet *_outlet,
                           DialogBarcode *_barcode, DialogMonitor *_monitor,
                           DialogIcecream *_icecream, DialogSlush *_slush,
                           DialogDoor *_door) :
    QDialog(parent), stock(_stock), robot(_robot), cup(_cup),
    coffee(_coffee), ice(_ice),
    syrup(_syrup), outlet(_outlet),
    barcode(_barcode), monitor(_monitor),
    icecream(_icecream), slush(_slush), door(_door),
    ui(new Ui::DialogNotice)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    currentState = 0;
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(onTimer()));
    timer->start(200);

}

DialogNotice::~DialogNotice()
{
    delete ui;
}

void DialogNotice::onTimer(){
    if(robot->cmdConnectionStatus==1){
        SetLEColor(ui->LE_CON_ROBOT_CMD,COLOR_GOOD);
        ui->LE_CON_ROBOT_CMD->setText("연결 됨");
    }else{
        SetLEColor(ui->LE_CON_ROBOT_CMD,COLOR_BAD);
        ui->LE_CON_ROBOT_CMD->setText("연결 안됨");
    }
    if(robot->dataConnectionStatus==1){
        SetLEColor(ui->LE_CON_ROBOT_DATA,COLOR_GOOD);
        ui->LE_CON_ROBOT_DATA->setText("연결 됨");
    }else{
        SetLEColor(ui->LE_CON_ROBOT_DATA,COLOR_BAD);
        ui->LE_CON_ROBOT_DATA->setText("연결 안됨");
    }

    if(plan->sockConnectionStatus==1){
        SetLEColor(ui->LE_CON_BOARD,COLOR_GOOD);
        ui->LE_CON_BOARD->setText("연결 됨");
    }else{
        SetLEColor(ui->LE_CON_BOARD,COLOR_BAD);
        ui->LE_CON_BOARD->setText("연결 안됨");
    }

    ui->LB_INIT_ROBOT_BASE->setText("("+QString::number(ROBOT_BASE_LOW)+" ~ "+QString::number(ROBOT_BASE_HIGH)+")");
    ui->LE_INIT_ROBOT_BASE_2->setText(QString::number(sys_status.sdata.jnt_ang[0]));
    if(sys_status.sdata.jnt_ang[0] > ROBOT_BASE_LOW && sys_status.sdata.jnt_ang[0] < ROBOT_BASE_HIGH){
        SetLEColor(ui->LE_INIT_ROBOT_BASE,COLOR_GOOD);
        SetLEColor(ui->LE_INIT_ROBOT_BASE_2,COLOR_GOOD);
    }else{
        SetLEColor(ui->LE_INIT_ROBOT_BASE,COLOR_BAD);
        SetLEColor(ui->LE_INIT_ROBOT_BASE_2,COLOR_BAD);
    }

    if(sys_status.sdata.digital_out[15] == 1){
        SetLEColor(ui->LE_INIT_ROBOT_INBOX,COLOR_GOOD);
        SetLEColor(ui->LE_INIT_ROBOT_INBOX_2,COLOR_GOOD);
    }else{
        SetLEColor(ui->LE_INIT_ROBOT_INBOX,COLOR_BAD);
        SetLEColor(ui->LE_INIT_ROBOT_INBOX_2,COLOR_BAD);
    }

    if(sys_status.sdata.op_stat_self_collision == 1){
        SetLEColor(ui->LE_INIT_ROBOT_COL,COLOR_BAD);
        SetLEColor(ui->LE_INIT_ROBOT_COL_2,COLOR_BAD);
    }else{
        SetLEColor(ui->LE_INIT_ROBOT_COL,COLOR_UNDETERMINED);
        SetLEColor(ui->LE_INIT_ROBOT_COL_2,COLOR_UNDETERMINED);
    }

    if(door->IsPlatformClosed() == 1){
        SetLEColor(ui->LE_DOOR_2,COLOR_GOOD);
        ui->LE_DOOR_2->setText("문 닫힘");
    }else{
        SetLEColor(ui->LE_DOOR_2,COLOR_BAD);
        ui->LE_DOOR_2->setText("문 열림");
    }


    SetLEColor(ui->LE_OUTLET_CELL_1,COLOR_NONE);
    SetLEColor(ui->LE_OUTLET_CELL_2,COLOR_NONE);
    SetLEColor(ui->LE_OUTLET_CELL_3,COLOR_NONE);
    SetLEColor(ui->LE_OUTLET_CELL_4,COLOR_NONE);
    SetLEColor(ui->LE_OUTLET_CELL_5,COLOR_NONE);
    SetLEColor(ui->LE_OUTLET_CELL_6,COLOR_NONE);

    if(OUTLET_DATA[0].cell_state[0] == CELL_OCC){
        SetLEColor(ui->LE_OUTLET_CELL_1,COLOR_BAD);
    }
    if(OUTLET_DATA[0].cell_state[1] == CELL_OCC){
        SetLEColor(ui->LE_OUTLET_CELL_2,COLOR_BAD);
    }
    if(OUTLET_DATA[0].cell_state[2] == CELL_OCC){
        SetLEColor(ui->LE_OUTLET_CELL_3,COLOR_BAD);
    }
    if(OUTLET_DATA[1].cell_state[0] == CELL_OCC){
        SetLEColor(ui->LE_OUTLET_CELL_4,COLOR_BAD);
    }
    if(OUTLET_DATA[1].cell_state[1] == CELL_OCC){
        SetLEColor(ui->LE_OUTLET_CELL_5,COLOR_BAD);
    }
    if(OUTLET_DATA[1].cell_state[2] == CELL_OCC){
        SetLEColor(ui->LE_OUTLET_CELL_6,COLOR_BAD);
    }

    if(currentState == 10 || currentState == 20){//robot teaching
        if(sys_status.sdata.jnt_ang[0] >= ROBOT_BASE_LOW && sys_status.sdata.jnt_ang[0] <= ROBOT_BASE_HIGH){
            if(sys_status.sdata.digital_out[15] == 1){
                if(sys_status.sdata.op_stat_self_collision == 0){
                    if(sys_status.sdata.is_freedrive_mode == 0){
                        plog->write("[NOTICE] ROBOT : CONFIRM ROBOT INIT POS");
                        if(currentState == 10){
                            currentState = 11;
                            ui->BTN_INIT_ROBOT_PROGRAM_EXIT->setVisible(false);
                            ui->IMAGE_INIT_ROBOT->setPixmap(QPixmap(":/build/image/error/rp3.png"));
                            ui->BTN_INIT_ROBOT_INIT->setEnabled(true);
                        }else{
                            currentState = 11;
                            ui->BTN_INIT_ROBOT_PROGRAM_EXIT_2->setVisible(false);
                            ui->IMAGE_INIT_ROBOT_2->setPixmap(QPixmap(":/build/image/error/rp7.png"));
                            ui->BTN_INIT_ROBOT_INIT_2->setEnabled(true);
                        }
                    }
                }
            }
        }

        if(sys_status.sdata.op_stat_ems_flag != 0 || sys_status.sdata.init_state_info == 0){
            ui->BTN_INIT_ROBOT_PROGRAM_EXIT->setVisible(false);
            ui->IMAGE_INIT_ROBOT->setPixmap(QPixmap(":/build/image/error/rp5.png"));
            ui->BTN_INIT_ROBOT_INIT->setEnabled(false);
            ui->BTN_INIT_ROBOT_PROGRAM_EXIT_2->setVisible(false);
            ui->IMAGE_INIT_ROBOT_2->setPixmap(QPixmap(":/build/image/error/rp5.png"));
            ui->BTN_INIT_ROBOT_INIT_2->setEnabled(false);
        }
    }
}

void DialogNotice::ShowOpNotice(QString error_code, QString details){
    ui->SW_MAIN->setCurrentIndex(1);
    currentState = 1;
    ui->LB_OP_ERROR_CODE->setText(error_code);
    ui->LB_OP_ERROR_DETAIL->setText(details);
    plog->write("[NOTICE] SHOW OP NOTICE : "+error_code);

    if(error_code == "INIT_FI"){
        ui->SW_OP->setCurrentIndex(0);
    }else if(error_code == "INIT_R1"){
        ui->SW_OP->setCurrentIndex(1);
        if(sys_status.sdata.task_state == 3){
            ui->IMAGE_INIT_ROBOT_2->setPixmap(QPixmap(":/build/image/error/rp1.png"));
            ui->BTN_INIT_ROBOT_PROGRAM_EXIT_2->setVisible(true);
            ui->BTN_INIT_ROBOT_INIT_2->setEnabled(false);
        }else{
            currentState = 20;
            ui->BTN_INIT_ROBOT_PROGRAM_EXIT_2->setVisible(false);
            ui->IMAGE_INIT_ROBOT_2->setPixmap(QPixmap(":/build/image/error/rp2.png"));
            ui->BTN_INIT_ROBOT_INIT_2->setEnabled(false);
        }
    }else if(error_code == "INIT_R2"){
        ui->SW_OP->setCurrentIndex(1);
        if(sys_status.sdata.task_state == 3){
            if(sys_status.sdata.op_stat_collision_occur == 1 || sys_status.sdata.op_stat_self_collision == 1){
                ui->IMAGE_INIT_ROBOT_2->setPixmap(QPixmap(":/build/image/error/rp4.png"));
                ui->BTN_INIT_ROBOT_PROGRAM_EXIT_2->setVisible(true);
                ui->BTN_INIT_ROBOT_INIT_2->setEnabled(false);
                currentState = 4;
            }else{
                ui->IMAGE_INIT_ROBOT_2->setPixmap(QPixmap(":/build/image/error/rp1.png"));
                ui->BTN_INIT_ROBOT_PROGRAM_EXIT_2->setVisible(true);
                ui->BTN_INIT_ROBOT_INIT_2->setEnabled(false);
            }
        }else{
            currentState = 20;
            ui->BTN_INIT_ROBOT_PROGRAM_EXIT_2->setVisible(false);
            ui->IMAGE_INIT_ROBOT_2->setPixmap(QPixmap(":/build/image/error/rp2.png"));
            ui->BTN_INIT_ROBOT_INIT_2->setEnabled(false);
        }
    }else if(error_code == "INIT_D1"){
        ui->SW_OP->setCurrentIndex(2);
        ui->IMAGE_INIT_DOOR_2->setEnabled(true);
        ui->IMAGE_INIT_DOOR_2->setPixmap(QPixmap(":/build/image/error/pd1.png"));
        ui->BTN_INIT_DOOR_INIT_2->setEnabled(true);
    }else if(error_code == "INIT_O1"){
        ui->SW_OP->setCurrentIndex(3);
        ui->IMAGE_OP_OUTLET->setPixmap(QPixmap(":/build/image/error/od1.png"));
        ui->BTN_OP_OUTLET_1->setEnabled(true);
        ui->BTN_OP_OUTLET_INIT->setEnabled(false);
        ui->BTN_OP_OUTLET_START->setEnabled(true);
        ui->frame_outlet->setVisible(true);
    }else{
        return;
    }
    this->show();

}

void DialogNotice::ShowOpStop(QString error_code, QString details){
    ui->SW_MAIN->setCurrentIndex(2);
    currentState = 1;
    ui->LB_SS_ERROR_CODE->setText(error_code);
    ui->LB_SS_DETAIL->setText(details);
    plog->write("[NOTICE] SHOW SS : "+error_code);

    if(error_code == "COL_R1"){
        ui->IMAGE_SS->setPixmap(QPixmap(":/build/image/error/rc1.png"));
        ui->BTN_SS_INIT->setEnabled(true);
        ui->BTN_SS->setVisible(false);
        ui->BTN_SS_2->setVisible(false);
        ui->BTN_SS_3->setVisible(false);
    }else if(error_code == "CON_R1"){
        ui->SW_MAIN->setCurrentIndex(0);
        currentState = 1;
        ui->LB_INIT_ERROR_CODE->setText(error_code);
        ui->LB_INIT_ERROR_DETAIL->setText(details);
        plog->write("[NOTICE] SHOW INIT NOTICE : "+error_code);
        ui->SW_INIT_CON->setCurrentIndex(0);
        ui->IMAGE_INIT_CON_ROBOT->setPixmap(QPixmap(":/build/image/error/ro1.png"));
        ui->BTN_INIT_CON_ROBOT_1->setEnabled(true);
        ui->BTN_INIT_CON_ROBOT_2->setEnabled(false);
        ui->BTN_INIT_CON_ROBOT_INIT->setEnabled(true);
    }else if(error_code == "SD_C1"){
        ui->IMAGE_SS->setPixmap(QPixmap(":/build/image/error/c2.png"));
        ui->BTN_SS_INIT->setEnabled(false);
        ui->BTN_SS->setVisible(true);
        ui->BTN_SS_2->setVisible(false);
        ui->BTN_SS_3->setVisible(false);
    }else if(error_code == "COL_C1"){
        ui->IMAGE_SS->setPixmap(QPixmap(":/build/image/error/c1.png"));
        ui->BTN_SS_INIT->setEnabled(true);
        ui->BTN_SS->setVisible(false);
        ui->BTN_SS_2->setVisible(true);
        ui->BTN_SS_3->setVisible(true);
    }else if(error_code == "ST_D1"){
        ui->IMAGE_SS->setPixmap(QPixmap(":/build/image/error/d1.png"));
        ui->BTN_SS_INIT->setVisible(false);
        ui->BTN_SS->setVisible(false);
        ui->BTN_SS_2->setVisible(false);
        ui->BTN_SS_3->setVisible(false);
    }else{
        ui->IMAGE_SS->setPixmap(QPixmap(":/build/image/error/pof.png"));
        ui->BTN_SS_INIT->setEnabled(true);
        ui->BTN_SS->setVisible(false);
        ui->BTN_SS_2->setVisible(false);
        ui->BTN_SS_3->setVisible(false);
    }
    this->show();
}
void DialogNotice::ShowInitNotice(QString error_code, QString details){

    ui->SW_MAIN->setCurrentIndex(0);
    currentState = 1;
    ui->LB_INIT_ERROR_CODE->setText(error_code);
    ui->LB_INIT_ERROR_DETAIL->setText(details);
    plog->write("[NOTICE] SHOW INIT NOTICE : "+error_code);

    if(error_code == "CON_R1"){
        ui->SW_INIT_CON->setCurrentIndex(0);
        ui->IMAGE_INIT_CON_ROBOT->setPixmap(QPixmap(":/build/image/error/ro1.png"));
        ui->BTN_INIT_CON_ROBOT_1->setEnabled(true);
        ui->BTN_INIT_CON_ROBOT_2->setEnabled(false);
        ui->BTN_INIT_CON_ROBOT_INIT->setEnabled(true);
    }else if(error_code == "CON_B1"){
        ui->SW_INIT_CON->setCurrentIndex(1);
        ui->IMAGE_INIT_CON_ROBOT->setPixmap(QPixmap(":/build/image/error/bc1.png"));
        ui->BTN_INIT_CON_ROBOT_1->setEnabled(true);
        ui->BTN_INIT_CON_ROBOT_2->setEnabled(false);
        ui->BTN_INIT_CON_ROBOT_INIT->setEnabled(false);
    }else if(error_code == "INIT_R1"){
        ui->SW_INIT_CON->setCurrentIndex(2);
        if(sys_status.sdata.task_state == 3){
            ui->IMAGE_INIT_ROBOT->setPixmap(QPixmap(":/build/image/error/rp1.png"));
            ui->BTN_INIT_ROBOT_PROGRAM_EXIT->setVisible(true);
            ui->BTN_INIT_ROBOT_INIT->setEnabled(false);
        }else{
            currentState = 10;
            ui->BTN_INIT_ROBOT_PROGRAM_EXIT->setVisible(false);
            ui->IMAGE_INIT_ROBOT->setPixmap(QPixmap(":/build/image/error/rp2.png"));
            ui->BTN_INIT_ROBOT_INIT->setEnabled(false);
        }
    }else if(error_code == "INIT_R2"){
        ui->SW_INIT_CON->setCurrentIndex(2);
        if(sys_status.sdata.task_state == 3){
            if(sys_status.sdata.op_stat_collision_occur == 1 || sys_status.sdata.op_stat_self_collision == 1){
                ui->IMAGE_INIT_ROBOT->setPixmap(QPixmap(":/build/image/error/rp4.png"));
                ui->BTN_INIT_ROBOT_PROGRAM_EXIT->setVisible(true);
                ui->BTN_INIT_ROBOT_INIT->setEnabled(false);
                currentState = 4;
            }else{
                ui->IMAGE_INIT_ROBOT->setPixmap(QPixmap(":/build/image/error/rp1.png"));
                ui->BTN_INIT_ROBOT_PROGRAM_EXIT->setVisible(true);
                ui->BTN_INIT_ROBOT_INIT->setEnabled(false);
            }
        }else{
            currentState = 10;
            ui->BTN_INIT_ROBOT_PROGRAM_EXIT->setVisible(false);
            ui->IMAGE_INIT_ROBOT->setPixmap(QPixmap(":/build/image/error/rp2.png"));
            ui->BTN_INIT_ROBOT_INIT->setEnabled(false);
        }
    }else{
        return;
    }
    this->show();
}


void DialogNotice::on_BTN_INIT_CON_ROBOT_1_clicked()
{
    switch(currentState){
    case 1:
    {
        ui->IMAGE_INIT_CON_ROBOT->setPixmap(QPixmap(":/build/image/error/ro2.png"));
        ui->BTN_INIT_CON_ROBOT_1->setEnabled(true);
        ui->BTN_INIT_CON_ROBOT_2->setEnabled(true);
        ui->BTN_INIT_CON_ROBOT_INIT->setEnabled(false);
        currentState = 2;
        break;
    }
    case 2:
    {
        ui->IMAGE_INIT_CON_ROBOT->setPixmap(QPixmap(":/build/image/error/ro3.png"));
        ui->BTN_INIT_CON_ROBOT_1->setEnabled(true);
        ui->BTN_INIT_CON_ROBOT_2->setEnabled(true);
        ui->BTN_INIT_CON_ROBOT_INIT->setEnabled(false);
        currentState = 3;
        break;
    }
    case 3:
    {
        ui->IMAGE_INIT_CON_ROBOT->setPixmap(QPixmap(":/build/image/error/ro4.png"));
        ui->BTN_INIT_CON_ROBOT_1->setEnabled(false);
        ui->BTN_INIT_CON_ROBOT_2->setEnabled(false);
        ui->BTN_INIT_CON_ROBOT_INIT->setEnabled(true);
        currentState = 4;
        break;
    }
    }
}

void DialogNotice::on_BTN_INIT_CON_ROBOT_2_clicked()
{
    switch(currentState){
    case 2:
    {
        ui->IMAGE_INIT_CON_ROBOT->setPixmap(QPixmap(":/build/image/error/ro6.png"));
        ui->BTN_INIT_CON_ROBOT_1->setEnabled(false);
        ui->BTN_INIT_CON_ROBOT_2->setEnabled(false);
        ui->BTN_INIT_CON_ROBOT_INIT->setEnabled(true);
        currentState = 6;
        break;
    }
    case 3:
    {
        ui->IMAGE_INIT_CON_ROBOT->setPixmap(QPixmap(":/build/image/error/ro5.png"));
        ui->BTN_INIT_CON_ROBOT_1->setEnabled(false);
        ui->BTN_INIT_CON_ROBOT_2->setEnabled(false);
        ui->BTN_INIT_CON_ROBOT_INIT->setEnabled(true);
        currentState = 5;
        break;
    }
    }
}

void DialogNotice::on_BTN_INIT_CON_ROBOT_INIT_clicked()
{
    plog->write("[NOTICE] INIT CON ROBOT : INIT START");
    emit init_start();
    this->close();
}

void DialogNotice::on_BTN_INIT_CON_BOARD_1_clicked()
{
    switch(currentState){
    case 1:
    {
        ui->IMAGE_INIT_CON_BOARD->setPixmap(QPixmap(":/build/image/error/bc2.png"));
        ui->BTN_INIT_CON_BOARD_1->setEnabled(true);
        ui->BTN_INIT_CON_BOARD_2->setEnabled(false);
        ui->BTN_INIT_CON_BOARD_INIT->setEnabled(false);
        currentState = 2;
        break;
    }
    case 2:
    {
        ui->IMAGE_INIT_CON_BOARD->setPixmap(QPixmap(":/build/image/error/bc3.png"));
        ui->BTN_INIT_CON_BOARD_1->setEnabled(false);
        ui->BTN_INIT_CON_BOARD_2->setEnabled(false);
        ui->BTN_INIT_CON_BOARD_INIT->setEnabled(true);
        currentState = 3;
        break;
    }
    }
}

void DialogNotice::on_BTN_INIT_CON_BOARD_2_clicked()
{

}

void DialogNotice::on_BTN_OP_OUTLET_1_clicked()
{
    ui->IMAGE_OP_OUTLET->setPixmap(QPixmap(":/build/image/error/od2.png"));
    ui->BTN_OP_OUTLET_1->setEnabled(false);
    ui->BTN_OP_OUTLET_START->setEnabled(false);
    ui->BTN_OP_OUTLET_INIT->setEnabled(true);
    ui->frame_outlet->setVisible(false);
    currentState = 2;
}

void DialogNotice::on_BTN_INIT_CON_BOARD_INIT_clicked()
{
    plog->write("[NOTICE] INIT CON BOARD : INIT START");
    emit init_start();
    this->close();
}

void DialogNotice::on_BTN_INIT_ROBOT_PROGRAM_EXIT_clicked()
{
    plog->write("[NOTICE] INIT ROBOT : MOTION HALT");
    robot->MotionHalt();
    currentState = 10;
    ui->BTN_INIT_ROBOT_PROGRAM_EXIT->setVisible(false);
    ui->IMAGE_INIT_ROBOT->setPixmap(QPixmap(":/build/image/error/rp2.png"));
    ui->BTN_INIT_ROBOT_INIT->setEnabled(false);
}

void DialogNotice::on_BTN_INIT_ROBOT_INIT_clicked()
{
    plog->write("[NOTICE] INIT ROBOT : INIT START");
    emit init_start();
    this->close();
}

void DialogNotice::on_BTN_INIT_CANCEL_clicked()
{
    emit cancel();
    this->close();
}

void DialogNotice::on_BTN_INIT_DOOR_INIT_clicked()
{
    plog->write("[NOTICE] INIT DOOR : INIT START");
    emit init_start();
    this->close();
}

void DialogNotice::on_BTN_OP_INIT_FIRST_clicked()
{
    plog->write("[NOTICE] OP : INIT START");
    emit init_start();
    this->close();
}

void DialogNotice::on_BTN_OP_OUTLET_START_clicked()
{
    plog->write("[NOTICE] OP : OP START");
    emit op_start();
    this->close();
}

void DialogNotice::on_BTN_OUTLET_CELL_1_clicked()
{
    if(outlet->IsModuleRunning(0)){
        qDebug()<<"Module is reserved";
    }else{
        pschedule->SetForcedDispensing(0, 0);
    }
    plog->write("[UI OPERATION - OUTLET] 음료 배출 1-1");
}
void DialogNotice::on_BTN_OUTLET_CELL_2_clicked()
{
    if(outlet->IsModuleRunning(0)){
        qDebug()<<"Module is reserved";
    }else{
        pschedule->SetForcedDispensing(0, 1);
    }
    plog->write("[UI OPERATION - OUTLET] 음료 배출 1-2");
}
void DialogNotice::on_BTN_OUTLET_CELL_3_clicked()
{
    if(outlet->IsModuleRunning(0)){
        qDebug()<<"Module is reserved";
    }else{
        pschedule->SetForcedDispensing(0, 2);
    }
    plog->write("[UI OPERATION - OUTLET] 음료 배출 1-3");
}
void DialogNotice::on_BTN_OUTLET_CELL_4_clicked()
{
    if(outlet->IsModuleRunning(1)){
        qDebug()<<"Module is reserved";
    }else{
        pschedule->SetForcedDispensing(1, 0);
    }
    plog->write("[UI OPERATION - OUTLET] 음료 배출 2-1");
}
void DialogNotice::on_BTN_OUTLET_CELL_5_clicked()
{
    if(outlet->IsModuleRunning(1)){
        qDebug()<<"Module is reserved";
    }else{
        pschedule->SetForcedDispensing(1, 1);
    }
    plog->write("[UI OPERATION - OUTLET] 음료 배출 2-2");
}
void DialogNotice::on_BTN_OUTLET_CELL_6_clicked()
{
    if(outlet->IsModuleRunning(1)){
        qDebug()<<"Module is reserved";
    }else{
        pschedule->SetForcedDispensing(1, 2);
    }
    plog->write("[UI OPERATION - OUTLET] 음료 배출 2-3");
}

void DialogNotice::on_BTN_INIT_ROBOT_PROGRAM_EXIT_2_clicked()
{
    plog->write("[NOTICE] OP ROBOT : MOTION HALT");
    robot->MotionHalt();
    currentState = 10;
    ui->BTN_INIT_ROBOT_PROGRAM_EXIT_2->setVisible(false);
    ui->IMAGE_INIT_ROBOT_2->setPixmap(QPixmap(":/build/image/error/rp2.png"));
    ui->BTN_INIT_ROBOT_INIT_2->setEnabled(false);
}

void DialogNotice::on_BTN_OP_OUTLET_INIT_clicked()
{
    plog->write("[NOTICE] OP OUTLET : INIT START");
    emit init_start();
    this->close();
}

void DialogNotice::on_BTN_INIT_DOOR_INIT_2_clicked()
{
    plog->write("[NOTICE] OP DOOR : OP START");
    emit op_start();
    this->close();
}

void DialogNotice::on_BTN_SS_INIT_clicked()
{
    plog->write("[NOTICE] SS : INIT START");
    emit init_start();
    this->close();
}

void DialogNotice::on_BTN_SS_clicked()
{
    if(pschedule->action_state == ACTION_STATE_CUP_ERROR){
        pschedule->action_state = ACTION_STATE_CUP_RECOVER;
        cup->error_clear();
        plog->write("[NOTICE] Button Click : Cup Add Done");
    }
    this->close();
}

void DialogNotice::on_BTN_SS_CANCEL_clicked()
{
    emit cancel();
    this->close();
}

void DialogNotice::on_BTN_SS_2_clicked()
{
    QMessageBox::StandardButton msgBox;
    msgBox = QMessageBox::question(this,"컵 배출",
                                   "컵 배출 테스트를 하시겠습니까?\n"
                                   "배출 된 컵은 반드시 운영 시작 전에 치워주십시오.");

    if(msgBox == QMessageBox::Yes){
        plog->write("[NOTICE] CUP OUT 1");
        cup->DispenseCup(0);
    }else{
    }
}

void DialogNotice::on_BTN_SS_3_clicked()
{
    QMessageBox::StandardButton msgBox;
    msgBox = QMessageBox::question(this,"컵 배출",
                                   "컵 배출 테스트를 하시겠습니까?\n"
                                   "배출 된 컵은 반드시 운영 시작 전에 치워주십시오.");

    if(msgBox == QMessageBox::Yes){
        plog->write("[NOTICE] CUP OUT 2");
        cup->DispenseCup(1);
    }else{
    }
}

void DialogNotice::on_BTN_OP_CANCEL_clicked()
{
    emit cancel();
    this->close();
}

void DialogNotice::on_BTN_INIT_CANCEL_5_clicked()
{
    emit cancel();
    this->close();
}
