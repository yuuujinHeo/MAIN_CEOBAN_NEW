#include "DialogSetting.h"
#include "ui_DialogSetting.h"
#include <QTableWidget>
#include <QTabWidget>
#include "GlobalHeader.h"
#include "Scheduler.h"
#include "DialogOutlet.h"
extern Scheduler *pschedule;
extern RBLAN2CAN *plan;
extern Logger *plog;


DialogSetting::DialogSetting(QWidget *parent, DialogStock *_stock, DialogRobot *_robot, DialogCupDispenser *_cup,
                             DialogCoffee *_coffee, DialogIceDispenser *_ice,
                             DialogSyrup *_syrup, DialogOutlet *_outlet,
                             DialogBarcode *_barcode, DialogMonitor *_monitor,
                             DialogIcecream *_icecream, DialogSlush *_slush) :
    QDialog(parent), stock(_stock), robot(_robot), cup(_cup),
    coffee(_coffee), ice(_ice),
    syrup(_syrup), outlet(_outlet),
    barcode(_barcode), monitor(_monitor),
    icecream(_icecream), slush(_slush),
    ui(new Ui::DialogSetting)
{
    ui->setupUi(this);
    is_lock = true;

#ifdef ICECREAM_VER
    ui->GB_SETTING->setStyleSheet("QGroupBox  {\n    margin-top: 10px;"
                                  "	font: 20pt \"함초롬돋움\";\n}\n\nQGroupBox::title  {"
                                                     "    subcontrol-origin: margin;"
                                                     "    subcontrol-position: top center;"
                                                     "    padding: 10px 8000px 10px 8000px;"
                                                     "    background-color: #FFC4D8;"
                                                     "    color: rgb(255, 255, 255);}"
                                                     "QLabel {\n	font: 10pt \"함초롬돋움\";\n}"
                                                    "QComboBox{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}\nQPushButton{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}"
                                                    "QLineEdit{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}");
    ui->TW_SETTING->removeTab(0);
#else
    ui->GB_SETTING->setStyleSheet("QGroupBox  {\n    margin-top: 10px;"
                                  "	font: 20pt \"함초롬돋움\";\n}\n\nQGroupBox::title  {"
                                                     "    subcontrol-origin: margin;"
                                                     "    subcontrol-position: top center;"
                                                     "    padding: 10px 8000px 10px 8000px;"
                                                     "    background-color: #595959;"
                                                     "    color: rgb(255, 255, 255);}"
                                                     "QLabel {\n	font: 10pt \"함초롬돋움\";\n}"
                                                    "QComboBox{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}\nQPushButton{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}"
                                                    "QLineEdit{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}");
    ui->TW_SETTING->removeTab(1);
#endif


    db = QSqlDatabase::addDatabase("QSQLITE", "DB_SETTING");
    db.setDatabaseName(DB_NAME_SETTING);
    db.open();

    LoadDB();

    //TEST MENU
    QStringList tableHeader;
    ui->TW_TEST_MENU->setColumnCount(2);
    tableHeader << "메뉴번호" << "메뉴명";
    ui->TW_TEST_MENU->setHorizontalHeaderLabels(tableHeader);
    SettingTestUI();
    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(400);
}

DialogSetting::~DialogSetting()
{
    delete ui;
}

void DialogSetting::LoadDB(){
    if(!db.open()){
        qDebug() << "Load Recipe Database Fail";
        return;
    }

    QSqlQuery query(db);
    if(query.exec("SELECT * FROM Table_User")){
        setting_info.users.clear();
        while(query.next()){
            setting_info.platform_name = query.value("platform").toString();

            ST_USER temp_user;

            temp_user.name = query.value("manager").toString();
            temp_user.phone = query.value("phone").toString();

            setting_info.users.push_back(temp_user);
        }
    }
    if(query.exec("SELECT * FROM Table_Setting")){
        while(query.next()){
            if(query.value("setting").toString() == "platform_number"){
                setting_info.platform_number = query.value("value").toString();
            }else if(query.value("setting").toString() == "use_alimtalk"){
                setting_info.use_alimtalk = query.value("value").toInt();
            }else if(query.value("setting").toString() == "use_milk"){
                setting_info.use_milk = query.value("value").toInt();
            }
        }
    }
}

