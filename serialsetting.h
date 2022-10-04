#ifndef SERIALSETTING_H
#define SERIALSETTING_H

#include <QSerialPort>
#include <QTimer>

class SerialSetting
{
public:
    SerialSetting();

    QString name;
    qint32 baudRate;
    QString stringBaudRate;
    QSerialPort::DataBits dataBits;
    QString stringDataBits;
    QSerialPort::Parity parity;
    QString stringParity;
    QSerialPort::StopBits stopBits;
    QString stringStopBits;
    QSerialPort::FlowControl flowControl;
    QString stringFlowControl;
    bool localEchoEnabled;

    bool OpenSerialPort();
    void CloseSerialPort();

    bool isOpen();
    QSerialPort *getPort();
    ushort calculateCRC(uchar *data, int len);
    QByteArray GeneratePacket(uchar packet_type, uchar command_type, ushort msg_param, ushort data_len, QByteArray input_data);
    QByteArray MakeTelegram(QByteArray data);
    int DoParsing(QByteArray input_data);

    void writeData(const QByteArray &data);
    void writeData(const char *data, int cnt);
    QSerialPort *serialPort;

private slots:
    void onTimer();
    void readyRead();
    void handleError(QSerialPort::SerialPortError error);

private:
    QTimer *timer;
};

#endif // SERIALSETTING_H
