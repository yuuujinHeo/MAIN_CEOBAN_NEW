#include "DialogMonitor.h"
#include "ui_DialogMonitor.h"
#include <QAction>
#include <QMenu>
#include <QPoint>

#include "Scheduler.h"
#include "displaydialog.h"
extern Scheduler *pschedule;
extern Logger       *plog;
extern DisplayDialog    *pdisplay;


#define MONITOR_TIMER_MS    200

DialogMonitor::DialogMonitor(QWidget *parent, DialogStock *_stock) :
    QDialog(parent), stock(_stock),
    ui(new Ui::DialogMonitor)
{
    ui->setupUi(this);

    displayConnectionStatus = false;
    prev_connection = false;
    FATAL_ERROR_CONNECTION_OF_DISPLAY = 0;

    disp_waiting.clear();
    disp_inprogress.clear();
    disp_completed.clear();


    display_mode = DISPLAY_MODE_IN_READY;

    force_monitor_status = "IN_READY";

    ui->LW_WAITING->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->LW_WAITING, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(ProvideContextListWAITING(const QPoint &)));

#ifdef ICECREAM_VER
    ui->GB_MONITOR->setStyleSheet("QGroupBox  {\n    margin-top: 10px;"
                                  "	font: 20pt \"함초롬돋움\";\n}\n\nQGroupBox::title  {"
                                                     "    subcontrol-origin: margin;"
                                                     "    subcontrol-position: top center;"
                                                     "    padding: 10px 8000px 10px 8000px;"
                                                     "    background-color: #FFC4D8;"
                                                     "    color: rgb(255, 255, 255);}"
                                                     "QLabel {\n	font: 10pt \"함초롬돋움\";\n}"
                                                    "QComboBox{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}\nQPushButton{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}"
                                                    "QLineEdit{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}");
#else
    ui->GB_MONITOR->setStyleSheet("QGroupBox  {\n    margin-top: 10px;"
                                  "	font: 20pt \"함초롬돋움\";\n}\n\nQGroupBox::title  {"
                                                     "    subcontrol-origin: margin;"
                                                     "    subcontrol-position: top center;"
                                                     "    padding: 10px 8000px 10px 8000px;"
                                                     "    background-color: #595959;"
                                                     "    color: rgb(255, 255, 255);}"
                                                     "QLabel {\n	font: 10pt \"함초롬돋움\";\n}"
                                                    "QComboBox{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}\nQPushButton{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}"
                                                    "QLineEdit{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}");
#endif

    // 네트워크 연결 관리
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), &connection_loop, SLOT(quit()));


    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(MONITOR_TIMER_MS);
}

DialogMonitor::~DialogMonitor()
{
    delete ui;
}



// 공통적으로 사용되는 POST 구문 : 출력으로 응답 정보를 보냄
QByteArray DialogMonitor::generalPost(QByteArray post_data){
    QByteArray postDataSize = QByteArray::number(post_data.size());

    QUrl serviceURL(DISPLAY_URL);
    QNetworkRequest request(serviceURL);
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Content-Length", postDataSize);
    request.setRawHeader("Connection", "Keep-Alive");
    request.setRawHeader("AcceptEncoding", "gzip, deflate");
    request.setRawHeader("AcceptLanguage", "ko-KR,en,*");

    QNetworkReply *reply = manager->post(request, post_data);
    connection_loop.exec();

    reply->waitForReadyRead(500);
    QByteArray ret = reply->readAll();
    reply->deleteLater();

    return ret;
}


