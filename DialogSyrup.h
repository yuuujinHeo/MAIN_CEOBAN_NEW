#ifndef DIALOGSYRUP_H
#define DIALOGSYRUP_H

#include <QDialog>
#include <QTimer>
#include <QPushButton>

#include "GlobalHeader.h"

#ifdef ICECREAM_VER
#include "DialogStock_icecream.h"
#else
#include "DialogStock.h"
#endif


namespace Ui {
class DialogSyrup;
}

class DialogSyrup : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSyrup(QWidget *parent = nullptr, DialogStock *_stock = nullptr);
    ~DialogSyrup();


    void SetButtonName();

    void DispenseSyrupByTime(int pump_num, int time_ms);
    void DispenseSyrupByWeight(int pump_num, int weight_g);
    void Tare();
    void SetCalibParam(int scale);

    int LoadcellValue();

    void UI_TimeDispense(int num);
    void UI_WeightDispense(int num);


    QString syrup_error;
    bool start_cleaning;
    unsigned int state_cleaning;


public slots:
    void onTimer();

private slots:
    void on_BTN_DISPENSE_SYRUP_BY_TIME_1_clicked();
    void on_BTN_DISPENSE_SYRUP_BY_TIME_2_clicked();
    void on_BTN_DISPENSE_SYRUP_BY_TIME_3_clicked();
    void on_BTN_DISPENSE_SYRUP_BY_TIME_4_clicked();
    void on_BTN_DISPENSE_SYRUP_BY_TIME_5_clicked();
    void on_BTN_DISPENSE_SYRUP_BY_TIME_6_clicked();
    void on_BTN_DISPENSE_SYRUP_BY_TIME_7_clicked();
    void on_BTN_DISPENSE_SYRUP_BY_TIME_8_clicked();

    void on_BTN_DISPENSE_SYRUP_BY_WEIGHT_1_clicked();
    void on_BTN_DISPENSE_SYRUP_BY_WEIGHT_2_clicked();
    void on_BTN_DISPENSE_SYRUP_BY_WEIGHT_3_clicked();
    void on_BTN_DISPENSE_SYRUP_BY_WEIGHT_4_clicked();
    void on_BTN_DISPENSE_SYRUP_BY_WEIGHT_5_clicked();
    void on_BTN_DISPENSE_SYRUP_BY_WEIGHT_6_clicked();
    void on_BTN_DISPENSE_SYRUP_BY_WEIGHT_7_clicked();
    void on_BTN_DISPENSE_SYRUP_BY_WEIGHT_8_clicked();

    void on_BTN_TARE_clicked();
    void on_BTN_SET_SCALE_clicked();

    void on_BTN_CLEANING_clicked();

private:
    Ui::DialogSyrup *ui;
    QTimer timer;

    QVector<QPushButton*> buttons_time;
    QVector<QPushButton*> buttons_weight;

    DialogStock *stock;
};

#endif // DIALOGSYRUP_H
