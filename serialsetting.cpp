#include "serialsetting.h"

SerialSetting::SerialSetting()
{
    serialPort = new QSerialPort();
    connect(serialPort, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(serialPort, SIGNAL(errorOccurred(QSerialPort::SerialPortError)),this, SLOT(handleError(QSerialPort::SerialPortError)));
}
