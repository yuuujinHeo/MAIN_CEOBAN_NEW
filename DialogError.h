#ifndef DIALOGERROR_H
#define DIALOGERROR_H

#include <QDialog>
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
class DialogError;
}

class DialogError : public QDialog
{
    Q_OBJECT

public:
    explicit DialogError(QWidget *parent = nullptr, DialogStock *_stock = nullptr, DialogRobot *_robot = nullptr, DialogCupDispenser *_cup = nullptr,
                         DialogCoffee *_coffee = nullptr, DialogIceDispenser *_ice = nullptr,
                         DialogSyrup *_syrup = nullptr, DialogOutlet *_outlet = nullptr,
                         DialogBarcode *_barcode = nullptr, DialogMonitor *_monitor = nullptr,
                         DialogIcecream *_icecream = nullptr, DialogSlush *_slush = nullptr);
    ~DialogError();

    int UpdateError();
    void UpdateMenuAvailable();

private slots:
    void on_BTN_CLOSE_clicked();

    void on_BTN_ERROR_CLEAR_COFFEE_clicked();
    void on_BTN_ERROR_CLEAR_ICE_1_clicked();
    void on_BTN_ERROR_CLEAR_PAPER_CUP_1_clicked();
    void on_BTN_ERROR_CLEAR_PP_CUP_1_clicked();
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

private:
    Ui::DialogError *ui;

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

#endif // DIALOGERROR_H
