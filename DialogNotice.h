#ifndef DIALOGNOTICE_H
#define DIALOGNOTICE_H

#include <QDialog>
#include <QTimer>
#include <QMessageBox>
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

namespace Ui {
class DialogNotice;
}

class DialogNotice : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNotice(QWidget *parent = nullptr, DialogStock *_stock = nullptr, DialogRobot *_robot = nullptr, DialogCupDispenser *_cup = nullptr,
                          DialogCoffee *_coffee = nullptr, DialogIceDispenser *_ice = nullptr,
                          DialogSyrup *_syrup = nullptr, DialogOutlet *_outlet = nullptr,
                          DialogBarcode *_barcode = nullptr, DialogMonitor *_monitor = nullptr,
                          DialogIcecream *_icecream = nullptr, DialogSlush *_slush = nullptr, DialogDoor *_door = nullptr);
    ~DialogNotice();

    void ShowInitNotice(QString error_code, QString details);
    void ShowOpNotice(QString error_code, QString details);
    void ShowOpStop(QString error_code, QString details);

signals:
    void cancel();
    void init_start();
    void op_start();

private slots:
    void onTimer();
    void on_BTN_INIT_CON_ROBOT_1_clicked();
    void on_BTN_INIT_CON_ROBOT_2_clicked();
    void on_BTN_INIT_CON_ROBOT_INIT_clicked();

    void on_BTN_INIT_CON_BOARD_1_clicked();

    void on_BTN_INIT_CON_BOARD_2_clicked();

    void on_BTN_INIT_CON_BOARD_INIT_clicked();

    void on_BTN_INIT_ROBOT_PROGRAM_EXIT_clicked();

    void on_BTN_INIT_ROBOT_INIT_clicked();

    void on_BTN_INIT_CANCEL_clicked();

    void on_BTN_INIT_DOOR_INIT_clicked();

    void on_BTN_OP_INIT_FIRST_clicked();

    void on_BTN_OP_OUTLET_1_clicked();

    void on_BTN_OP_OUTLET_START_clicked();

    void on_BTN_OUTLET_CELL_1_clicked();
    void on_BTN_OUTLET_CELL_2_clicked();
    void on_BTN_OUTLET_CELL_3_clicked();
    void on_BTN_OUTLET_CELL_4_clicked();
    void on_BTN_OUTLET_CELL_5_clicked();
    void on_BTN_OUTLET_CELL_6_clicked();

    void on_BTN_INIT_ROBOT_PROGRAM_EXIT_2_clicked();

    void on_BTN_OP_OUTLET_INIT_clicked();

    void on_BTN_INIT_DOOR_INIT_2_clicked();

    void on_BTN_SS_INIT_clicked();

    void on_BTN_SS_clicked();

    void on_BTN_SS_CANCEL_clicked();

    void on_BTN_SS_2_clicked();

    void on_BTN_SS_3_clicked();

    void on_BTN_OP_CANCEL_clicked();

    void on_BTN_INIT_CANCEL_5_clicked();

private:
    Ui::DialogNotice *ui;
    QTimer *timer;

    int currentState;

    DialogStock         *stock;
    DialogRobot         *robot;
    DialogCupDispenser  *cup;
    DialogCoffee        *coffee;
    DialogIceDispenser  *ice;
    DialogSyrup         *syrup;
    DialogOutlet        *outlet;
    DialogDoor          *door;
    DialogBarcode       *barcode;
    DialogMonitor       *monitor;
    DialogIcecream      *icecream;
    DialogSlush         *slush;
};

#endif // DIALOGNOTICE_H
