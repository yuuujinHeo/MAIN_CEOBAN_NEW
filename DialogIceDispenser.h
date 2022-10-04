#ifndef DIALOGICEDISPENSER_H
#define DIALOGICEDISPENSER_H

#include <QDialog>
#include <QTimer>
#include <QSerialPort>

#include "GlobalHeader.h"

#ifdef ICECREAM_VER
#include "DialogStock_icecream.h"
#else
#include "DialogStock.h"
#endif


namespace Ui {
class DialogIceDispenser;
}

class DialogIceDispenser : public QDialog
{
    Q_OBJECT

public:
    explicit DialogIceDispenser(QWidget *parent = nullptr, DialogStock *_stock = nullptr);
    ~DialogIceDispenser();

    void DispenseIceWater(int target, int ice_time_ms, int water_time_ms);
    void ChangeCommMode(int target, int comm_mode, int cup_ignore);
    void ClearStatus(int target);
    void SetTimeout(int target, int timeout);
    void Reboot(int target);
    void SetAmbientTemperature(int target, int tempL, int tempH);
    void RequestStatus();
    bool isOpenPort();

    QString ice_1_error;


    void CheckFatalError();

    int IsIceAvailable(int dev);

    QSerialPort *m_serialPort = nullptr;

    int FATAL_INFO_ICE_CONNECTION_ERROR_1;
    int FATAL_INFO_ICE_DEVICE_ERROR_1;

    int FORCE_FATAL_ERROR_ICE_CONNECTION;
    int FORCE_FATAL_ERROR_ICE_DEVICE;

    void WriteData(const QByteArray &data);
public slots:
    void onTimer();
    void readData();
    void handleError(QSerialPort::SerialPortError error);

private slots:
    void on_BTN_ICE_TEST_ICE_OUT_clicked();

    void on_BTN_ICE_CHANGE_COMM_MODE_clicked();

    void on_BTN_ICE_TEST_STATUS_CLEAR_clicked();

    void on_BTN_ICE_CHANGE_ICE_OUT_TIME_clicked();

    void on_BTN_ICE_TEST_REBOOT_clicked();

    void on_BTN_ICE_CHANGE_AMBIENT_TEMP_clicked();

private:
    Ui::DialogIceDispenser *ui;
    QTimer timer;

    int connectionCount;
    DialogStock *stock;
};

#endif // DIALOGICEDISPENSER_H
