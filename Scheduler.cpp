#include "Scheduler.h"
#include <math.h>
#include "displaydialog.h"


#define SCHEDULER_TIME_INTERVAL 100
#define MOTION_RESPONSE_DELAY   60000
#define LOADCELL_TARE_DELAY     400
#define COFFEE_RESPONSE_DELAY   4000
#define COFFEE_LAST_DELAY       1500
#define ICECREAM_WAIT_DELAY     3500

extern Logger *plog;
extern DisplayDialog *pdisplay;
Scheduler::Scheduler(DialogStock *_stock, DialogRobot *_robot, DialogCupDispenser *_cup,
                     DialogCoffee *_coffee, DialogIceDispenser *_ice,
                     DialogSyrup *_syrup, DialogOutlet *_outlet,
                     DialogBarcode *_barcode, DialogMonitor *_monitor,
                     DialogIcecream *_icecream, DialogSlush *_slush) :
    stock(_stock), robot(_robot), cup(_cup),
    coffee(_coffee), ice(_ice),
    syrup(_syrup), outlet(_outlet),
    barcode(_barcode), monitor(_monitor),
    icecream(_icecream), slush(_slush)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(SCHEDULER_TIME_INTERVAL);

    last_order_flag = false;

    action_state = ACTION_STATE_INIT;
    outlet_rotate_state = OR_STATE_IDLE;

    is_coffee_used = false;
    is_coffee_triggered = true;
    early_coffee_button = "";
    prev_step = "";
    pprev_step = "";

    for(int i=0; i<NUMBER_OF_OUTLET; i++){
        outlet_state[i] = OUTLET_MODULE_IDLE;
    }
    // test menu
//    ST_RECIPE_INFO temp;
//    temp.pin = "1111";
//    temp.recipe = stock->menu["0001"].recipe;
//    temp.menu_id = stock->menu["0001"].menu_id;
//    temp.menu_name = stock->menu["0001"].menu_name;
//    list_waiting.push_back(temp);
//    action_state = ACTION_STATE_IDLE;

}

