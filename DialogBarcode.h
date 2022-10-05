#ifndef DIALOGBARCODE_H
#define DIALOGBARCODE_H

#include <QDialog>
#include <QTimer>

#include "GlobalHeader.h"
#include <QtSerialPort>

#define PLATFORM_NUMBER "074612"

namespace Ui {
class DialogBarcode;
}

class DialogBarcode : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBarcode(QWidget *parent = nullptr);
    ~DialogBarcode();

    bool isOpenPort();
    int NewInputNotification;
    QString NewBarcodePin;
    QSerialPort *m_serialPort = nullptr;

public slots:
    void onTimer();
    void readData();
    void handleError(QSerialPort::SerialPortError error);

private:
    Ui::DialogBarcode *ui;
    QTimer timer;
    QByteArray datas;
    int readCount;
    int readFlag;
};

#endif // DIALOGBARCODE_H