void DialogSetting::SettingTestUI(){
    ui->TW_TEST_MENU->setRowCount(stock->menu.size());
    qDebug() << stock->menu.size();

    QStringList menu_ids = stock->menu.keys();
    for(int i=0; i<stock->menu.size(); i++){
        ui->TW_TEST_MENU->setItem(i,0,new QTableWidgetItem(menu_ids[i]));
        ui->TW_TEST_MENU->setItem(i,1,new QTableWidgetItem(stock->menu[menu_ids[i]].menu_name));
    }
}
void DialogSetting::onTimer(){

    if(IS_UI_LOCK){
        ui->GB_SETTING->setEnabled(false);
        is_lock = true;
    }else{
        ui->GB_SETTING->setEnabled(true);
    }

    if(is_lock){
        ui->TW_SETTING->setTabEnabled(1,false);
        ui->TW_SETTING->setTabEnabled(2,false);
        ui->BTN_OPEN_RECIPE->setEnabled(false);
//        ui->BTN_OPEN_RECIPE_2->setEnabled(false);
    }else{
//        ui->TW_SETTING->setTabEnabled(1,true);
        ui->TW_SETTING->setTabEnabled(2,true);
        ui->BTN_OPEN_RECIPE->setEnabled(true);
        ui->BTN_OPEN_RECIPE_2->setEnabled(true);
    }

    if(stock->IsDeviceError("COFFEE")){
        SetLEColor(ui->LE_DEVICE_ERROR_COFFEE, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_COFFEE, COLOR_GOOD);
    }

    if(stock->IsDeviceError("ICE")){
        SetLEColor(ui->LE_DEVICE_ERROR_ICE_1, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_ICE_1, COLOR_GOOD);
    }

    if(stock->IsDeviceError("ICECREAM")){
        SetLEColor(ui->LE_DEVICE_ERROR_ICECREAM, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_ICECREAM, COLOR_GOOD);
    }

    if(stock->IsDeviceError("SLUSH")){
        SetLEColor(ui->LE_DEVICE_ERROR_SLUSH, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_SLUSH, COLOR_GOOD);
    }

    if(stock->IsDeviceError("PAPER_CUP_1")){
        SetLEColor(ui->LE_DEVICE_ERROR_PAPER_CUP_1, COLOR_BAD);
        SetLEColor(ui->LE_DEVICE_ERROR_PAPER_CUP_3, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_PAPER_CUP_1, COLOR_GOOD);
        SetLEColor(ui->LE_DEVICE_ERROR_PAPER_CUP_3, COLOR_GOOD);
    }
    if(stock->IsDeviceError("PP_CUP_1")){
        SetLEColor(ui->LE_DEVICE_ERROR_PP_CUP_1, COLOR_BAD);
        SetLEColor(ui->LE_DEVICE_ERROR_PAPER_CUP_4, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_PP_CUP_1, COLOR_GOOD);
        SetLEColor(ui->LE_DEVICE_ERROR_PAPER_CUP_4, COLOR_GOOD);
    }

    if(outlet->isError(0)){
        SetLEColor(ui->LE_DEVICE_ERROR_OUTLET_1, COLOR_BAD);
        SetLEColor(ui->LE_DEVICE_ERROR_OUTLET_3, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_OUTLET_1, COLOR_GOOD);
        SetLEColor(ui->LE_DEVICE_ERROR_OUTLET_3, COLOR_GOOD);
    }

    if(outlet->isError(1)){
        SetLEColor(ui->LE_DEVICE_ERROR_OUTLET_2, COLOR_BAD);
        SetLEColor(ui->LE_DEVICE_ERROR_OUTLET_4, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_OUTLET_2, COLOR_GOOD);
        SetLEColor(ui->LE_DEVICE_ERROR_OUTLET_4, COLOR_GOOD);
    }

    if(robot->isError()){
        SetLEColor(ui->LE_DEVICE_ERROR_ROBOT_1, COLOR_BAD);
        SetLEColor(ui->LE_DEVICE_ERROR_ROBOT_2, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_ROBOT_1, COLOR_GOOD);
        SetLEColor(ui->LE_DEVICE_ERROR_ROBOT_2, COLOR_GOOD);
    }


    if(SUPER_FATAL_ERROR_PLATFORM_OPEN == 1){
        SetLEColor(ui->LE_SUPER_STOP_PLATFORM_OPEN, COLOR_BAD);
        SetLEColor(ui->LE_SUPER_STOP_PLATFORM_OPEN_2, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_PLATFORM_OPEN, COLOR_GOOD);
        SetLEColor(ui->LE_SUPER_STOP_PLATFORM_OPEN_2, COLOR_GOOD);
    }
    if(plan->SUPER_FATAL_ERROR_CONNECTION_OF_LAN2CAN == 1){
        SetLEColor(ui->LE_SUPER_STOP_BOARD_CONNECTION, COLOR_BAD);
        SetLEColor(ui->LE_SUPER_STOP_BOARD_CONNECTION_2, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_BOARD_CONNECTION, COLOR_GOOD);
        SetLEColor(ui->LE_SUPER_STOP_BOARD_CONNECTION_2, COLOR_GOOD);
    }
    if(robot->SUPER_FATAL_ERROR_ROBOT_DATA == 1){
        SetLEColor(ui->LE_SUPER_STOP_ROBOT_DATA, COLOR_BAD);
        SetLEColor(ui->LE_SUPER_STOP_ROBOT_DATA_2, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_ROBOT_DATA, COLOR_GOOD);
        SetLEColor(ui->LE_SUPER_STOP_ROBOT_DATA_2, COLOR_GOOD);
    }
    if(robot->SUPER_FATAL_ERROR_ROBOT_MISS_COMMAND_WORKING_CHECK == 1){
        SetLEColor(ui->LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK, COLOR_BAD);
        SetLEColor(ui->LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK_2, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK, COLOR_GOOD);
        SetLEColor(ui->LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK_2, COLOR_GOOD);
    }
    if(outlet->SUPER_FATAL_ERROR_OUTLET_CONNECTION == 1){
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_CONNECTION, COLOR_BAD);
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_CONNECTION_2, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_CONNECTION, COLOR_GOOD);
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_CONNECTION_2, COLOR_GOOD);
    }
    if(outlet->SUPER_FATAL_ERROR_OUTLET_CONTROL == 1){
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_CONTROL, COLOR_BAD);
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_CONTROL_2, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_CONTROL, COLOR_GOOD);
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_CONTROL_2, COLOR_GOOD);
    }
    if(outlet->SUPER_FATAL_ERROR_OUTLET_SENSOR == 1){
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_SENSOR, COLOR_BAD);
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_SENSOR_2, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_SENSOR, COLOR_GOOD);
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_SENSOR_2, COLOR_GOOD);
    }

    //OUTLET DATA
    if(plan->sockConnectionStatus == false){
        SetLEColor(ui->LE_SET_OUTLET_CONNECTION_1, COLOR_NONE);
        SetLEColor(ui->LE_SET_OUTLET_CONNECTION_2, COLOR_NONE);

        SetLEColor(ui->LE_SET_INIT_SPIN_1, COLOR_NONE);
        SetLEColor(ui->LE_SET_INIT_SPIN_2, COLOR_NONE);
        SetLEColor(ui->LE_SET_INIT_DOOR_1, COLOR_NONE);
        SetLEColor(ui->LE_SET_INIT_DOOR_2, COLOR_NONE);

        SetLEColor(ui->LE_SET_MOVE_SPIN_1, COLOR_NONE);
        SetLEColor(ui->LE_SET_MOVE_SPIN_2, COLOR_NONE);
        SetLEColor(ui->LE_SET_MOVE_DOOR_1, COLOR_NONE);
        SetLEColor(ui->LE_SET_MOVE_DOOR_2, COLOR_NONE);

    }else{
        if(OUTLET_DATA[0].connection_status == 1){
            SetLEColor(ui->LE_SET_OUTLET_CONNECTION_1, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_SET_OUTLET_CONNECTION_1, COLOR_BAD);
        }
        if(OUTLET_DATA[1].connection_status == 1){
            SetLEColor(ui->LE_SET_OUTLET_CONNECTION_2, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_SET_OUTLET_CONNECTION_2, COLOR_BAD);
        }

        // TODO
        if(OUTLET_DATA[0].init_status[0] == 1){
            SetLEColor(ui->LE_SET_INIT_SPIN_1, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_SET_INIT_SPIN_1, COLOR_BAD);
        }
        if(OUTLET_DATA[0].init_status[1] == 1){
            SetLEColor(ui->LE_SET_INIT_DOOR_1, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_SET_INIT_DOOR_1, COLOR_BAD);
        }

        if(OUTLET_DATA[1].init_status[0] == 1){
            SetLEColor(ui->LE_SET_INIT_SPIN_2, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_SET_INIT_SPIN_2, COLOR_BAD);
        }
        if(OUTLET_DATA[1].init_status[1] == 1){
            SetLEColor(ui->LE_SET_INIT_DOOR_2, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_SET_INIT_DOOR_2, COLOR_BAD);
        }


        if(OUTLET_DATA[0].operating_status[0] == 1){
            SetLEColor(ui->LE_SET_MOVE_SPIN_1, COLOR_BLUE);
        }else{
            SetLEColor(ui->LE_SET_MOVE_SPIN_1, COLOR_NONE);
        }
        if(OUTLET_DATA[0].operating_status[1] == 1){
            SetLEColor(ui->LE_SET_MOVE_DOOR_1, COLOR_BLUE);
        }else{
            SetLEColor(ui->LE_SET_MOVE_DOOR_1, COLOR_NONE);
        }

        if(OUTLET_DATA[1].operating_status[0] == 1){
            SetLEColor(ui->LE_SET_MOVE_SPIN_2, COLOR_BLUE);
        }else{
            SetLEColor(ui->LE_SET_MOVE_SPIN_2, COLOR_NONE);
        }
        if(OUTLET_DATA[1].operating_status[1] == 1){
            SetLEColor(ui->LE_SET_MOVE_DOOR_2, COLOR_BLUE);
        }else{
            SetLEColor(ui->LE_SET_MOVE_DOOR_2, COLOR_NONE);
        }
    }

}

