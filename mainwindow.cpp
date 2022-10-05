#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

RBLAN2CAN *plan;
DialogSetting *psetting;

int IS_UI_LOCK = true;


int LOADCELL_SCALE_SYRUP = 300;
int LOADCELL_SCALE_SODA_1 = 300;
int LOADCELL_SCALE_SODA_2 = 300;


CUP_DISPENSER_INFO      CUP_DATA[MAX_CUP];
ICE_DISPENSER_INFO      ICE_DATA[MAX_ICE];
SYRUP_DISPENSER_INFO    SYRUP_DATA[1];
SODA_DISPENSER_INFO     SODA_DATA[1];
BARCODE_INFO            BARCODE_DATA[1];
OUTLET_INFO             OUTLET_DATA[NUMBER_OF_OUTLET];
DOOR_INFO               DOOR_DATA[1];


Scheduler *pschedule = NULL;
Logger    *plog;
DialogOutlet  *poutlet;
DisplayDialog   *pdisplay;

int OP_STATUS_INITIALIZING = PLATFORM_INIT_IDLE;
int OP_STATUS_OPERATING = PLATFORM_OPERATION_IDLE;

int OP_COMMAND_STOP_OPERATING = 0;          // intended by user
int OP_COMMAND_SUPER_STOP_OPERATING = 0;    // unintended stop
int OP_COMMAND_FORCED_STOP_OPERATING = 0;   // unintended stop

int SUPER_FATAL_ERROR_PLATFORM_OPEN;
int PLATFORM_OPENED_WHEN_OPERATING_FLAG = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    LoadLoadcellDB();


    lan = new RBLAN2CAN();
    plan = lan;

    logger = new Logger();
    plog = logger;

    stock = new DialogStock(ui->FRAME_DEVICE);
    stock->setWindowFlags(Qt::Widget);
    stock->move(0, 0);

    cup = new DialogCupDispenser(ui->FRAME_DEVICE, stock);
    cup->setWindowFlags(Qt::Widget);
    cup->move(0, 0);

    ice = new DialogIceDispenser(ui->FRAME_DEVICE, stock);
    ice->setWindowFlags(Qt::Widget);
    ice->move(0, 0);

    coffee = new DialogCoffee(ui->FRAME_DEVICE, stock);
    coffee->setWindowFlags(Qt::Widget);
    coffee->move(0, 0);

    syrup = new DialogSyrup(ui->FRAME_DEVICE, stock);
    syrup->setWindowFlags(Qt::Widget);
    syrup->move(0, 0);

    soda = new DialogSoda(ui->FRAME_DEVICE, stock);
    soda->setWindowFlags(Qt::Widget);
    soda->move(0, 0);

    robot = new DialogRobot(ui->FRAME_DEVICE, stock);
    robot->setWindowFlags(Qt::Widget);
    robot->move(0, 0);

    monitor = new DialogMonitor(ui->FRAME_DEVICE, stock);
    monitor->setWindowFlags(Qt::Widget);
    monitor->move(0, 0);

    door = new DialogDoor(ui->FRAME_DEVICE);
    door->setWindowFlags(Qt::Widget);
    door->move(0, 0);

    barcode = new DialogBarcode(ui->FRAME_DEVICE);
    barcode->setWindowFlags(Qt::Widget);
    barcode->move(0, 0);

    outlet = new DialogOutlet(ui->FRAME_DEVICE);
    outlet->setWindowFlags(Qt::Widget);
    outlet->move(0, 0);
    poutlet = outlet;

    kiosk = new DialogKiosk(ui->FRAME_DEVICE);
    kiosk->setStock(stock);
    kiosk->setWindowFlags(Qt::Widget);
    kiosk->move(0, 0);

    setting = new DialogSetting(ui->FRAME_DEVICE, stock, robot, cup, coffee, ice, syrup, outlet, barcode, monitor);
    setting->setWindowFlags(Qt::Widget);
    setting->move(0, 0);
    psetting = setting;

    error = new DialogError(nullptr, stock, robot, cup, coffee, ice, syrup, outlet, barcode, monitor);

    schedule = new Scheduler(stock, robot, cup, coffee, ice, syrup, outlet, barcode, monitor, soda);
    pschedule = schedule;

    display = new DisplayDialog();
//    display->show();
//    display->move(1920,0);
//    display->showFullScreen();
    pdisplay = display;

    notice = new DialogNotice(nullptr, stock, robot, cup, coffee, ice, syrup, outlet, barcode, monitor, door);
    connect(notice, SIGNAL(cancel()),this,SLOT(cancelnotice()));
    connect(notice, SIGNAL(init_start()),this,SLOT(noticeinit()));
    connect(notice, SIGNAL(op_start()),this,SLOT(noticeop()));
//    ques_recipe->setWindowFlags(Qt::Widget);

    // Program Starts
    logger->write_space();
    logger->write("[SYSTEM] Core Program Start");

    SUPER_FATAL_ERROR_PLATFORM_OPEN = 0;

    ChangeDeviceDialog(DEV_DIALOG_ID_CUP);
    SettingRecipeDB();

    ui->PB_CUP_1m->setMaximum(stock->stock["PAPER_CUP_1"].maximum);
    ui->PB_CUP_2m->setMaximum(stock->stock["PAPER_CUP_2"].maximum);
    ui->PB_CUP_3m->setMaximum(stock->stock["PP_CUP_1"].maximum);
    ui->PB_CUP_4m->setMaximum(stock->stock["PP_CUP_2"].maximum);
    ui->PB_SYRUP_1m->setMaximum(stock->stock["SYRUP_1"].maximum);
    ui->PB_SYRUP_2m->setMaximum(stock->stock["SYRUP_2"].maximum);
    ui->PB_SYRUP_3m->setMaximum(stock->stock["SYRUP_3"].maximum);
    ui->PB_SYRUP_4m->setMaximum(stock->stock["SYRUP_4"].maximum);
    ui->PB_SYRUP_5m->setMaximum(stock->stock["SYRUP_5"].maximum);
    ui->PB_SYRUP_6m->setMaximum(stock->stock["SYRUP_6"].maximum);
    ui->PB_SYRUP_7m->setMaximum(stock->stock["SYRUP_7"].maximum);
    ui->PB_SYRUP_8m->setMaximum(stock->stock["SYRUP_8"].maximum);
    ui->PB_SYRUP_9m->setMaximum(stock->stock["SYRUP_9"].maximum);
    ui->PB_SYRUP_10m->setMaximum(stock->stock["SYRUP_10"].maximum);
    ui->PB_SYRUP_11m->setMaximum(stock->stock["SYRUP_11"].maximum);
    ui->PB_SYRUP_12m->setMaximum(stock->stock["SYRUP_12"].maximum);


    ui->stackedWidget->setCurrentIndex(0);
    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    connect(setting, SIGNAL(openRecipe()),this, SLOT(openRecipePage()));
    connect(setting, SIGNAL(closeRecipe()),this, SLOT(closeRecipePage()));
    timer.start(MAINWINDOW_LOOP_TIME);



    //Test Notice
//    notice->ShowOpStop("ST_D1","운영 중 문이 열렸습니다.");
//    notice->ShowOpStop("COL_C1","컵 디스펜서에 컵이 끼어 있거나 배출이 되지 않습니다.\n컵을 모두 정상상태로 하고 다시 초기화 해 주십시오.");
//    notice->ShowOpStop("CON_R1","로봇과 연결이 끊어졌습니다.");
//    notice->ShowOpNotice("INIT_O1","하기시르다");
//    notice->ShowInitNotice("CON_R1", "로봇이 연결되지 않습니다.");
//    notice->ShowInitNotice("CON_B1", "보드가 연결되지 않습니다.");
//    notice->ShowInitNotice("INIT_R1", "우엥엥");
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cancelnotice(){
    IS_UI_LOCK = false;
    ui->BTN_UI_LOCK->setIcon(QIcon(":/build/image/unlockw.png"));
}

void MainWindow::noticeinit(){
    logger->write("[USER INPUT] INIT START");
    OP_STATUS_INITIALIZING = PLATFORM_INIT_START;
}
void MainWindow::noticeop(){
    logger->write("[USER INPUT] PLATFORM OPERATION START");
    OP_STATUS_OPERATING = PLATFORM_OPERATION_START;
}

void MainWindow::SettingRecipeDB(){
    QStringList tableHeader;
    ui->TW_MENU->setColumnCount(2);
    QStringList tableHeader2;
    ui->TW_RECIPE->setColumnCount(2);
    tableHeader << "메뉴 ID" << "메뉴 이름";
    tableHeader2 << "재료" << "양";

    ui->TW_MENU->setHorizontalHeaderLabels(tableHeader);
    ui->TW_RECIPE->setHorizontalHeaderLabels(tableHeader2);
}

void MainWindow::LoadLoadcellDB(){
    db = QSqlDatabase::addDatabase("QSQLITE", "DB_LOADCELL");
    db.setDatabaseName(DB_NAME_LOADCELL);

    if(!db.open()){
        qDebug() << "Load Loadcell Database Fail";
        return;
    }

    QSqlQuery query(db);
    if(query.exec("SELECT * FROM Table_Loadcell")){
        while(query.next()){
            QString uses = query.value("uses").toString();
            int scale = query.value("scale").toInt();
//            int initial = query.value("initial").toInt();
            if(uses == "SYRUP"){
                LOADCELL_SCALE_SYRUP = scale;
            }else if(uses == "SODA1"){
                LOADCELL_SCALE_SODA_1 = scale;
            }else if(uses == "SODA2"){
                LOADCELL_SCALE_SODA_2 = scale;
            }
        }
    }
    db.close();
}