void Scheduler::onTimer(){
    static int timeout = 0;
    static int timeout_door[NUMBER_OF_OUTLET] = {0,0};
    static int timeout_rotate = 0;

    static int cup_trycount = 0;
    static int cup_changed = 0;
    static int cup_selection = 0;
    static int cup_fail = 0;
    static int cup_toggle_paper = 0;
    static int write_log = 0;

    static int ice_working = 0;

    static int timeout_greeting = MOTION_RESPONSE_DELAY/SCHEDULER_TIME_INTERVAL;
    static int greeting_motion_cnt = 0;

    static int syrup_start_loadcell = 0;
    static int sauce_shot_count = 0;
    static int icecream_start_loadcell = 0;

    static int coffee_milk_refill_message_flag = 0;


    static int need_coffee_display_clear = 0;

    static int free_module = -1;

    static QDateTime startT;
    static QDateTime prevT;
    static int flag_takttime=0;

//    qDebug() << "scheduler timer";

//    static int tttt = 0;
//    if(tttt == 0){
//        ST_MENU t_menu = stock->menu["0001"];

//        qDebug() << t_menu.menu_id << ", " << t_menu.menu_name;
//        for(int j=0; j<t_menu.recipe.size(); j++){
//            qDebug() << "*****" << t_menu.recipe[j].ingredient << ", " << t_menu.recipe[j].amount;
//        }
//        tttt = 1;
//    }



    if(recall_order_flag == 1){
        recall_order_flag = 0;

//        for(int i=0; i<list_waiting.size(); i++){
//            pbarcode->recall_barcode_history(list_waiting[i].str_date, list_waiting[i].str_hour, list_waiting[i].trans_number);
//        }
//        list_waiting.clear();
    }

    if(recall_inprogressing_order_flag == 1){
        recall_inprogressing_order_flag = 0;

//        if(list_inprogress.size() > 0){
//            pbarcode->recall_barcode_history(list_inprogress[0].str_date, list_inprogress[0].str_hour, list_inprogress[0].trans_number);
//        }
//        list_inprogress.clear();
    }




    monitor->UpdateList_WaitingDrinks(list_waiting);
    monitor->UpdateList_InprogressDrinks(list_inprogress);
    monitor->UpdateList_CompletedDrinks(list_completed);
    monitor->UpdateList_DispensingDrinkgs(list_dispensing);



    static unsigned int ext_coll_flag = 0;
    static unsigned int ext_coll_cnt = 0;
    if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_STATE){
        if((sys_status.sdata.op_stat_collision_occur == 1) && (ext_coll_cnt < 3)){
            ext_coll_flag++;
            if(ext_coll_flag%10 == 0){
                robot->CollisionResume();
                ext_coll_cnt++;

                plog->write("[SCHEDULE] ERROR : ROBOT COLLISION OCCUR " + QString::number(ext_coll_cnt));

            }
        }
    }

    switch(action_state){
    case ACTION_STATE_INIT:
        // For Initialization
        // Do Nothing
        LAST_ROBOT_POSITION_DEVICE_NAME = ROBOT_ON_INIT;
        break;
    case ACTION_STATE_IDLE:
        // In Operation
        ext_coll_flag = 0;
        ext_coll_cnt = 0;

        if(list_waiting.size() > 0){
            plog->write("[SCHEDULE] LIST WAITING SIZE : " + QString::number(list_waiting.size()));
            action_state = ACTION_STATE_GET_ORDER;
            // 대기 인사 모션 10초 간격으로 설정
            timeout_greeting = MOTION_RESPONSE_DELAY/SCHEDULER_TIME_INTERVAL;
        }else{
            if(--timeout_greeting > 0)    break;

            // 대기 인사 모션 10초 간격으로 설정
            timeout_greeting = MOTION_RESPONSE_DELAY/SCHEDULER_TIME_INTERVAL;
            plog->write("[SCHEDULE] START GREETING MOTION ");
            action_state = ACTION_STATE_GREETING_READY;
        }
        break;

    case ACTION_STATE_GREETING_READY:
    {
        action_state = ACTION_STATE_GREETING_START;
        break;
    }
    case ACTION_STATE_GREETING_START:
    {
        ////**************두 인사 모션을 번갈아 함
        if(greeting_motion_cnt == 0)
        {
            keymotion = "HELLO";
#ifdef ICECREAM_VER
#else
//            greeting_motion_cnt = 1;
#endif
        }else if(greeting_motion_cnt == 1)
        {
            keymotion = "HELLO_2";
            greeting_motion_cnt = 0;
        }

        qDebug()<<"ROBOT MOTION:"<<keymotion;

        robot->MotionServerCommand(keymotion);
        robot->RobotMoving = true;

        action_state = ACTION_STATE_GREETING_DONE;
        break;
    }
    case ACTION_STATE_GREETING_DONE:
    {
        ////***************로봇 모션 완료까지 대기
        if(robot->RobotMoving == true) break;

        timeout_greeting = MOTION_RESPONSE_DELAY/SCHEDULER_TIME_INTERVAL;
        action_state = ACTION_STATE_IDLE;
        break;
    }
    case ACTION_STATE_GET_ORDER:
    {
        qDebug() << "ACTION_STATE_GET_ORDER";
        // New Order


//        if(coffee->IsRefillMilkSoon()){
//            // 우유 청소 중이거나 청소가 곧 임박할 경우
//            coffee_milk_refill_message_flag = 1;
//            monitor->SetDisplayMessage("위생적인 음료 제조를 위해 우유관을 청소하고 있습니다. 커피머신을 이용하지 않는 음료를 먼저 제조합니다.(5분 소요)");

//            int order_selection = -1;
//            for(int i=0; i<list_waiting.size(); i++){
//                V_RECIPE temp_recipe = list_waiting[i].recipe;
//                int recipe_no_coffee = true;
//                for(int j=0; j<temp_recipe.size(); j++){
//                    if(temp_recipe[j].ingredient == "COFFEE" || temp_recipe[j].ingredient == "MILK"){
//                        recipe_no_coffee = false;
//                        break;
//                    }
//                }
//                if(recipe_no_coffee = true){
//                    order_selection = i;
//                    break;
//                }
//            }

//            if(order_selection != -1){
//                list_inprogress.push_back(list_waiting[order_selection]);
//                list_waiting.remove(order_selection);
//            }else{
//                // keep waiting coffee milk refill finished
//            }

//        }else{
            if(coffee_milk_refill_message_flag == 1){
                coffee_milk_refill_message_flag = 0;
                monitor->SetDisplayMessage("");
            }
            list_inprogress.push_back(list_waiting[0]);
            list_waiting.pop_front();
//        }

        plog->write("[SCHEDULE] SET INPROGRESS DRINK : " + list_inprogress[0].pin + ", " + list_inprogress[0].menu_name);
        // Copy Recipes
        recipe_inprogress = list_inprogress[0].recipe;

        ////***************택타임 체크
        plog->start_measure_takttime(list_inprogress[0].menu_name);
        startT = QDateTime::currentDateTime();
        prevT = QDateTime::currentDateTime();

        // Set Coffee Trigger ----------------------------------
        prev_step = "";
        pprev_step = "";
        is_coffee_used = false;
        for(int i=0; i<recipe_inprogress.size(); i++){
            if(recipe_inprogress[i].ingredient == "COFFEE"){// || recipe_inprogress[i].ingredient == "MILK"){
                is_coffee_used = true;
                early_coffee_button = recipe_inprogress[i].amount;
                break;
            }else{
                pprev_step = prev_step;
                prev_step = recipe_inprogress[i].ingredient;
            }
        }
        if(is_coffee_used == true){
            is_coffee_triggered = false;
        }
        //----------------------------------------------------


        //배출구에 대기음료가 없으면 미리 회전
        free_module = outlet->GetFreeModuleInfo();

        if(free_module != -1){
            outlet->SpinToLoad(free_module, 0);
            plog->write("[SCHEDULE] OUTLET READY : " + QString::number(free_module));
        }

        action_state = ACTION_STATE_MAKING_PROCESS;
        break;
    }
    case ACTION_STATE_MAKING_PROCESS:
        // Define Next Action
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0)
            break;

        if(recipe_inprogress.size() > 0){
            current_recipe_step = recipe_inprogress[0];
            recipe_inprogress.pop_front();

            QString next_type = current_recipe_step.ingredient;
            if(next_type == "CUP"){
                cup_changed = 0;
                cup_trycount = 0;
                action_state = ACTION_STATE_CUP_READY;
            }else if(next_type == "ICE"){
                action_state = ACTION_STATE_ICE_READY;
            }else if(next_type == "COFFEE" ||
                     next_type == "MILK"){
                action_state = ACTION_STATE_COFFEE_READY;
            }else if(next_type.left(5) == "SYRUP"){
                action_state = ACTION_STATE_SYRUP_READY;
            }else if(next_type == "OUTLET"){
                action_state = ACTION_STATE_OUTLET_READY;
            }else if(next_type == "ICECREAM"){
                action_state = ACTION_STATE_ICECREAM_READY;
            }else if(next_type.left(5) == "SLUSH"){
                action_state = ACTION_STATE_SLUSH_READY;
            }else if(next_type.left(4) == "BASE"){
                action_state = ACTION_STATE_BASE_READY;
            }
            plog->write("[SCHEDULE] MAKING PROCESS SET : " + next_type);

        }else{
            if(last_order_flag == 1){
                last_order_flag = 0;
                plog->write("[SCHEDULE] LAST ORDER : STATE GO TO INIT");
                action_state = ACTION_STATE_INIT;
            }else{
                action_state = ACTION_STATE_IDLE;
            }
        }
        break;

    //==========================================================================================
    case ACTION_STATE_CUP_READY:
    {
        if(robot->RobotMoving == true)
            break;

        ////***************택타임 체크
        plog->add_takttime("START CUP       ",prevT.msecsTo(QDateTime::currentDateTime()));
        prevT = QDateTime::currentDateTime();

        plog->write("[SCHEDULE] CUP READY");
        cup_fail = 0;

        int dev_available[2];
        dev_available[0] = cup->IsCupAvailable(0);
        dev_available[1] = cup->IsCupAvailable(1);
        if(current_recipe_step.amount == "HOT"){
            if(dev_available[1] == 0){
                plog->write("[SCHEDULE] HOT CUP IS UNAVAILABLE");
                action_state = ACTION_STATE_CUP_ERROR;
                break;
            }
        }else{
            if(dev_available[0] == 1){
                keymotion = "READY_CUP_1";
                cup_selection = 0;
            }else if(dev_available[1] == 1){
                keymotion = "READY_CUP_2";
                cup_selection = 1;
            }else{
                plog->write("[SCHEDULE] ALL OF CUP ARE UNAVAILABLE");
                action_state = ACTION_STATE_CUP_ERROR;
                break;
            }
        }
        plog->write("[SCHEDULE] SEND MOTION : "+keymotion);
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);
        action_state = ACTION_STATE_CUP_DISPENSE;
        break;
    }

    case ACTION_STATE_CUP_DISPENSE:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_CUP_DISPENSE";

        ////***************택타임 체크
        plog->add_takttime("READY CUP       ",prevT.msecsTo(QDateTime::currentDateTime()));
        prevT = QDateTime::currentDateTime();

        if(CUP_DATA[cup_selection].dispense_op_flag == 0){
            plog->write("[SCHEDULE] DISPENSE CUP : "+QString::number(cup_selection));
            cup->DispenseCup(cup_selection);
            action_state = ACTION_STATE_CUP_CHECK_IF_DISPENSED;
            DoEarlyCoffeeDispense(current_recipe_step.ingredient);
        }
        break;

    case ACTION_STATE_CUP_CHECK_IF_DISPENSED:
        if(CUP_DATA[cup_selection].prev_out_count != CUP_DATA[cup_selection].cup_out_count){
            int last_error = CUP_DATA[cup_selection].last_error;

            if(last_error == 0){
                plog->write("[SCHEDULE] DISPENSE CUP : SUCCESS ");

                ////***************택타임 체크
                plog->add_takttime("DISPENSE CUP    ",prevT.msecsTo(QDateTime::currentDateTime()));
                prevT = QDateTime::currentDateTime();

                action_state = ACTION_STATE_CUP_GET;
            }else{
                plog->write("[SCHEDULE] DISPENSE CUP : ERROR "+QString::number(last_error));
//                if(last_error == 1){
//                    // busy
//                }else if(last_error == 2){
//                    // cup already exist
//                }else if(last_error == 3){
//                    // dispense done, but cup not detected
//                }else if(last_error == 4){
//                    // timeout
//                }
                cup_trycount++;
                if(cup_trycount > 3){
                    plog->write("[SCHEDULE] DISPENSE CUP : FAIL 3 TIME");
                    if(cup_selection==0){
                        cup->FATAL_INFO_CUP_DISPENSER_ERROR_1 = 1;
                    }else{
                        cup->FATAL_INFO_CUP_DISPENSER_ERROR_2 = 1;
                    }
                    action_state = ACTION_STATE_CUP_REPOSITIONING;
                    cup_trycount = 0;
                }else{
                    action_state = ACTION_STATE_CUP_DISPENSE;
                }
            }
        }
        break;
    case ACTION_STATE_CUP_REPOSITIONING:
    {
        if(cup_selection == 0){
            if(cup->IsCupAvailable(1) == 0 || cup->FATAL_INFO_CUP_DISPENSER_ERROR_2 == 1){
                plog->write("[SCHEDULE] ALL OF CUP ARE UNAVAILABLE");
                cup_fail = 1;
                action_state = ACTION_STATE_CUP_GET;
                break;
            }else{
                keymotion = "CUP_1_TO_CUP_2";
                cup_selection = 1;
            }
        }else{
            if(cup->IsCupAvailable(0) == 0|| cup->FATAL_INFO_CUP_DISPENSER_ERROR_1 == 1){
                plog->write("[SCHEDULE] ALL OF CUP ARE UNAVAILABLE");
                cup_fail = 1;
                cup->FATAL_INFO_CUP_DISPENSER_ERROR_1 = 1;
                cup->FATAL_INFO_CUP_DISPENSER_ERROR_2 = 1;
                action_state = ACTION_STATE_CUP_GET;
                break;
            }else{
                keymotion = "CUP_2_TO_CUP_1";
                cup_selection = 0;
            }
        }
        plog->write("[SCHEDULE] SEND MOTION : "+keymotion);
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);
        action_state = ACTION_STATE_CUP_DISPENSE;
        break;
    }
    case ACTION_STATE_CUP_GET:
        if(robot->RobotMoving == true)
            break;

        if(cup_selection == 0){
            stock->UseStock("PAPER_CUP_1", 1);
            keymotion = "GET_CUP_1";
        }else if(cup_selection == 1){
            stock->UseStock("PP_CUP_1", 1);
            keymotion = "GET_CUP_2";
        }
        plog->write("[SCHEDULE] SEND MOTION : "+keymotion);
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        LAST_ROBOT_POSITION_DEVICE_NAME = ROBOT_ON_CUP;

        if(cup_fail == 0){
            plog->write("[SCHEDULE] GET CUP : SUCCESS ");
            action_state = ACTION_STATE_MAKING_PROCESS;
        }else{
            plog->write("[SCHEDULE] GET CUP : FAIL ");
            action_state = ACTION_STATE_CUP_BACK_TO_READY;
        }
        break;

    case ACTION_STATE_CUP_BACK_TO_READY:
        if(robot->RobotMoving == true)
            break;

        plog->write("[SCHEDULE] GET CUP : FAIL -> BACK TO INIT ");

        keymotion = "CUP_TO_INIT";
        plog->write("[SCHEDULE] SEND MOTION : "+keymotion);
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_CUP_ERROR;
        break;

    case ACTION_STATE_CUP_ERROR:
        monitor->SetDisplayMessage("컵의 재고가 없습니다. 관리자를 호출해주세요^^");
        break;

    case ACTION_STATE_CUP_RECOVER:
        plog->write("[SCHEDULE] CUP RECOVER");
        monitor->SetDisplayMessage("");
        cup_changed = 0;
        cup_trycount = 0;
        action_state = ACTION_STATE_CUP_READY;
        break;


    //==========================================================================================
    case ACTION_STATE_ICE_READY:
        if(robot->RobotMoving == true)
            break;

        ////***************택타임 체크
        plog->add_takttime("START ICE       ",prevT.msecsTo(QDateTime::currentDateTime()));
        prevT = QDateTime::currentDateTime();

        if(LAST_ROBOT_POSITION_DEVICE_NAME == ROBOT_ON_CUP){
            keymotion = "CUP_TO_ICE";
        }else if(LAST_ROBOT_POSITION_DEVICE_NAME == ROBOT_ON_SYRUP){
            keymotion = "SYRUP_TO_ICE";
        }else{
            plog->write("[SCHEDULE] ICE READY : NO MOTION "+LAST_ROBOT_POSITION_DEVICE_NAME);
        }

        plog->write("[SCHEDULE] SEND MOTION : "+keymotion);
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);


        action_state = ACTION_STATE_ICE_DISPENSE;
        break;

    case ACTION_STATE_ICE_DISPENSE:
    {
        if(robot->RobotMoving == true)
            break;

        ice_working = 0;
        qDebug() << "ACTION_STATE_ICE_DISPENSE";

        ////***************택타임 체크
        plog->add_takttime("READY ICE       ",prevT.msecsTo(QDateTime::currentDateTime()));
        prevT = QDateTime::currentDateTime();

        int out_ms = 0;
        int out_ice_ms = 0;
        int out_water_ms = 0;
        QStringList amount = current_recipe_step.amount.split("/");
        plog->write("[SCHEDULE] ICE DISPENSE : "+QString::number(int(amount[0].toFloat()*1000.0))+","+QString::number(int(amount[1].toFloat()*1000.0)));
        ice->DispenseIceWater(0, int(amount[0].toFloat()*1000.0), int(amount[1].toFloat()*1000.0));
        out_ice_ms = int(amount[0].toFloat()*1000.0);
        out_water_ms = int(amount[1].toFloat()*1000.0);

        if(out_ice_ms > out_water_ms){
            out_ms = out_ice_ms;
        }else{
            out_ms = out_water_ms;
        }
        timeout = (out_ms+1000)/SCHEDULER_TIME_INTERVAL;


//        float ice_time = current_recipe_step.amount.toFloat();

//        ice->DispenseIceWater(0, int(ice_time*1000.0), 0);
//        out_ms = int(ice_time*1000.0);
//        timeout = (out_ms + 1000)/SCHEDULER_TIME_INTERVAL;

        action_state = ACTION_STATE_ICE_WAIT_DISPENSE_DONE;
        break;
    }

    case ACTION_STATE_ICE_WAIT_DISPENSE_DONE:
    {
        if(--timeout > 0){
            if(ICE_DATA[0].status.b.gear_motor_working == 1)
                ice_working = 1;

            break;
        }

        if(ice_working == 1){
            qDebug() << "ACTION_STATE_ICE_WAIT_DISPENSE_DONE";

            if(timeout < 0 || ICE_DATA[0].prev_out_count != ICE_DATA[0].ice_out_count){
                DoEarlyCoffeeDispense(current_recipe_step.ingredient);

                ////***************택타임 체크
                plog->add_takttime("DISPENSE ICE    ",prevT.msecsTo(QDateTime::currentDateTime()));
                prevT = QDateTime::currentDateTime();

                plog->write("[SCHEDULE] ICE DISPENSE : DONE");
                LAST_ROBOT_POSITION_DEVICE_NAME = ROBOT_ON_ICE;
                action_state = ACTION_STATE_MAKING_PROCESS;
            }
        }else{
            plog->write("[SCHEDULE] ICE DISPENSE : ERROR -> RE_TRY");
            action_state = ACTION_STATE_ICE_DISPENSE;
        }
        break;
    }
    //==========================================================================================
    //==========================================================================================
    case ACTION_STATE_ICECREAM_READY:
    {
        if(robot->RobotMoving == true)
            break;

        ////***************택타임 체크
        plog->add_takttime("START ICECREAM     ",prevT.msecsTo(QDateTime::currentDateTime()));
        prevT = QDateTime::currentDateTime();

        if(LAST_ROBOT_POSITION_DEVICE_NAME == ROBOT_ON_CUP){
            keymotion = "CUP_TO_ICECREAM";
        }else if(LAST_ROBOT_POSITION_DEVICE_NAME == ROBOT_ON_BASE){
            keymotion = "BASE_TO_ICECREAM";
        }else{
            plog->write("[SCHEDULE] ICECREAM READY : NO MOTION "+LAST_ROBOT_POSITION_DEVICE_NAME);
        }

        plog->write("[SCHEDULE] SEND MOTION : "+keymotion);
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_ICECREAM_PLACE;
        break;
    }
    case ACTION_STATE_ICECREAM_PLACE:
    {
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_ICECREAM_PLACE";
        action_state = ACTION_STATE_ICECREAM_WAIT_PLACE;
        break;
    }
    case ACTION_STATE_ICECREAM_WAIT_PLACE:
    {
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_ICECREAM_WAIT_PLACE";

        // loadcell tare
        plog->write("[SCHEDULE] ICECREAM READY : LOADCELL TARE");
        icecream->Tare();
        timeout = LOADCELL_TARE_DELAY/SCHEDULER_TIME_INTERVAL;

        action_state = ACTION_STATE_ICECREAM_WAIT_TARE;
        break;
    }
    case ACTION_STATE_ICECREAM_WAIT_TARE:
    {
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0)
            break;
        qDebug() << "ACTION_STATE_ICECREAM_WAIT_TARE";

        if(fabs(icecream->LoadcellValue()) > 5){
            // tare error
            plog->write("[SCHEDULE] ICECREAM READY : LOADCELL RE-TARE "+QString::number(icecream->LoadcellValue()));
            icecream->Tare();
            timeout = LOADCELL_TARE_DELAY/SCHEDULER_TIME_INTERVAL;
        }else{
            plog->write("[SCHEDULE] ICECREAM READY : LOADCELL TARE DONE");
            icecream->StartMeasure(current_recipe_step.amount.toInt());
            timeout = LOADCELL_TARE_DELAY/SCHEDULER_TIME_INTERVAL;
            action_state = ACTION_STATE_ICECREAM_DISPENSE;
        }
        break;
    }
    case ACTION_STATE_ICECREAM_DISPENSE:
    {
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0)
            break;
        ////***************택타임 체크
        plog->add_takttime("READY ICECREAM     ",prevT.msecsTo(QDateTime::currentDateTime()));
        prevT = QDateTime::currentDateTime();

        icecream_start_loadcell = icecream->LoadcellValue();

