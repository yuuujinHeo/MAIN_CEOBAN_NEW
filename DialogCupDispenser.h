#ifndef DIALOGCUPDISPENSER_H
#define DIALOGCUPDISPENSER_H

#include <QDialog>
#include <QTimer>

#include "GlobalHeader.h"

#include "DialogStock.h"


namespace Ui {
class DialogCupDispenser;
}

class DialogCupDispenser : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCupDispenser(QWidget *parent = nullptr, DialogStock *_stock = nullptr);
    ~DialogCupDispenser();

    void DispenseCup(int target);

    QString cup_1_error;
    QString cup_2_error;
    QString cup_3_error;
    QString cup_4_error;


    void CheckFatalError();

    int IsCupAvailable(int dev);
    void error_clear();

    int FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_1;
    int FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_2;
    int FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_3;
    int FATAL_INFO_CUP_DEVICE_CONNECTION_ERROR_4;

    // working 중에 체크
    int FATAL_INFO_CUP_DISPENSER_ERROR_1;
    int FATAL_INFO_CUP_DISPENSER_ERROR_2;
    int FATAL_INFO_CUP_DISPENSER_ERROR_3;
    int FATAL_INFO_CUP_DISPENSER_ERROR_4;

    int FATAL_INFO_CUP_SENSOR_ERROR_1;
    int FATAL_INFO_CUP_SENSOR_ERROR_2;
    int FATAL_INFO_CUP_SENSOR_ERROR_3;
    int FATAL_INFO_CUP_SENSOR_ERROR_4;

    int SUPER_FATAL_ERROR_CUP_SENSOR_CONNECTION;
    int SUPER_FATAL_ERROR_CUP_SENSOR_ERROR;

    int PAUSE_FATAL_ERROR_CUP_DISPENSER;
    int PAUSE_FATAL_ERROR_CUP_SOLDOUT;

public slots:
    void onTimer();

private slots:
    void on_BTN_CUP_DISPENSE_1_clicked();
    void on_BTN_CUP_DISPENSE_2_clicked();
    void on_BTN_CUP_DISPENSE_3_clicked();
    void on_BTN_CUP_DISPENSE_4_clicked();

private:
    Ui::DialogCupDispenser *ui;
    QTimer timer;

    DialogStock *stock;
};

#endif // DIALOGCUPDISPENSER_H