void MainWindow::openRecipePage(){
    plog->write("[UI - SETTING] CHANGE PAGE TO 1");
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::closeRecipePage(){
    plog->write("[UI - SETTING] CHANGE PAGE TO 0");
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::UpdateMenuAvailable(){
    ui->LW_MENU->clear();

    QList<QString> keys = stock->menu.keys();
    for(int i=0; i<keys.size(); i++){
//        qDebug() << stock->menu[keys[i]].menu_name;
        ui->LW_MENU->addItem(stock->menu[keys[i]].menu_name);
        if(stock->menu[keys[i]].available)
            ui->LW_MENU->item(i)->setBackgroundColor(COLOR_GOOD);
        else
            ui->LW_MENU->item(i)->setBackgroundColor(COLOR_BAD);
    }
}

void MainWindow::onTimer(){
//    qDebug() << "mainwindow timer";

    UpdateMenuAvailable();
//    if(QApplication::desktop()->screenCount() > 1){
//        if(this->geometry().x() != 1920){
//            this->move(1920,0);
//        }
//        if(display->geometry().x() != 0){
//            display->move(0,0);
//            display->showFullScreen();
//        }
//    }else{

//    }

    if(IS_UI_LOCK){
        ui->GB_OP_CONTROL->setEnabled(false);
        ui->FRAME->setEnabled(false);
    }else{
        ui->GB_OP_CONTROL->setEnabled(true);
        ui->FRAME->setEnabled(true);
    }

    if(schedule->action_state == ACTION_STATE_CUP_ERROR){
        ui->BTN_CUP_ADD_DONE->setEnabled(true);
    }else{
        ui->BTN_CUP_ADD_DONE->setEnabled(false);
    }

    CoreLogic_Initializing();
    CoreLogic_Operating();

    UpdatePlatformOperationInfo();
    Update_Dev_CupInfo();
    Update_Dev_IceInfo();
    Update_Dev_CoffeeInfo();
    Update_Dev_SyrupInfo();
    Update_Dev_RobotInfo();
    Update_Dev_SodaInfo();
    Update_Dev_MonitorInfo();
    Update_Dev_DoorInfo();
    Update_Dev_BarcodeInfo();
    Update_Dev_OutletInfo();
    Update_Dev_KioskInfo();
    Update_Dev_StockInfo();

    if(error->UpdateError() > 0){
        ui->BTN_ERROR->setText("에러발생");
        SetBTNColor(ui->BTN_ERROR,COLOR_BAD);
    }else{
        ui->BTN_ERROR->setText("에러없음");
        SetBTNColor(ui->BTN_ERROR,COLOR_GOOD);
    }
}




void MainWindow::CoreLogic_Initializing()
{
    static int timeout = 0;
    static uint init_count = 0;
    static int try_count = 0;

    init_count++;
    switch(OP_STATUS_INITIALIZING){
    case PLATFORM_INIT_IDLE:
        ui->LE_PLATFORM_INITIALIZING->setText("");
        // Do nothing
        break;

    case PLATFORM_INIT_START:
        ui->LE_PLATFORM_INITIALIZING->setText("0 %");
        logger->write("[INIT PROCESS] Platform Initialization Start");
        try_count = 0;
        ClearForcedSuperError();
        // 220401 fix--------
        schedule->action_state = ACTION_STATE_INIT;
        schedule->outlet_rotate_state = OR_STATE_IDLE;
        robot->RobotMoving = false;
        schedule->remove_inprogress_list();
        schedule->ClearWaitingList();
        schedule->ClearCompletedList();
        robot->MotionHalt();
        // ------------------
        OP_STATUS_OPERATING = PLATFORM_OPERATION_IDLE;
        OP_STATUS_INITIALIZING = PLATFORM_INIT_CHECK_CONNECTION;
        break;

    case PLATFORM_INIT_CHECK_CONNECTION:
    {
        ui->LE_PLATFORM_INITIALIZING->setText("10 %");
        if(init_count%5 != 0){
            break;
        }

        int device_check_result = CheckDeviceConnection();
        if(device_check_result != 0){
            try_count++;
            if(try_count > 3){
                QString dev_type = "";
                if(device_check_result == 1){
                    dev_type = "Robot(CMD)";
                    IS_UI_LOCK = true;
                    notice->ShowInitNotice("CON_R1", "로봇이 연결되지 않습니다.");
                }else if(device_check_result == 2){
                    dev_type = "Robot(DATA)";
                    IS_UI_LOCK = true;
                    notice->ShowInitNotice("CON_R1", "로봇이 연결되지 않습니다.");
                }else if(device_check_result == 3){
                    dev_type = "Device(LAN)";
                    IS_UI_LOCK = true;
                    notice->ShowInitNotice("CON_B1", "보드와 연결되지 않습니다.");
                }else if(device_check_result == 4){
                    dev_type = "Monitor";
                }
                logger->write("[INIT PROCESS] FAIL -- Device Connection Check Error");

//                QMessageBox::warning(this, "초기화 실패", "<font size=4>장치 연결 에러 (" + dev_type + ")<font>");
                OP_STATUS_INITIALIZING = PLATFORM_INIT_ON_FAIL_STATE;
            }
            break;
        }
        try_count = 0;
        OP_STATUS_INITIALIZING = PLATFORM_INIT_CHECK_ROBOT_IN_GOOD_POSTURE;
        timeout = 500/MAINWINDOW_LOOP_TIME;
        break;
    }

    case PLATFORM_INIT_CHECK_ROBOT_IN_GOOD_POSTURE:
        ui->LE_PLATFORM_INITIALIZING->setText("20 %");
        if(sys_status.sdata.jnt_ang[0] >= ROBOT_BASE_LOW && sys_status.sdata.jnt_ang[0] <= ROBOT_BASE_HIGH){
            if(sys_status.sdata.digital_out[15] == 1){
                OP_STATUS_INITIALIZING = PLATFORM_INIT_CHECK_ROBOT_CONNECTION;
            }else{
                logger->write("[INIT PROCESS] FAIL -- Robot Posture Error");

                IS_UI_LOCK = true;
                notice->ShowInitNotice("INIT_R1", "로봇의 자세가 초기자세가 아닙니다.");
//                QMessageBox::warning(this, "초기화 실패", "<font size=4>로봇 자세 에러<font>");
                OP_STATUS_INITIALIZING = PLATFORM_INIT_ON_FAIL_STATE;
            }
        }else{
            logger->write("[INIT PROCESS] FAIL -- Robot Base Angle Error ("+QString::number(ROBOT_BASE_LOW)+" ~ "+QString::number(ROBOT_BASE_HIGH)+")");

            IS_UI_LOCK = true;
            notice->ShowInitNotice("INIT_R1", "로봇의 자세가 초기자세가 아닙니다.");
//            QMessageBox::warning(this, "초기화 실패", "<font size=4>로봇 베이스 각도 에러 ("+QString::number(ROBOT_BASE_LOW)+" ~ "+QString::number(ROBOT_BASE_HIGH)+")<font>");
            OP_STATUS_INITIALIZING = PLATFORM_INIT_ON_FAIL_STATE;
        }
        break;

    case PLATFORM_INIT_CHECK_ROBOT_CONNECTION:
        ui->LE_PLATFORM_INITIALIZING->setText("30 %");
        if(--timeout > 0) break;

        if(robot->motionServer->RBConnectionStatus == false || sys_status.sdata.task_state != 3){
            try_count++;
            if(try_count > 5){
                logger->write("[INIT PROCESS] FAIL -- Robot Program Connection Fail");

                IS_UI_LOCK = true;
                notice->ShowInitNotice("INIT_R2", "로봇 프로그램와 연결에 실패했습니다.");
//                QMessageBox::warning(this, "초기화 실패", "<font size=4>로봇 프로그램 연결 실패<font>");
                OP_STATUS_INITIALIZING = PLATFORM_INIT_ON_FAIL_STATE;
                break;
            }
            logger->write("[INIT PROCESS] Restart Robot Program...");
            robot->MotionHalt();
            timeout = 5000/MAINWINDOW_LOOP_TIME;
            OP_STATUS_INITIALIZING = PLATFORM_INIT_ROBOT_PROGRAM_TURN_ON;
            break;
        }

        logger->write("[INIT PROCESS] Robot Program Connected!");
        timeout = 1000/MAINWINDOW_LOOP_TIME;
        OP_STATUS_INITIALIZING = PLATFORM_INIT_OUTLET;
        break;

    case PLATFORM_INIT_ROBOT_PROGRAM_TURN_ON: // Branch
        ui->LE_PLATFORM_INITIALIZING->setText("40 %");
        if(--timeout > 0) break;

        robot->MotionPlay();
        timeout = 5000/MAINWINDOW_LOOP_TIME;
        OP_STATUS_INITIALIZING = PLATFORM_INIT_CHECK_ROBOT_CONNECTION;

        break;

    case PLATFORM_INIT_OUTLET:
        ui->LE_PLATFORM_INITIALIZING->setText("50 %");
        logger->write("[INIT PROCESS] Outlet Initialization Start...");
        for(int i=0; i<NUMBER_OF_OUTLET; i++){
            if(outlet->OUTLET_DISABLE[i] == 0){
                outlet->init_state_door[i] = OUTLET_INIT_START;
                outlet->init_state_spin[i] = OUTLET_INIT_START;
            }
        }
        timeout = 1000/MAINWINDOW_LOOP_TIME;
        OP_STATUS_INITIALIZING = PLATFORM_INIT_OUTLET_DONE;
        break;

    case PLATFORM_INIT_OUTLET_DONE:
    {
        ui->LE_PLATFORM_INITIALIZING->setText("90 %");
        if(--timeout > 0)
            break;

        int outlet_init_done = true;
        for(int i=0; i<NUMBER_OF_OUTLET; i++){
            if(outlet->OUTLET_DISABLE[i] == 0 && outlet->is_door_ready[i] == false){
                outlet_init_done = false;
                break;
            }
            if(outlet->OUTLET_DISABLE[i] == 0 && outlet->is_spin_ready[i] == false){
                outlet_init_done = false;
                break;
            }
        }
        if(outlet_init_done == false)
            break;

        OP_STATUS_INITIALIZING = PLATFORM_INIT_DONE;
        break;
    }

    case PLATFORM_INIT_DONE:
        ui->LE_PLATFORM_INITIALIZING->setText("100 %");
        logger->write("[INIT PROCESS] Outlet Initialization Done!");
        OP_STATUS_INITIALIZING = PLATFORM_INIT_ON_SUCCESS_STATE;
        break;

    case PLATFORM_INIT_ON_SUCCESS_STATE:
        ui->LE_PLATFORM_INITIALIZING->setText("초기화 완료");
        // in success state
        break;

    case PLATFORM_INIT_ON_FAIL_STATE:
        ui->LE_PLATFORM_INITIALIZING->setText("초기화 실패");
        // in fail state
        break;

    default:
        break;
    }
}

void MainWindow::CoreLogic_Operating(){
    static int platform_opening_detection_count = 0;
    static int platform_closing_detection_count = 0;
    static int platform_opened_flag = 0;
    static int platform_open_close_transition_flag = 0;
    static int timeout = 0;


    // OP_COMMAND_STOP_OPERATING only works when the OP_STATUS_OPERATING is on operating state
    if(OP_STATUS_OPERATING != PLATFORM_OPERATION_ON_OPERATING_STATE){
        if(OP_COMMAND_STOP_OPERATING == 1){
            OP_COMMAND_STOP_OPERATING = 0;
        }
        if(OP_COMMAND_FORCED_STOP_OPERATING == 1){
            OP_COMMAND_FORCED_STOP_OPERATING = 0;
        }
        if(OP_COMMAND_SUPER_STOP_OPERATING == 1){
            OP_COMMAND_SUPER_STOP_OPERATING = 0;
        }
    }



    switch(OP_STATUS_OPERATING){
    case PLATFORM_OPERATION_IDLE:
        ui->LE_PLATFORM_OPERATING->setText("");
        // Do nothing
        break;

    case PLATFORM_OPERATION_START:
        ui->LE_PLATFORM_OPERATING->setText("0 %");
        logger->write("[OPERATING PROCESS] Platform Operation Sequence Start");
        ClearForcedSuperError();
        OP_STATUS_OPERATING = PLATFORM_OPERATION_CHECK_ON_INIT_SUCCES_STATE;
        break;

    case PLATFORM_OPERATION_CHECK_ON_INIT_SUCCES_STATE:
        ui->LE_PLATFORM_OPERATING->setText("10 %");
        if(OP_STATUS_INITIALIZING == PLATFORM_INIT_ON_SUCCESS_STATE){
            platform_closing_detection_count = 0;
            OP_STATUS_OPERATING = PLATFORM_OPERATION_CHECK_ROBOT_POSTURE;
            logger->write("[OPERATING PROCESS] Check Initial State : Initialized");
        }else{
            logger->write("[OPERATING PROCESS] FAIL -- Do Initialize First");
            IS_UI_LOCK = true;
            notice->ShowOpNotice("INIT_FI","초기화를 먼저 수행해주십시오.");
//            QMessageBox::warning(this, "운영시작 실패", "<font size=4>초기화를 먼저 수행하십시오.<font>");
            OP_STATUS_OPERATING = PLATFORM_OPERATION_ON_OPERATING_FAIL_STATE;
        }
        break;

    case PLATFORM_OPERATION_CHECK_ROBOT_POSTURE:
        ui->LE_PLATFORM_OPERATING->setText("20 %");
        if(sys_status.sdata.jnt_ang[0] >= ROBOT_BASE_LOW && sys_status.sdata.jnt_ang[0] <= ROBOT_BASE_HIGH){
            if(sys_status.sdata.digital_out[15] == 1){
                logger->write("[OPERATING PROCESS] Robot Init Position Check : Success");
                OP_STATUS_OPERATING = PLATFORM_OPERATION_CHECK_PLATFORM_CLOSED;
            }else{
                logger->write("[OPERATING PROCESS] FAIL -- Robot Posture Error");
                IS_UI_LOCK = true;
                notice->ShowOpNotice("INIT_R1", "로봇의 자세가 초기자세가 아닙니다.");
//                QMessageBox::warning(this, "운영시작 실패", "<font size=4>로봇 자세 에러<font>");
                OP_STATUS_OPERATING = PLATFORM_OPERATION_ON_OPERATING_FAIL_STATE;
            }
        }else{
            logger->write("[OPERATING PROCESS] FAIL -- Robot Base Angle Error");
            IS_UI_LOCK = true;
            notice->ShowOpNotice("INIT_R1", "로봇의 자세가 초기자세가 아닙니다.");
//            QMessageBox::warning(this, "운영시작 실패", "<font size=4>로봇 베이스 각도 에러 ("+QString::number(ROBOT_BASE_LOW)+" ~ "+QString::number(ROBOT_BASE_HIGH)+")<font>");
            OP_STATUS_OPERATING = PLATFORM_OPERATION_ON_OPERATING_FAIL_STATE;
        }
        break;

    case PLATFORM_OPERATION_CHECK_PLATFORM_CLOSED:
        ui->LE_PLATFORM_OPERATING->setText("40 %");
        if(door->IsPlatformClosed() == 1){
            platform_closing_detection_count++;
        }else{
            logger->write("[OPERATING PROCESS] FAIL -- Platform is Opened");
            IS_UI_LOCK = true;
            notice->ShowOpNotice("INIT_D1", "플랫폼 문이 열려 있습니다.");
//            QMessageBox::warning(this, "운영시작 실패", "<font size=4>플랫폼 문이 열려 있습니다.<font>");
            OP_STATUS_OPERATING = PLATFORM_OPERATION_ON_OPERATING_FAIL_STATE;
        }
        if(platform_closing_detection_count > 10){
            logger->write("[OPERATING PROCESS] Platform Door : Closed");
            OP_STATUS_OPERATING = PLATFORM_OPERATION_CHECK_OUTLET_OCCUPY;
        }
        break;

    case PLATFORM_OPERATION_CHECK_OUTLET_OCCUPY:
    {
        ui->LE_PLATFORM_OPERATING->setText("60 %");
        int occupy_num = 0;
        for(int i=0; i<NUMBER_OF_OUTLET; i++){
            for(int j=0; j<NUMBER_OF_CELL; j++){
                if(outlet->OUTLET_DISABLE[i] == 0 && OUTLET_DATA[i].cell_state[j] == CELL_OCC){
                    occupy_num++;
                }
            }
        }
        logger->write("[OPERATING PROCESS] Check Outlet occupy....");
        if(occupy_num > 0){
            logger->write("[OPERATING PROCESS] FAIL -- Dispense Outlet First");
            IS_UI_LOCK = true;
            notice->ShowOpNotice("INIT_O1", "배출구에 음료가 있습니다. 먼저 배출하십시오.");
            OP_STATUS_OPERATING = PLATFORM_OPERATION_ON_OPERATING_FAIL_STATE;
            break;
        }

        if(outlet->OUTLET_DISABLE[0] == 1 && outlet->OUTLET_DISABLE[1] == 1){
            logger->write("[OPERATING PROCESS] FAIL -- Outlet All Disable");
            QMessageBox::warning(this, "운영시작 실패", "<font size=4>배출구가 모두 비활성화 되었습니다.<font>");
            OP_STATUS_OPERATING = PLATFORM_OPERATION_ON_OPERATING_FAIL_STATE;
            break;
        }
        logger->write("[OPERATING PROCESS] Check Outlet occupy : Success");
        OP_STATUS_OPERATING = PLATFORM_OPERATION_CHECK_SCHEDULER;
        break;
    }

    case PLATFORM_OPERATION_CHECK_SCHEDULER:
        ui->LE_PLATFORM_OPERATING->setText("80 %");
        logger->write("[OPERATING PROCESS] Scheduler action state : IDLE");
        schedule->action_state = ACTION_STATE_IDLE;

        // unblock the order
        kiosk->block_order = false;
        logger->write("[OPERATING PROCESS] Kiosk Order block : false");

        // clear platform opened flag
        platform_opened_flag = 0;
        platform_open_close_transition_flag = 0;

        // clear robot force stop flag
        logger->write("[OPERATING PROCESS] Clear System Forced Stop Flag");
        robot->ClearSystemForcedStopFlag();

        // clear stop flags
        OP_COMMAND_SUPER_STOP_OPERATING = 0;
        OP_COMMAND_FORCED_STOP_OPERATING = 0;

        // led on
        outlet->LEDon(0,LED_YELLOW);
        outlet->LEDon(1,LED_YELLOW);

        logger->write("[OPERATING PROCESS] Platform is in the Operation State");
        OP_STATUS_OPERATING = PLATFORM_OPERATION_ON_OPERATING_STATE;
        break;

    case PLATFORM_OPERATION_ON_OPERATING_STATE:
        ui->LE_PLATFORM_OPERATING->setText("영업 중");
        // in operating state
        if(platform_opened_flag == 0){
            // platform closed
            // normal operation
            if(door->IsPlatformClosed() == 0){
                platform_opening_detection_count++;
            }else{
                platform_opening_detection_count = 0;
            }
            if(platform_opening_detection_count > 5){
                platform_closing_detection_count = 0;
                platform_open_close_transition_flag = 1;
                platform_opened_flag = 1;
            }

            // do it once
            if(platform_open_close_transition_flag == 1){
                platform_open_close_transition_flag = 0;

                // block the order
                kiosk->block_order = true;

                // fatal error check -- is robot in the unsafe position??
                if((schedule->action_state != ACTION_STATE_IDLE) && (schedule->action_state != ACTION_STATE_INIT)){
//                    logger->write("[SUPER STOP] DUE TO PLATFORM OPEN ERROR");
//                    SUPER_FATAL_ERROR_PLATFORM_OPEN = 1;
//                    OP_COMMAND_SUPER_STOP_OPERATING = 1;

                    logger->write("[OPERATING PROCESS] Platform Door : Opened");
                    notice->ShowOpStop("ST_D1","운영 중 문이 열렸습니다.");
                    IS_UI_LOCK = true;
                    PLATFORM_OPENED_WHEN_OPERATING_FLAG = 1;
                }
            }else{
                // continuously work code

                // robot speed to normal
                if(PLATFORM_OPENED_WHEN_OPERATING_FLAG == 1){
                    if(fabs(sys_status.sdata.default_speed-ROBOT_STOP_SPPED) > 0.01){
                        robot->BaseSpeedChange(ROBOT_STOP_SPPED);
                    }
                }else{
                    if(fabs(sys_status.sdata.default_speed-ROBOT_NORMAL_SPEED) > 0.01){
                        robot->BaseSpeedChange(ROBOT_NORMAL_SPEED);
                    }
                }

                // unblock the order
                kiosk->block_order = false;
            }

        }else{
            // platform opened
            if(door->IsPlatformClosed() == 1){
                platform_closing_detection_count++;
            }else{
                platform_closing_detection_count = 0;
            }
            if(platform_closing_detection_count > 5){
                platform_opening_detection_count = 0;
                platform_open_close_transition_flag = 1;
                platform_opened_flag = 0;
            }

            // do it once
            if(platform_open_close_transition_flag == 1){

                logger->write("[OPERATING PROCESS] Platform Door : Closed");
                platform_open_close_transition_flag = 0;

                // unblock the order
                kiosk->block_order = false;
                PLATFORM_OPENED_WHEN_OPERATING_FLAG = 0;

            }else{
                // continuously work code

                // robot speed to zero
                if(schedule->action_state == ACTION_STATE_OUTLET_CUP_PLACE ||
                   schedule->action_state == ACTION_STATE_OUTLET_DISPENSE_COMPLETED ||
                   schedule->action_state == ACTION_STATE_OUTLET_GET){
                    ;
                }else{
                    if(fabs(sys_status.sdata.default_speed-ROBOT_STOP_SPPED) > 0.01){
                        robot->BaseSpeedChange(ROBOT_STOP_SPPED);
                    }
                }

                // block the order
                kiosk->block_order = true;
            }

        }


        // FORCE STOP TRIGGER
//        if(loadcell->FORCE_FATAL_ERROR_LOADCELL_BOBA == 1){
////            logger->write("[FORCE STOP] DUE TO LOADCELL BOBA ERROR");
//            OP_COMMAND_FORCED_STOP_OPERATING = 1;
//        }

        // SUPER STOP TRIGGER
        if(lan->SUPER_FATAL_ERROR_CONNECTION_OF_LAN2CAN == 1){
            logger->write("[SUPER STOP] DUE TO LAN2CAN BOARD CONNECTION ERROR");
            notice->ShowOpStop("CON_B1","보드와 CMD 연결이 끊어졌습니다.");
            IS_UI_LOCK = true;
            OP_COMMAND_SUPER_STOP_OPERATING = 1;
        }else if(robot->SUPER_FATAL_ERROR_ROBOT_DATA == 1){
            logger->write("[SUPER STOP] DUE TO ROBOT DATA ERROR");
            notice->ShowOpStop("CON_R1","로봇과 DATA 연결이 끊어졌습니다.");
            IS_UI_LOCK = true;
            OP_COMMAND_SUPER_STOP_OPERATING = 1;
        }else if(robot->SUPER_FATAL_ERROR_ROBOT_MISS_COMMAND_WORKING_CHECK == 1){
            logger->write("[SUPER STOP] DUE TO ROBOT MISS COMMAND CHECK ERROR");
            notice->ShowOpStop("CON_R1","로봇에서 명령에 대한 응답이 돌아오지 않습니다.");
            IS_UI_LOCK = true;
            OP_COMMAND_SUPER_STOP_OPERATING = 1;
        }else if(outlet->SUPER_FATAL_ERROR_OUTLET_CONNECTION == 1){
            logger->write("[SUPER STOP] DUE TO OUTLET CONNECTION ERROR");
            notice->ShowOpStop("CON_O1","배출구 보드와 연결이 끊어졌습니다.");
            IS_UI_LOCK = true;
            OP_COMMAND_SUPER_STOP_OPERATING = 1;
        }else if(outlet->SUPER_FATAL_ERROR_OUTLET_CONTROL == 1){
            logger->write("[SUPER STOP] DUE TO OUTLET CONTROL ERROR");
            notice->ShowOpStop("CON_O1","배출구에 제어 에러가 발생했습니다.");
            IS_UI_LOCK = true;
            OP_COMMAND_SUPER_STOP_OPERATING = 1;
        }else if(outlet->SUPER_FATAL_ERROR_OUTLET_SENSOR){
            logger->write("[SUPER STOP] DUE TO OUTLET SENSOR ERROR");
            notice->ShowOpStop("CON_O1","배출구 센서가 연결되지 않습니다.");
            IS_UI_LOCK = true;
            OP_COMMAND_SUPER_STOP_OPERATING = 1;
        }else if(cup->PAUSE_FATAL_ERROR_CUP_DISPENSER == 1){
            logger->write("[SUPER STOP] CUP DISPENSER ERROR");
            IS_UI_LOCK = true;
            OP_COMMAND_SUPER_STOP_OPERATING = 1;
            notice->ShowOpStop("COL_C1","컵 디스펜서에 컵이 끼어 있거나 배출이 되지 않습니다.\n컵을 모두 정상상태로 하고 다시 초기화 해 주십시오.");
        }else if(cup->PAUSE_FATAL_ERROR_CUP_SOLDOUT == 1){
            logger->write("[SUPER STOP] CUP SOLDOUT ERROR");
            IS_UI_LOCK = true;
            notice->ShowOpStop("SD_C1","컵이 모두 사용되었습니다. \n 컵을 채운 뒤 운영을 재개하여 주십시오.");
        }
        // Super Operating Stop Command
        if(OP_COMMAND_SUPER_STOP_OPERATING == 1){
            // block the order
            kiosk->block_order = true;

            robot->SetSystemForcedStopFlag();

            schedule->SetRecallOrderFlag();
            schedule->SetRecallInprogressingOrderFlag();
            schedule->action_state = ACTION_STATE_INIT;

            //led
            outlet->LEDon(0,LED_RED);
            outlet->LEDon(1,LED_RED);
            OP_STATUS_OPERATING = PLATFORM_OPERATION_ON_ERROR_STATE;
            OP_STATUS_INITIALIZING = PLATFORM_INIT_IDLE;

            logger->write("[SUPER STOP] DO SUPER STOP");
        }
        // Forced Operating Stop Command
        else if(OP_COMMAND_FORCED_STOP_OPERATING == 1){
            // block the order
            kiosk->block_order = true;

            schedule->last_order_flag = true;
            //led
            outlet->LEDon(0,LED_RED);
            outlet->LEDon(1,LED_RED);
            OP_STATUS_OPERATING = PLATFORM_OPERATION_ON_ERROR_STATE;
            OP_STATUS_INITIALIZING = PLATFORM_INIT_IDLE;

            logger->write("[FORCED STOP] DO FORCED STOP");
        }
        // Operating Stop Command
        else if(OP_COMMAND_STOP_OPERATING == 1){
            // block the order
            kiosk->block_order = true;

            if((schedule->IsIdle()) && (schedule->action_state == ACTION_STATE_IDLE)){
                qDebug()<<"-- All outlets & orders are free, ACTION STATE IDLE, Motion Flag 0";

                schedule->action_state = ACTION_STATE_INIT;
                OP_STATUS_OPERATING = PLATFORM_OPERATION_IDLE;

                logger->write("[GENTLE STOP] DO GENTLE STOP");
            }
        }


        // check the robot in the safe region or not
        // todo lim

        //OP_STATUS_OPERATING = PLATFORM_OPERATION_PLATFORM_OPENED_DETECTED;

        break;

    case PLATFORM_OPERATION_ON_ERROR_STATE:
        ui->LE_PLATFORM_OPERATING->setText("강제 종료됨");
        // in error state
        break;

    case PLATFORM_OPERATION_ON_OPERATING_FAIL_STATE:
        ui->LE_PLATFORM_OPERATING->setText("영업 시작 실패");
        // in init fail state
        break;

    case PLATFORM_OPERATION_FATAL_CHECK_ROBOT_DANGEROUS_POSITION:

        break;

    case PLATFORM_OPERATION_FATAL_AVOID_ROBOT_DANGEROUS_POSITION:
        break;

    case PLATFORM_OPERATION_PLATFORM_OPENED_DETECTED:
        break;

    default:
        break;
    }
}



void MainWindow::UpdatePlatformOperationInfo(){
    static int blink_count = 0;
    static int platform_physically_opened_or_not = -1;

    blink_count++;

    // Operating Status for Initializing
    if(OP_STATUS_INITIALIZING == PLATFORM_INIT_ON_SUCCESS_STATE){
        SetLEColor(ui->LE_PLATFORM_INITIALIZING, COLOR_GOOD);
    }else if(OP_STATUS_INITIALIZING == PLATFORM_INIT_ON_FAIL_STATE){
        SetLEColor(ui->LE_PLATFORM_INITIALIZING, COLOR_BAD);
    }else if(OP_STATUS_INITIALIZING == PLATFORM_INIT_IDLE){
        SetLEColor(ui->LE_PLATFORM_INITIALIZING, "white");
    }else{
        SetLEColor(ui->LE_PLATFORM_INITIALIZING, "yellow");
    }


    if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_STATE){
        SetLEColor(ui->LE_PLATFORM_OPERATING, COLOR_GOOD);
    }else if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_ERROR_STATE){
        SetLEColor(ui->LE_PLATFORM_OPERATING, COLOR_BAD);
    }else if(OP_STATUS_OPERATING == PLATFORM_OPERATION_IDLE || OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_FAIL_STATE){
        SetLEColor(ui->LE_PLATFORM_OPERATING, "white");
    }else{
        SetLEColor(ui->LE_PLATFORM_OPERATING, "yellow");
    }


    if(door->IsPlatformClosed() == 1){
        SetLEColor(ui->LE_PLATFORM_CLOSED, COLOR_GOOD);
    }else{
        SetLEColor(ui->LE_PLATFORM_CLOSED, COLOR_BAD);
    }

    if(door->IsPlatformClosed() != platform_physically_opened_or_not){
        platform_physically_opened_or_not = door->IsPlatformClosed();
        if(platform_physically_opened_or_not == 1){
            logger->write("[SYSTEM] PLATFORM PHYSICALLY CLOSED NOW");
        }else{
            logger->write("[SYSTEM] PLATFORM PHYSICALLY OPENED NOW");
        }
    }



    if(OP_COMMAND_STOP_OPERATING == 1){
        if(blink_count%10 == 0){
            SetLEColor(ui->LE_PLATFORM_WAITING_STOP, "yellow");
        }else if(blink_count%10 == 5){
            SetLEColor(ui->LE_PLATFORM_WAITING_STOP, "white");
        }
    }else{
        SetLEColor(ui->LE_PLATFORM_WAITING_STOP, "white");
    }


    if(PLATFORM_OPENED_WHEN_OPERATING_FLAG == 1){
        if(blink_count%10 == 0){
            SetLEColor(ui->LE_PLATFORM_OPENED_WHEN_OPERATING, "yellow");
        }else if(blink_count%10 == 5){
            SetLEColor(ui->LE_PLATFORM_OPENED_WHEN_OPERATING, "white");
        }
    }else{
        SetLEColor(ui->LE_PLATFORM_OPENED_WHEN_OPERATING, "white");
    }
}