bool DialogMonitor::SendDisplayInfo(){
    QJsonObject json;


    QJsonArray waiting_array;
    for(int i=0; i<disp_inprogress.size(); i++){
        QJsonObject temp;
        temp["TRANSACTION_NUMBER"] = disp_inprogress[i].pin;
        temp["MENU"] = disp_inprogress[i].menu_name;
        temp["STATUS"] = 2;
        waiting_array.push_back(temp);
    }
    for(int i=0; i<disp_waiting.size(); i++){
        QJsonObject temp;
        temp["TRANSACTION_NUMBER"] = disp_waiting[i].pin;
        temp["MENU"] = disp_waiting[i].menu_name;
        temp["STATUS"] = 1;
        waiting_array.push_back(temp);
    }
    json["WAITING_LIST"] = waiting_array;


    QJsonArray complete_array;
    for(int i=0; i< disp_completed.size() ; i++){
        QJsonObject temp;
        temp["TRANSACTION_NUMBER"] = disp_completed[i].pin;
        temp["MENU"] = disp_completed[i].menu_name;
        temp["MODULE_NUMBER"] = disp_completed[i].id_module;
        temp["CELL_NUMBER"] = disp_completed[i].id_cell;
        temp["OUTLET_STATUS"] = 0;
        complete_array.push_back(temp);
    }
    for(int i=0; i<NUMBER_OF_OUTLET; i++){
        QJsonObject temp;
        if(disp_dispensing[i].pin != ""){
            temp["TRANSACTION_NUMBER"] = disp_dispensing[i].pin;
            temp["MENU"] = disp_dispensing[i].menu_name;
            temp["MODULE_NUMBER"] = disp_dispensing[i].id_module;
            temp["CELL_NUMBER"] = disp_dispensing[i].id_cell;
            temp["OUTLET_STATUS"] = 1;
            complete_array.push_back(temp);
        }
    }
    json["COMPLETE_LIST"] = complete_array;



    // **************************** for test
//    QJsonObject temp1;
//    temp1["TRANSACTION_NUMBER"] = "54321";
//    temp1["MENU"] = "블랙밀크티";
//    temp1["IS_MAKING"] = 1;
//    waiting_array.push_back(temp1);
//    json["WAITING_LIST"] = waiting_array;

//    QJsonObject temp;
//    temp["TRANSACTION_NUMBER"] = "01234";
//    temp["MENU"] = "블랙티";
//    temp["MODULE_NUMBER"] = "1";
//    temp["CELL_NUMBER"] = "1";
//    temp["BOBA"] = "1";
//    temp["SYRUP"] = "1";
//    temp["OUTLET_STATUS"] = 0;
//    complete_array.push_back(temp);

//    json["COMPLETE_LIST"] = complete_array;
    // ****************************


    QString msg_status = "";
    switch (display_mode) {
    case DISPLAY_MODE_IN_READY:
        msg_status = "IN_READY";
        break;
    case DISPLAY_MODE_IN_OPERATION:
        msg_status = "IN_OPERATING";
        break;
    }

    if(ui->CB_FORCE_MONITOR_STATUS->isChecked()){
        pdisplay->notice = ui->LE_FORCE_MSG->text();
        pdisplay->notice_count = 3;
//        json["PLATFORM_STATE"] = force_monitor_status;
//        json["OPERATION_MSG"] = ui->LE_FORCE_MSG->text();
    }else{
        json["PLATFORM_STATE"] = msg_status;
        json["OPERATION_MSG"] = display_msg;
    }

    int waiting_time_minute = stock->ApproximateWaitingTime/60;

    QByteArray json_string = QJsonDocument(json).toJson();
    QByteArray ret = generalPost(json_string);
    if(ret == ""){
        return false;
    }

    return true;
}

void DialogMonitor::UpdateList_WaitingDrinks(QVector<ST_RECIPE_INFO> list_waiting){
    disp_waiting = list_waiting;
}
void DialogMonitor::UpdateList_InprogressDrinks(QVector<ST_RECIPE_INFO> list_inprogress){
    disp_inprogress = list_inprogress;
}
void DialogMonitor::UpdateList_CompletedDrinks(QVector<ST_COMPLETED_DRINK_INFO> list_completed){
    disp_completed = list_completed;
}
void DialogMonitor::UpdateList_DispensingDrinkgs(ST_COMPLETED_DRINK_INFO list_dispensing[]){
    for(int i=0; i<NUMBER_OF_OUTLET; i++){
        disp_dispensing[i] = list_dispensing[i];
    }
}


void DialogMonitor::ProvideContextListWAITING(const QPoint &pos){
    QPoint item = ui->LW_WAITING->mapToGlobal(pos);
    QMenu submenu1;
    submenu1.addAction("Delete");
    QAction* rightClickItem = submenu1.exec(item);
    int Inprogress_size = pschedule->get_inprogress_size();
    if(rightClickItem && rightClickItem->text().contains("Delete")){
        if(ui->LW_WAITING->indexAt(pos).row() == 0 && Inprogress_size > 0){
//            pschedule->remove_inprogress_list();
            plog->write("[UI WAITING] Inprogress List Delete Clicked");
        }else if(Inprogress_size > 0){
            pschedule->remove_waiting_list(ui->LW_WAITING->indexAt(pos).row() - 1);
            plog->write("[UI WAITING] List " + QString().sprintf("%d",ui->LW_WAITING->indexAt(pos).row()-1) +" Delete Clicked");
        }else{
            pschedule->remove_waiting_list(ui->LW_WAITING->indexAt(pos).row());
            plog->write("[UI WAITING] List " + QString().sprintf("%d",ui->LW_WAITING->indexAt(pos).row()) +" Delete Clicked");
        }
    }
}

