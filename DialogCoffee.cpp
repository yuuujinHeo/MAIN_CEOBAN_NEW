#include "DialogCoffee.h"
#include "ui_DialogCoffee.h"
#include "DialogSetting.h"
#include <iostream>

using namespace std;
extern DialogSetting    *psetting;
extern Logger   *plog;
static ushort crcPolynomTable[] =
{
    0x0000,0xc0c1,0xc181,0x0140,0xc301,0x03c0,0x0280,0xc241,
    0xc601,0x06c0,0x0780,0xc741,0x0500,0xc5c1,0xc481,0x0440,
    0xcc01,0x0cc0,0x0d80,0xcd41,0x0f00,0xcfc1,0xce81,0x0e40,
    0x0a00,0xcac1,0xcb81,0x0b40,0xc901,0x09c0,0x0880,0xc841,
    0xd801,0x18c0,0x1980,0xd941,0x1b00,0xdbc1,0xda81,0x1a40,
    0x1e00,0xdec1,0xdf81,0x1f40,0xdd01,0x1dc0,0x1c80,0xdc41,
    0x1400,0xd4c1,0xd581,0x1540,0xd701,0x17c0,0x1680,0xd641,
    0xd201,0x12c0,0x1380,0xd341,0x1100,0xd1c1,0xd081,0x1040,
    0xf001,0x30c0,0x3180,0xf141,0x3300,0xf3c1,0xf281,0x3240,
    0x3600,0xf6c1,0xf781,0x3740,0xf501,0x35c0,0x3480,0xf441,
    0x3c00,0xfcc1,0xfd81,0x3d40,0xff01,0x3fc0,0x3e80,0xfe41,
    0xfa01,0x3ac0,0x3b80,0xfb41,0x3900,0xf9c1,0xf881,0x3840,
    0x2800,0xe8c1,0xe981,0x2940,0xeb01,0x2bc0,0x2a80,0xea41,
    0xee01,0x2ec0,0x2f80,0xef41,0x2d00,0xedc1,0xec81,0x2c40,
    0xe401,0x24c0,0x2580,0xe541,0x2700,0xe7c1,0xe681,0x2640,
    0x2200,0xe2c1,0xe381,0x2340,0xe101,0x21c0,0x2080,0xe041,
    0xa001,0x60c0,0x6180,0xa141,0x6300,0xa3c1,0xa281,0x6240,
    0x6600,0xa6c1,0xa781,0x6740,0xa501,0x65c0,0x6480,0xa441,
    0x6c00,0xacc1,0xad81,0x6d40,0xaf01,0x6fc0,0x6e80,0xae41,
    0xaa01,0x6ac0,0x6b80,0xab41,0x6900,0xa9c1,0xa881,0x6840,
    0x7800,0xb8c1,0xb981,0x7940,0xbb01,0x7bc0,0x7a80,0xba41,
    0xbe01,0x7ec0,0x7f80,0xbf41,0x7d00,0xbdc1,0xbc81,0x7c40,
    0xb401,0x74c0,0x7580,0xb541,0x7700,0xb7c1,0xb681,0x7640,
    0x7200,0xb2c1,0xb381,0x7340,0xb101,0x71c0,0x7080,0xb041,
    0x5000,0x90c1,0x9181,0x5140,0x9301,0x53c0,0x5280,0x9241,
    0x9601,0x56c0,0x5780,0x9741,0x5500,0x95c1,0x9481,0x5440,
    0x9c01,0x5cc0,0x5d80,0x9d41,0x5f00,0x9fc1,0x9e81,0x5e40,
    0x5a00,0x9ac1,0x9b81,0x5b40,0x9901,0x59c0,0x5880,0x9841,
    0x8801,0x48c0,0x4980,0x8941,0x4b00,0x8bc1,0x8a81,0x4a40,
    0x4e00,0x8ec1,0x8f81,0x4f40,0x8d01,0x4dc0,0x4c80,0x8c41,
    0x4400,0x84c1,0x8581,0x4540,0x8701,0x47c0,0x4680,0x8641,
    0x8201,0x42c0,0x4380,0x8341,0x4100,0x81c1,0x8081,0x4040
};