void MainWindow::Update_Dev_CupInfo(){
    if(lan->sockConnectionStatus == false){
        SetBTNColor(ui->BTN_DEV_INFO_CUP, COLOR_UNDETERMINED);
        ui->LB_CUP_1_LAST_ERROR->setText("-");
        ui->LB_CUP_2_LAST_ERROR->setText("-");
        ui->LB_CUP_3_LAST_ERROR->setText("-");
        ui->LB_CUP_4_LAST_ERROR->setText("-");
        ui->LB_CUP_1_OP_STATE->setText("-");
        ui->LB_CUP_2_OP_STATE->setText("-");
        ui->LB_CUP_3_OP_STATE->setText("-");
        ui->LB_CUP_4_OP_STATE->setText("-");
    }else{
        if(CUP_DATA[0].connection_status == 1 &&
            CUP_DATA[1].connection_status == 1 &&
            CUP_DATA[2].connection_status == 1 &&
            CUP_DATA[3].connection_status == 1){
            SetBTNColor(ui->BTN_DEV_INFO_CUP, COLOR_GOOD);
        }else{
            SetBTNColor(ui->BTN_DEV_INFO_CUP, COLOR_WEAKBAD);
        }

        if(CUP_DATA[0].connection_status == 1){
            ui->LB_CUP_1_LAST_ERROR->setText(cup->cup_1_error);
            if(CUP_DATA[0].dispense_op_flag == 0){
                ui->LB_CUP_1_OP_STATE->setText("준비");
            }else{
                ui->LB_CUP_1_OP_STATE->setText("동작중");
            }
        }else{
            ui->LB_CUP_1_LAST_ERROR->setText("-");
            ui->LB_CUP_1_OP_STATE->setText("-");
        }

        if(CUP_DATA[1].connection_status == 1){
            ui->LB_CUP_2_LAST_ERROR->setText(cup->cup_2_error);
            if(CUP_DATA[1].dispense_op_flag == 0){
                ui->LB_CUP_2_OP_STATE->setText("준비");
            }else{
                ui->LB_CUP_2_OP_STATE->setText("동작중");
            }
        }else{
            ui->LB_CUP_2_LAST_ERROR->setText("-");
            ui->LB_CUP_2_OP_STATE->setText("-");
        }
        if(CUP_DATA[2].connection_status == 1){
            ui->LB_CUP_3_LAST_ERROR->setText(cup->cup_2_error);
            if(CUP_DATA[2].dispense_op_flag == 0){
                ui->LB_CUP_3_OP_STATE->setText("준비");
            }else{
                ui->LB_CUP_3_OP_STATE->setText("동작중");
            }
        }else{
            ui->LB_CUP_3_LAST_ERROR->setText("-");
            ui->LB_CUP_3_OP_STATE->setText("-");
        }
        if(CUP_DATA[3].connection_status == 1){
            ui->LB_CUP_4_LAST_ERROR->setText(cup->cup_2_error);
            if(CUP_DATA[3].dispense_op_flag == 0){
                ui->LB_CUP_4_OP_STATE->setText("준비");
            }else{
                ui->LB_CUP_4_OP_STATE->setText("동작중");
            }
        }else{
            ui->LB_CUP_4_LAST_ERROR->setText("-");
            ui->LB_CUP_4_OP_STATE->setText("-");
        }
    }
}