void DialogMonitor::set_display_mode(int mode){
    display_mode = mode;
}
void DialogMonitor::SetDisplayMessage(QString msg){
    display_msg = msg;
}

int DialogMonitor::get_display_mode(){
    return display_mode;
}

void DialogMonitor::onTimer(){
    static int connection_cnt = 0;
    static int cnt = 0;
    cnt++;
    connection_cnt--;

    if(IS_UI_LOCK){
        ui->GB_MONITOR->setEnabled(false);
    }else{
        ui->GB_MONITOR->setEnabled(true);
    }

    int post_ret = false;
    post_ret = SendDisplayInfo();

    if(post_ret == true){
        connection_cnt = 10;
    }

    if(connection_cnt > 0){
        displayConnectionStatus = true;
        SetLEColor(ui->LE_MONITOR_CONNECTION, COLOR_GOOD);
    }else{
        displayConnectionStatus = false;
        SetLEColor(ui->LE_MONITOR_CONNECTION, COLOR_BAD);
    }


    switch (display_mode) {
    case DISPLAY_MODE_IN_READY:
        SetLEColor(ui->LE_MONITOR_STATUS_OPERATION, COLOR_NONE);
        SetLEColor(ui->LE_MONITOR_STATUS_PREPARATION, COLOR_BLUE);
        SetLEColor(ui->LE_MONITOR_STATUS_MAINTENANCE, COLOR_NONE);
        SetLEColor(ui->LE_MONITOR_STATUS_ERROR, COLOR_NONE);
        break;
    case DISPLAY_MODE_IN_OPERATION:
        SetLEColor(ui->LE_MONITOR_STATUS_OPERATION, COLOR_BLUE);
        SetLEColor(ui->LE_MONITOR_STATUS_PREPARATION, COLOR_NONE);
        SetLEColor(ui->LE_MONITOR_STATUS_MAINTENANCE, COLOR_NONE);
        SetLEColor(ui->LE_MONITOR_STATUS_ERROR, COLOR_NONE);
        break;
    }
    ui->LE_MONITOR_STATUS_MESSAGE->setText(display_msg);

    // check only when the initialize process passed
//    if(OP_STATUS_INITIALIZING == PLATFORM_INIT_ON_SUCCESS_STATE){
//        if((prev_connection == true) && (displayConnectionStatus == false)){
//            FATAL_ERROR_CONNECTION_OF_DISPLAY = 1;
//        }
//        prev_connection = displayConnectionStatus;
//    }

    ui->LW_WAITING->clear();
    for(int i=0; i<disp_inprogress.size(); i++){
        QString pin = disp_inprogress[i].pin;
        QString marking = "■";
        QString space = "  ";
        QString menu_name = disp_inprogress[i].menu_name;
        QString statement = marking + space + "[" + pin + "]" + space + menu_name;
        ui->LW_WAITING->addItem(statement);
    }
    for(int i=0; i<disp_waiting.size(); i++){
        QString pin = disp_waiting[i].pin;
        QString marking = "□";
        QString space = "  ";
        QString menu_name = disp_waiting[i].menu_name;
        QString statement = marking + space + "[" + pin + "]" + space + menu_name;
        ui->LW_WAITING->addItem(statement);
    }

    ui->LW_COMPLETED->clear();
    if(disp_dispensing[0].pin != ""){
        QString pin = disp_dispensing[0].pin;
        QString marking = "■";
        QString space = "  ";
        QString menu_name = disp_dispensing[0].menu_name;
        QString id_module = QString::number(disp_dispensing[0].id_module);
        QString id_cell = QString::number(disp_dispensing[0].id_cell);
        QString statement = marking + space + "[" + pin + "]" + space + "[" + id_module + " | " + id_cell + "]" + space + menu_name;
        ui->LW_COMPLETED->addItem(statement);
    }
    if(disp_dispensing[1].pin != ""){
        QString pin = disp_dispensing[1].pin;
        QString marking = "■";
        QString space = "  ";
        QString menu_name = disp_dispensing[1].menu_name;
        QString id_module = QString::number(disp_dispensing[1].id_module);
        QString id_cell = QString::number(disp_dispensing[1].id_cell);
        QString statement = marking + space + "[" + pin + "]" + space + "[" + id_module + " | " + id_cell + "]" + space + menu_name;
        ui->LW_COMPLETED->addItem(statement);
    }
    for(int i=0; i<disp_completed.size(); i++){
        QString pin = disp_completed[i].pin;
        QString marking = "□";
        QString space = "  ";
        QString menu_name = disp_completed[i].menu_name;
        QString id_module = QString::number(disp_completed[i].id_module);
        QString id_cell = QString::number(disp_completed[i].id_cell);
        QString statement = marking + space + "[" + pin + "]" + space + "[" + id_module + " | " + id_cell + "]" + space + menu_name;
        ui->LW_COMPLETED->addItem(statement);
    }
}