DialogCoffee::DialogCoffee(QWidget *parent, DialogStock *_stock) :
    QDialog(parent), stock(_stock),
    ui(new Ui::DialogCoffee)
{
    ui->setupUi(this);

    SetComboBox();

    coffee_connection = false;
    coffee_data_connection = false;
    coffee_data_count = 100;

    coffee_detail_L = coffee_detail_R = 0;
    memset(&module_status, 0, sizeof(module_status));
    memset(&module_process, 0, sizeof(module_process));

    port = new QSerialPort(this);
    connect(port, SIGNAL(readyRead()), this, SLOT(ReadData()));

    sequence_number = 0;

    setting.name = "ttyS5";
    setting.dataBits = QSerialPort::Data8;
    setting.stopBits = QSerialPort::OneStop;
    setting.parity = QSerialPort::NoParity;
    setting.flowControl = QSerialPort::NoFlowControl;
    setting.baudRate = 115200;

//    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
//        plog->write("[COFFEE] PORT : "+port.portName());

//        setting.name = port.portName();
//    }

    db = QSqlDatabase::addDatabase("QSQLITE", "DB_LOADCELL2");
    db.setDatabaseName(DB_NAME_LOADCELL);
    db.open();

#ifdef ICECREAM_VER
#else
    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(500);

    connect(&askTimer, SIGNAL(timeout()), this, SLOT(onAsk()));
    askTimer.start(1000);
#endif
}

DialogCoffee::~DialogCoffee()
{
    delete ui;
}

bool DialogCoffee::OpenSerialPort(){
    port->setPortName(setting.name);
    port->setBaudRate(setting.baudRate);
    port->setDataBits(setting.dataBits);
    port->setParity(setting.parity);
    port->setStopBits(setting.stopBits);
    port->setFlowControl(setting.flowControl);

    if(port->open(QIODevice::ReadWrite)){
        // open success
        plog->write("[COFFEE] Serial : "+setting.name+" Open Success");
        return true;
    }else{
        plog->write("[COFFEE] Serial : "+setting.name+" Open Fail");
        // open error
        return false;
    }
}

void DialogCoffee::CloseSerialPort(){
    if(port->isOpen()){
        plog->write("[COFFEE] Close Port");
        port->close();
    }
}

void DialogCoffee::SetComboBox(){
    coffee_desc_btn = stock->coffee_desc_btn;
    QStringList keys = coffee_desc_btn.keys();
    for(int i=0; i<keys.size(); i++){
        ui->CB_LIST->addItem(keys[i]);
    }
}

void DialogCoffee::onAsk(){
    static unsigned int connect_try = 3;
    static unsigned int ask_message_info_count = 0;
    static unsigned int data_fail_count = 0;

    connect_try++;
    if(connect_try%5 == 0){
        if(!(port->isOpen())){
            data_fail_count = 0;
            totalData.clear();
            OpenSerialPort();
        }
    }

    if(port->isOpen()){
        coffee_connection = true;
        coffee_data_count++;
        if(coffee_data_count > 10){
            if(coffee_data_connection == true)
                plog->write("[COFFEE] Disconnected!!");

            coffee_data_connection = false;
        }else{
            if(coffee_data_connection == false)
                plog->write("[COFFEE] Connected!!");

            data_fail_count = 0;
            coffee_data_connection = true;
        }
        if((machine_status.b.InfoMessageSet_e == 1) && (ask_message_info_count%5 == 0)){
//            qDebug() << "GetInfoMessage";
            GetInfoMessage();
        }else{
            DoAskStatus();
        }
        ask_message_info_count++;
        if(coffee_connection == true && coffee_data_connection == false){
            qDebug() << "Coffee Connected BUT Data Not Connected -- DoAskStatus()";
            data_fail_count++;
            if(data_fail_count > 5){
                CloseSerialPort();
                qDebug() << "CloseSerialPort()";
            }
        }else{
            data_fail_count = 0;
        }
    }else{
        coffee_connection = false;
        coffee_data_connection = false;
    }
}

