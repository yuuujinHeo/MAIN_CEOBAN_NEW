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
                             DialogBarcode *_barcode, DialogMonitor *_monitor) :
    QDialog(parent), stock(_stock), robot(_robot), cup(_cup),
    coffee(_coffee), ice(_ice),
    syrup(_syrup), outlet(_outlet),
    barcode(_barcode), monitor(_monitor),
    ui(new Ui::DialogSetting)
{
    ui->setupUi(this);
    is_lock = true;

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
        ui->BTN_OPEN_RECIPE->setEnabled(false);
//        ui->BTN_OPEN_RECIPE_2->setEnabled(false);
    }else{
        ui->TW_SETTING->setTabEnabled(1,true);
        ui->BTN_OPEN_RECIPE->setEnabled(true);
        ui->BTN_OPEN_RECIPE_2->setEnabled(true);
    }

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
    if(stock->IsDeviceError("SODA")){
        SetLEColor(ui->LE_DEVICE_ERROR_SODA, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_SODA, COLOR_GOOD);
    }
    if(stock->IsDeviceError("PAPER_CUP_2")){
        SetLEColor(ui->LE_DEVICE_ERROR_PAPER_CUP_2, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_PAPER_CUP_2, COLOR_GOOD);
    }
    if(stock->IsDeviceError("PP_CUP_1")){
        SetLEColor(ui->LE_DEVICE_ERROR_PP_CUP_1, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_PP_CUP_1, COLOR_GOOD);
    }
    if(stock->IsDeviceError("PP_CUP_2")){
        SetLEColor(ui->LE_DEVICE_ERROR_PP_CUP_2, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_PP_CUP_2, COLOR_GOOD);
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


    if(SUPER_FATAL_ERROR_PLATFORM_OPEN == 1){
        SetLEColor(ui->LE_SUPER_STOP_PLATFORM_OPEN, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_PLATFORM_OPEN, COLOR_GOOD);
    }
    if(plan->SUPER_FATAL_ERROR_CONNECTION_OF_LAN2CAN == 1){
        SetLEColor(ui->LE_SUPER_STOP_BOARD_CONNECTION, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_BOARD_CONNECTION, COLOR_GOOD);
    }
    if(robot->SUPER_FATAL_ERROR_ROBOT_DATA == 1){
        SetLEColor(ui->LE_SUPER_STOP_ROBOT_DATA, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_ROBOT_DATA, COLOR_GOOD);
    }
    if(robot->SUPER_FATAL_ERROR_ROBOT_MISS_COMMAND_WORKING_CHECK == 1){
        SetLEColor(ui->LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK, COLOR_GOOD);
    }
    if(outlet->SUPER_FATAL_ERROR_OUTLET_CONNECTION == 1){
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_CONNECTION, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_CONNECTION, COLOR_GOOD);
    }
    if(outlet->SUPER_FATAL_ERROR_OUTLET_CONTROL == 1){
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_CONTROL, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_CONTROL, COLOR_GOOD);
    }
    if(outlet->SUPER_FATAL_ERROR_OUTLET_SENSOR == 1){
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_SENSOR, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_SENSOR, COLOR_GOOD);
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
void DialogSetting::on_BTN_ERROR_CLEAR_SODA_clicked(){
    stock->ClearDeviceError("SODA");
    plog->write("[SETTING - UI INPUT] Error Clear SODA");
}
void DialogSetting::on_BTN_ERROR_CLEAR_ICE_1_clicked(){
    stock->ClearDeviceError("ICE_1");
    plog->write("[SETTING - UI INPUT] Error Clear ICE_1");
}
void DialogSetting::on_BTN_ERROR_CLEAR_PAPER_CUP_1_clicked(){
    stock->ClearDeviceError("PAPER_CUP_1");
    plog->write("[SETTING - UI INPUT] Error Clear PAPER_CUP_1");
}
void DialogSetting::on_BTN_ERROR_CLEAR_PAPER_CUP_2_clicked(){
    stock->ClearDeviceError("PAPER_CUP_2");
    plog->write("[SETTING - UI INPUT] Error Clear PAPER_CUP_2");
}
void DialogSetting::on_BTN_ERROR_CLEAR_PP_CUP_1_clicked(){
    stock->ClearDeviceError("PP_CUP_1");
    plog->write("[SETTING - UI INPUT] Error Clear PP_CUP_1");
}
void DialogSetting::on_BTN_ERROR_CLEAR_PP_CUP_2_clicked(){
    stock->ClearDeviceError("PP_CUP_2");
    plog->write("[SETTING - UI INPUT] Error Clear PP_CUP_2");
}

void DialogSetting::on_BTN_DB_RELOAD_clicked(){
    plog->write("[SETTING] DB RELOAD ");
    stock->LoadDatabase();
    SettingTestUI();
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
    stock->ClearDeviceError("PP_CUP_1");
    plog->write("[SETTING - UI INPUT] Error Clear PP_CUP_1");
}

void DialogSetting::on_BTN_ERROR_CLEAR_PAPER_CUP_4_clicked()
{
    stock->ClearDeviceError("PP_CUP_2");
    plog->write("[SETTING - UI INPUT] Error Clear PP_CUP_2");
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