void DialogSetting::on_BTN_TEST_ORDER_clicked()
{
//    QString menu_id = ui->LE_TEST_ORDER_MENU_ID->text();

    QString menu_id = "";
    if(ui->TW_TEST_MENU->currentRow() > -1)
        menu_id = ui->TW_TEST_MENU->item(ui->TW_TEST_MENU->currentRow(),0)->text();

    plog->write("[USER INPUT] TEST ORDER : "+menu_id);
    if(stock->menu.find(menu_id) != stock->menu.end()){
        ST_RECIPE_INFO new_order;
        new_order.pin = "9999";
        new_order.recipe = stock->menu[menu_id].recipe;
        new_order.menu_id = stock->menu[menu_id].menu_id;
        new_order.menu_name = stock->menu[menu_id].menu_name;

        if(stock->menu[menu_id].available){
            pschedule->list_waiting.push_back(new_order);
            plog->write("[SETTING] TEST ORDER " + new_order.menu_name);
        }else{
            plog->write("[SETTING] TEST ORDER " + new_order.menu_name + " (STOCK OVER)");
            QMessageBox::information(this, "재고 부족 에러", "해당하는 메뉴를 제조할 재고가 부족합니다.");
        }
    }else{
        plog->write("[SETTING] TEST ORDER " + menu_id + " (BAD ID)");
        QMessageBox::information(this, "메뉴 ID 에러", "해당하는 메뉴ID가 존재하지 않습니다.");
    }
}