void MainWindow::Update_Dev_IceInfo(){
    if(ice->isOpenPort() == false){
        SetBTNColor(ui->BTN_DEV_INFO_ICE_1, COLOR_UNDETERMINED);
        ui->LB_ICE_1_FULL->setText("-");
        ui->LB_ICE_1_ERROR->setText("-");
    }else{
        if(ICE_DATA[0].connection_status == 1 && ICE_DATA[0].data_connection == 1){
            SetBTNColor(ui->BTN_DEV_INFO_ICE_1, COLOR_GOOD);

            if(ICE_DATA[0].status.b.full_ice == 1){
                ui->LB_ICE_1_FULL->setText("만빙");
            }else{
                ui->LB_ICE_1_FULL->setText("만빙아님");
            }
            ui->LB_ICE_1_ERROR->setText(ice->ice_1_error);
        }else{
            SetBTNColor(ui->BTN_DEV_INFO_ICE_1, COLOR_WEAKBAD);
            ui->LB_ICE_1_FULL->setText("-");
            ui->LB_ICE_1_ERROR->setText("-");
        }
    }
}


void MainWindow::Update_Dev_CoffeeInfo(){
    if(coffee->coffee_connection == false){
        SetBTNColor(ui->BTN_DEV_INFO_COFFEE, COLOR_UNDETERMINED);
    }else{
        if(coffee->coffee_data_connection == true){
            SetBTNColor(ui->BTN_DEV_INFO_COFFEE, COLOR_GOOD);
        }else{
            SetBTNColor(ui->BTN_DEV_INFO_COFFEE, COLOR_WEAKBAD);
        }
    }

    switch(coffee->module_status.coffee_L_status){
    case notReady_e:
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_NOT_READY, COLOR_BLUE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_COFFEE_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_MILK_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_UNDEF, COLOR_NONE);
        break;
    case Ready_e:
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_NOT_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_READY, COLOR_BLUE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_COFFEE_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_MILK_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_UNDEF, COLOR_NONE);
        break;
    case OnlyCoffeeUnitReady:
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_NOT_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_COFFEE_READY, COLOR_BLUE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_MILK_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_UNDEF, COLOR_NONE);
        break;
    case OnlyMilkUnitReady:
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_NOT_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_COFFEE_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_MILK_READY, COLOR_BLUE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_UNDEF, COLOR_NONE);
        break;
    case Undef_e:
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_NOT_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_COFFEE_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_MILK_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_UNDEF, COLOR_BLUE);
        break;
    }

    switch(coffee->module_status.water_status){
    case notReady_e:
        SetLEColor(ui->LE_WATER_M_STATUS_NOT_READY, COLOR_BLUE);
        SetLEColor(ui->LE_WATER_M_STATUS_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_COFFEE_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_MILK_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_UNDEF, COLOR_NONE);
        break;
    case Ready_e:
        SetLEColor(ui->LE_WATER_M_STATUS_NOT_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_READY, COLOR_BLUE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_COFFEE_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_MILK_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_UNDEF, COLOR_NONE);
        break;
    case OnlyCoffeeUnitReady:
        SetLEColor(ui->LE_WATER_M_STATUS_NOT_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_COFFEE_READY, COLOR_BLUE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_MILK_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_UNDEF, COLOR_NONE);
        break;
    case OnlyMilkUnitReady:
        SetLEColor(ui->LE_WATER_M_STATUS_NOT_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_COFFEE_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_MILK_READY, COLOR_BLUE);
        SetLEColor(ui->LE_WATER_M_STATUS_UNDEF, COLOR_NONE);
        break;
    case Undef_e:
        SetLEColor(ui->LE_WATER_M_STATUS_NOT_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_COFFEE_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_MILK_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_UNDEF, COLOR_BLUE);
        break;
    }


    ui->LE_COFFEE_L_M_ACTION->setText(module_action_name[coffee->module_status.coffee_L_action]);
    ui->LE_WATER_M_ACTION->setText(module_action_name[coffee->module_status.water_action]);

    if(uint(coffee->module_process.coffee_L_process) > uint(ProcessRequested_e)){
        ui->LE_COFFEE_L_M_PROCESS->setText(QString().sprintf("%d", coffee->module_process.coffee_L_process));
    }else{
        ui->LE_COFFEE_L_M_PROCESS->setText(module_process_name[coffee->module_process.coffee_L_process]);
    }
    ui->LE_WATER_M_PROCESS->setText(module_process_name[coffee->module_process.water_process]);

}


void MainWindow::Update_Dev_SyrupInfo(){
    if(lan->sockConnectionStatus == false){
        SetBTNColor(ui->BTN_DEV_INFO_SYRUP, COLOR_UNDETERMINED);
        ui->LB_SYRUP_LOADCELL->setText("-");
        ui->LB_SYRUP_LAST_ERROR->setText("-");
        ui->LB_SYRUP_OP_STATE->setText("-");
    }else{
        if(SYRUP_DATA[0].connection_status == 1){
            SetBTNColor(ui->BTN_DEV_INFO_SYRUP, COLOR_GOOD);
            ui->LB_SYRUP_LOADCELL->setText(QString().sprintf("%d", syrup->LoadcellValue()));
            ui->LB_SYRUP_LAST_ERROR->setText(syrup->syrup_error);
            if(SYRUP_DATA[0].out_state == 0){
                ui->LB_SYRUP_OP_STATE->setText("준비");
            }else{
                ui->LB_SYRUP_OP_STATE->setText("동작중");
            }
        }else{
            SetBTNColor(ui->BTN_DEV_INFO_SYRUP, COLOR_WEAKBAD);
            ui->LB_SYRUP_LOADCELL->setText("-");
            ui->LB_SYRUP_LAST_ERROR->setText("-");
            ui->LB_SYRUP_OP_STATE->setText("-");
        }
    }
}

void MainWindow::Update_Dev_SodaInfo(){
    if(lan->sockConnectionStatus == false){
        SetBTNColor(ui->BTN_DEV_INFO_SODA, COLOR_UNDETERMINED);
        ui->LB_SODA_LOADCELL->setText("-");
        ui->LB_SODA_LAST_ERROR->setText("-");
        ui->LB_SODA_OP_STATE->setText("-");
    }else{
        if(SODA_DATA[0].connection_status == 1){
            SetBTNColor(ui->BTN_DEV_INFO_SODA, COLOR_GOOD);
            ui->LB_SODA_LOADCELL->setText(QString().sprintf("%d", soda->LoadcellValue()));
            ui->LB_SODA_LAST_ERROR->setText(soda->soda_error);
            if(SODA_DATA[0].out_state == 0){
                ui->LB_SODA_OP_STATE->setText("준비");
            }else{
                ui->LB_SODA_OP_STATE->setText("동작중");
            }
        }else{
            SetBTNColor(ui->BTN_DEV_INFO_SODA, COLOR_WEAKBAD);
            ui->LB_SODA_LOADCELL->setText("-");
            ui->LB_SODA_LAST_ERROR->setText("-");
            ui->LB_SODA_OP_STATE->setText("-");
        }
    }
}