void DialogCoffee::onTimer(){
//    qDebug() << "coffee timer";
    if(IS_UI_LOCK){
        ui->GB_COFFEE->setEnabled(false);
    }else{
        ui->GB_COFFEE->setEnabled(true);
    }

    if(coffee_connection == true){
        SetLEColor(ui->LE_COFFEE_CONNECTION, COLOR_GOOD);
    }else{
        SetLEColor(ui->LE_COFFEE_CONNECTION, COLOR_BAD);
    }
    if(coffee_data_connection == true){
        SetLEColor(ui->LE_COFFEE_DATA_CONNECTION, COLOR_GOOD);
    }else{
        SetLEColor(ui->LE_COFFEE_DATA_CONNECTION, COLOR_BAD);
    }

    if(machine_status.b.JustReset_e == 1){
        if(machine_status.b.JustReset_e == 0)
            plog->write("[COFFEE] Machine State : Machine Just Reset");
        SetLEColor(ui->LE_MACHINE_JUST_RESET, COLOR_BLUE);
    }else{
        SetLEColor(ui->LE_MACHINE_JUST_RESET, COLOR_NONE);
    }
    if(machine_status.b.RequestSet_e == 1){
        if(machine_status.b.RequestSet_e == 0)
            plog->write("[COFFEE] Machine State : Machine Request Set");
        SetLEColor(ui->LE_MACHINE_REQUEST_SET, COLOR_BLUE);
    }else{
        SetLEColor(ui->LE_MACHINE_REQUEST_SET, COLOR_NONE);
    }
    if(machine_status.b.InfoMessageSet_e == 1){
        if(machine_status.b.InfoMessageSet_e == 0)
            plog->write("[COFFEE] Machine State : Machine Info Message Set");
        SetLEColor(ui->LE_MACHINE_INFO_MSG_SET, COLOR_BLUE);
    }else{
        SetLEColor(ui->LE_MACHINE_INFO_MSG_SET, COLOR_NONE);
    }
    if(machine_status.b.ProductDump_e == 1){
        if(machine_status.b.ProductDump_e == 0)
            plog->write("[COFFEE] Machine State : Product Dump");
        SetLEColor(ui->LE_MACHINE_PRODUCT_DUMP, COLOR_BLUE);
    }else{
        SetLEColor(ui->LE_MACHINE_PRODUCT_DUMP, COLOR_NONE);
    }
    if(machine_status.b.EditMode_e == 1){
        if(machine_status.b.EditMode_e == 0)
            plog->write("[COFFEE] Machine State : Edit Mode");
        SetLEColor(ui->LE_MACHINE_EDIT_MODE, COLOR_BLUE);
    }else{
        SetLEColor(ui->LE_MACHINE_EDIT_MODE, COLOR_NONE);
    }
    if(machine_status.b.SteamBoilerWaterLevel_e == 1){
        if(machine_status.b.SteamBoilerWaterLevel_e == 0)
            plog->write("[COFFEE] Machine State : Water Level");
        SetLEColor(ui->LE_MACHINE_WATER_LEVEL, COLOR_BLUE);
    }else{
        SetLEColor(ui->LE_MACHINE_WATER_LEVEL, COLOR_NONE);
    }
    if(machine_status.b.Standby_e == 1){
        if(machine_status.b.Standby_e == 0)
            plog->write("[COFFEE] Machine State : Standby");
        SetLEColor(ui->LE_MACHINE_STAND_BY, COLOR_BLUE);
    }else{
        SetLEColor(ui->LE_MACHINE_STAND_BY, COLOR_NONE);
    }

    if(machine_status.b.InfoMessageSet_e == 1){
//        stock->stock["COFFEE"].error = 1;
//        stock->stock["MILK"].error = 1;
    }else{
        if(module_status.coffee_L_status == OnlyCoffeeUnitReady){
            stock->stock["COFFEE"].error = 0;
//            stock->stock["MILK"].error = 1;
        }else if(module_status.coffee_L_status == OnlyMilkUnitReady){
//            stock->stock["COFFEE"].error = 1;
            stock->stock["MILK"].error = 0;
        }else{
            stock->stock["COFFEE"].error = 0;
         //   stock->stock["MILK"].error = 0;
        }
    }
    switch(module_status.coffee_L_status){
    case notReady_e:
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_NOT_READY, COLOR_BLUE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_COFFEE_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_MILK_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_UNDEF, COLOR_NONE);
        break;
    case Ready_e:
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_NOT_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_READY, COLOR_BLUE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_COFFEE_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_MILK_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_UNDEF, COLOR_NONE);
        break;
    case OnlyCoffeeUnitReady:
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_NOT_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_COFFEE_READY, COLOR_BLUE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_MILK_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_UNDEF, COLOR_NONE);
        break;
    case OnlyMilkUnitReady:
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_NOT_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_COFFEE_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_MILK_READY, COLOR_BLUE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_UNDEF, COLOR_NONE);
        break;
    case Undef_e:
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_NOT_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_COFFEE_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_ONLY_MILK_READY, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_L_M_STATUS_UNDEF, COLOR_BLUE);
        break;
    }

    switch(module_status.water_status){
    case notReady_e:
        SetLEColor(ui->LE_WATER_M_STATUS_NOT_READY, COLOR_BLUE);
        SetLEColor(ui->LE_WATER_M_STATUS_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_COFFEE_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_MILK_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_UNDEF, COLOR_NONE);
        break;
    case Ready_e:
        SetLEColor(ui->LE_WATER_M_STATUS_NOT_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_READY, COLOR_BLUE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_COFFEE_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_MILK_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_UNDEF, COLOR_NONE);
        break;
    case OnlyCoffeeUnitReady:
        SetLEColor(ui->LE_WATER_M_STATUS_NOT_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_COFFEE_READY, COLOR_BLUE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_MILK_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_UNDEF, COLOR_NONE);
        break;
    case OnlyMilkUnitReady:
        SetLEColor(ui->LE_WATER_M_STATUS_NOT_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_COFFEE_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_MILK_READY, COLOR_BLUE);
        SetLEColor(ui->LE_WATER_M_STATUS_UNDEF, COLOR_NONE);
        break;
    case Undef_e:
        SetLEColor(ui->LE_WATER_M_STATUS_NOT_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_COFFEE_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_ONLY_MILK_READY, COLOR_NONE);
        SetLEColor(ui->LE_WATER_M_STATUS_UNDEF, COLOR_BLUE);
        break;
    }



    ui->LE_COFFEE_L_M_ACTION->setText(module_action_name[module_status.coffee_L_action]);
    ui->LE_WATER_M_ACTION->setText(module_action_name[module_status.water_action]);


    ui->LE_COFFEE_L_PRODUCT_KEY->setText(QString().sprintf("%d", product_keyid.coffee_L_productID));
    ui->LE_WATER_PRODUCT_KEY->setText(QString().sprintf("%d", product_keyid.water_productID));

    if(uint(module_process.coffee_L_process) > uint(ProcessRequested_e)){
        ui->LE_COFFEE_L_M_PROCESS->setText(QString().sprintf("%d", module_process.coffee_L_process));
    }else{
        ui->LE_COFFEE_L_M_PROCESS->setText(module_process_name[module_process.coffee_L_process]);
    }
    ui->LE_WATER_M_PROCESS->setText(module_process_name[module_process.water_process]);



    switch(coffee_detail_L){
    case CoffeeAction_Undef_e:
        SetLEColor(ui->LE_COFFEE_DETAIL_UNDEF, COLOR_BLUE);
        SetLEColor(ui->LE_COFFEE_DETAIL_GRINDING, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_TAMPING_PREBREW, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_DISPENSING, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_PRESS_DROPCAKE, COLOR_NONE);
        break;
    case CoffeeAction_Grinding_e:
        SetLEColor(ui->LE_COFFEE_DETAIL_UNDEF, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_GRINDING, COLOR_BLUE);
        SetLEColor(ui->LE_COFFEE_DETAIL_TAMPING_PREBREW, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_DISPENSING, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_PRESS_DROPCAKE, COLOR_NONE);
        break;
    case CoffeeAction_TampingAndPreBrew_e:
        SetLEColor(ui->LE_COFFEE_DETAIL_UNDEF, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_GRINDING, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_TAMPING_PREBREW, COLOR_BLUE);
        SetLEColor(ui->LE_COFFEE_DETAIL_DISPENSING, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_PRESS_DROPCAKE, COLOR_NONE);
        break;
    case CoffeeAction_Dispensing_e:
        SetLEColor(ui->LE_COFFEE_DETAIL_UNDEF, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_GRINDING, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_TAMPING_PREBREW, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_DISPENSING, COLOR_BLUE);
        SetLEColor(ui->LE_COFFEE_DETAIL_PRESS_DROPCAKE, COLOR_NONE);
        break;
    case CoffeeAction_PressAndDropCake_e:
        SetLEColor(ui->LE_COFFEE_DETAIL_UNDEF, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_GRINDING, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_TAMPING_PREBREW, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_DISPENSING, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_PRESS_DROPCAKE, COLOR_BLUE);
        break;
    default:
        SetLEColor(ui->LE_COFFEE_DETAIL_UNDEF, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_GRINDING, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_TAMPING_PREBREW, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_DISPENSING, COLOR_NONE);
        SetLEColor(ui->LE_COFFEE_DETAIL_PRESS_DROPCAKE, COLOR_NONE);
        ui->LE_COFFEE_DETAIL_UNKNOWN->setText(QString().sprintf("0x%02x", coffee_detail_L));
        break;
    }


    switch(milk_detail_L){
    case MilkAction_Undef_e:
        SetLEColor(ui->LE_MILK_DETAIL_UNDEF, COLOR_BLUE);
        SetLEColor(ui->LE_MILK_DETAIL_SUCTION_DETECTION, COLOR_NONE);
        SetLEColor(ui->LE_MILK_DETAIL_DISPENSING, COLOR_NONE);
        SetLEColor(ui->LE_MILK_DETAIL_RINSE, COLOR_NONE);
        break;
    case MilkAction_SuctionAndDetection_e:
        SetLEColor(ui->LE_MILK_DETAIL_UNDEF, COLOR_NONE);
        SetLEColor(ui->LE_MILK_DETAIL_SUCTION_DETECTION, COLOR_BLUE);
        SetLEColor(ui->LE_MILK_DETAIL_DISPENSING, COLOR_NONE);
        SetLEColor(ui->LE_MILK_DETAIL_RINSE, COLOR_NONE);
        break;
    case MilkAction_Dispensing_e:
        SetLEColor(ui->LE_MILK_DETAIL_UNDEF, COLOR_NONE);
        SetLEColor(ui->LE_MILK_DETAIL_SUCTION_DETECTION, COLOR_NONE);
        SetLEColor(ui->LE_MILK_DETAIL_DISPENSING, COLOR_BLUE);
        SetLEColor(ui->LE_MILK_DETAIL_RINSE, COLOR_NONE);
        break;
    case MilkAction_RinseAfterDispensing_e:
        SetLEColor(ui->LE_MILK_DETAIL_UNDEF, COLOR_NONE);
        SetLEColor(ui->LE_MILK_DETAIL_SUCTION_DETECTION, COLOR_NONE);
        SetLEColor(ui->LE_MILK_DETAIL_DISPENSING, COLOR_NONE);
        SetLEColor(ui->LE_MILK_DETAIL_RINSE, COLOR_BLUE);
        break;
    default:
        SetLEColor(ui->LE_MILK_DETAIL_UNDEF, COLOR_NONE);
        SetLEColor(ui->LE_MILK_DETAIL_SUCTION_DETECTION, COLOR_NONE);
        SetLEColor(ui->LE_MILK_DETAIL_DISPENSING, COLOR_NONE);
        SetLEColor(ui->LE_MILK_DETAIL_RINSE, COLOR_NONE);
        ui->LE_MILK_DETAIL_UNKNOWN->setText(QString().sprintf("0x%02x", milk_detail_L));
        break;
    }


    if(machine_status.b.InfoMessageSet_e == 1){
        ;
    }else{
        ui->LW_INFO_MSG->clear();
//        stock->ClearDeviceError("COFFEE");
//        stock->ClearDeviceError("MILK");
    }
}