void DialogSetting::on_BTN_ERROR_CLEAR_COFFEE_clicked(){
    stock->ClearDeviceError("COFFEE");
    plog->write("[SETTING - UI INPUT] Error Clear COFFEE");
}
void DialogSetting::on_BTN_ERROR_CLEAR_ICE_1_clicked(){
    stock->ClearDeviceError("ICE");
    plog->write("[SETTING - UI INPUT] Error Clear ICE_1");
}
void DialogSetting::on_BTN_ERROR_CLEAR_PAPER_CUP_1_clicked(){
    stock->ClearDeviceError("PAPER_CUP_1");
    plog->write("[SETTING - UI INPUT] Error Clear PAPER_CUP_1");
}
void DialogSetting::on_BTN_ERROR_CLEAR_PP_CUP_1_clicked(){
    stock->ClearDeviceError("PP_CUP_1");
    plog->write("[SETTING - UI INPUT] Error Clear PP_CUP_1");
}

void DialogSetting::on_BTN_DB_RELOAD_clicked(){
    plog->write("[SETTING] DB RELOAD ");
    stock->LoadDatabase();
    SettingTestUI();
}

void DialogSetting::on_BTN_SET_FIND_HOME_SPIN_1_clicked(){
    plog->write("[SETTING - UI INPUT] FIND HOME SPIN 1");
    outlet->FindHome(0,OUTLET_SPIN);
}

