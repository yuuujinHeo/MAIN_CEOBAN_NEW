#ifndef DIALOGSLUSH_H
#define DIALOGSLUSH_H

#include <QDialog>
#include <QTimer>

#include "GlobalHeader.h"

#ifdef ICECREAM_VER
#include "DialogStock_icecream.h"
#else
#include "DialogStock.h"
#endif

namespace Ui {
class DialogSlush;
}

class DialogSlush : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSlush(QWidget *parent = nullptr, DialogStock *_stock = nullptr);
    ~DialogSlush();

//    void DispenseSlushByTime(int time_ms);
//    void DispenseSlushByWeight(int weight_g);
    void StartMeasure(int threshold);
    void RobotStop();
    void Tare();
    void SetCalibParam(int scale, int loadcell_id);

    int LoadcellValue();

    int IsSlushAvailable();
    QString slush_error;

public slots:
    void onTimer();

private slots:
    void on_BTN_DISPENSE_SLUSH_BY_TIME_clicked();
    void on_BTN_DISPENSE_SLUSH_BY_WEIGHT_clicked();
    void on_BTN_TARE_clicked();
    void on_BTN_SET_SCALE_clicked();

    void on_BTN_SET_SCALE_2_clicked();

    void on_BTN_START_MEASURE_clicked();

    void on_BTN_ROBOT_STOP_clicked();

private:
    Ui::DialogSlush *ui;
    QTimer timer;
    DialogStock *stock;
};

#endif // DIALOGSLUSH_H