void DialogCoffee::ReadData(){


    QByteArray data = port->readAll();
    totalData.push_back(data);

    while(1){
//        qDebug() << "IIII";
        if(totalData.size() < 14){
            break;
        }
        if(uchar(totalData[0]) != SOH_e){
            totalData.remove(0, 1);
//            qDebug() << "remove 1 byte";
            continue;
        }
        int have_eot = 0;
        for(int i=0; i<totalData.size(); i++){
            if(uchar(totalData[i]) == EOT_e){
                QByteArray telegram = totalData.mid(1, i-1);

//                cout << "recv: ";
//                for(int j=0; j<i+1; j++){
//                    printf("0x%02x ", (uchar)(totalData[j]));
//                }
//                cout << endl;

//                cout << "crop: ";
//                for(int j=0; j<telegram.size(); j++){
//                    printf("0x%02x ", (uchar)(telegram[j]));
//                }
//                cout << endl;
//                qDebug() << "start parsing";
//                qDebug() << "lets remove " << i+1 << ", " << totalData.size();
                DoParsing(telegram);
                totalData.remove(0, i+1);
//                qDebug() << "total remove , " << totalData.size() << "\n";
                have_eot = 1;
                break;
            }
        }
        if(have_eot == 0){
            break;
        }
    }

}



