#ifndef DIALOGICECREAM_H
#define DIALOGICECREAM_H

#include <QDialog>
#include <QTimer>

#include "GlobalHeader.h"

#ifdef ICECREAM_VER
#include "DialogStock_icecream.h"
#else
#include "DialogStock.h"
#endif

namespace Ui {
class DialogIcecream;
}

class DialogIcecream : public QDialog
{
    Q_OBJECT

public:
    explicit DialogIcecream(QWidget *parent = nullptr, DialogStock *_stock = nullptr);
    ~DialogIcecream();

    void DispenseIcecreamByWeight(int weight_g);
    void StartMeasure(int threshold);
    void RobotStop();
    void Tare();
    void SetCalibParam(int scale, int loadcell_id);

    int LoadcellValue();

    int IsIcecreamAvailable();
    QString icecream_error;

public slots:
    void onTimer();

private slots:
    void on_BTN_SET_SCALE_2_clicked();

    void on_BTN_SET_SCALE_clicked();

    void on_BTN_TARE_clicked();

    void on_BTN_DISPENSE_ICECREAM_BY_WEIGHT_clicked();

    void on_BTN_ICECREAM_CLEANING_START_clicked();

    void on_BTN_ICECREAM_CLEANING_STOP_clicked();

    void on_BTN_START_MEASURE_clicked();

    void on_BTN_ROBOT_STOP_clicked();

private:
    Ui::DialogIcecream *ui;
    QTimer timer;
    DialogStock *stock;
};

#endif // DIALOGICECREAM_H