void DialogMonitor::on_BTN_FORCE_OPERATION_clicked(){
    force_monitor_status = "IN_OPERATING";
    if(ui->CB_FORCE_MONITOR_STATUS->isChecked()){
        pdisplay->Set_ForcedMode(DISPLAY_MODE_IN_OPERATION);
        plog->write("[UI OPERATION - MONITOR] 현황판 강제 적용 - 운영중");
    }
}
void DialogMonitor::on_BTN_FORCE_MAINTENANCE_clicked(){
    force_monitor_status = "IN_PROBLEM";
    if(ui->CB_FORCE_MONITOR_STATUS->isChecked()){
        plog->write("[UI OPERATION - MONITOR] 현황판 강제 적용 - 정비중");
    }
}
void DialogMonitor::on_BTN_FORCE_PREPARATION_clicked(){
    force_monitor_status = "IN_READY";
    if(ui->CB_FORCE_MONITOR_STATUS->isChecked()){
        pdisplay->Set_ForcedMode(DISPLAY_MODE_IN_READY);
        plog->write("[UI OPERATION - MONITOR] 현황판 강제 적용 - 준비중");
    }
}
void DialogMonitor::on_BTN_FORCE_ERROR_clicked(){
    force_monitor_status = "ERROR_OCCURED";
    if(ui->CB_FORCE_MONITOR_STATUS->isChecked()){
        plog->write("[UI OPERATION - MONITOR] 현황판 강제 적용 - 에러발생");
    }
}

void DialogMonitor::on_CB_FORCE_MONITOR_STATUS_clicked(bool checked){
    if(checked == true){
        plog->write("[UI OPERATION - MONITOR] 현황판 강제 적용 시작");
    }else{
        pdisplay->Set_ForcedMode(DISPLAY_MODE_IDLE);
        plog->write("[UI OPERATION - MONITOR] 현황판 강제 적용 종료");
    }
}

void DialogMonitor::on_BTN_FORCE_CLEAR_WAITING_LIST_clicked(){
    if(ui->CB_FORCE_CLEAR_DRINKS->isChecked()){
        plog->write("[UI OPERATION - MONITOR] 대기 음료 리스트 클리어");
//        if(OP_STATUS_OPERATING != PLATFORM_OPERATION_ON_OPERATING_STATE){
            pschedule->ClearWaitingList();
//        }
    }
}

void DialogMonitor::on_BTN_FORCE_CLEAR_COMPLETED_LIST_clicked(){
    if(ui->CB_FORCE_CLEAR_DRINKS->isChecked()){
        plog->write("[UI OPERATION - MONITOR] 완료 음료 리스트 클리어");
//        if(OP_STATUS_OPERATING != PLATFORM_OPERATION_ON_OPERATING_STATE){
            pschedule->ClearCompletedList();
//        }
    }
}

void DialogMonitor::on_CB_FORCE_CLEAR_DRINKS_clicked(bool checked){
    if(checked == true){
        plog->write("[UI OPERATION - MONITOR] 음료 리스트 클리어 허용");
    }else{
        plog->write("[UI OPERATION - MONITOR] 음료 리스트 클리어 차단");
    }
}