#ifdef ICECREAM_CYLINDER
        if(ICECREAM_DATA[0].out_state == 0){
            icecream->DispenseIcecreamByWeight(current_recipe_step.amount.toInt());
        }
        keymotion = "OUT_ICECREAM";

        plog->write("[SCHEDULE] SEND MOTION : "+keymotion);
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        timeout = 15000/SCHEDULER_TIME_INTERVAL;
#else
        keymotion = "OUT_ICECREAM";

        plog->write("[SCHEDULE] SEND MOTION : "+keymotion);
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        timeout = 15000/SCHEDULER_TIME_INTERVAL;
#endif
        action_state = ACTION_STATE_ICECREAM_WAIT_DISPENSE_DONE;
        break;
    }
    case ACTION_STATE_ICECREAM_WAIT_DISPENSE_DONE:
    {
#ifdef ICECREAM_CYLINDER
#else
        if(robot->RobotMoving == true){
            if(--timeout > 0){
                break;
            }
            icecream->RobotStop();
            plog->write("[SCHEDULE] ICECREAM TIMETOUT -> ROBOT STOP");
        }
#endif
        if(ICECREAM_DATA[0].prev_out_count != ICECREAM_DATA[0].out_count){
            qDebug() << "ACTION_STATE_ICECREAM_WAIT_DISPENSE_DONE";

#ifdef ICECREAM_CYLINDER
            if(robot->RobotMoving == true){
                if(--timeout > 0){
                    break;
                }
                icecream->RobotStop();
                plog->write("[SCHEDULE] ICECREAM TIMETOUT -> ROBOT STOP");
            }

#endif



            int last_error = ICECREAM_DATA[0].last_error;

            ////***************택타임 체크
            plog->add_takttime("DISPENSE ICECREAM     ",prevT.msecsTo(QDateTime::currentDateTime()));
            prevT = QDateTime::currentDateTime();

            if(last_error == 0){
                ;
            }else{
                if(icecream->LoadcellValue() < 10){
                    plog->write("[SCHEDULE] ICECREAM DISPENSE : SOLDOUT "+current_recipe_step.ingredient);
                    stock->SetStock(current_recipe_step.ingredient, 0);
                }
            }
            int current_loadcell = icecream->LoadcellValue();
            int used_amount = current_loadcell-icecream_start_loadcell;

            plog->write("[SCHEDULE] ICECREAM DISPENSE : DONE "+current_recipe_step.ingredient + QString().sprintf(" -> %d",used_amount));
            stock->UseStock(current_recipe_step.ingredient, used_amount);

            LAST_ROBOT_POSITION_DEVICE_NAME = ROBOT_ON_ICECREAM;
            action_state = ACTION_STATE_ICECREAM_GET;
        }
        break;
     }
    case ACTION_STATE_ICECREAM_GET:
    {
        if(robot->RobotMoving == true)
            break;

        keymotion = "GET_ICECREAM";

        plog->write("[SCHEDULE] SEND MOTION : "+keymotion);
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);


        plog->write("[SCHEDULE] ICECREAM DONE");
        action_state = ACTION_STATE_MAKING_PROCESS;
        break;
    }
    //==========================================================================================
    //==========================================================================================
    case ACTION_STATE_SLUSH_READY:
    {
        if(robot->RobotMoving == true)
            break;

        ////***************택타임 체크
        plog->add_takttime("START SLUSH     ",prevT.msecsTo(QDateTime::currentDateTime()));
        prevT = QDateTime::currentDateTime();

        if(LAST_ROBOT_POSITION_DEVICE_NAME == ROBOT_ON_CUP){
            if(current_recipe_step.ingredient == "SLUSH_1")
                keymotion = "CUP_TO_SLUSH_1";
            else
                keymotion = "CUP_TO_SLUSH_2";
        }else{
            plog->write("[SCHEDULE] SLUSH READY : NO MOTION "+LAST_ROBOT_POSITION_DEVICE_NAME);
        }

        plog->write("[SCHEDULE] SEND MOTION : "+keymotion);
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_SLUSH_PLACE;
        break;
    }
    case ACTION_STATE_SLUSH_PLACE:
    {
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_SLUSH_PLACE";
        action_state = ACTION_STATE_SLUSH_WAIT_PLACE;
        break;
    }
    case ACTION_STATE_SLUSH_WAIT_PLACE:
    {
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_SLUSH_WAIT_PLACE";

        // loadcell tare
        plog->write("[SCHEDULE] SLUSH READY : LOADCELL TARE");
        slush->Tare();
        timeout = LOADCELL_TARE_DELAY/SCHEDULER_TIME_INTERVAL;

        action_state = ACTION_STATE_SLUSH_WAIT_TARE;
        break;
    }
    case ACTION_STATE_SLUSH_WAIT_TARE:
    {
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0)
            break;
        qDebug() << "ACTION_STATE_SLUSH_WAIT_TARE";

        if(fabs(slush->LoadcellValue()) > 5){
            // tare error
            plog->write("[SCHEDULE] SLUSH READY : LOADCELL RE-TARE "+QString::number(slush->LoadcellValue()));
            slush->Tare();
            timeout = LOADCELL_TARE_DELAY/SCHEDULER_TIME_INTERVAL;
        }else{
            ////***************택타임 체크
            plog->add_takttime("READY SLUSH     ",prevT.msecsTo(QDateTime::currentDateTime()));
            prevT = QDateTime::currentDateTime();

            plog->write("[SCHEDULE] SLUSH READY : LOADCELL TARE DONE");
            slush->StartMeasure(current_recipe_step.amount.toInt());
            timeout = LOADCELL_TARE_DELAY/SCHEDULER_TIME_INTERVAL;
            action_state = ACTION_STATE_SLUSH_DISPENSE;
        }
        break;
    }
    case ACTION_STATE_SLUSH_DISPENSE:
    {
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0)
            break;

        if(current_recipe_step.ingredient == "SLUSH_1")
            keymotion = "OUT_SLUSH_1";
        else
            keymotion = "OUT_SLUSH_2";

        plog->write("[SCHEDULE] SEND MOTION : "+keymotion);
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        timeout = 15000/SCHEDULER_TIME_INTERVAL;
        action_state = ACTION_STATE_SLUSH_WAIT_DISPENSE_DONE;
        break;
    }
    case ACTION_STATE_SLUSH_WAIT_DISPENSE_DONE:
    {
        if(robot->RobotMoving == true){
            if(--timeout > 0){
                break;
            }

//            icecream->RobotStop();
//            plog->write("[SCHEDULE] SLUSH TIMETOUT -> ROBOT STOP");
        }


        if(SLUSH_DATA[0].prev_out_count != SLUSH_DATA[0].out_count){
            qDebug() << "ACTION_STATE_SLUSH_WAIT_DISPENSE_DONE";
            int last_error = SLUSH_DATA[0].last_error;

            ////***************택타임 체크
            plog->add_takttime("DISPENSE SLUSH     ",prevT.msecsTo(QDateTime::currentDateTime()));
            prevT = QDateTime::currentDateTime();

            if(last_error == 0){
                ;
            }else{
                if(slush->LoadcellValue() < 10){
                    plog->write("[SCHEDULE] SLUSH DISPENSE : SOLDOUT "+current_recipe_step.ingredient);
                    stock->SetStock(current_recipe_step.ingredient, 0);
                }
            }
            int current_loadcell = slush->LoadcellValue();
            int used_amount = current_loadcell;

            plog->write("[SCHEDULE] SLUSH DISPENSE : DONE "+current_recipe_step.ingredient + QString().sprintf(" -> %d",used_amount));
            stock->UseStock(current_recipe_step.ingredient, used_amount);

            LAST_ROBOT_POSITION_DEVICE_NAME = ROBOT_ON_SLUSH;
            action_state = ACTION_STATE_SLUSH_GET;
        }
        break;
    }
    case ACTION_STATE_SLUSH_GET:
    {
        if(robot->RobotMoving == true)
            break;

        if(current_recipe_step.ingredient == "SLUSH_1")
            keymotion = "GET_SLUSH_1";
        else
            keymotion = "GET_SLUSH_2";

        plog->write("[SCHEDULE] SEND MOTION : "+keymotion);
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        plog->write("[SCHEDULE] SLUSH DONE");
        action_state = ACTION_STATE_MAKING_PROCESS;
        break;
    }
    //==========================================================================================
    //==========================================================================================
    case ACTION_STATE_BASE_READY:
    {
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_BASE_READY";

        ////***************택타임 체크
        plog->add_takttime("START BASE     ",prevT.msecsTo(QDateTime::currentDateTime()));
        prevT = QDateTime::currentDateTime();


        if(LAST_ROBOT_POSITION_DEVICE_NAME == ROBOT_ON_ICECREAM){

            int sauce_type = current_recipe_step.ingredient.split("_")[1].toInt();
            int sauce_amount = current_recipe_step.amount.toInt();
            sauce_shot_count = sauce_amount/20;

            keymotion = QString().sprintf("ICECREAM_TO_BASE_%d",sauce_type);

            robot->RobotMoving = true;
            robot->MotionServerCommand(keymotion);
        }else{
            plog->write("[SCHEDULE] BASE READY : NO MOTION "+LAST_ROBOT_POSITION_DEVICE_NAME);
            break;
        }

        action_state = ACTION_STATE_BASE_DISPENSE;
        break;

    }
    case ACTION_STATE_BASE_PLACE:
    {
//        if(robot->RobotMoving == true)
//            break;
//        qDebug() << "ACTION_STATE_BASE_PLACE";

//        int sauce_type = current_recipe_step.ingredient.split("_")[1].toInt();
//        int sauce_amount = current_recipe_step.amount.toInt();
//        sauce_shot_count = sauce_amount/20;

//        keymotion = QString().sprintf("SET_BASE_%d", sauce_type);
//        robot->RobotMoving = true;
//        robot->MotionServerCommand(keymotion);

//        action_state = ACTION_STATE_BASE_DISPENSE;
        break;
    }
    case ACTION_STATE_BASE_DISPENSE:
    {
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_BASE_DISPENSE";

        ////***************택타임 체크
        plog->add_takttime("READY BASE     ",prevT.msecsTo(QDateTime::currentDateTime()));
        prevT = QDateTime::currentDateTime();

        keymotion = "OUT_BASE";
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        sauce_shot_count--;
        if(sauce_shot_count > 0){
            action_state = ACTION_STATE_BASE_DISPENSE;
        }else{
            action_state = ACTION_STATE_BASE_GET;
        }
        break;
    }
    case ACTION_STATE_BASE_GET:
    {
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_BASE_GET";

        ////***************택타임 체크
        plog->add_takttime("DISPENSE BASE     ",prevT.msecsTo(QDateTime::currentDateTime()));
        prevT = QDateTime::currentDateTime();

        stock->UseStock(current_recipe_step.ingredient, current_recipe_step.amount.toInt()*20);

        int sauce_type = current_recipe_step.ingredient.split("_")[1].toInt();
        keymotion = QString().sprintf("GET_BASE_%d", sauce_type);
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        LAST_ROBOT_POSITION_DEVICE_NAME = ROBOT_ON_BASE;
        action_state = ACTION_STATE_MAKING_PROCESS;
        break;
    }
    //==========================================================================================
    //==========================================================================================
    case ACTION_STATE_SYRUP_READY:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_SYRUP_READY";

        ////***************택타임 체크
        plog->add_takttime("START SYRUP     ",prevT.msecsTo(QDateTime::currentDateTime()));
        prevT = QDateTime::currentDateTime();

        if(LAST_ROBOT_POSITION_DEVICE_NAME == ROBOT_ON_SYRUP){
            // continuous syrup out
            // loadcell tare
            plog->write("[SCHEDULE] SYRUP READY : LOADCELL TARE");
            syrup->Tare();
            timeout = LOADCELL_TARE_DELAY/SCHEDULER_TIME_INTERVAL;

            action_state = ACTION_STATE_SYRUP_WAIT_TARE;
        }else{
            // first approaching
            if(LAST_ROBOT_POSITION_DEVICE_NAME == ROBOT_ON_CUP){
                keymotion = "CUP_TO_SYRUP";
            }else if(LAST_ROBOT_POSITION_DEVICE_NAME == ROBOT_ON_ICE){
                keymotion = "ICE_TO_SYRUP";
            }else{
                plog->write("[SCHEDULE] SYRUP READY : NO MOTION "+LAST_ROBOT_POSITION_DEVICE_NAME);
            }
            plog->write("[SCHEDULE] SEND MOTION : "+keymotion);
            robot->RobotMoving = true;
            robot->MotionServerCommand(keymotion);
            action_state = ACTION_STATE_SYRUP_WAIT_PLACE;
        }

        break;

    case ACTION_STATE_SYRUP_WAIT_PLACE:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_SYRUP_WAIT_PLACE";

        // loadcell tare
        plog->write("[SCHEDULE] SYRUP READY : LOADCELL TARE");
        syrup->Tare();
        timeout = LOADCELL_TARE_DELAY/SCHEDULER_TIME_INTERVAL;

        action_state = ACTION_STATE_SYRUP_WAIT_TARE;
        break;

    case ACTION_STATE_SYRUP_WAIT_TARE:
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0)
            break;
        qDebug() << "ACTION_STATE_SYRUP_WAIT_TARE";

        if(fabs(syrup->LoadcellValue()) > 5){
            // tare error
            plog->write("[SCHEDULE] SYRUP READY : LOADCELL RE-TARE "+QString::number(syrup->LoadcellValue()));
            syrup->Tare();
            timeout = LOADCELL_TARE_DELAY/SCHEDULER_TIME_INTERVAL;
        }else{
            plog->write("[SCHEDULE] SYRUP READY : LOADCELL TARE DONE");
            action_state = ACTION_STATE_SYRUP_DISPENSE;
        }
        break;

    case ACTION_STATE_SYRUP_DISPENSE:
    {
        if(robot->RobotMoving == true)
            break;


        qDebug() << "ACTION_STATE_SYRUP_DISPENSE";

        int pump_num = stock->syrup_to_pump[current_recipe_step.ingredient];
        int syrup_amount = current_recipe_step.amount.toInt();
        if(current_recipe_step.ingredient != "SYRUP_5" && syrup_amount >= 100){
            syrup_amount = 100;
            plog->write("[SCHEDULE] SYRUP DISPENSE : WRONG AMOUNT "+QString::number(syrup_amount));
        }
        syrup_start_loadcell = syrup->LoadcellValue();
        if(SYRUP_DATA[0].out_state == 0){
            ////***************택타임 체크
            plog->add_takttime("READY SYRUP     ",prevT.msecsTo(QDateTime::currentDateTime()));
            prevT = QDateTime::currentDateTime();
            plog->write("[SCHEDULE] SYRUP DISPENSE : "+QString::number(pump_num)+", "+QString::number(syrup_amount));
            syrup->DispenseSyrupByWeight(pump_num, syrup_amount);
            action_state = ACTION_STATE_SYRUP_WAIT_DISPENSE_DONE;
        }
        break;
    }

    case ACTION_STATE_SYRUP_WAIT_DISPENSE_DONE:

        if(SYRUP_DATA[0].prev_out_count != SYRUP_DATA[0].out_count){
            qDebug() << "ACTION_STATE_SYRUP_WAIT_DISPENSE_DONE";
            int last_error = SYRUP_DATA[0].last_error;

            ////***************택타임 체크
            plog->add_takttime("DISPENSE SYRUP     ",prevT.msecsTo(QDateTime::currentDateTime()));
            prevT = QDateTime::currentDateTime();

            if(last_error == 0){
                ;
            }else{
                // syrup #X error
                // set syrup #X stock 0
                if(syrup->LoadcellValue() < 10){
                    plog->write("[SCHEDULE] SYRUP DISPENSE : SOLDOUT "+current_recipe_step.ingredient);
//                    stock->SetStock(current_recipe_step.ingredient, 0);
                }
            }
            int current_loadcell = syrup->LoadcellValue();
            int used_amount = current_loadcell-syrup_start_loadcell;

            if(current_recipe_step.ingredient != "SYRUP_5"){
                plog->write("[SCHEDULE] SYRUP DISPENSE : DONE "+current_recipe_step.ingredient + QString().sprintf(" -> %d",used_amount));
                stock->UseStock(current_recipe_step.ingredient, used_amount);
            }
            DoEarlyCoffeeDispense(current_recipe_step.ingredient);

            LAST_ROBOT_POSITION_DEVICE_NAME = ROBOT_ON_SYRUP;
            action_state = ACTION_STATE_MAKING_PROCESS;
        }
        break;

    //==========================================================================================
    case ACTION_STATE_COFFEE_READY:
        if(robot->RobotMoving == true)
            break;

        plog->write("[SCHEDULE] COFFEE READY ");
        qDebug() << "ACTION_STATE_COFFEE_READY";
        need_coffee_display_clear = 0;

        ////***************택타임 체크
        plog->add_takttime("START COFFEE     ",prevT.msecsTo(QDateTime::currentDateTime()));
        prevT = QDateTime::currentDateTime();

        if(LAST_ROBOT_POSITION_DEVICE_NAME == ROBOT_ON_COFFEE){
            // continuous coffee out
            action_state = ACTION_STATE_COFFEE_DISPENSE;
        }else{
            // first approaching
            if(LAST_ROBOT_POSITION_DEVICE_NAME == ROBOT_ON_CUP){
                keymotion = "CUP_TO_COFFEE";
            }else if(LAST_ROBOT_POSITION_DEVICE_NAME == ROBOT_ON_ICE){
                keymotion = "ICE_TO_COFFEE";
            }else if(LAST_ROBOT_POSITION_DEVICE_NAME == ROBOT_ON_SYRUP){
                keymotion = "SYRUP_TO_COFFEE";
            }else{
                plog->write("[SCHEDULE] COFFEE READY : NO MOTION "+LAST_ROBOT_POSITION_DEVICE_NAME);
            }
            plog->write("[SCHEDULE] SEND MOTION : "+keymotion);
            robot->RobotMoving = true;
            robot->MotionServerCommand(keymotion);

            if(current_recipe_step.ingredient == "COFFEE"){
                // COFFEE
                if(is_coffee_triggered == true){
                    plog->write("[SCHEDULE] COFFEE READY : COFFEE -> EARLY DISPENSED");
                    action_state = ACTION_STATE_COFFEE_WAIT_DISPENSE_DONE;
                    timeout = COFFEE_RESPONSE_DELAY/SCHEDULER_TIME_INTERVAL;
                }else{
                    plog->write("[SCHEDULE] COFFEE READY : COFFEE");
                    action_state = ACTION_STATE_COFFEE_DISPENSE;
                }
            }else{
                // MILK
                plog->write("[SCHEDULE] COFFEE READY : MILK");
                action_state = ACTION_STATE_COFFEE_DISPENSE;
            }
        }
        break;

    case ACTION_STATE_COFFEE_DISPENSE:
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0)
            break;
        qDebug() << "ACTION_STATE_COFFEE_DISPENSE";

        if(coffee->module_status.coffee_L_status == Ready_e && coffee->module_status.water_status == Ready_e){
            ////***************택타임 체크
            plog->add_takttime("READY COFFEE     ",prevT.msecsTo(QDateTime::currentDateTime()));
            prevT = QDateTime::currentDateTime();

            plog->write("[SCHEDULE] COFFEE DISPENSE : "+QString().sprintf("%d",stock->coffee_key_btn[current_recipe_step.amount].toInt()));
            coffee->DoProduct(stock->coffee_key_btn[current_recipe_step.amount].toInt());
            timeout = COFFEE_RESPONSE_DELAY/SCHEDULER_TIME_INTERVAL;
            action_state = ACTION_STATE_COFFEE_WAIT_DISPENSE_DONE;
        }
        break;

    case ACTION_STATE_COFFEE_WAIT_DISPENSE_DONE:
    {
        if(--timeout > 0)
            break;
//        qDebug() << "ACTION_STATE_COFFEE_WAIT_DISPENSE_DONE";

        int check_go_to_next = false;
        if(coffee->module_status.coffee_L_status == notReady_e){
            if(coffee->module_status.coffee_L_action == ActionEndCyc_e ||                
                coffee->module_status.coffee_L_action == ActionStopped_e){
                // something wrong
                // bean hopper empty
                // no milk
                // ....
                need_coffee_display_clear = 1;
            }

            // quickly go forward -- lim
            if(coffee->module_status.coffee_L_action == ActionEnding_e){
                check_go_to_next = true;
            }
        }else if(coffee->module_status.coffee_L_status == Ready_e){
            //yujinn
            if(coffee->module_status.coffee_L_action == ActionIdle_e ||
                coffee->module_status.coffee_L_action == ActionEnding_e){
                check_go_to_next = true;
            }
        }

        if(check_go_to_next == true){
            // dispense finished
            ////***************택타임 체크
            plog->add_takttime("DISPENSE COFFEE     ",prevT.msecsTo(QDateTime::currentDateTime()));
            prevT = QDateTime::currentDateTime();

            if(need_coffee_display_clear == 1){
                need_coffee_display_clear = 0;
//                    stock->SetDeviceError("COFFEE");
                coffee->SendDisplayAction(DA_BeanHopperRefilled_e);
            }
            plog->write("[SCHEDULE] COFFEE DISPENSE : DONE");

            timeout = 1000/SCHEDULER_TIME_INTERVAL;
            LAST_ROBOT_POSITION_DEVICE_NAME = ROBOT_ON_COFFEE;
            action_state = ACTION_STATE_MAKING_PROCESS;
        }
        break;
    }

    //==========================================================================================

    case ACTION_STATE_OUTLET_READY:
        if(robot->RobotMoving == true)
            break;


        ////***************택타임 체크
        plog->add_takttime("START OUTLET     ",prevT.msecsTo(QDateTime::currentDateTime()));
        prevT = QDateTime::currentDateTime();

        if(free_module == -1){
            outlet_cell_info = outlet->GetFreeCellInfo();
        }else{
            outlet_cell_info.id_module = free_module;
            outlet_cell_info.id_cell = 0;
        }

        if(outlet_cell_info.id_module == -1){
            if(write_log == 0){
                write_log = 1;
                plog->write("[SCHEDULE] OUTLET READY : ALL MODULES ARE RUNNING OR CELLS ARE OCCUPIED");
            }
            monitor->SetDisplayMessage("모든 배출구에 음료가 찼습니다. 관리자를 호출해주세요^^");
            break;
        }
        write_log = 0;
        plog->write("[SCHEDULE] OUTLET READY : "+QString().sprintf("MODULE(%d), CELL(%d)",outlet_cell_info.id_module,outlet_cell_info.id_cell));

        if((outlet->IsModuleMoving(outlet_cell_info.id_module) == true) || (outlet->IsModuleRunning(outlet_cell_info.id_module) == true)){
            if(write_log == 0){
                write_log = 1;
                plog->write("[SCHEDULE] OUTLET READY : MODULE RUNNING....WAIT");
            }
            break;
        }
        write_log = 0;

        monitor->SetDisplayMessage("");

        outlet->SetModuleRunning(outlet_cell_info.id_module, true);
        outlet->SetCellOccupancy(outlet_cell_info.id_module, outlet_cell_info.id_cell, CELL_OCC, list_inprogress[0].pin);

        plog->write("[SCHEDULE] OUTLET READY : SPIN TO LOAD ");
        outlet->SpinToLoad(outlet_cell_info.id_module, outlet_cell_info.id_cell);
        timeout = 500/SCHEDULER_TIME_INTERVAL;

        action_state = ACTION_STATE_OUTLET_CUP_PLACE;
        break;

    case ACTION_STATE_OUTLET_CUP_PLACE:
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0 )
            break;

        if(outlet->IsModuleMoving(outlet_cell_info.id_module) == true)
            break;


        if(outlet->CheckSpinInLoadPos(outlet_cell_info.id_module, outlet_cell_info.id_cell) == false){   // new added by lim -- motion miss prevention
            timeout = 1000/SCHEDULER_TIME_INTERVAL;
            plog->write("[SCHEDULE] OUTLET READY : SPIN TO LOAD (RE-TRY)");
            outlet->SpinToLoad(outlet_cell_info.id_module, outlet_cell_info.id_cell);
            break;
        }


        if(LAST_ROBOT_POSITION_DEVICE_NAME == ROBOT_ON_COFFEE){
            if(outlet_cell_info.id_module == 0){
                keymotion = "COFFEE_TO_OUTLET_1";
            }else if(outlet_cell_info.id_module == 1){
                keymotion = "COFFEE_TO_OUTLET_2";
            }
        }else if(LAST_ROBOT_POSITION_DEVICE_NAME == ROBOT_ON_SYRUP){
            if(outlet_cell_info.id_module == 0){
                keymotion = "SYRUP_TO_OUTLET_1";
            }else if(outlet_cell_info.id_module == 1){
                keymotion = "SYRUP_TO_OUTLET_2";
            }
        }else if(LAST_ROBOT_POSITION_DEVICE_NAME == ROBOT_ON_BASE){
            if(outlet_cell_info.id_module == 0){
                keymotion = "BASE_TO_OUTLET_1";
            }else if(outlet_cell_info.id_module == 1){
                keymotion = "BASE_TO_OUTLET_2";
            }
        }else if(LAST_ROBOT_POSITION_DEVICE_NAME == ROBOT_ON_ICECREAM){
            if(outlet_cell_info.id_module == 0){
                keymotion = "ICECREAM_TO_OUTLET_1";
            }else if(outlet_cell_info.id_module == 1){
                keymotion = "ICECREAM_TO_OUTLET_2";
            }
        }else if(LAST_ROBOT_POSITION_DEVICE_NAME == ROBOT_ON_SLUSH){
            if(outlet_cell_info.id_module == 0){
                keymotion = "SLUSH_TO_OUTLET_1";
            }else if(outlet_cell_info.id_module == 1){
                keymotion = "SLUSH_TO_OUTLET_2";
            }
        }



        plog->write("[SCHEDULE] SEND MOTION : "+keymotion);
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_OUTLET_DISPENSE_COMPLETED;
        qDebug()<<"OUTLET CUP PLACE: "<<keymotion;
        break;

    case ACTION_STATE_OUTLET_DISPENSE_COMPLETED:
        if(robot->RobotMoving == true)
            break;

        ////***************택타임 체크
        plog->add_takttime("READY OUTLET     ",prevT.msecsTo(QDateTime::currentDateTime()));
        prevT = QDateTime::currentDateTime();

        plog->write("[SCHEDULE] OUTLET READY : DONE");

        if(outlet_cell_info.id_module == 0)
            keymotion = "OUT_OUTLET_1"; //INIT_POS";
        else if(outlet_cell_info.id_module == 1)
            keymotion = "OUT_OUTLET_2"; //INIT_POS";

        plog->write("[SCHEDULE] SEND MOTION : "+keymotion);
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        qDebug()<<"OUTLET DISPENSE: "<< keymotion;
        action_state = ACTION_STATE_OUTLET_GET;
        break;

    case ACTION_STATE_OUTLET_GET:
    {
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0 )
            break;

        plog->write("[SCHEDULE] OUTLET CUP PLACE : DONE");

        ////***************택타임 체크
        plog->add_takttime("DISPENSE OUTLET     ",prevT.msecsTo(QDateTime::currentDateTime()));
        prevT = QDateTime::currentDateTime();

        if(outlet->IsModuleMoving(outlet_cell_info.id_module) == true)
            break;


        ST_COMPLETED_DRINK_INFO temp_info;
        temp_info.pin = list_inprogress[0].pin;
        temp_info.menu_name = list_inprogress[0].menu_name;
        temp_info.id_module = outlet_cell_info.id_module;
        temp_info.id_cell = outlet_cell_info.id_cell;


        plog->write("[SCHEDULE] COMPLETE MAKING: PIN[" + temp_info.pin + "] / NAME[" + temp_info.menu_name +
                    "] --> OUTLET[" + QString::number(temp_info.id_module+1) + "/" + QString::number(temp_info.id_cell+1) + "]");


        plog->stop_measure_takttime(list_inprogress[0].menu_name, startT.msecsTo(QDateTime::currentDateTime()));

        last_make_pin = list_inprogress[0].pin;
        list_completed.push_back(temp_info);
        list_inprogress.clear();

        // simultaneously rotate outlet & set module not running
        outlet_rotate_state = OR_STATE_DO_ROTATE;


        outlet->SetModuleRunning(outlet_cell_info.id_module,false);

        action_state = ACTION_STATE_MAKING_PROCESS;
        qDebug()<<"OUTLET GET: "<<keymotion;
        break;
    }

    default:
        break;
    }


    switch(outlet_rotate_state){
    case OR_STATE_DO_ROTATE:
        // led on
        outlet->LEDon(outlet_cell_info.id_module,LED_TURN_GREEN);

        outlet->SpinToExit(outlet_cell_info.id_module, outlet_cell_info.id_cell);
        timeout_rotate = 500/SCHEDULER_TIME_INTERVAL;
        outlet_rotate_state = OR_STATE_WAIT_ROTATE_DONE;
        break;

    case OR_STATE_WAIT_ROTATE_DONE:
        if(--timeout_rotate > 0 )
            break;

        if(outlet->IsModuleMoving(outlet_cell_info.id_module) == true)
            break;

        if(outlet->CheckSpinInExitPos(outlet_cell_info.id_module, outlet_cell_info.id_cell) == false){   // new added by lim -- motion miss prevention
            timeout_rotate = 1000/SCHEDULER_TIME_INTERVAL;
            outlet->SpinToExit(outlet_cell_info.id_module, outlet_cell_info.id_cell);
            break;
        }

        outlet->SetModuleRunning(outlet_cell_info.id_module, false);


        outlet_rotate_state = OR_STATE_IDLE;
        break;
    }


    // Barcode Input for Dispensing Drinks
    if(barcode->NewInputNotification == true){
        barcode->NewInputNotification = false;
        QString barcode_pin = barcode->NewBarcodePin.right(4);
        int match_code = 0;

        for(int i=0; i<list_completed.size();i++){
            if(list_completed[i].pin == barcode_pin){

                int id_module = list_completed[i].id_module;
                if(outlet->IsModuleMoving(id_module) == false && outlet->IsModuleRunning(id_module) == false){

                    list_dispensing[id_module].pin = list_completed[i].pin;
                    list_dispensing[id_module].menu_name = list_completed[i].menu_name;

                    list_dispensing[id_module].id_module = list_completed[i].id_module;
                    list_dispensing[id_module].id_cell = list_completed[i].id_cell;

                    plog->write("[SCHEDULE OUTLET] DISPENSE REQUEST: PIN[" + list_completed[i].pin + "] / NAME[" + list_completed[i].menu_name +
                                "] --> OUTLET[" + QString::number(list_completed[i].id_module+1) + "/" + QString::number(list_completed[i].id_cell+1) + "]");

                    outlet_state[id_module] = OUTLET_MODULE_READY;

                    list_completed.removeAt(i);
                    break;
                }
                else{
                    if(last_make_pin == barcode_pin){
                        if(list_completed.size() == 1){
                            list_dispensing[id_module].pin = list_completed[i].pin;
                            list_dispensing[id_module].menu_name = list_completed[i].menu_name;

                            list_dispensing[id_module].id_module = list_completed[i].id_module;
                            list_dispensing[id_module].id_cell = list_completed[i].id_cell;

                            plog->write("[SCHEDULE OUTLET] DISPENSE REQUEST EARLY : PIN[" + list_completed[i].pin + "] / NAME[" + list_completed[i].menu_name +
                                        "] --> OUTLET[" + QString::number(list_completed[i].id_module+1) + "/" + QString::number(list_completed[i].id_cell+1) + "]");

                            outlet_state[id_module] = OUTLET_MODULE_READY;
                            last_make_pin = "";
                            list_completed.removeAt(i);
                            break;
                        }
                    }else{
                        qDebug()<<"Module is Running: SOUNDS";
                        pdisplay->notice = "모듈이 동작 중 임으로 잠시만 기다려주세요.";
                        pdisplay->notice_count = 3;
                    }
                }
                match_code = 1;
            }
        }

        if(match_code == 0){
            if(list_dispensing[0].pin == barcode_pin)
                match_code = 4;
            else if(list_dispensing[1].pin == barcode_pin)
                match_code = 4;
        }
        if(match_code == 0){
            for(int i=0; i<list_inprogress.size(); i++){
                if(list_inprogress[i].pin == barcode_pin){
                    match_code = 2;
                    break;
                }
            }
        }

        if(match_code == 0){
            for(int i=0; i<list_waiting.size(); i++){
                if(list_waiting[i].pin == barcode_pin){
                    match_code = 3;
                    break;
                }
            }
        }


        if(match_code == 0){
            plog->write("[SCHEDULER] UNKNOWN BARCODE READ : "+barcode_pin);
            pdisplay->notice = "잘못된 바코드 번호입니다.";
            pdisplay->notice_count = 3;
        }else if(match_code == 2 || match_code == 3){
            qDebug() << "PLEASE WAIT BARCODE";
            pdisplay->notice = "음료 제조 중입니다. 잠시만 기다려주세요.";
            pdisplay->notice_count = 3;
        }else{
            qDebug() << "BARCODE KK " <<match_code;
        }
    }





    // Outlet Schedule ========================================
    for(int i=0; i<NUMBER_OF_OUTLET; i++){
        switch(outlet_state[i]){
        case OUTLET_MODULE_IDLE:
            break;

        case OUTLET_MODULE_READY:
            outlet->SetModuleRunning(i, true);
            outlet_state[i] = OUTLET_MODULE_SPIN;
            qDebug()<<"OUTLET_READY"<<i;
            break;

        case OUTLET_MODULE_SPIN:
            // led on
            outlet->LEDon(i,LED_TURN_GREEN);
            outlet->SpinToExit(i, list_dispensing[i].id_cell);

            timeout_door[i] = 1500/SCHEDULER_TIME_INTERVAL;
            outlet_state[i] = OUTLET_MODULE_SPIN_WAIT;
            qDebug()<<"OUTLET_SPIN"<<i;
            break;

        case OUTLET_MODULE_SPIN_WAIT:
            if(--timeout_door[i] > 0)
                break;

            if(outlet->IsModuleMoving(i) == true)
                break;

            outlet_state[i] = OUTLET_MODULE_DOOR_OPEN;
            qDebug()<<"OUTLET_SPIN_WAIT"<<i;
            break;

        case OUTLET_MODULE_DOOR_OPEN:
            // led on
            outlet->LEDon(i,LED_BLINK_GREEN);
            outlet->OpenDoor(i);
            timeout_door[i] = 1500/SCHEDULER_TIME_INTERVAL;

            outlet_state[i] = OUTLET_MODULE_DOOR_WAIT_IN_OPEN;
            qDebug()<<"OUTLET_OPEN"<<i;
            break;

        case OUTLET_MODULE_DOOR_WAIT_IN_OPEN:
            if(--timeout_door[i] > 0)
                break;
            if(outlet->IsModuleMoving(i) == true)
                break;

            if(outlet->CheckDoorInOpenPos(i) == false){  // new added by lim -- motion miss prevention
                outlet_state[i] = OUTLET_MODULE_DOOR_OPEN;
            }

            if(outlet->GetSonarSensor(i) < OUTLET_SONAR_SENSOR_THRESHOLD)
                break;
            else
                outlet_state[i] = OUTLET_MODULE_DOOR_CLOSE;

            timeout_door[i] = 3000/SCHEDULER_TIME_INTERVAL;
            break;

        case OUTLET_MODULE_DOOR_CLOSE:
            if(--timeout_door[i] >0)
                break;

            // led on
            outlet->LEDon(i,LED_TURN_YELLOW);
            outlet->CloseDoor(i);
            timeout_door[i] = 1000/SCHEDULER_TIME_INTERVAL;

            outlet_state[i] = OUTLET_MODULE_DOOR_WAITE_IN_CLOSE;
            qDebug()<<"OUTLET_CLOSE"<<i;
            break;

        case OUTLET_MODULE_DOOR_WAITE_IN_CLOSE:
            if(outlet->GetSonarSensor(i) < OUTLET_SONAR_SENSOR_THRESHOLD){
                qDebug()<<"ULTRA SONIC Detected";
                outlet_state[i] = OUTLET_MODULE_DOOR_OPEN;
                break;
            }

            if(--timeout_door[i] >0)
                break;
            if(outlet->IsModuleMoving(i) == true)
                break;


            if(MOTOR_COL_ERROR(outlet->GetMotorStatus(i, OUTLET_DOOR)) == 1){
                qDebug()<<"OUTLET MODULE (DOOR): "<<i<<" COLLISION DETECTED"<<i;
                timeout_door[i] = 5000/SCHEDULER_TIME_INTERVAL;
                outlet_state[i] = OUTLET_MODULE_DOOR_CLOSE;
                break;
            }

            if(outlet->CheckDoorInClosePos(i) == false){  // new added by lim -- motion miss prevention
                outlet_state[i] = OUTLET_MODULE_DOOR_CLOSE;
            }

            timeout_door[i] = 500/SCHEDULER_TIME_INTERVAL;
            outlet_state[i] = OUTLET_MODULE_CHECK_CELL_OCC;
            break;

        case OUTLET_MODULE_CHECK_CELL_OCC:
            if(--timeout_door[i] >0)
                break;
            if(outlet->IsModuleMoving(i) == true)
                break;

            if(outlet->GetSonarSensor(i) < OUTLET_SONAR_SENSOR_THRESHOLD){
                //outlet->SetCellOccupancy(i, list_dispensing[i].id_cell, CELL_OCC);
            }
            else{
                outlet->SetCellOccupancy(i, list_dispensing[i].id_cell, CELL_EMP, "");
            }

            outlet->SetModuleRunning(i, false);
            outlet_state[i] = OUTLET_MODULE_COMPLETED;

            break;

        case OUTLET_MODULE_COMPLETED:
            plog->write("[SCHEDULE OUTLET] DISPENSE COMPLETE: PIN[" + list_dispensing[i].pin + "] / NAME[" + list_dispensing[i].menu_name +
                        "] --> OUTLET[" + QString::number(list_dispensing[i].id_module+1) + "/" + QString::number(list_dispensing[i].id_cell+1) + "]");

            list_dispensing[i].pin = "";
            qDebug()<<"OUTLET_COMPLETED"<<i;
            outlet_state[i] = OUTLET_MODULE_IDLE;
            break;
        }
    }




    // for test