void MainWindow::Update_Dev_RobotInfo(){
    if(robot->cmdConnectionStatus == true && robot->dataConnectionStatus == true){
        SetBTNColor(ui->BTN_DEV_INFO_ROBOT, COLOR_GOOD);

        if(sys_status.sdata.program_mode == 0){
            SetLEColor(ui->LE_PG_MODE_REAL, COLOR_GOOD);
            SetLEColor(ui->LE_PG_MODE_SIMULATION, "white");
        }else if(sys_status.sdata.program_mode == 1){
            SetLEColor(ui->LE_PG_MODE_REAL, "white");
            SetLEColor(ui->LE_PG_MODE_SIMULATION, COLOR_BAD);
        }else{
            SetLEColor(ui->LE_PG_MODE_REAL, "white");
            SetLEColor(ui->LE_PG_MODE_SIMULATION, "white");
        }

        if(sys_status.sdata.robot_state == 1){
            SetLEColor(ui->LE_ROBOT_STATE_IDLE, COLOR_BLUE);
            SetLEColor(ui->LE_ROBOT_STATE_MOVING, "white");
        }else if(sys_status.sdata.robot_state == 2){
            SetLEColor(ui->LE_ROBOT_STATE_IDLE, "white");
            SetLEColor(ui->LE_ROBOT_STATE_MOVING, "white");
        }else if(sys_status.sdata.robot_state == 3){
            SetLEColor(ui->LE_ROBOT_STATE_IDLE, "white");
            SetLEColor(ui->LE_ROBOT_STATE_MOVING, COLOR_BLUE);
        }else{
            SetLEColor(ui->LE_ROBOT_STATE_IDLE, "white");
            SetLEColor(ui->LE_ROBOT_STATE_MOVING, "white");
        }


        if(sys_status.sdata.is_freedrive_mode == 1){
            SetLEColor(ui->LE_ROBOT_STATUS_TEACHING, COLOR_BLUE);
        }else{
            SetLEColor(ui->LE_ROBOT_STATUS_TEACHING, "white");
        }
        if(sys_status.sdata.op_stat_collision_occur == 1){
            SetLEColor(ui->LE_ROBOT_STATUS_EXT_COLLISION, COLOR_BAD);
            //logger->write("[ROBOT] EXT COLLISION OCCURED");
        }else{
            SetLEColor(ui->LE_ROBOT_STATUS_EXT_COLLISION, "white");
        }
        if(sys_status.sdata.op_stat_self_collision == 1){
            SetLEColor(ui->LE_ROBOT_STATUS_SELF_COLLISION, COLOR_BAD);
            //logger->write("[ROBOT] SELF COLLISION OCCURED");
        }else{
            SetLEColor(ui->LE_ROBOT_STATUS_SELF_COLLISION, "white");
        }
        if(sys_status.sdata.op_stat_soft_estop_occur == 1){
            SetLEColor(ui->LE_ROBOT_STATUS_PAUSED, COLOR_BAD);
            //logger->write("[ROBOT] SOTF ESTOP OCCURED");
        }else{
            SetLEColor(ui->LE_ROBOT_STATUS_PAUSED, "white");
        }
        if(sys_status.sdata.op_stat_ems_flag != 0){
            SetLEColor(ui->LE_ROBOT_STATUS_EMS, COLOR_BAD);
            //logger->write("[ROBOT] EMS ERROR OCCURED");
        }else{
            SetLEColor(ui->LE_ROBOT_STATUS_EMS, "white");
        }
        if(sys_status.sdata.op_stat_sos_flag == 1){
            SetLEColor(ui->LE_ROBOT_STATUS_SOS, COLOR_BAD);
            //logger->write("[ROBOT] SOS ERROR OCCURED");
        }else{
            SetLEColor(ui->LE_ROBOT_STATUS_SOS, "white");
        }


        if(sys_status.sdata.task_state == 1){
            SetLEColor(ui->LE_ROBOT_PRG_WORKING_STATUS, COLOR_BAD);
        }else if(sys_status.sdata.task_state == 2){
            SetLEColor(ui->LE_ROBOT_PRG_WORKING_STATUS, "yellow");
        }else if(sys_status.sdata.task_state == 3){
            SetLEColor(ui->LE_ROBOT_PRG_WORKING_STATUS, COLOR_GOOD);
        }

        if(robot->motionServer->RBConnectionStatus == true){
            SetLEColor(ui->LE_ROBOT_PRG_CONNECT, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_ROBOT_PRG_CONNECT, COLOR_BAD);
        }

        if(OP_STATUS_OPERATING != PLATFORM_OPERATION_ON_OPERATING_STATE){
            if(sys_status.sdata.jnt_ang[0] > ROBOT_BASE_LOW && sys_status.sdata.jnt_ang[0] < ROBOT_BASE_HIGH ){
                SetLEColor(ui->LE_ROBOT_INIT_BASE_ANGLE, COLOR_GOOD);
            }else{
                SetLEColor(ui->LE_ROBOT_INIT_BASE_ANGLE, COLOR_BAD);
            }
            if(sys_status.sdata.digital_out[15] == 1){
                SetLEColor(ui->LE_ROBOT_INIT_POSITION, COLOR_GOOD);
            }else{
                SetLEColor(ui->LE_ROBOT_INIT_POSITION, COLOR_BAD);
            }
        }else{
            SetLEColor(ui->LE_ROBOT_INIT_BASE_ANGLE, "white");
            SetLEColor(ui->LE_ROBOT_INIT_POSITION, "white");
        }
    }else{
        SetBTNColor(ui->BTN_DEV_INFO_ROBOT, COLOR_WEAKBAD);

        SetLEColor(ui->LE_PG_MODE_REAL, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_PG_MODE_SIMULATION, COLOR_UNDETERMINED);

        SetLEColor(ui->LE_ROBOT_STATE_IDLE, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_ROBOT_STATE_MOVING, COLOR_UNDETERMINED);

        SetLEColor(ui->LE_ROBOT_STATUS_TEACHING, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_ROBOT_STATUS_EXT_COLLISION, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_ROBOT_STATUS_SELF_COLLISION, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_ROBOT_STATUS_PAUSED, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_ROBOT_STATUS_EMS, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_ROBOT_STATUS_SOS, COLOR_UNDETERMINED);

        SetLEColor(ui->LE_ROBOT_PRG_WORKING_STATUS, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_ROBOT_PRG_CONNECT, COLOR_UNDETERMINED);

        SetLEColor(ui->LE_ROBOT_INIT_BASE_ANGLE, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_ROBOT_INIT_POSITION, COLOR_UNDETERMINED);
    }
}

void MainWindow::Update_Dev_MonitorInfo(){
    if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_STATE){
        display->Set_Mode(DISPLAY_MODE_IN_OPERATION);
    }else if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_ERROR_STATE){
        display->Set_Mode(DISPLAY_MODE_IN_OPERATION);
        monitor->display_msg = "에러가 발생하였습니다. 관리자를 호출해주세요.";
    }else{
        monitor->display_msg = "";
        display->Set_Mode(DISPLAY_MODE_IN_READY);
    }

    SetBTNColor(ui->BTN_DEV_INFO_MONITOR, COLOR_GOOD);
    ui->LB_MONITOR_INPROGRESS->setText(QString().sprintf("%d", monitor->disp_inprogress.size()));
    ui->LB_MONITOR_WAITING->setText(QString().sprintf("%d", monitor->disp_waiting.size()));
    ui->LB_MONITOR_COMPLETED->setText(QString().sprintf("%d", monitor->disp_completed.size()));

    if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_STATE){
        monitor->set_display_mode(DISPLAY_MODE_IN_OPERATION);
    }else if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_ERROR_STATE){
        monitor->set_display_mode(DISPLAY_MODE_IN_OPERATION);
        monitor->display_msg = "에러가 발생하였습니다. 관리자를 호출해주세요.";
    }else{
        monitor->display_msg = "";
        monitor->set_display_mode(DISPLAY_MODE_IN_READY);
    }
//    if(monitor->displayConnectionStatus == true){
//    }else{
//        SetBTNColor(ui->BTN_DEV_INFO_MONITOR, COLOR_WEAKBAD);
//        ui->LB_MONITOR_INPROGRESS->setText("-");
//        ui->LB_MONITOR_WAITING->setText("-");
//        ui->LB_MONITOR_COMPLETED->setText("-");
//    }
}

void MainWindow::Update_Dev_DoorInfo(){
    if(lan->sockConnectionStatus == false){
        SetBTNColor(ui->BTN_DEV_INFO_DOOR, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_DOOR_OPENED, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_DOOR_CLOSED, COLOR_UNDETERMINED);
    }else{
        //test
//        DOOR_DATA[0].connection_status = 1;
//        DOOR_DATA[0].platform_sensorA = 1;
//        DOOR_DATA[0].platform_sensorB = 1;


        if(DOOR_DATA[0].connection_status == 1){
            SetBTNColor(ui->BTN_DEV_INFO_DOOR, COLOR_GOOD);
            if(door->IsPlatformClosed() == 1){
                SetLEColor(ui->LE_DOOR_OPENED, COLOR_NONE);
                SetLEColor(ui->LE_DOOR_CLOSED, COLOR_BLUE);
            }else{
                SetLEColor(ui->LE_DOOR_OPENED, COLOR_BLUE);
                SetLEColor(ui->LE_DOOR_CLOSED, COLOR_NONE);
            }
        }else{
            SetBTNColor(ui->BTN_DEV_INFO_DOOR, COLOR_WEAKBAD);
            SetLEColor(ui->LE_DOOR_OPENED, COLOR_UNDETERMINED);
            SetLEColor(ui->LE_DOOR_CLOSED, COLOR_UNDETERMINED);
        }
    }
}

void MainWindow::Update_Dev_BarcodeInfo(){
    if(barcode->isOpenPort() == false){
        SetBTNColor(ui->BTN_DEV_INFO_BARCODE, COLOR_UNDETERMINED);
        ui->LB_BARCODE_LAST_DATA->setText("-");
    }else{
        SetBTNColor(ui->BTN_DEV_INFO_BARCODE, COLOR_GOOD);
        ui->LB_BARCODE_LAST_DATA->setText(barcode->NewBarcodePin);
    }
}

void MainWindow::Update_Dev_OutletInfo(){
    if(lan->sockConnectionStatus == false){
        SetBTNColor(ui->BTN_DEV_INFO_OUTLET, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_M_1_DOOR_OPEN, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_M_1_DOOR_CLOSE, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_M_1_CUP_DETECT, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_M_2_DOOR_OPEN, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_M_2_DOOR_CLOSE, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_M_2_CUP_DETECT, COLOR_UNDETERMINED);
        ui->LB_OUTLET_M_1_CELL_1->setText("-");
        ui->LB_OUTLET_M_1_CELL_2->setText("-");
        ui->LB_OUTLET_M_1_CELL_3->setText("-");
        ui->LB_OUTLET_M_2_CELL_1->setText("-");
        ui->LB_OUTLET_M_2_CELL_2->setText("-");
        ui->LB_OUTLET_M_2_CELL_3->setText("-");
    }else{
        if(OUTLET_DATA[0].connection_status == 1 && OUTLET_DATA[1].connection_status == 1){
            SetBTNColor(ui->BTN_DEV_INFO_OUTLET, COLOR_GOOD);
        }else{
            SetBTNColor(ui->BTN_DEV_INFO_OUTLET, COLOR_WEAKBAD);
        }

        if(OUTLET_DATA[0].connection_status == 1){
            if(outlet->GetDoorPosition(0) == DOOR_IN_OPEN_POS){
                SetLEColor(ui->LE_OUTLET_M_1_DOOR_OPEN, COLOR_BLUE);
                SetLEColor(ui->LE_OUTLET_M_1_DOOR_CLOSE, COLOR_NONE);
            }else if(outlet->GetDoorPosition(0) == DOOR_IN_CLOSE_POS){
                SetLEColor(ui->LE_OUTLET_M_1_DOOR_OPEN, COLOR_NONE);
                SetLEColor(ui->LE_OUTLET_M_1_DOOR_CLOSE, COLOR_BLUE);
            }else{
                SetLEColor(ui->LE_OUTLET_M_1_DOOR_OPEN, COLOR_NONE);
                SetLEColor(ui->LE_OUTLET_M_1_DOOR_CLOSE, COLOR_NONE);
            }

            if(OUTLET_DATA[0].sonar_sensor_data < OUTLET_SONAR_SENSOR_THRESHOLD){
                SetLEColor(ui->LE_OUTLET_M_1_CUP_DETECT, COLOR_BLUE);
            }else{
                SetLEColor(ui->LE_OUTLET_M_1_CUP_DETECT, COLOR_NONE);
            }

            if(OUTLET_DATA[0].cell_state[0] == CELL_OCC){
                ui->LB_OUTLET_M_1_CELL_1->setText(OUTLET_DATA[0].cell_occupy_pin[0]);
            }else{
                ui->LB_OUTLET_M_1_CELL_1->setText("-");
            }
            if(OUTLET_DATA[0].cell_state[1] == CELL_OCC){
                ui->LB_OUTLET_M_1_CELL_2->setText(OUTLET_DATA[0].cell_occupy_pin[1]);
            }else{
                ui->LB_OUTLET_M_1_CELL_2->setText("-");
            }
            if(OUTLET_DATA[0].cell_state[2] == CELL_OCC){
                ui->LB_OUTLET_M_1_CELL_3->setText(OUTLET_DATA[0].cell_occupy_pin[2]);
            }else{
                ui->LB_OUTLET_M_1_CELL_3->setText("-");
            }
        }else{
            SetLEColor(ui->LE_OUTLET_M_1_DOOR_OPEN, COLOR_UNDETERMINED);
            SetLEColor(ui->LE_OUTLET_M_1_DOOR_CLOSE, COLOR_UNDETERMINED);
            SetLEColor(ui->LE_OUTLET_M_1_CUP_DETECT, COLOR_UNDETERMINED);
            ui->LB_OUTLET_M_1_CELL_1->setText("-");
            ui->LB_OUTLET_M_1_CELL_2->setText("-");
            ui->LB_OUTLET_M_1_CELL_3->setText("-");
        }

        if(OUTLET_DATA[1].connection_status == 1){
            if(outlet->GetDoorPosition(1) == DOOR_IN_OPEN_POS){
                SetLEColor(ui->LE_OUTLET_M_2_DOOR_OPEN, COLOR_BLUE);
                SetLEColor(ui->LE_OUTLET_M_2_DOOR_CLOSE, COLOR_NONE);
            }else if(outlet->GetDoorPosition(1) == DOOR_IN_CLOSE_POS){
                SetLEColor(ui->LE_OUTLET_M_2_DOOR_OPEN, COLOR_NONE);
                SetLEColor(ui->LE_OUTLET_M_2_DOOR_CLOSE, COLOR_BLUE);
            }else{
                SetLEColor(ui->LE_OUTLET_M_2_DOOR_OPEN, COLOR_NONE);
                SetLEColor(ui->LE_OUTLET_M_2_DOOR_CLOSE, COLOR_NONE);
            }

            if(OUTLET_DATA[1].sonar_sensor_data < OUTLET_SONAR_SENSOR_THRESHOLD){
                SetLEColor(ui->LE_OUTLET_M_2_CUP_DETECT, COLOR_BLUE);
            }else{
                SetLEColor(ui->LE_OUTLET_M_2_CUP_DETECT, COLOR_NONE);
            }

            if(OUTLET_DATA[1].cell_state[0] == CELL_OCC){
                ui->LB_OUTLET_M_2_CELL_1->setText(OUTLET_DATA[1].cell_occupy_pin[0]);
            }else{
                ui->LB_OUTLET_M_2_CELL_1->setText("-");
            }
            if(OUTLET_DATA[1].cell_state[1] == CELL_OCC){
                ui->LB_OUTLET_M_2_CELL_2->setText(OUTLET_DATA[1].cell_occupy_pin[1]);
            }else{
                ui->LB_OUTLET_M_2_CELL_2->setText("-");
            }
            if(OUTLET_DATA[1].cell_state[2] == CELL_OCC){
                ui->LB_OUTLET_M_2_CELL_3->setText(OUTLET_DATA[1].cell_occupy_pin[2]);
            }else{
                ui->LB_OUTLET_M_2_CELL_3->setText("-");
            }
        }else{
            SetLEColor(ui->LE_OUTLET_M_2_DOOR_OPEN, COLOR_UNDETERMINED);
            SetLEColor(ui->LE_OUTLET_M_2_DOOR_CLOSE, COLOR_UNDETERMINED);
            SetLEColor(ui->LE_OUTLET_M_2_CUP_DETECT, COLOR_UNDETERMINED);
            ui->LB_OUTLET_M_2_CELL_1->setText("-");
            ui->LB_OUTLET_M_2_CELL_2->setText("-");
            ui->LB_OUTLET_M_2_CELL_3->setText("-");
        }
    }
}

