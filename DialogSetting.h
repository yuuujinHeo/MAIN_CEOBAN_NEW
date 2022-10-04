#ifndef DIALOGSETTING_H
#define DIALOGSETTING_H

#include <QDialog>
#include <QTimer>
#include <QMessageBox>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include "DialogCupDispenser.h"
#include "DialogIceDispenser.h"
#include "DialogCoffee.h"
#include "DialogSyrup.h"
#include "DialogRobot.h"
#include "DialogMonitor.h"
#include "DialogDoor.h"
#include "DialogBarcode.h"
#include "DialogIcecream.h"
#include "DialogSlush.h"
#include "DialogOutlet.h"
#include "DialogKiosk.h"
#include "RBLAN2CAN.h"

#include "GlobalHeader.h"

#ifdef ICECREAM_VER
#include "DialogStock_icecream.h"
#else
#include "DialogStock.h"
#endif

#define DB_NAME_SETTING     "DB/setting"




namespace Ui {
class DialogSetting;
}

class DialogSetting : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSetting(QWidget *parent = nullptr, DialogStock *_stock = nullptr, DialogRobot *_robot = nullptr, DialogCupDispenser *_cup = nullptr,
                           DialogCoffee *_coffee = nullptr, DialogIceDispenser *_ice = nullptr,
                           DialogSyrup *_syrup = nullptr, DialogOutlet *_outlet = nullptr,
                           DialogBarcode *_barcode = nullptr, DialogMonitor *_monitor = nullptr,
                           DialogIcecream *_icecream = nullptr, DialogSlush *_slush = nullptr);
    ~DialogSetting();
    bool is_lock;

    void SettingTestUI();

    ST_SETTING  setting_info;
    void LoadDB();
signals:
    void openRecipe();
    void closeRecipe();

public slots:
    void onTimer();

private slots:
    void on_BTN_TEST_ORDER_clicked();

    void on_BTN_ERROR_CLEAR_COFFEE_clicked();
    void on_BTN_ERROR_CLEAR_ICE_1_clicked();
    void on_BTN_ERROR_CLEAR_PAPER_CUP_1_clicked();
    void on_BTN_ERROR_CLEAR_PP_CUP_1_clicked();

    void on_BTN_DB_RELOAD_clicked();

    void on_BTN_SET_FIND_HOME_SPIN_1_clicked();
    void on_BTN_SET_FIND_HOME_DOOR_1_clicked();
    void on_BTN_SET_FIND_HOME_SPIN_2_clicked();
    void on_BTN_SET_FIND_HOME_DOOR_2_clicked();

    void on_BTN_SET_FET_ON_SPIN_1_clicked();
    void on_BTN_SET_FET_ON_SPIN_2_clicked();
    void on_BTN_SET_FET_OFF_SPIN_1_clicked();
    void on_BTN_SET_FET_OFF_SPIN_2_clicked();
    void on_BTN_SET_FET_ON_DOOR_1_clicked();
    void on_BTN_SET_FET_ON_DOOR_2_clicked();
    void on_BTN_SET_FET_OFF_DOOR_1_clicked();
    void on_BTN_SET_FET_OFF_DOOR_2_clicked();
    void on_BTN_SET_CON_ON_SPIN_1_clicked();
    void on_BTN_SET_CON_ON_SPIN_2_clicked();
    void on_BTN_SET_CON_OFF_SPIN_1_clicked();
    void on_BTN_SET_CON_OFF_SPIN_2_clicked();
    void on_BTN_SET_CON_ON_DOOR_1_clicked();
    void on_BTN_SET_CON_ON_DOOR_2_clicked();
    void on_BTN_SET_CON_OFF_DOOR_1_clicked();
    void on_BTN_SET_CON_OFF_DOOR_2_clicked();

    void on_BTN_SET_ENC_ZERO_SPIN_1_clicked();
    void on_BTN_SET_ENC_ZERO_SPIN_2_clicked();
    void on_BTN_SET_ENC_ZERO_DOOR_1_clicked();
    void on_BTN_SET_ENC_ZERO_DOOR_2_clicked();

    void on_BTN_SET_GOTO_SPIN_1_clicked();
    void on_BTN_SET_GOTO_SPIN_2_clicked();
    void on_BTN_SET_GOTO_DOOR_1_clicked();
    void on_BTN_SET_GOTO_DOOR_2_clicked();

    void on_BTN_SET_OFFSET_SPIN_1_clicked();
    void on_BTN_SET_OFFSET_SPIN_2_clicked();
    void on_BTN_SET_OFFSET_DOOR_1_clicked();
    void on_BTN_SET_OFFSET_DOOR_2_clicked();

    void on_BTN_SET_UNLOCK_clicked();
    void on_BTN_SET_LOCK_clicked();

    void on_BTN_ERROR_CLEAR_OUTLET_1_clicked();
    void on_BTN_ERROR_CLEAR_ROBOT_3_clicked();

    void on_BTN_ERROR_CLEAR_PAPER_CUP_3_clicked();
    void on_BTN_ERROR_CLEAR_PAPER_CUP_4_clicked();

    void on_BTN_ERROR_CLEAR_OUTLET_2_clicked();
    void on_BTN_ERROR_CLEAR_ROBOT_2_clicked();

    void on_BTN_ERROR_CLEAR_SLUSH_clicked();
    void on_BTN_ERROR_CLEAR_ICECREAM_clicked();

    void on_BTN_ERROR_CLEAR_OUTLET_3_clicked();

    void on_BTN_ERROR_CLEAR_OUTLET_4_clicked();

    void on_BTN_OPEN_RECIPE_clicked();

    void on_BTN_OPEN_RECIPE_2_clicked();

private:
    Ui::DialogSetting *ui;
    QTimer timer;

    QSqlDatabase    db;

    DialogStock         *stock;
    DialogRobot         *robot;
    DialogCupDispenser  *cup;
    DialogCoffee        *coffee;
    DialogIceDispenser  *ice;
    DialogSyrup         *syrup;
    DialogOutlet        *outlet;
    DialogBarcode       *barcode;
    DialogMonitor       *monitor;
    DialogIcecream      *icecream;
    DialogSlush         *slush;
};

#endif // DIALOGSETTING_H