//    robot->RobotMoving = false;
//    CUP_DATA[0].cup_out_count++;
//    CUP_DATA[1].cup_out_count++;
//    CUP_DATA[2].cup_out_count++;
//    CUP_DATA[3].cup_out_count++;
//    SLUSH_DATA[0].out_count++;
//    coffee->beverage_state = BEVERAGE_DONE;
}


int Scheduler::IsIdle(){
    if(list_waiting.size() > 0)
        return false;
    if(list_completed.size() > 0)
        return false;
    if(list_inprogress.size() > 0)
        return false;
    for(int i=0; i<NUMBER_OF_OUTLET; i++){
        if(list_dispensing[i].pin != ""){
            return false;
        }
    }
    return true;
}


void Scheduler::SetForcedDispensing(int id_module, int id_cell){
    if(outlet->IsModuleMoving(id_module) == false && outlet->IsModuleRunning(id_module) == false){
        list_dispensing[id_module].pin = OUTLET_DATA[id_module].cell_occupy_pin[id_cell];
        list_dispensing[id_module].id_module = id_module;
        list_dispensing[id_module].id_cell = id_cell;
        outlet_state[id_module] = OUTLET_MODULE_READY;


        // new fixed by lim -- error occurs when dispense initially occupied drinks
        // list_completed_info.removeAt(id_cell);
        for(int i=0; i<list_completed.size(); i++){
            if(list_completed[i].id_module == id_module && list_completed[i].id_cell == id_cell){
                list_dispensing[id_module].menu_name = list_completed[i].menu_name;
                list_completed.removeAt(i);
            }
        }
    }else{
        qDebug()<<"Module is Running: SOUNDS";
    }
}