void MainWindow::Update_Dev_KioskInfo(){
    if(kiosk->connection_status == false){
        SetBTNColor(ui->BTN_DEV_INFO_KIOSK, COLOR_WEAKBAD);
        ui->LB_KIOSK_BLOCK_ORDER->setText("주문차단");
    }else{
        SetBTNColor(ui->BTN_DEV_INFO_KIOSK, COLOR_GOOD);
        if(kiosk->block_order == true){
            ui->LB_KIOSK_BLOCK_ORDER->setText("주문차단");
        }else{
            ui->LB_KIOSK_BLOCK_ORDER->setText("주문허용");
        }
    }
}

QString MainWindow::DesToIng(QString des){
    if(des == "컵"){
        return "CUP";
    }else if(des == "얼음"){
        return "ICE";
    }else if(des == "탄산"){
        return "SODA";
    }else if(des == "냉수"){
        return "COLD";
    }else if(des == "온수"){
        return "HOT";
    }else if(des == "설탕시럽"){
        return "SYRUP_1";
    }else if(des == "헤이즐넛시럽"){
        return "SYRUP_2";
    }else if(des == "바닐라시럽"){
        return "SYRUP_3";
    }else if(des == "초코시럽"){
        return "SYRUP_4";
    }else if(des == "카라멜시럽"){
        return "SYRUP_5";
    }else if(des == "딸기시럽"){
        return "SYRUP_6";
    }else if(des == "청포도시럽"){
        return "SYRUP_7";
    }else if(des == "자몽시럽"){
        return "SYRUP_8";
    }else if(des == "레몬시럽"){
        return "SYRUP_9";
    }else if(des == "복숭아시럽"){
        return "SYRUP_10";
    }else if(des == "흑당시럽"){
        return "SYRUP_11";
    }else if(des == "얼그레이시럽"){
        return "SYRUP_12";
    }else if(des == "커피/우유"){
        return "COFFEE";
    }else
        return "UNKNOWN";
}
QString MainWindow::IngToDes(QString ing){
    if(ing == "CUP"){
        return "컵";
    }else if(ing == "ICE"){
        return "얼음";
    }else if(ing == "SODA"){
        return "탄산";
    }else if(ing == "COLD"){
        return "냉수";
    }else if(ing == "HOT"){
        return "온수";
    }else if(ing == "SYRUP_1"){
        return "설탕시럽";
    }else if(ing == "SYRUP_2"){
        return "헤이즐넛시럽";
    }else if(ing == "SYRUP_3"){
        return "바닐라시럽";
    }else if(ing == "SYRUP_4"){
        return "초코시럽";
    }else if(ing == "SYRUP_5"){
        return "카라멜시럽";
    }else if(ing == "SYRUP_6"){
        return "딸기시럽";
    }else if(ing == "SYRUP_7"){
        return "청포도시럽";
    }else if(ing == "SYRUP_8"){
        return "자몽시럽";
    }else if(ing == "SYRUP_9"){
        return "레몬시럽";
    }else if(ing == "SYRUP_10"){
        return "복숭아시럽";
    }else if(ing == "SYRUP_11"){
        return "흑당시럽";
    }else if(ing == "SYRUP_12"){
        return "얼그레이시럽";
    }else if(ing == "COFFEE"){
        return "커피/우유";
    }else
        return "불명";
}
void MainWindow::Update_Dev_StockInfo(){
    ui->PB_CUP_1m->setValue(stock->stock["PAPER_CUP_1"].current);
    ui->PB_CUP_2m->setValue(stock->stock["PP_CUP_1"].current);

    ui->PB_SYRUP_1m->setValue(stock->stock["SYRUP_1"].current);
    ui->PB_SYRUP_2m->setValue(stock->stock["SYRUP_2"].current);
    ui->PB_SYRUP_3m->setValue(stock->stock["SYRUP_3"].current);
    ui->PB_SYRUP_4m->setValue(stock->stock["SYRUP_4"].current);
    ui->PB_SYRUP_5m->setValue(stock->stock["SYRUP_5"].current);
    ui->PB_SYRUP_6m->setValue(stock->stock["SYRUP_6"].current);
    ui->PB_SYRUP_7m->setValue(stock->stock["SYRUP_7"].current);
    ui->PB_SYRUP_8m->setValue(stock->stock["SYRUP_8"].current);
    ui->PB_SYRUP_9m->setValue(stock->stock["SYRUP_9"].current);
    ui->PB_SYRUP_10m->setValue(stock->stock["SYRUP_10"].current);
    ui->PB_SYRUP_11m->setValue(stock->stock["SYRUP_11"].current);
    ui->PB_SYRUP_12m->setValue(stock->stock["SYRUP_12"].current);

    if(stock->stock["PAPER_CUP_1"].current > stock->stock["PAPER_CUP_1"].maximum/2){
        ui->PB_CUP_1m->setStyleSheet("QProgressBar::chunk{background-color: #40C86D;}");
    }else if(stock->stock["PAPER_CUP_1"].current > stock->stock["PAPER_CUP_1"].maximum/4){
        ui->PB_CUP_1m->setStyleSheet("QProgressBar::chunk{background-color: #FBC221;}");
    }else{
        ui->PB_CUP_1m->setStyleSheet("QProgressBar::chunk{background-color: #FF4F4F;}");
    }

    if(stock->stock["PAPER_CUP_2"].current > stock->stock["PAPER_CUP_2"].maximum/2){
        ui->PB_CUP_2m->setStyleSheet("QProgressBar::chunk{background-color: #40C86D;}");
    }else if(stock->stock["PAPER_CUP_2"].current > stock->stock["PAPER_CUP_2"].maximum/4){
        ui->PB_CUP_2m->setStyleSheet("QProgressBar::chunk{background-color: #FBC221;}");
    }else{
        ui->PB_CUP_2m->setStyleSheet("QProgressBar::chunk{background-color: #FF4F4F;}");
    }
    if(stock->stock["PP_CUP_1"].current > stock->stock["PP_CUP_1"].maximum/2){
        ui->PB_CUP_3m->setStyleSheet("QProgressBar::chunk{background-color: #40C86D;}");
    }else if(stock->stock["PP_CUP_1"].current > stock->stock["PP_CUP_1"].maximum/4){
        ui->PB_CUP_3m->setStyleSheet("QProgressBar::chunk{background-color: #FBC221;}");
    }else{
        ui->PB_CUP_3m->setStyleSheet("QProgressBar::chunk{background-color: #FF4F4F;}");
    }
    if(stock->stock["PP_CUP_2"].current > stock->stock["PP_CUP_2"].maximum/2){
        ui->PB_CUP_4m->setStyleSheet("QProgressBar::chunk{background-color: #40C86D;}");
    }else if(stock->stock["PP_CUP_2"].current > stock->stock["PP_CUP_2"].maximum/4){
        ui->PB_CUP_4m->setStyleSheet("QProgressBar::chunk{background-color: #FBC221;}");
    }else{
        ui->PB_CUP_4m->setStyleSheet("QProgressBar::chunk{background-color: #FF4F4F;}");
    }

    if(stock->stock["SYRUP_1"].current > stock->stock["SYRUP_1"].maximum/2){
        ui->PB_SYRUP_1m->setStyleSheet("QProgressBar::chunk{background-color: #40C86D;}");
    }else if(stock->stock["SYRUP_1"].current > stock->stock["SYRUP_1"].maximum/4){
        ui->PB_SYRUP_1m->setStyleSheet("QProgressBar::chunk{background-color: #FBC221;}");
    }else{
        ui->PB_SYRUP_1m->setStyleSheet("QProgressBar::chunk{background-color: #FF4F4F;}");
    }
    if(stock->stock["SYRUP_2"].current > stock->stock["SYRUP_2"].maximum/2){
        ui->PB_SYRUP_2m->setStyleSheet("QProgressBar::chunk{background-color: #40C86D;}");
    }else if(stock->stock["SYRUP_2"].current > stock->stock["SYRUP_2"].maximum/4){
        ui->PB_SYRUP_2m->setStyleSheet("QProgressBar::chunk{background-color: #FBC221;}");
    }else{
        ui->PB_SYRUP_2m->setStyleSheet("QProgressBar::chunk{background-color: #FF4F4F;}");
    }
    if(stock->stock["SYRUP_3"].current > stock->stock["SYRUP_3"].maximum/2){
        ui->PB_SYRUP_3m->setStyleSheet("QProgressBar::chunk{background-color: #40C86D;}");
    }else if(stock->stock["SYRUP_3"].current > stock->stock["SYRUP_3"].maximum/4){
        ui->PB_SYRUP_3m->setStyleSheet("QProgressBar::chunk{background-color: #FBC221;}");
    }else{
        ui->PB_SYRUP_3m->setStyleSheet("QProgressBar::chunk{background-color: #FF4F4F;}");
    }
    if(stock->stock["SYRUP_4"].current > stock->stock["SYRUP_4"].maximum/2){
        ui->PB_SYRUP_4m->setStyleSheet("QProgressBar::chunk{background-color: #40C86D;}");
    }else if(stock->stock["SYRUP_4"].current > stock->stock["SYRUP_4"].maximum/4){
        ui->PB_SYRUP_4m->setStyleSheet("QProgressBar::chunk{background-color: #FBC221;}");
    }else{
        ui->PB_SYRUP_4m->setStyleSheet("QProgressBar::chunk{background-color: #FF4F4F;}");
    }
    if(stock->stock["SYRUP_5"].current > stock->stock["SYRUP_5"].maximum/2){
        ui->PB_SYRUP_5m->setStyleSheet("QProgressBar::chunk{background-color: #40C86D;}");
    }else if(stock->stock["SYRUP_5"].current > stock->stock["SYRUP_5"].maximum/4){
        ui->PB_SYRUP_5m->setStyleSheet("QProgressBar::chunk{background-color: #FBC221;}");
    }else{
        ui->PB_SYRUP_5m->setStyleSheet("QProgressBar::chunk{background-color: #FF4F4F;}");
    }
    if(stock->stock["SYRUP_6"].current > stock->stock["SYRUP_6"].maximum/2){
        ui->PB_SYRUP_6m->setStyleSheet("QProgressBar::chunk{background-color: #40C86D;}");
    }else if(stock->stock["SYRUP_6"].current > stock->stock["SYRUP_6"].maximum/4){
        ui->PB_SYRUP_6m->setStyleSheet("QProgressBar::chunk{background-color: #FBC221;}");
    }else{
        ui->PB_SYRUP_6m->setStyleSheet("QProgressBar::chunk{background-color: #FF4F4F;}");
    }
    if(stock->stock["SYRUP_7"].current > stock->stock["SYRUP_7"].maximum/2){
        ui->PB_SYRUP_7m->setStyleSheet("QProgressBar::chunk{background-color: #40C86D;}");
    }else if(stock->stock["SYRUP_7"].current > stock->stock["SYRUP_7"].maximum/4){
        ui->PB_SYRUP_7m->setStyleSheet("QProgressBar::chunk{background-color: #FBC221;}");
    }else{
        ui->PB_SYRUP_7m->setStyleSheet("QProgressBar::chunk{background-color: #FF4F4F;}");
    }
    if(stock->stock["SYRUP_8"].current > stock->stock["SYRUP_8"].maximum/2){
        ui->PB_SYRUP_8m->setStyleSheet("QProgressBar::chunk{background-color: #40C86D;}");
    }else if(stock->stock["SYRUP_8"].current > stock->stock["SYRUP_8"].maximum/4){
        ui->PB_SYRUP_8m->setStyleSheet("QProgressBar::chunk{background-color: #FBC221;}");
    }else{
        ui->PB_SYRUP_8m->setStyleSheet("QProgressBar::chunk{background-color: #FF4F4F;}");
    }
    if(stock->stock["SYRUP_9"].current > stock->stock["SYRUP_9"].maximum/2){
        ui->PB_SYRUP_9m->setStyleSheet("QProgressBar::chunk{background-color: #40C86D;}");
    }else if(stock->stock["SYRUP_9"].current > stock->stock["SYRUP_9"].maximum/4){
        ui->PB_SYRUP_9m->setStyleSheet("QProgressBar::chunk{background-color: #FBC221;}");
    }else{
        ui->PB_SYRUP_9m->setStyleSheet("QProgressBar::chunk{background-color: #FF4F4F;}");
    }
    if(stock->stock["SYRUP_10"].current > stock->stock["SYRUP_10"].maximum/2){
        ui->PB_SYRUP_10m->setStyleSheet("QProgressBar::chunk{background-color: #40C86D;}");
    }else if(stock->stock["SYRUP_10"].current > stock->stock["SYRUP_10"].maximum/4){
        ui->PB_SYRUP_10m->setStyleSheet("QProgressBar::chunk{background-color: #FBC221;}");
    }else{
        ui->PB_SYRUP_10m->setStyleSheet("QProgressBar::chunk{background-color: #FF4F4F;}");
    }
    if(stock->stock["SYRUP_11"].current > stock->stock["SYRUP_11"].maximum/2){
        ui->PB_SYRUP_11m->setStyleSheet("QProgressBar::chunk{background-color: #40C86D;}");
    }else if(stock->stock["SYRUP_11"].current > stock->stock["SYRUP_11"].maximum/4){
        ui->PB_SYRUP_11m->setStyleSheet("QProgressBar::chunk{background-color: #FBC221;}");
    }else{
        ui->PB_SYRUP_11m->setStyleSheet("QProgressBar::chunk{background-color: #FF4F4F;}");
    }
    if(stock->stock["SYRUP_12"].current > stock->stock["SYRUP_12"].maximum/2){
        ui->PB_SYRUP_12m->setStyleSheet("QProgressBar::chunk{background-color: #40C86D;}");
    }else if(stock->stock["SYRUP_12"].current > stock->stock["SYRUP_12"].maximum/4){
        ui->PB_SYRUP_12m->setStyleSheet("QProgressBar::chunk{background-color: #FBC221;}");
    }else{
        ui->PB_SYRUP_12m->setStyleSheet("QProgressBar::chunk{background-color: #FF4F4F;}");
    }
}


