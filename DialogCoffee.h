#ifndef DIALOGCOFFEE_H
#define DIALOGCOFFEE_H

#include <QDialog>
#include <QTimer>
#include <QList>
#include <QSerialPort>
#include <QSerialPortInfo>

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include "GlobalHeader.h"

#ifdef ICECREAM_VER
#include "DialogStock_icecream.h"
#else
#include "DialogStock.h"
#endif


#define DB_NAME_LOADCELL    "DB/loadcell"


enum SpecialChar_t
{
    NUL_e = 0x00, // NULL char
    SOH_e = 0x01, // Start of Header (begin of packet)
    STX_e = 0x02, // Start of Text
    ETX_e = 0x03, // End of Text
    EOT_e = 0x04, // End of Transmission
    LF_e = 0x0A, // Line Feed
    CR_e = 0x0D, // Carriage Return
    DLE_e = 0x10, // Shift Character
    ETB_e = 0x17, // End of Transmit Block (end of packet)
};

enum API_Command_t
{
    GetApiVersion_e = 0,
    GetStatus_e,
    DoProduct_e,
    DoRinse_e,
    StartCleaning_e,
    Reserved1_e,
    Reserved2_e,
    Reserved3_e,
    ScreenRinse_e,
    Reserved4_e,
    Reserved5_e, // 10
    Stop_e,
    GetRequests_e,
    GetInfoMessages_e,
    MilkOutletRinse_e,
    DisplayAction_e,
    GetProductDump_e,
    GetSensorValues_e,
    DoEtcCalibration_e,
    DoProductOfDisplay_e,
    GetProductParameters_e, // 20
    GetMachineCounters_e,
    BlockedScreenMode_e,
    GetBlockedScreenState_e,
    CustomScreen_e,
    CustomScreenState_e,
    SendOrder_e,
    GetOrder_e,
    MonitorText_e,
    DoSelectorProduct_e,
    GetSelectorProduct_e, // 30
    GetSerialNumbers_e,
};


enum CoffeeAction_t
{
    CoffeeAction_Undef_e = 0,
    CoffeeAction_Grinding_e, // Grinding process
    CoffeeAction_NotUsed1_e, // Not used (reserve)
    CoffeeAction_TampingAndPreBrew_e, // Tamping, Prebrew, Relax Time and Second Tamping
    CoffeeAction_Dispensing_e, // Coffee dispensing
    CoffeeAction_NotUsed2_e, // Not used (reserve)
    CoffeeAction_PressAndDropCake_e, // Squeeze out and drop the cake
};

enum MilkAction_t
{
    MilkAction_Undef_e = 0,
    MilkAction_NotUsed_e, // Not used (reserve)
    MilkAction_SuctionAndDetection_e, // Suck milk and try to detect it
    MilkAction_Dispensing_e, // Dispense milk
    MilkAction_RinseAfterDispensing_e, // Internal rinsing after product
};

enum ModuleStatus_t
{
    notReady_e = 0, // no product can be ordered
    Ready_e, // product can be ordered
    OnlyCoffeeUnitReady, // coffee product can be ordered, milk product not
    OnlyMilkUnitReady, // milk product can be ordered, coffee product not
    Undef_e = 0x0F
};

enum ModuleAction_t
{
    ActionIdle_e = 0, // No process is running, Product can be ordered
    ActionQueued_e, // Next product is already ordered and queued
    ActionSuspended_e, // Product process interrupted and waiting for an action
    // E.g. Bean hopper missing or empty, Groundsdrawer // missing
    ActionEnding_e, // Product is dispensed, Finish process sequences // Next product can already be ordered
    ActionEndCyc_e, // Only used for multi cyle products (end of one cylce) // Further cycles will be executed
    ActionStopped_e, // Process or product has been stopped // (user or machine abort)
    ActionStarted_e, // Product or process has been started
    ActionPumping_e, // Product is being dispensed or service function is // running
    ActionMilkInterrupt_e, // Milk tank is empty => Waiting for refilling
    ActionCycleAborted_e, // Abortion of a product cycle because of empty bean // hopper => Will jump to ActionSuspended
    ActionPwdrChute_e, // Only used for powder chute products // => Operator has to fill in powder and press “Continue”
    ActionCleanTabs_e, // Cleaning tabs empty during cleaning // => Waiting for refilling
    ActionPreheat_e, // If the function “Automatic Brew Group Pre-heating” is // activated (Machine Parameter Menu) and the brew group // hasn’t been used for more than 10 minutes // => Pre-heating of the brew group is performed
};
const QString module_action_name[]={
    "Idle",
    "Queued",
    "Suspended",
    "Ending",
    "EndCyc",
    "Stopped",
    "Started",
    "Pumping",
    "MiklInterrupt",
    "CycleAborted",
    "PwdrChute",
    "CleanTabs",
    "PreHeat"
};

