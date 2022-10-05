#ifndef DialogSoda_H
#define DialogSoda_H

#include <QDialog>
#include <QTimer>

#include "GlobalHeader.h"
#include "DialogStock.h"


namespace Ui {
class DialogSoda;
}

class DialogSoda : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSoda(QWidget *parent = nullptr, DialogStock *_stock = nullptr);
    ~DialogSoda();

    void DispenseSodaByTime(int type, int time_ms);
    void DispenseSodaByWeight(int type, int weight_g);
    void StartMeasure(int threshold);
    void RobotStop();
    void Tare();
    void SetCalibParam(int scale, int loadcell_id);

    int LoadcellValue();

    int IsSlushAvailable();
    QString soda_error;

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

    void on_BTN_DISPENSE_SODA_BY_TIME_clicked();

    void on_BTN_DISPENSE_COLD_BY_TIME_clicked();

    void on_BTN_DISPENSE_HOT_BY_TIME_clicked();

    void on_BTN_DISPENSE_SODA_BY_TIME_2_clicked();

    void on_BTN_DISPENSE_COLD_BY_WEIGHT_clicked();

    void on_BTN_DISPENSE_HOT_BY_WEIGHT_clicked();

private:
    Ui::DialogSoda *ui;
    QTimer timer;
    DialogStock *stock;
};

#endif // DialogSoda_H