void MainWindow::ChangeDeviceDialog(DEVICE_DIALOG_ID id){
    setting->hide();
    cup->hide();
    ice->hide();
    coffee->hide();
    robot->hide();
    syrup->hide();
    monitor->hide();
    door->hide();
    barcode->hide();
    soda->hide();
    outlet->hide();
    kiosk->hide();
    stock->hide();


    switch(id){
    case DEV_DIALOG_ID_SETTING:
        setting->show();
        break;
    case DEV_DIALOG_ID_CUP:
        cup->show();
        break;
    case DEV_DIALOG_ID_ICE:
        ice->show();
        break;
    case DEV_DIALOG_ID_COFFEE:
        coffee->show();
        break;
    case DEV_DIALOG_ID_ROBOT:
        robot->show();
        break;
    case DEV_DIALOG_ID_SYRUP:
        syrup->show();
        break;
    case DEV_DIALOG_ID_MONITOR:
        monitor->show();
        break;
    case DEV_DIALOG_ID_DOOR:
        door->show();
        break;
    case DEV_DIALOG_ID_BARCODE:
        barcode->show();
        break;
    case DEV_DIALOG_ID_OUTLET:
        outlet->show();
        break;
    case DEV_DIALOG_ID_KIOSK:
        kiosk->show();
        break;
    case DEV_DIALOG_ID_STOCK:
        stock->show();
        break;
    case DEV_DIALOG_ID_SODA:
        soda->show();
        break;
    default:
        break;
    }
}

void MainWindow::on_BTN_DEV_INFO_CUP_clicked(){
    logger->write("[USER INPUT] Button Click : CUP INFO");
    ChangeDeviceDialog(DEV_DIALOG_ID_CUP);
}

void MainWindow::on_BTN_DEV_INFO_COFFEE_clicked(){
    logger->write("[USER INPUT] Button Click : COFFEE INFO");
    ChangeDeviceDialog(DEV_DIALOG_ID_COFFEE);
}

void MainWindow::on_BTN_DEV_INFO_ICE_1_clicked(){
    logger->write("[USER INPUT] Button Click : ICE INFO");
    ChangeDeviceDialog(DEV_DIALOG_ID_ICE);
}

void MainWindow::on_BTN_DEV_INFO_ROBOT_clicked(){
    logger->write("[USER INPUT] Button Click : ROBOT INFO");
    ChangeDeviceDialog(DEV_DIALOG_ID_ROBOT);
}

void MainWindow::on_BTN_DEV_INFO_SYRUP_clicked(){
    logger->write("[USER INPUT] Button Click : SYRUP INFO");
    ChangeDeviceDialog(DEV_DIALOG_ID_SYRUP);
}

void MainWindow::on_BTN_DEV_INFO_MONITOR_clicked(){
    logger->write("[USER INPUT] Button Click : MONITOR INFO");
    ChangeDeviceDialog(DEV_DIALOG_ID_MONITOR);
}

void MainWindow::on_BTN_DEV_INFO_DOOR_clicked(){
    logger->write("[USER INPUT] Button Click : DOOR INFO");
    ChangeDeviceDialog(DEV_DIALOG_ID_DOOR);
}

void MainWindow::on_BTN_DEV_INFO_BARCODE_clicked(){
    logger->write("[USER INPUT] Button Click : BARCODE INFO");
    ChangeDeviceDialog(DEV_DIALOG_ID_BARCODE);
}

void MainWindow::on_BTN_DEV_INFO_OUTLET_clicked(){
    logger->write("[USER INPUT] Button Click : OUTLET INFO");
    ChangeDeviceDialog(DEV_DIALOG_ID_OUTLET);
}

void MainWindow::on_BTN_DEV_INFO_KIOSK_clicked(){
    logger->write("[USER INPUT] Button Click : KIOSK INFO");
    ChangeDeviceDialog(DEV_DIALOG_ID_KIOSK);
}

void MainWindow::on_BTN_DEV_INFO_STOCK_clicked(){
    logger->write("[USER INPUT] Button Click : STOCK INFO");
    ChangeDeviceDialog(DEV_DIALOG_ID_STOCK);
}



void MainWindow::ClearForcedSuperError(){
    lan->SUPER_FATAL_ERROR_CONNECTION_OF_LAN2CAN = 0;

    robot->SUPER_FATAL_ERROR_ROBOT_DATA = 0;
    robot->SUPER_FATAL_ERROR_ROBOT_MISS_COMMAND_WORKING_CHECK = 0;
    outlet->SUPER_FATAL_ERROR_OUTLET_CONNECTION = 0;
    outlet->SUPER_FATAL_ERROR_OUTLET_CONTROL = 0;
    outlet->SUPER_FATAL_ERROR_OUTLET_SENSOR = 0;
    SUPER_FATAL_ERROR_PLATFORM_OPEN = 0;

    PLATFORM_OPENED_WHEN_OPERATING_FLAG = 0;
}

int MainWindow::CheckDeviceConnection(){
    if(robot->cmdConnectionStatus == false){
        return 1;
    }
    if(robot->dataConnectionStatus == false){
        return 2;
    }
    if(lan->sockConnectionStatus == false){
        return 3;
    }
//    if(monitor->displayConnectionStatus == false){
//        return 4;
//    }
    return 0;
}

void MainWindow::on_BTN_DO_INITIALIZING_clicked(){
    QMessageBox::StandardButton msgBox;
    msgBox = QMessageBox::question(this,"초기화 시작",
                                   "초기화를 시작하시겠습니까?\n"
                                   "모든 음료 대기열이 사라집니다.");

    if(msgBox == QMessageBox::Yes){
        logger->write("[USER INPUT] INIT START");
        OP_STATUS_INITIALIZING = PLATFORM_INIT_START;
    }else{
        logger->write("[USER INPUT] INIT START CANCLE");
    }
}

void MainWindow::on_BTN_DO_OPERATING_clicked(){
    // Operate normally
    QMessageBox::StandardButton msgBox;
    msgBox = QMessageBox::question(this,"영업 시작",
                                   "영업을 시작하시겠습니까?\n");

    if(msgBox == QMessageBox::Yes){
        logger->write("[USER INPUT] PLATFORM OPERATION START");
        OP_STATUS_OPERATING = PLATFORM_OPERATION_START;
    }else{
        logger->write("[USER INPUT] PLATFORM OPERATION CANCLE");
    }
}

void MainWindow::on_BTN_STOP_OPERATING_clicked(){
    logger->write("[USER INPUT] DO STOP ORERATING");
    OP_COMMAND_STOP_OPERATING = 1;
}

void MainWindow::on_BTN_CANCEL_STOP_clicked(){
    logger->write("[USER INPUT] CANCEL STOP ORERATING");
    OP_COMMAND_STOP_OPERATING = 0;
}

void MainWindow::on_BTN_RESUME_clicked(){
    logger->write("[USER INPUT] RESUME ORERATION");
    PLATFORM_OPENED_WHEN_OPERATING_FLAG = 0;
}


void MainWindow::on_BTN_SETTING_clicked(){
    logger->write("[USER INPUT] Button Click : SETTING");
    ChangeDeviceDialog(DEV_DIALOG_ID_SETTING);
    setting->is_lock = true;
}

void MainWindow::on_BTN_EXIT_clicked(){
    QMessageBox msgBox;
    msgBox.setText("프로그램을 종료하시겠습니까?");
    msgBox.setWindowTitle("프로그램 종료");
    msgBox.setStandardButtons(QMessageBox::Apply | QMessageBox::Retry | QMessageBox::Cancel);
    msgBox.setButtonText(QMessageBox::Apply, "종료");
    msgBox.setButtonText(QMessageBox::Retry, "다시 시작");
    msgBox.setButtonText(QMessageBox::Cancel, "취소");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setStyleSheet("QLabel {font: 15pt \"함초롬돋움\";}"
                         "QComboBox{font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}\n"
                         "QPushButton{\n	border-width: 2px; min-width: 100px; min-height: 50px; font: 13pt \"함초롬돋움\";\n	background-color: #ffffff\n}"
                         "QLineEdit{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}");
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");

    int ret = msgBox.exec();
    if(ret == QMessageBox::Apply){
        logger->write("[USER INPUT] EXIT : TERMINATE PROGRAM");
        QApplication::quit();
    }else if(ret == QMessageBox::Retry){
        logger->write("[USER INPUT] EXIT : RESTART PROGRAM");
        logger->write("[SYSTEM] RESTART CORE PROGRAM CLICKED");
        QProcess::startDetached(QApplication::applicationFilePath());
        QApplication::exit(12);
    }else{
        logger->write("[USER INPUT] EXIT : CANCEL");

    }
}

void MainWindow::on_BTN_UI_LOCK_clicked(){
    if(IS_UI_LOCK == true){
        logger->write("[USER INPUT] UI : UNLOCK");
        IS_UI_LOCK = false;
        ui->BTN_UI_LOCK->setIcon(QIcon(":/build/image/unlockw.png"));
    }else{
        logger->write("[USER INPUT] UI : LOCK");
        IS_UI_LOCK = true;
        ui->BTN_UI_LOCK->setIcon(QIcon(":/build/image/lockw.png"));
    }
}

void MainWindow::on_BTN_CUP_ADD_DONE_clicked(){
    if(schedule->action_state == ACTION_STATE_CUP_ERROR){
        schedule->action_state = ACTION_STATE_CUP_RECOVER;
        logger->write("[USER INPUT] Button Click : Cup Add Done");
    }
}



void MainWindow::on_BTN_ERROR_clicked()
{
    error->UpdateError();
    error->UpdateMenuAvailable();
    error->show();
}


void MainWindow::on_BTN_MENU_LOAD_clicked()
{
    ui->TW_MENU->clear();
    ui->TW_RECIPE->clear();

    ui->TW_MENU->setRowCount(0);
    ui->TW_RECIPE->setRowCount(0);

    QList<QString> ids = stock->menu.keys();
    for(int i=0; i<ids.size(); i++){
        ui->TW_MENU->insertRow(ui->TW_MENU->rowCount());
        int index = ui->TW_MENU->rowCount() -1;
        ui->TW_MENU->setItem(index, 0, new QTableWidgetItem(stock->menu[ids[i]].menu_id));
        ui->TW_MENU->setItem(index, 1, new QTableWidgetItem(stock->menu[ids[i]].menu_name));
    }
}


void MainWindow::on_BTN_MENU_ADD_clicked()
{
    ques_recipe = new DialogRecipe();
    ques_recipe->AddMenu();
    connect(ques_recipe, SIGNAL(add_menu(ST_MENU_INFO)), this, SLOT(addmenu(ST_MENU_INFO)));
    connect(ques_recipe, SIGNAL(cancel()),this, SLOT(cancelrecipe()));
    IS_UI_LOCK = true;
    ui->BTN_UI_LOCK->setIcon(QIcon(":/build/image/lockw.png"));
}

void MainWindow::on_BTN_MENU_EDIT_clicked()
{
    ques_recipe = new DialogRecipe();
    ques_recipe->EditMenu(ui->TW_MENU->currentRow(), ui->TW_MENU->item(ui->TW_MENU->currentRow(),0)->text(),ui->TW_MENU->item(ui->TW_MENU->currentRow(),1)->text());
    connect(ques_recipe, SIGNAL(edit_menu(int,ST_MENU_INFO)), this, SLOT(editmenu(int,ST_MENU_INFO)));
    connect(ques_recipe, SIGNAL(cancel()),this, SLOT(cancelrecipe()));
    IS_UI_LOCK = true;
    ui->BTN_UI_LOCK->setIcon(QIcon(":/build/image/lockw.png"));
}