enum ModuleProcess_t
{
    ProcessCoffee_e = 0,
    ProcessSteam_e,
    ProcessHotWater_e,
    ProcessLearnWaterQnty_e,
    ProcessPowderTest_e,
    ProcessClean_e,
    ProcessRinse_e,
    ProcessScreenRinse_e,
    ProcessServicePos_e,
    ProcessDePressurize_e,
    ProcessEmptyBoiler_e,
    ProcessAdjPumpPress_e,
    ProcessFlowMeterTest_e,
    ProcessGrinderSensorTest_e,
    ProcessMotIni_e,
    ProcessMotIniRebootAbort_e,
    ProcessBrewMoveTest_e,
    ProcessMilkClean_e,
    ProcessOutletRinse_e,
    ProcessEmptyCofBoiler_e,
    ProcessGrinderAdjustMenu_e,
    ProcessTestBallDispenser_e,
    ProcessTestMilkPump_e,
    ProcessMilkReactorWarmup_e,
    ProcessReducePressure_e,
    ProcessTestSecurityValve_e,
    ProcessDispenseBall_e,
    ProcessMilkDetectionTest_e,
    ProcessBrewTightnessTest_e,
    ProcessSteamBoilerAirPurge_e,
    ProcessDeblockGrinder_e,
    ProcessHotWaterTempCalibration_e,
    ProcessMilkInitRinse_e,
    ProcessShortCalibration_e,
    ProcessRequested_e,
    ProcessUndef_e = 0xFF
};

const QString module_process_name[256]={
    "Coffee",
    "Steam",
    "HotWater",
    "LearnWaterQnty",
    "PowderTest",
    "Clean",
    "Rinse",
    "ScreenRinse",
    "ServicePos",
    "DePressurize",
    "EmptyBoiler",
    "AdjPumpPress",
    "FlowMeterTest",
    "GrinderSensorTest",
    "MotIni",
    "MotIniRebootAbort",
    "BrewMoveTest",
    "MilkClean",
    "OutletRinse",
    "EmptyCofBoiler",
    "GrinderAdjustMenu",
    "TestBallDispenser",
    "TestMilkPump",
    "MilkReactorWarmup",
    "ReducePressure",
    "TestSecurityValve",
    "DispenseBall",
    "MilkDetectionTest",
    "BrewTightnessTest",
    "SteamBoilerAirPurge",
    "DeblockGrinder",
    "HotWaterTempCalibration",
    "MilkInitRinse",
    "ShortCalibration",
    "Requested",
    "Undef",
};


enum DisplayAction_t
{
    DA_GroundsBinEmptied_e = 0, // S-021
    DA_BeanHopperRefilled_e,    // S-010, S-011, S-012, W-034, W-035
    DA_MilkTankCleaned_e,       // S-024
    DA_SendContinue_e,          // W-036
    DA_MilkTankLeftRefilledAndFinishProduct_e,  // W-018
    DA_MilkTankLeftRefilledAndAbortProduct_e,   // W-018
    DA_MilkTankRightRefilledAndFinishProduct_e, // W-024
    DA_MilkTankRightRefilledAndAbortProduct_e,  // W-024
    DA_RebootCpu_e,             // E-103
    DA_RestartDisplay_e,        // W-043
    DA_GroundsDrawerEmptiedYes_e,   // S-007
    DA_GroundsDrawerEmptiedNo_e,    // S-007
};