void Scheduler::ClearWaitingList(){
    if(list_inprogress.size() > 0){
        list_inprogress.clear();
    }
    list_waiting.clear();
}

void Scheduler::ClearCompletedList(){
    list_completed.clear();
}

int Scheduler::get_inprogress_size(){
    return list_inprogress.size();
}
void Scheduler::remove_inprogress_list(){
    if(list_inprogress.size() > 0){
        list_inprogress.clear();
    }
}

void Scheduler::remove_waiting_list(int index){
    if(index < list_waiting.size()){
        list_waiting.remove(index);
    }
}


void Scheduler::SetRecallOrderFlag(){
    recall_order_flag = 1;
}
void Scheduler::SetRecallInprogressingOrderFlag(){
    recall_inprogressing_order_flag = 1;
}


void Scheduler::DoEarlyCoffeeDispense(QString now_step){
    if(prev_step == now_step){// || pprev_step.left(3) == now_step){
        if(is_coffee_used == true){
            if(is_coffee_triggered == false){
                if(coffee->module_status.coffee_L_status == Ready_e && coffee->module_status.water_status == Ready_e){

                    plog->write("[SCHEDULE] COFFEE EARLY DISPENSE : "+now_step);
                    coffee->DoProduct(stock->coffee_key_btn[early_coffee_button].toInt());
                    is_coffee_triggered = true;
                }
            }
        }
    }else{
        ;
    }
}