void DialogCoffee::WriteData(const QByteArray &data){
    port->write(data);
    port->waitForBytesWritten(200);
}
void DialogCoffee::WriteData(const char *data, int cnt){
    port->write(data, cnt);
    port->waitForBytesWritten(200);
}

bool DialogCoffee::IsOpen(){
    return port->isOpen();
}

QSerialPort* DialogCoffee::GetPort(){
    return port;
}

ushort DialogCoffee::CalculateCRC(uchar *data, int len){
    ushort checksum;
    checksum = CRC_INIT;

    for (int nIndex = 0; nIndex < len; nIndex++){
        checksum = (ushort)((checksum >> 8) ^ crcPolynomTable[(checksum ^ data[nIndex]) & 0xFF]);
    }
    return checksum;
}

int DialogCoffee::DoParsing(QByteArray input_data){
    QByteArray data;

//    qDebug() << "Do Parsing!!";

    for(int i=0; i<input_data.size(); i++){
        if(i == input_data.size()-1){
            data.push_back(input_data[i]);
        }else{
            if(uchar(input_data[i]) == 0x10){
                if(uchar(input_data[i+1]) == 0x40 || uchar(input_data[i+1]) == 0x41 || uchar(input_data[i+1]) == 0x42 ||
                        uchar(input_data[i+1]) == 0x43 || uchar(input_data[i+1]) == 0x44 || uchar(input_data[i+1]) == 0x4A ||
                        uchar(input_data[i+1]) == 0x4D || uchar(input_data[i+1]) == 0x50 || uchar(input_data[i+1]) == 0x57){
                    data.push_back(uchar(input_data[i+1]-0x40));
                    i++;
                }
            }else{
                data.push_back(input_data[i]);
            }
        }
    }

    if(uchar(data[1]) == 0x6A){
        // ACK
//        qDebug() << "ACK";
        return 0;
    }

//    cout << "modi: ";
//    for(int j=0; j<data.size(); j++){
//        printf("0x%02x ", (uchar)(data[j]));
//    }
//    cout << endl;


    uchar s_pip = data[0];
    uchar s_pie = data[1];
    uchar s_pn = data[2];
    uchar s_sa = data[3];
    uchar s_da = data[4];
    uchar s_mi = data[5];
    ushort s_mp = ushort(data[6] | (data[7]<<8));
    ushort s_dl = ushort(data[8] | (data[9]<<8));

    QByteArray real_data;
    for(int i=0; i<s_dl; i++){
        real_data.push_back(data[10+i]);
    }
    ushort s_crc = ushort(uchar(data[10+s_dl]) | (uchar(data[11+s_dl])<<8));
    ushort calc_crc = CalculateCRC(reinterpret_cast<uchar*>(data.data()), 10+s_dl);

//    cout << "crc: ";
//    printf("0x%02x 0x%02x", (uchar)(data[10+s_dl]), (uchar)(data[11+s_dl]));
//    cout << endl;
//    qDebug() << "real_data size: " << real_data.size() << ", " << input_data.size();

    //
    if(s_crc == calc_crc){
        // success
//        qDebug() << "CRC SUCCESS!!";

        if(s_mi == GetApiVersion_e){
            if(s_dl == real_data.size()){
                api_version.api_version_major = real_data[0];
                api_version.api_version_minor = real_data[1];
                api_version.api_version_revision = real_data[2];
            }else{
                qDebug() << "GetApiVersion Size miss match " << s_dl << ", " << real_data.size();
            }
        }else if(s_mi == GetStatus_e){
//            qDebug() << "GetStatus_e";
            if(s_dl == real_data.size()){
                machine_status.B[0] = uchar(real_data[0]);
                module_status.coffee_L_action = (((uchar(real_data[1]))>>4)&0x0F);
                module_status.coffee_R_action = (((uchar(real_data[2]))>>4)&0x0F);
                module_status.steam_L_action = (((uchar(real_data[3]))>>4)&0x0F);
                module_status.steam_R_action = (((uchar(real_data[4]))>>4)&0x0F);
                module_status.water_action = (((uchar(real_data[5]))>>4)&0x0F);

                module_status.coffee_L_status = ((uchar(real_data[1]))&0x0F);
                module_status.coffee_R_status = ((uchar(real_data[2]))&0x0F);
                module_status.steam_L_status = ((uchar(real_data[3]))&0x0F);
                module_status.steam_R_status = ((uchar(real_data[4]))&0x0F);
                module_status.water_status = ((uchar(real_data[5]))&0x0F);

                module_process.coffee_L_process = uchar(real_data[6]);
                module_process.coffee_R_process = uchar(real_data[7]);
                module_process.steam_L_process = uchar(real_data[8]);
                module_process.steam_R_process = uchar(real_data[9]);
                module_process.water_process = uchar(real_data[10]);

                coffee_detail_L = (((uchar(real_data[11]))>>4)&0x0F);
                coffee_detail_R = ((uchar(real_data[11]))&0x0F);
                milk_detail_L = (((uchar(real_data[12]))>>4)&0x0F);
                milk_detail_R = ((uchar(real_data[12]))&0x0F);

                product_keyid.coffee_L_productID = uchar(real_data[13]);
                product_keyid.coffee_R_productID = uchar(real_data[14]);
                product_keyid.steam_L_productID = uchar(real_data[15]);
                product_keyid.steam_R_productID = uchar(real_data[16]);
                product_keyid.water_productID = uchar(real_data[17]);

                coffee_data_count = 0;
            }else{
                qDebug() << "GetStatus_e Size miss match " << s_dl << ", " << real_data.size();
            }
        }else if(s_mi == GetInfoMessages_e){
            if(s_dl == real_data.size()){
                int check_warn = 0;
                int check_stop = 0;
                int check_error = 0;
                int index = 0;
                QByteArray warn_array;
                QByteArray stop_array;
                QByteArray error_array;
                while(1){
                    if(check_warn == 0){
                        int warn_num = uchar(real_data[index]);
                        index++;
                        for(int i=0; i<warn_num; i++){
                            warn_array.push_back(uchar(real_data[index]));
                            index++;
                        }
                        check_warn = 1;
                    }else if(check_stop == 0){
                        int stop_num = uchar(real_data[index]);
                        index++;
                        for(int i=0; i<stop_num; i++){
                            stop_array.push_back(uchar(real_data[index]));
                            index++;
                        }
                        check_stop = 1;
                    }else if(check_error == 0){
                        int error_num = uchar(real_data[index]);
                        index++;
                        for(int i=0; i<error_num; i++){
                            error_array.push_back(uchar(real_data[index]));
                            index++;
                        }
                        check_error = 1;
                    }else{
                        break;
                    }
                }

                ui->LW_INFO_MSG->clear();
//                qDebug() << "Warning:";
                for(int i=0; i<warn_array.size(); i++){
//                    qDebug() << int(warn_array[i]);
                    ui->LW_INFO_MSG->addItem(QString().sprintf("W: %d", int(warn_array[i])));
                    if(int(warn_array[i]) == 18){
                        stock->SetDeviceError("MILK");
                    }
                }
//                qDebug() << "Stop:";
                for(int i=0; i<stop_array.size(); i++){
//                    qDebug() << int(stop_array[i]);
                    ui->LW_INFO_MSG->addItem(QString().sprintf("S: %d", int(stop_array[i])));
                }
//                qDebug() << "Error:";
                for(int i=0; i<error_array.size(); i++){
//                    qDebug() << int(error_array[i]);
                    ui->LW_INFO_MSG->addItem(QString().sprintf("E: %d", int(error_array[i])));
                }

                coffee_data_count = 0;
            }else{
                qDebug() << "GetInfoMessages Size miss match " << s_dl << ", " << real_data.size();
            }
        }

    }else{
        // fail
        qDebug() << "CRC FAIL!!";
        qDebug() << "Data Size: " << s_dl << ", " << real_data.size();
    }



    // general display
    ui->LE_PIP->setText(QString().sprintf("0x%02x", uchar(s_pip)));
    ui->LE_PIE->setText(QString().sprintf("0x%02x", uchar(s_pie)));
    ui->LE_PN->setText(QString().sprintf("0x%02x", uchar(s_pn)));
    ui->LE_SA->setText(QString().sprintf("0x%02x", uchar(s_sa)));
    ui->LE_DA->setText(QString().sprintf("0x%02x", uchar(s_da)));

    ui->LE_MI->setText(QString().sprintf("0x%02x", uchar(s_mi)));
    ui->LE_MP->setText(QString().sprintf("%d", uchar(s_mp)));
    ui->LE_DL->setText(QString().sprintf("%d", uchar(s_dl)));

    QString str_data;
    for(int i=0; i<real_data.size(); i++){
        str_data += QString().sprintf("0x%02x ", uchar(real_data[i]));
    }
    ui->LE_DATA->setText(str_data);

    ui->LE_CRC->setText(QString().sprintf("0x%02x 0x%02x", s_crc&0xFF, ((s_crc>>8)&0xFF)));
    ui->LE_CRC_2->setText(QString().sprintf("0x%02x 0x%02x", calc_crc&0xFF, ((calc_crc>>8)&0xFF)));

    return true;
}