typedef union{
    struct{
        unsigned    JustReset_e:1;              // is ‘1’ after a reboot of the machine =>
                                                // It is set to ‘0’ as soon as the
                                                // first “Get Status” packet has been sent.
        unsigned    RequestSet_e:1;             // is ‘1’ if at least one request is set
                                                // (e.g. “Milk Outlet Rinse Left Necessary”)
        unsigned    InfoMessageSet_e:1;         // is ‘1’ if at least one info message is set
                                                // (e.g. a warning or error)
        unsigned    Reserved_3_e:1;
        unsigned    ProductDump_e:1;            // is ‘1’ if a product dump in the queue is ready
        unsigned    EditMode_e:1;               // is ‘1’ if machine is in edit mode
        unsigned    SteamBoilerWaterLevel_e:1;  // ‘1’: Above sensor, ‘0’: Below sensor
        unsigned    Standby_e:1;                // is ‘1’ if machine is in standby

        unsigned    rsvd:24;
    }b;
    unsigned char B[4];
}COFFEE_MACHINE_STATUS;


typedef struct{
    unsigned char   coffee_L_action;
    unsigned char   coffee_R_action;
    unsigned char   steam_L_action;
    unsigned char   steam_R_action;
    unsigned char   water_action;

    unsigned char   coffee_L_status;
    unsigned char   coffee_R_status;
    unsigned char   steam_L_status;
    unsigned char   steam_R_status;
    unsigned char   water_status;
}COFFEE_MODULE_STATUS;


typedef struct{
    unsigned char   coffee_L_process;
    unsigned char   coffee_R_process;
    unsigned char   steam_L_process;
    unsigned char   steam_R_process;
    unsigned char   water_process;
}COFFEE_MODULE_PROCESS;

typedef struct{
    unsigned char   coffee_L_productID;
    unsigned char   coffee_R_productID;
    unsigned char   steam_L_productID;
    unsigned char   steam_R_productID;
    unsigned char   water_productID;
}COFFEE_PRODUCT_KEY_ID;

typedef struct{
    int api_version_major;
    int api_version_minor;
    int api_version_revision;
}COFFEE_API_VERSION;

#define CRC_INIT    0xFFFF

#define PIE_COMMAND     0x68
#define PIE_REQUEST     0x6C
#define PIE_RESERVED    0x69
#define PIE_ACK         0x6A
#define PIE_NACK        0x6B

// SOH(0x00)  PIP(0x00)  PIE  PN  SA  DA  MI  MP  DL  Data  CRC  EOT
//


namespace Ui {
class DialogCoffee;
}

class DialogCoffee : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCoffee(QWidget *parent = nullptr, DialogStock *_stock = nullptr);
    ~DialogCoffee();


    void SetComboBox();


    void WriteData(const QByteArray &data);
    void WriteData(const char *data, int cnt);
//    void ReadData();
    bool IsOpen();
    QSerialPort* GetPort();
    ushort CalculateCRC(uchar *data, int len);
    QByteArray GeneratePacket(uchar packet_type, uchar command_type, ushort msg_param, ushort data_len, QByteArray input_data);
    QByteArray MakeTelegram(QByteArray data);
    int DoParsing(QByteArray input_data);


    uchar sequence_number;

    struct SerialSettings {
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
    };
    SerialSettings  setting;



    COFFEE_API_VERSION      api_version;
    COFFEE_MACHINE_STATUS   machine_status;
    COFFEE_MODULE_STATUS    module_status;
    COFFEE_MODULE_PROCESS   module_process;
    COFFEE_PRODUCT_KEY_ID   product_keyid;

    unsigned char           coffee_detail_L;
    unsigned char           coffee_detail_R;
    unsigned char           milk_detail_L;
    unsigned char           milk_detail_R;


    bool OpenSerialPort();
    void CloseSerialPort();

    void DoAskStatus();
    void DoProduct(int product_number);
    void DoRinse();
    void SendDisplayAction(int display_action);
    void GetInfoMessage();


    int     coffee_connection;
    int     coffee_data_connection;
    unsigned int     coffee_data_count;
    QSerialPort     *port;

private:
    //socket write 함수
    void sendCommand(QString _function);
    void sendCommand(QString _function, int _recipe);
    void requestStatus(QString _function);


public slots:
    void ReadData();
    void onAsk();
    void onTimer();

private slots:

    void on_BTN_COFFEE_MAKE_clicked();

    void on_BTN_BEAN_HOPPER_REFILLED_clicked();

private:
    Ui::DialogCoffee *ui;
    QTimer  timer;
    QTimer  askTimer;

    QSqlDatabase    db;

    QByteArray      totalData;


    DialogStock *stock;
    QMap<QString, QString> coffee_desc_btn;
};

#endif // DIALOGCOFFEE_H
