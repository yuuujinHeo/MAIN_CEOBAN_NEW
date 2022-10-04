#ifndef MAINWINDOWICECREAM_H
#define MAINWINDOWICECREAM_H

#include <QMainWindow>
#include <QTimer>
#include <QMessageBox>

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include "GlobalHeader.h"

#ifdef ICECREAM_VER
#include "RBLAN2CAN.h"

#include "DialogSetting.h"
#include "DialogCupDispenser.h"
#include "DialogRobot.h"
#include "DialogMonitor.h"
#include "DialogDoor.h"
#include "DialogIceDispenser.h"
#include "DialogCoffee.h"
#include "DialogSyrup.h"
#include "DialogIcecream.h"
#include "DialogSlush.h"
#include "DialogBarcode.h"
#include "DialogRecipeIcecream.h"
#include "DialogOutlet.h"
#include "DialogKiosk.h"
#include "DialogStock_icecream.h"
#include "displaydialog.h"
#include "DialogError.h"
#include "DialogNotice.h"
#include "Scheduler.h"
#include "Logger.h"


#define MAINWINDOW_LOOP_TIME        200


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    RBLAN2CAN           *lan;

    DialogSetting       *setting;
    DialogCupDispenser  *cup;
    DialogIcecream      *icecream;
    DialogSlush         *slush;
    DialogIceDispenser  *ice;
    DialogCoffee        *coffee;
    DialogSyrup         *syrup;
    DialogRobot         *robot;
    DialogMonitor       *monitor;
    DialogNotice        *notice;
    DialogDoor          *door;
    DialogBarcode       *barcode;
    DialogOutlet        *outlet;
    DialogKiosk         *kiosk;
    DialogStock         *stock;
    DialogRecipeIcecream    *ques_recipe;
    DisplayDialog       *display;
    DialogError         *error;

    Scheduler           *schedule;
    Logger              *logger;



    void LoadLoadcellDB();
    void SettingRecipeDB();

    void ChangeDeviceDialog(DEVICE_DIALOG_ID id);


    void CoreLogic_Initializing();
    void CoreLogic_Operating();


    void UpdatePlatformOperationInfo();

    void Update_Dev_CupInfo();
    void Update_Dev_IcecreamInfo();
    void Update_Dev_SlushInfo();
    void Update_Dev_RobotInfo();
    void Update_Dev_MonitorInfo();
    void Update_Dev_DoorInfo();
    void Update_Dev_BarcodeInfo();
    void Update_Dev_OutletInfo();
    void Update_Dev_KioskInfo();
    void Update_Dev_StockInfo();

    QString DesToIng(QString des);
    QString IngToDes(QString ing);

    bool is_recipe_changed;

    void ClearForcedSuperError();
    int CheckDeviceConnection();
    void UpdateMenuAvailable();

public slots:
    void onTimer();
    void openRecipePage();
    void closeRecipePage();
    void addmenu(ST_MENU_INFO menu);
    void editmenu(int index, ST_MENU_INFO menu);
    void editingredient(int index, ST_RECIPE_STEP ingredient);
    void addingredient(ST_RECIPE_STEP ingredient);
    void cancelrecipe();
    void cancelnotice();
    void noticeinit();
    void noticeop();

private slots:
    void on_BTN_DEV_INFO_CUP_clicked();
    void on_BTN_DEV_INFO_ROBOT_clicked();
    void on_BTN_DEV_INFO_MONITOR_clicked();
    void on_BTN_DEV_INFO_DOOR_clicked();
    void on_BTN_DEV_INFO_BARCODE_clicked();
    void on_BTN_DEV_INFO_OUTLET_clicked();
    void on_BTN_DEV_INFO_ICECREAM_clicked();
    void on_BTN_DEV_INFO_SLUSH_clicked();
    void on_BTN_DEV_INFO_KIOSK_clicked();
    void on_BTN_DEV_INFO_STOCK_clicked();

    void on_BTN_DO_INITIALIZING_clicked();
    void on_BTN_DO_OPERATING_clicked();
    void on_BTN_STOP_OPERATING_clicked();
    void on_BTN_CANCEL_STOP_clicked();
    void on_BTN_SETTING_clicked();

    void on_BTN_EXIT_clicked();
    void on_BTN_UI_LOCK_clicked();

    void on_BTN_CUP_ADD_DONE_clicked();

    void on_BTN_RESUME_clicked();


    void on_BTN_ERROR_clicked();

    void on_BTN_CUP_ADD_DONE_2_clicked();

    void on_BTN_MENU_LOAD_clicked();

    void on_BTN_MENU_SAVE_clicked();

    void on_BTN_MENU_ADD_clicked();

    void on_BTN_MENU_EDIT_clicked();

    void on_BTN_MENU_DELETE_clicked();

    void on_BTN_RECIPE_SAVE_clicked();

    void on_BTN_RECIPE_EDIT_clicked();

    void on_BTN_RECIPE_DELETE_clicked();

    void on_BTN_RECIPE_ADD_clicked();

    void on_BTN_RECIPE_UP_clicked();

    void on_BTN_RECIPE_DOWN_clicked();

    void on_TW_MENU_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_BTN_ERROR_2_clicked();

private:
    Ui::MainWindow *ui;
    QTimer  timer;

    QSqlDatabase    db;
};

#endif

#endif // MAINWINDOWICECREAM_H