QByteArray DialogCoffee::GeneratePacket(uchar packet_type, uchar command_type, ushort msg_param, ushort data_len, QByteArray input_data){
    QByteArray data;
    data.push_back(uchar(0x00));
    data.push_back(packet_type);
    data.push_back(sequence_number++);
    data.push_back(uchar(0x42));
    data.push_back(uchar(0x41));
    data.push_back(command_type);
    data.push_back(uchar(msg_param&0xFF));
    data.push_back(uchar((msg_param>>8)&0xFF));
    data.push_back(uchar(data_len&0xFF));
    data.push_back(uchar((data_len>>8)&0xFF));
    data.push_back(input_data);

    QByteArray send_data = MakeTelegram(data);
    return send_data;
}

QByteArray DialogCoffee::MakeTelegram(QByteArray data){
    QByteArray ret;

    // first append crc
    ushort crc = CalculateCRC(reinterpret_cast<uchar*>(data.data()), data.size());
    data.append(crc&0xFF);
    data.append((crc>>8)&0xFF);

    // stuffing
    for(int i=0; i<data.size(); i++){
        if(uchar(data[i]) == 0x00 || uchar(data[i]) == 0x01 || uchar(data[i]) == 0x02 || uchar(data[i]) == 0x03 || uchar(data[i]) == 0x04 ||
                uchar(data[i]) == 0x0A || uchar(data[i]) == 0x0D || uchar(data[i]) == 0x10 || uchar(data[i]) == 0x17){
            ret.push_back(uchar(0x10));
            ret.push_back(uchar(0x40+data[i]));
        }else{
            ret.push_back(data[i]);
        }
    }
    ret.push_front(SOH_e);
    ret.push_back(EOT_e);
    return ret;
}

