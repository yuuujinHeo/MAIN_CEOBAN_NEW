#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <QObject>
#include <QTimer>

#include "DialogCupDispenser.h"
#include "DialogIceDispenser.h"
#include "DialogCoffee.h"
#include "DialogSyrup.h"
#include "DialogRobot.h"
#include "DialogMonitor.h"
#include "DialogDoor.h"
#include "DialogBarcode.h"
#include "DialogOutlet.h"
#include "DialogSoda.h"
#include "DialogKiosk.h"

#include "GlobalHeader.h"

#include "DialogStock.h"


enum{
    ROBOT_ON_CENTER = 0,
    ROBOT_ON_LEFT,
    ROBOT_ON_RIGHT,
};

enum{
    ROBOT_ON_INIT = 0,
    ROBOT_ON_OUTLET,
    ROBOT_ON_CUP_HOT,
    ROBOT_ON_CUP_ICE,
    ROBOT_ON_ICE,
    ROBOT_ON_SYRUP,
    ROBOT_ON_COFFEE,
    ROBOT_ON_SODA
};

enum{
    ACTION_STATE_IDLE = 0,
    ACTION_STATE_INIT,

    ACTION_STATE_GET_ORDER,
    ACTION_STATE_MAKING_PROCESS,


    // 대기시간 중 인사 모션 관련
    ACTION_STATE_GREETING_READY,
    ACTION_STATE_GREETING_START,
    ACTION_STATE_GREETING_DONE,

    ACTION_STATE_CUP_READY,
    ACTION_STATE_CUP_PLACE,
    ACTION_STATE_CUP_DISPENSE,
    ACTION_STATE_CUP_CHECK_IF_DISPENSED,
    ACTION_STATE_CUP_BACK_TO_READY,
    ACTION_STATE_CUP_REPOSITIONING,
    ACTION_STATE_CUP_ISSUE_CALL_MANAGER,
    ACTION_STATE_CUP_ISSUE_CALL_MANAGER_MOTION_WAIT,
    ACTION_STATE_CUP_GET,
    ACTION_STATE_CUP_ERROR,
    ACTION_STATE_CUP_RECOVER,



    ACTION_STATE_ICE_READY,
    ACTION_STATE_ICE_PLACE,
    ACTION_STATE_ICE_DISPENSE,
    ACTION_STATE_ICE_WAIT_DISPENSE_DONE,
    ACTION_STATE_ICE_GET,


    ACTION_STATE_SODA_READY,
    ACTION_STATE_SODA_PLACE,
    ACTION_STATE_SODA_WAIT_PLACE,
    ACTION_STATE_SODA_WAIT_TARE,
    ACTION_STATE_SODA_DISPENSE,
    ACTION_STATE_SODA_WAIT_DISPENSE_DONE,
    ACTION_STATE_SODA_GET,



    ACTION_STATE_COFFEE_READY,
    ACTION_STATE_COFFEE_PLACE,
    ACTION_STATE_COFFEE_DISPENSE,
    ACTION_STATE_COFFEE_WAIT_DISPENSE_DONE,
    ACTION_STATE_COFFEE_GET,

    ACTION_STATE_SYRUP_READY,
    ACTION_STATE_SYRUP_PLACE,
    ACTION_STATE_SYRUP_WAIT_PLACE,
    ACTION_STATE_SYRUP_WAIT_TARE,
    ACTION_STATE_SYRUP_DISPENSE,
    ACTION_STATE_SYRUP_WAIT_DISPENSE_DONE,
    ACTION_STATE_SYRUP_GET,



    ACTION_STATE_OUTLET_READY,
    ACTION_STATE_OUTLET_MOVE_TO_MODULE,
    ACTION_STATE_OUTLET_CUP_PLACE,
    ACTION_STATE_OUTLET_DISPENSE_COMPLETED,
    ACTION_STATE_OUTLET_GET,

    ACTION_STATE_DRINK_DISPOSAL_READY,
    ACTION_STATE_DRINK_DISPOSAL_TAKE_BACK,
    ACTION_STATE_DRINK_DISPOSAL_PLACEMENT,
    ACTION_STATE_DRINK_DISPOSAL_DONE,

    ACTION_STATE_MOTION_READY,
    ACTION_STATE_MOTION_START,
    ACTION_STATE_MOTION_DONE,


};

enum{
    OR_STATE_IDLE = 0,
    OR_STATE_DO_ROTATE,
    OR_STATE_WAIT_ROTATE_DONE
};


enum{
    OUTLET_MODULE_IDLE = 0,
    OUTLET_MODULE_READY,
    OUTLET_MODULE_SPIN,
    OUTLET_MODULE_SPIN_WAIT,
    OUTLET_MODULE_DOOR_OPEN,
    OUTLET_MODULE_DOOR_WAIT_IN_OPEN,
    OUTLET_MODULE_DOOR_CLOSE,
    OUTLET_MODULE_DOOR_WAITE_IN_CLOSE,
    OUTLET_MODULE_CHECK_CELL_OCC,
    OUTLET_MODULE_COMPLETED,
};



class Scheduler : QObject
{
    Q_OBJECT
public:
    Scheduler(DialogStock *_stock, DialogRobot *_robot, DialogCupDispenser *_cup,
              DialogCoffee *_coffee, DialogIceDispenser *_ice,
              DialogSyrup *_syrup, DialogOutlet *_outlet,
              DialogBarcode *_barcode, DialogMonitor *_monitor, DialogSoda *_soda);


    int action_state;
    int outlet_rotate_state;
    int outlet_state[NUMBER_OF_OUTLET];

    QString keymotion;

    QVector<ST_RECIPE_INFO> list_waiting;
    QVector<ST_RECIPE_INFO> list_inprogress;
    V_RECIPE                recipe_inprogress;
    ST_RECIPE_STEP          current_recipe_step;


    QString                             last_make_pin;
    QVector<ST_COMPLETED_DRINK_INFO>    list_completed;
    ST_COMPLETED_DRINK_INFO             list_dispensing[NUMBER_OF_OUTLET];
    ST_OUTLET_CELL_INFO     outlet_cell_info;


    int LAST_ROBOT_POSITION_DEVICE_NAME;


    int last_order_flag;
    int recall_order_flag;
    int recall_inprogressing_order_flag;

    int IsIdle();
    void SetForcedDispensing(int id_module, int id_cell);

    void ClearWaitingList();
    void ClearCompletedList();

    int get_inprogress_size();
    void remove_inprogress_list();
    void remove_waiting_list(int index);

    void SetRecallOrderFlag();
    void SetRecallInprogressingOrderFlag();


    int is_coffee_used;
    int is_coffee_triggered;
    QString early_coffee_button;
    QString prev_step = "";
    QString pprev_step = "";

    void DoEarlyCoffeeDispense(QString now_step);

public slots:
    void onTimer();

private:
    QTimer  timer;

    DialogStock         *stock;
    DialogRobot         *robot;
    DialogCupDispenser  *cup;
    DialogCoffee        *coffee;
    DialogIceDispenser  *ice;
    DialogSyrup         *syrup;
    DialogSoda          *soda;
    DialogOutlet        *outlet;
    DialogBarcode       *barcode;
    DialogMonitor       *monitor;
};

#endif // SCHEDULER_H