void DialogSetting::on_BTN_SET_FIND_HOME_DOOR_1_clicked(){
    plog->write("[SETTING - UI INPUT] FIND HOME DOOR 1");
    outlet->FindHome(0,OUTLET_DOOR);
}

void DialogSetting::on_BTN_SET_FIND_HOME_SPIN_2_clicked(){
    plog->write("[SETTING - UI INPUT] FIND HOME SPIN 2");
    outlet->FindHome(1,OUTLET_SPIN);
}

void DialogSetting::on_BTN_SET_FIND_HOME_DOOR_2_clicked(){
    plog->write("[SETTING - UI INPUT] FIND HOME DOOR 2");
    outlet->FindHome(1,OUTLET_DOOR);
}
void DialogSetting::on_BTN_SET_FET_ON_SPIN_1_clicked(){
    plog->write("[SETTING - UI INPUT] FET ON SPIN 1");
    outlet->FetOn(0,OUTLET_SPIN);
}
void DialogSetting::on_BTN_SET_FET_ON_SPIN_2_clicked(){
    plog->write("[SETTING - UI INPUT] FET ON SPIN 2");
    outlet->FetOn(1,OUTLET_SPIN);

}
void DialogSetting::on_BTN_SET_FET_OFF_SPIN_1_clicked(){
    plog->write("[SETTING - UI INPUT] FET OFF SPIN 1");
    outlet->FetOff(0,OUTLET_SPIN);

}
void DialogSetting::on_BTN_SET_FET_OFF_SPIN_2_clicked(){
    plog->write("[SETTING - UI INPUT] FET OFF SPIN 2");
    outlet->FetOff(1,OUTLET_SPIN);

}
void DialogSetting::on_BTN_SET_FET_ON_DOOR_1_clicked(){
    plog->write("[SETTING - UI INPUT] FET ON DOOR 1");
    outlet->FetOn(0,OUTLET_DOOR);
}
void DialogSetting::on_BTN_SET_FET_ON_DOOR_2_clicked(){
    plog->write("[SETTING - UI INPUT] FET ON DOOR 2");
    outlet->FetOn(1,OUTLET_DOOR);
}
void DialogSetting::on_BTN_SET_FET_OFF_DOOR_1_clicked(){
    plog->write("[SETTING - UI INPUT] FET OFF DOOR 1");
    outlet->FetOff(0,OUTLET_DOOR);
}
void DialogSetting::on_BTN_SET_FET_OFF_DOOR_2_clicked(){
    plog->write("[SETTING - UI INPUT] FET OFF DOOR 2");
    outlet->FetOff(1,OUTLET_DOOR);
}