void MainWindow::on_BTN_RECIPE_SAVE_clicked()
{
    //메시지 알람
    QMessageBox::StandardButton msgBox;
    msgBox = QMessageBox::question(this, "레시피 저장","저장하시겠습니까?\n"
                                    "레시피 저장 후 [DB저장] 버튼을 눌러주셔야 적용됩니다.\n"
                                   "[DB저장]을 누르지 않고 프로그램이 종료되면 모든 수정사항이 사라집니다.");

    if(msgBox == QMessageBox::Yes){
        //값 확인
        V_RECIPE new_recipe;
        for(int i=0; i<ui->TW_RECIPE->rowCount(); i++){
            ST_RECIPE_STEP temp;
            temp.ingredient = DesToIng(ui->TW_RECIPE->item(i,0)->text());
            temp.amount = ui->TW_RECIPE->item(i,1)->text();

            // CUP 존재유무
            if(i==0 && temp.ingredient != "CUP"){
                QMessageBox::warning(this, "저장 실패", "레시피 첫 번째 항목은 반드시 CUP이어야 합니다.\n"
                                     "레시피를 다시 불러와 수정해주십시오.");
                return;
            }
            // INGREDIENT 중복 체크, 순서
            for(int j=0; j<new_recipe.size(); j++){
                if(temp.ingredient == new_recipe[j].ingredient){
                    QMessageBox::warning(this, "저장 실패", "중복되는 항목이 있습니다 : "+temp.ingredient);
                    return;
                }
                if(temp.ingredient == "ICE"){
                    if(new_recipe[j].ingredient == "COFFEE" || new_recipe[j].ingredient == "SODA" || new_recipe[j].ingredient == "COLD" || new_recipe[j].ingredient == "HOT"){
                        QMessageBox::warning(this, "저장 실패", "ICE는 반드시 COFFEE, SODA, COLD, HOT 보다 위에 있어야 합니다.");
                        return;
                    }
                }else if(temp.ingredient == "COFFEE"){
                    if(new_recipe[j].ingredient == "SODA"){
                        QMessageBox::warning(this, "저장 실패", "COFFEE와 SODA(탄산수)는 함께 배출할 수 없습니다.");
                        return;
                    }
                    if((temp.amount == "LH1" || temp.amount == "LH2" || temp.amount == "LH3" || temp.amount == "PLH1" || temp.amount == "PLH2" || temp.amount == "MFH1" || temp.amount == "MFH2") && new_recipe[j].ingredient == "ICE"){
                        QMessageBox::warning(this, "저장 실패", "ICE와 COFFEE의 뜨거운메뉴(LH1, LH2, LH3, PLH1, PLH2, MFH1, MFH2)는 함께 배출할 수 없습니다.");
                        return;
                    }
                }else if(temp.ingredient == "SODA"){//SODA
                    if(new_recipe[j].ingredient == "COFFEE"){
                        QMessageBox::warning(this, "저장 실패", "COFFEE와 SODA(탄산수)는 함께 배출할 수 없습니다.");
                        return;
                    }
                }else if(temp.ingredient.left(5) == "SYRUP"){
                    if(new_recipe[j].ingredient == "SODA"){
                        QMessageBox::warning(this, "저장 실패", "SODA(탄산수)는 기타 다른 시럽 보다 위에 있어야 합니다.");
                        return;
                    }
                    if(new_recipe[j].ingredient == "COFFEE"){
                        QMessageBox::warning(this, "저장 실패", "SYRUP은 COFFEE 보다 위에 있어야 합니다.");
                        return;
                    }
                }
            }

            new_recipe.push_back(temp);
        }

        ST_RECIPE_STEP temp;
        temp.ingredient = "OUTLET";
        temp.amount = "1";
        new_recipe.push_back(temp);

        //저장
        is_recipe_changed = false;
        plog->write("[RECIPE] SAVE RECIPE : "+ui->TW_MENU->item(ui->TW_MENU->currentRow(),1)->text());
        stock->SaveRecipe(ui->TW_MENU->item(ui->TW_MENU->currentRow(),0)->text(),new_recipe);
    }else{

    }
}

void MainWindow::on_BTN_RECIPE_DELETE_clicked()
{
    if(ui->TW_RECIPE->currentRow() > 0){
        ui->TW_RECIPE->removeRow(ui->TW_RECIPE->currentRow());
        is_recipe_changed = true;
    }
}

void MainWindow::on_BTN_RECIPE_ADD_clicked()
{
    ques_recipe = new DialogRecipe();
    ques_recipe->AddIngredient();
    connect(ques_recipe, SIGNAL(add_ingredient(ST_RECIPE_STEP)), this, SLOT(addingredient(ST_RECIPE_STEP)));
    connect(ques_recipe, SIGNAL(cancel()),this, SLOT(cancelrecipe()));
    IS_UI_LOCK = true;
    ui->BTN_UI_LOCK->setIcon(QIcon(":/build/image/lockw.png"));
}

void MainWindow::on_BTN_RECIPE_UP_clicked()
{
    if(ui->TW_RECIPE->currentRow() < 2){
        QMessageBox::information(this, "에러", "더 이상 위로 올릴 수 없습니다.");
    }else{
        QString temp_ingredient;
        QString temp_amount;
        temp_ingredient = ui->TW_RECIPE->item(ui->TW_RECIPE->currentRow(),0)->text();
        temp_amount = ui->TW_RECIPE->item(ui->TW_RECIPE->currentRow(),1)->text();
        ui->TW_RECIPE->setItem(ui->TW_RECIPE->currentRow(), 0, new QTableWidgetItem(ui->TW_RECIPE->item(ui->TW_RECIPE->currentRow()-1,0)->text()));
        ui->TW_RECIPE->setItem(ui->TW_RECIPE->currentRow(), 1, new QTableWidgetItem(ui->TW_RECIPE->item(ui->TW_RECIPE->currentRow()-1,1)->text()));
        ui->TW_RECIPE->setItem(ui->TW_RECIPE->currentRow()-1, 0, new QTableWidgetItem(temp_ingredient));
        ui->TW_RECIPE->setItem(ui->TW_RECIPE->currentRow()-1, 1, new QTableWidgetItem(temp_amount));
        ui->TW_RECIPE->setCurrentItem(ui->TW_RECIPE->item(ui->TW_RECIPE->currentRow()-1, ui->TW_RECIPE->currentColumn()));
        is_recipe_changed = true;
    }
}

void MainWindow::on_BTN_RECIPE_DOWN_clicked()
{
    if(ui->TW_RECIPE->currentRow() > ui->TW_RECIPE->rowCount() - 2){
        QMessageBox::information(this, "에러", "더 이상 내릴 수 없습니다.");
    }else{
        QString temp_ingredient;
        QString temp_amount;
        temp_ingredient = ui->TW_RECIPE->item(ui->TW_RECIPE->currentRow(),0)->text();
        temp_amount = ui->TW_RECIPE->item(ui->TW_RECIPE->currentRow(),1)->text();
        ui->TW_RECIPE->setItem(ui->TW_RECIPE->currentRow(), 0, new QTableWidgetItem(ui->TW_RECIPE->item(ui->TW_RECIPE->currentRow()+1,0)->text()));
        ui->TW_RECIPE->setItem(ui->TW_RECIPE->currentRow(), 1, new QTableWidgetItem(ui->TW_RECIPE->item(ui->TW_RECIPE->currentRow()+1,1)->text()));
        ui->TW_RECIPE->setItem(ui->TW_RECIPE->currentRow()+1, 0, new QTableWidgetItem(temp_ingredient));
        ui->TW_RECIPE->setItem(ui->TW_RECIPE->currentRow()+1, 1, new QTableWidgetItem(temp_amount));
        ui->TW_RECIPE->setCurrentItem(ui->TW_RECIPE->item(ui->TW_RECIPE->currentRow()+1, ui->TW_RECIPE->currentColumn()));
        is_recipe_changed = true;
    }
}


void MainWindow::on_TW_MENU_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    ui->TW_RECIPE->clear();
    ui->TW_RECIPE->setRowCount(0);
    is_recipe_changed = false;

    if(ui->TW_MENU->rowCount() > 0 && currentRow > -1){
        QString menu_id = ui->TW_MENU->item(currentRow,0)->text();

        if(stock->menu[menu_id].recipe.size() == 0){
            ST_RECIPE_STEP temp;
            temp.ingredient = "CUP";
            temp.amount = "HOT";
            stock->menu[menu_id].recipe.push_back(temp);
        }

        V_RECIPE recipe = stock->menu[menu_id].recipe;
        for(int i=0; i<recipe.size(); i++){
            if(recipe[i].ingredient != "OUTLET"){
                ui->TW_RECIPE->insertRow(ui->TW_RECIPE->rowCount());
                int index = ui->TW_RECIPE->rowCount() -1;
                ui->TW_RECIPE->setItem(index, 0, new QTableWidgetItem(IngToDes(recipe[i].ingredient)));
                ui->TW_RECIPE->setItem(index, 1, new QTableWidgetItem(recipe[i].amount));
            }
        }

    }
}


void MainWindow::on_BTN_MENU_SAVE_clicked()
{
    //Backup origin File
    QFile::copy("DB/recipe","DB/recipe_backup"+QDateTime().currentDateTime().toString("yymmddhhmmss"));

    //Save Recipe
    if(is_recipe_changed){
        QMessageBox::warning(this, "저장 실패", "레시피에 수정사항이 있습니다.\n"
                             "먼저 [레시피저장]버튼을 눌러 레시피를 저장해주세요.");
        return;
    }


    //Check Value(MENU)
    QVector<ST_MENU> menu_list;
    for(int i=0; i<ui->TW_MENU->rowCount(); i++){
        ST_MENU temp;
        temp.menu_id = ui->TW_MENU->item(i,0)->text();
        temp.menu_name = ui->TW_MENU->item(i,1)->text();
        temp.recipe = stock->menu[temp.menu_id].recipe;

        //ID 중복 체크
        bool IsDuplication = false;
        for(int j=0; j<menu_list.size(); j++){
            if(menu_list[j].menu_id == temp.menu_id){
                IsDuplication = true;
                break;
            }
        }
        if(IsDuplication){
            QMessageBox::warning(this, "저장 실패", "중복 된 MENU ID ("+temp.menu_id+")");
            return;
        }

        menu_list.push_back(temp);


    }
    //Save
    stock->SaveDatabase(menu_list);

}
void MainWindow::on_BTN_RECIPE_EDIT_clicked()
{
    if(ui->TW_RECIPE->rowCount() > 0){
        int curRow = ui->TW_RECIPE->currentRow();
        if(curRow == 0){
            QMessageBox::warning(this,"레시피 수정","해당 재료는 수정할 수 없습니다.");
        }else if(curRow != -1){
            ST_RECIPE_STEP step;
            step.ingredient = DesToIng(ui->TW_RECIPE->item(curRow, 0)->text());
            step.amount = ui->TW_RECIPE->item(curRow,1)->text();
            ques_recipe = new DialogRecipe();
            ques_recipe->EditIngredient(curRow,step);
            connect(ques_recipe, SIGNAL(edit_ingredient(int,ST_RECIPE_STEP)), this, SLOT(editingredient(int,ST_RECIPE_STEP)));
            connect(ques_recipe, SIGNAL(cancel()),this, SLOT(cancelrecipe()));
        }
    }
}

void MainWindow::cancelrecipe(){
    IS_UI_LOCK = false;
    ui->BTN_UI_LOCK->setIcon(QIcon(":/build/image/unlockw.png"));
    is_recipe_changed = false;
    ques_recipe->deleteLater();
}

void MainWindow::addmenu(ST_MENU_INFO menu){
    IS_UI_LOCK = false;
    ui->BTN_UI_LOCK->setIcon(QIcon(":/build/image/unlockw.png"));
    ui->TW_MENU->insertRow(ui->TW_MENU->rowCount());
    ui->TW_MENU->setItem(ui->TW_MENU->rowCount()-1, 0, new QTableWidgetItem(menu.menu_id));
    ui->TW_MENU->setItem(ui->TW_MENU->rowCount()-1, 1, new QTableWidgetItem(menu.menu_name));
    ques_recipe->deleteLater();
}

void MainWindow::editmenu(int index, ST_MENU_INFO menu){
    IS_UI_LOCK = false;
    ui->BTN_UI_LOCK->setIcon(QIcon(":/build/image/unlockw.png"));
    ui->TW_MENU->setItem(index, 0, new QTableWidgetItem(menu.menu_id));
    ui->TW_MENU->setItem(index, 1, new QTableWidgetItem(menu.menu_name));
    ques_recipe->deleteLater();
}

void MainWindow::addingredient(ST_RECIPE_STEP ingredient){
    IS_UI_LOCK = false;
    ui->BTN_UI_LOCK->setIcon(QIcon(":/build/image/unlockw.png"));
    ui->TW_RECIPE->insertRow(ui->TW_RECIPE->rowCount());
    ui->TW_RECIPE->setItem(ui->TW_RECIPE->rowCount()-1, 0, new QTableWidgetItem(IngToDes(ingredient.ingredient)));
    ui->TW_RECIPE->setItem(ui->TW_RECIPE->rowCount()-1, 1, new QTableWidgetItem(ingredient.amount));
    ques_recipe->deleteLater();
    is_recipe_changed = true;
}

void MainWindow::editingredient(int index, ST_RECIPE_STEP ingredient){
    IS_UI_LOCK = false;
    ques_recipe->deleteLater();
    ui->BTN_UI_LOCK->setIcon(QIcon(":/build/image/unlockw.png"));
    ui->TW_RECIPE->setItem(index, 0, new QTableWidgetItem(IngToDes(ingredient.ingredient)));
    ui->TW_RECIPE->setItem(index, 1, new QTableWidgetItem(ingredient.amount));
    is_recipe_changed = true;
}
void MainWindow::on_BTN_MENU_DELETE_clicked()
{
    if(ui->TW_MENU->currentRow() > -1){
        QMessageBox::StandardButton msgBox;
        msgBox = QMessageBox::question(this, "메뉴 삭제","선택된 메뉴를 정말 삭제하시겠습니까?\n"
                                       "삭제하신 후 [DB저장] 버튼을 눌러 저장해주세요.\n"
                                        "저장되지 않은 항목은 [불러오기]시, 모두 복원됩니다.");

        if(msgBox == QMessageBox::Yes){
            ui->TW_MENU->removeRow(ui->TW_MENU->currentRow());
        }
    }
}


void MainWindow::on_BTN_DEV_INFO_SODA_clicked()
{
    logger->write("[USER INPUT] Button Click : SODA INFO");
    ChangeDeviceDialog(DEV_DIALOG_ID_SODA);
}