void DialogCoffee::DoAskStatus(){
    QByteArray data;
    QByteArray send_data = GeneratePacket(PIE_REQUEST, GetStatus_e, 0, 0, data);
    WriteData(send_data);
}

void DialogCoffee::DoProduct(int product_number){
    QByteArray data;
    data.push_back(product_number);
    QByteArray send_data = GeneratePacket(PIE_COMMAND, DoProductOfDisplay_e, 0, 1, data);
    WriteData(send_data);
}

void DialogCoffee::DoRinse(){
    QByteArray data;
    QByteArray send_data = GeneratePacket(PIE_COMMAND, DoRinse_e, 0, 0, data);
    WriteData(send_data);
}

void DialogCoffee::SendDisplayAction(int display_action){
    QByteArray data;
    QByteArray send_data = GeneratePacket(PIE_COMMAND, DisplayAction_e, display_action, 0, data);
    WriteData(send_data);
}

void DialogCoffee::GetInfoMessage(){
    QByteArray data;
    data.push_back(uchar(0x00));
    data.push_back(uchar(0x00));
    data.push_back(uchar(0x00));
    QByteArray send_data = GeneratePacket(PIE_REQUEST, GetInfoMessages_e, 0, 3, data);
    WriteData(send_data);
}

void DialogCoffee::on_BTN_COFFEE_MAKE_clicked(){
    QString btn = coffee_desc_btn[ui->CB_LIST->currentText()];
    plog->write("[COFFEE] Make Coffee : "+ui->CB_LIST->currentText());
    DoProduct(btn.toInt());
}

void DialogCoffee::on_BTN_BEAN_HOPPER_REFILLED_clicked(){
    plog->write("[COFFEE] Refilled Bean Hopper");
    SendDisplayAction(DA_BeanHopperRefilled_e);
}