void DialogSetting::on_BTN_SET_CON_ON_SPIN_1_clicked(){
    plog->write("[SETTING - UI INPUT] CON ON SPIN 1");
    outlet->ControlOn(0,OUTLET_SPIN);
}
void DialogSetting::on_BTN_SET_CON_ON_SPIN_2_clicked(){
    plog->write("[SETTING - UI INPUT] CON ON SPIN 2");
    outlet->ControlOn(1,OUTLET_SPIN);
}
void DialogSetting::on_BTN_SET_CON_OFF_SPIN_1_clicked(){
    plog->write("[SETTING - UI INPUT] CON OFF SPIN 1");
    outlet->ControlOff(0,OUTLET_SPIN);
}
void DialogSetting::on_BTN_SET_CON_OFF_SPIN_2_clicked(){
    plog->write("[SETTING - UI INPUT] CON OFF SPIN 2");
    outlet->ControlOff(1,OUTLET_SPIN);
}
void DialogSetting::on_BTN_SET_CON_ON_DOOR_1_clicked(){
    plog->write("[SETTING - UI INPUT] CON ON DOOR 1");
    outlet->ControlOn(0,OUTLET_DOOR);
}
void DialogSetting::on_BTN_SET_CON_ON_DOOR_2_clicked(){
    plog->write("[SETTING - UI INPUT] CON ON DOOR 2");
    outlet->ControlOn(1,OUTLET_DOOR);
}
void DialogSetting::on_BTN_SET_CON_OFF_DOOR_1_clicked(){
    plog->write("[SETTING - UI INPUT] CON OFF DOOR 1");
    outlet->ControlOff(0,OUTLET_DOOR);
}
void DialogSetting::on_BTN_SET_CON_OFF_DOOR_2_clicked(){
    plog->write("[SETTING - UI INPUT] CON OFF DOOR 2");
    outlet->ControlOff(1,OUTLET_DOOR);
}


void DialogSetting::on_BTN_SET_ENC_ZERO_SPIN_1_clicked(){
    plog->write("[SETTING - UI INPUT] ENC ZERO SPIN 1");
    outlet->EncoderZero(0,OUTLET_SPIN);
}
void DialogSetting::on_BTN_SET_ENC_ZERO_SPIN_2_clicked(){
    plog->write("[SETTING - UI INPUT] ENC ZERO SPIN 2");
    outlet->EncoderZero(1,OUTLET_SPIN);
}
void DialogSetting::on_BTN_SET_ENC_ZERO_DOOR_1_clicked(){
    plog->write("[SETTING - UI INPUT] ENC ZERO DOOR 1");
    outlet->EncoderZero(0,OUTLET_DOOR);
}
void DialogSetting::on_BTN_SET_ENC_ZERO_DOOR_2_clicked(){
    plog->write("[SETTING - UI INPUT] ENC ZERO DOOR 2");
    outlet->EncoderZero(1,OUTLET_DOOR);
}
void DialogSetting::on_BTN_SET_GOTO_SPIN_1_clicked(){
    int target = ui->LE_SET_GOTO_SPIN_1->text().toInt();
    plog->write("[SETTING - UI INPUT] GOTO SPIN 1 : "+QString::number(target));
    outlet->GoPosition(0,OUTLET_SPIN, target);
}
void DialogSetting::on_BTN_SET_GOTO_SPIN_2_clicked(){
    int target = ui->LE_SET_GOTO_SPIN_2->text().toInt();
    plog->write("[SETTING - UI INPUT] GOTO SPIN 2 : "+QString::number(target));
    outlet->GoPosition(1,OUTLET_SPIN, target);
}
void DialogSetting::on_BTN_SET_GOTO_DOOR_1_clicked(){
    int target = ui->LE_SET_GOTO_DOOR_1->text().toInt();
    plog->write("[SETTING - UI INPUT] GOTO DOOR 1 : "+QString::number(target));
    outlet->GoPosition(0,OUTLET_DOOR, target);
}
void DialogSetting::on_BTN_SET_GOTO_DOOR_2_clicked(){
    int target = ui->LE_SET_GOTO_DOOR_2->text().toInt();
    plog->write("[SETTING - UI INPUT] GOTO DOOR 2 : "+QString::number(target));
    outlet->GoPosition(1,OUTLET_DOOR, target);
}
void DialogSetting::on_BTN_SET_OFFSET_SPIN_1_clicked(){
    int target = ui->LE_SET_OFFSET_SPIN_1->text().toInt();
    plog->write("[SETTING - UI INPUT] SET OFFSET SPIN 1 : "+QString::number(target));
    outlet->SetOffset(0,OUTLET_SPIN, target);
}
void DialogSetting::on_BTN_SET_OFFSET_SPIN_2_clicked(){
    int target = ui->LE_SET_OFFSET_SPIN_2->text().toInt();
    plog->write("[SETTING - UI INPUT] SET OFFSET SPIN 2 : "+QString::number(target));
    outlet->SetOffset(1,OUTLET_SPIN, target);
}
void DialogSetting::on_BTN_SET_OFFSET_DOOR_1_clicked(){
    int target = ui->LE_SET_OFFSET_DOOR_1->text().toInt();
    plog->write("[SETTING - UI INPUT] SET OFFSET DOOR 1 : "+QString::number(target));
    outlet->SetOffset(0,OUTLET_DOOR, target);
}
void DialogSetting::on_BTN_SET_OFFSET_DOOR_2_clicked(){
    int target = ui->LE_SET_OFFSET_DOOR_2->text().toInt();
    plog->write("[SETTING - UI INPUT] SET OFFSET DOOR 2 : "+QString::number(target));
    outlet->SetOffset(1,OUTLET_DOOR, target);
}

void DialogSetting::on_BTN_SET_UNLOCK_clicked()
{
    if(ui->LE_SET_PASSWD->text() == "2011"){
        plog->write("[SETTING - UI INPUT] UNLOCK SUCCESS");
        ui->LE_SET_PASSWD->setText("");
        is_lock = false;
    }else{
        plog->write("[SETTING - UI INPUT] UNLOCK FAIL : " + ui->LE_SET_PASSWD->text());
        ui->LE_SET_PASSWD->setText("");
        is_lock = true;
    }
}

void DialogSetting::on_BTN_SET_LOCK_clicked()
{
    plog->write("[SETTING - UI INPUT] LOCK SUCCESS");
    is_lock = true;
}

void DialogSetting::on_BTN_ERROR_CLEAR_OUTLET_1_clicked()
{
    plog->write("[SETTING - UI INPUT] Error Clear OUTLET 1");
    outlet->ErrorClear();
}

void DialogSetting::on_BTN_ERROR_CLEAR_ROBOT_3_clicked()
{
    plog->write("[SETTING - UI INPUT] Error Clear ROBOT");
    robot->ErrorClear();
}

void DialogSetting::on_BTN_ERROR_CLEAR_PAPER_CUP_3_clicked()
{
    stock->ClearDeviceError("PAPER_CUP_1");
    plog->write("[SETTING - UI INPUT] Error Clear PAPER_CUP_1");
}

void DialogSetting::on_BTN_ERROR_CLEAR_PAPER_CUP_4_clicked()
{
    stock->ClearDeviceError("PP_CUP_1");
    plog->write("[SETTING - UI INPUT] Error Clear PP_CUP_1");
}

void DialogSetting::on_BTN_ERROR_CLEAR_OUTLET_2_clicked()
{
    plog->write("[SETTING - UI INPUT] Error Clear OUTLET 2");
    outlet->ErrorClear();
}

void DialogSetting::on_BTN_ERROR_CLEAR_ROBOT_2_clicked()
{
    plog->write("[SETTING - UI INPUT] Error Clear ROBOT");
    robot->ErrorClear();
}

void DialogSetting::on_BTN_ERROR_CLEAR_SLUSH_clicked()
{
    stock->ClearDeviceError("SLUSH");
    plog->write("[SETTING - UI INPUT] Error Clear SLUSH");
}

void DialogSetting::on_BTN_ERROR_CLEAR_ICECREAM_clicked()
{
    stock->ClearDeviceError("ICECREAM");
    plog->write("[SETTING - UI INPUT] Error Clear ICECREAM");
}

void DialogSetting::on_BTN_ERROR_CLEAR_OUTLET_3_clicked()
{
    plog->write("[SETTING - UI INPUT] Error Clear OUTLET 1");
    outlet->ErrorClear();
}

void DialogSetting::on_BTN_ERROR_CLEAR_OUTLET_4_clicked()
{
    plog->write("[SETTING - UI INPUT] Error Clear OUTLET 2");
    outlet->ErrorClear();
}

void DialogSetting::on_BTN_OPEN_RECIPE_clicked()
{
    plog->write("[UI - SETTING] RECIPE OPEN Clicked");
    emit openRecipe();
}

void DialogSetting::on_BTN_OPEN_RECIPE_2_clicked()
{
    plog->write("[UI - SETTING] RECIPE CLOSE Clicked");
    emit closeRecipe();
}
