#include "DialogStock.h"
#include "ui_DialogStock.h"

#ifdef ICECREAM_VER
#else
#include "Scheduler.h"

extern Scheduler *pschedule;
extern Logger *plog;

int use_soda;

DialogStock::DialogStock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStock)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE", "DB_RECIPE");
    db.setDatabaseName(DB_NAME_RECIPE);

    use_soda = 1;
    ApproximateWaitingTime = 0;
    forced_syrup_use = true;
    LoadDatabase();
    SetUIForm();

    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(400);
}

DialogStock::~DialogStock()
{
    delete ui;
}

void DialogStock::onTimer(){
    if(IS_UI_LOCK){
        ui->GB_STOCK->setEnabled(false);
    }else{
        ui->GB_STOCK->setEnabled(true);
    }

    UpdateUI();

    UpdateStockReserved();
    UpdateMenuAvailable();
    UpdateWaitingTime();

    if(SYRUP_DATA[0].connection_status == 0){
        stock["SYRUP_1"].error = 1;
        stock["SYRUP_2"].error = 1;
        stock["SYRUP_3"].error = 1;
        stock["SYRUP_4"].error = 1;
        stock["SYRUP_5"].error = 1;
        ui->frame->setEnabled(false);
        ui->frame_2->setEnabled(false);
    }else{
        ui->frame_2->setEnabled(true);
        if(use_soda == 0){
            stock["SYRUP_5"].error = 1;
        }else{
            stock["SYRUP_5"].error = 0;
        }
        if(forced_syrup_use){
            stock["SYRUP_1"].error = 0;
            stock["SYRUP_2"].error = 0;
            stock["SYRUP_3"].error = 0;
            stock["SYRUP_4"].error = 0;
//            stock["SYRUP_5"].error = 0;
//            stock["SYRUP_6"].error = 0;
            ui->frame->setEnabled(true);
        }else{
            stock["SYRUP_1"].error = 1;
            stock["SYRUP_2"].error = 1;
            stock["SYRUP_3"].error = 1;
            stock["SYRUP_4"].error = 1;
//            stock["SYRUP_5"].error = 1;
//            stock["SYRUP_6"].error = 1;
            ui->frame->setEnabled(false);
        }
    }


}

void DialogStock::LoadDatabase(){
    if(!db.open()){
        qDebug() << "Load Recipe Database Fail";
        return;
    }

    QSqlQuery query(db);
    if(query.exec("SELECT * FROM Table_Stock")){
        stock.clear();
        syrup_to_pump.clear();
        syrup_to_name.clear();
        while(query.next()){
            QString key_stock = query.value("stock").toString();
            QString type = query.value("type").toString();
            int current = query.value("current").toInt();
            int minimum = query.value("minimum").toInt();
            int maximum = query.value("maximum").toInt();
            QString name = query.value("korean").toString();
            int pump_num = query.value("pump").toInt();
            ST_STOCK temp_stock;
            temp_stock.type = type;
            temp_stock.menu_name = name;
            temp_stock.current = current;
            temp_stock.maximum = maximum;
            temp_stock.minimum = minimum;
            temp_stock.error = 0;
            temp_stock.pump_num = pump_num;
            stock[key_stock] = temp_stock;

            if(type == "SYRUP"){
                syrup_to_pump[key_stock] = pump_num;
                syrup_to_name[key_stock] = name;
            }
        }
    }

    if(query.exec("SELECT * FROM Table_Coffee")){
        coffee_key_btn.clear();
        coffee_desc_btn.clear();
        while(query.next()){
            QString key_coffee = query.value("key").toString();
            QString btn_coffee = query.value("button").toString();
            QString desc_coffee = query.value("description").toString();

            coffee_key_btn[key_coffee] = btn_coffee;
            coffee_desc_btn[desc_coffee] = btn_coffee;
        }
    }

    if(query.exec("SELECT * FROM Table_Menu")){
        menu.clear();
        while(query.next()){
            QString menu_id = query.value("menu_id").toString();
            QString menu_name = query.value("menu_name").toString();
            int menu_time = query.value("time").toInt();
            ST_MENU temp_menu;
            temp_menu.menu_id = menu_id;
            temp_menu.menu_name = menu_name;
            temp_menu.time = menu_time;

            V_RECIPE temp_recipe;
            for(int i=0; i<10; i++){
                QString step = QString().sprintf("step%d", i+1);
                QString amount = QString().sprintf("amount%d", i+1);
                if(query.value(step).isNull()){
                    ST_RECIPE_STEP temp_step;
                    temp_step.ingredient = "OUTLET";
                    temp_step.amount = "1";
                    temp_recipe.push_back(temp_step);
                    break;
                }else{
                    ST_RECIPE_STEP temp_step;
                    temp_step.ingredient = query.value(step).toString();
                    temp_step.amount = query.value(amount).toString();
                    temp_recipe.push_back(temp_step);
                }
            }
            temp_menu.recipe = temp_recipe;
            menu[menu_id] = temp_menu;
        }
    }

}

void DialogStock::SaveDatabase(QVector<ST_MENU> new_db){
    if(!db.open()){
        qDebug() << "Load Recipe Database Fail";
        return;
    }

    QSqlQuery query(db);

    //Delete All
    QString query_str;
    query_str = "DELETE FROM Table_Menu";
    query.exec(query_str);

    for(int i=0; i<new_db.size(); i++){
        query_str = "INSERT INTO Table_Menu (menu_id, menu_name, time";

        for(int j=0; j<new_db[i].recipe.size(); j++){
            if(new_db[i].recipe[j].ingredient != "OUTLET"){
                query_str += ", step"+QString::number(j+1)+", amount"+QString::number(j+1);
            }
        }
        query_str += ") VALUES ('" + new_db[i].menu_id + "','" + new_db[i].menu_name + "',60";

        for(int j=0; j<new_db[i].recipe.size(); j++){
            if(new_db[i].recipe[j].ingredient != "OUTLET"){
                query_str += ",'"+new_db[i].recipe[j].ingredient+"','"+new_db[i].recipe[j].amount+"'";
            }
        }

        query_str += ")";

        qDebug() << query_str;
        query.exec(query_str);

    }
}

void DialogStock::BackupDatabase(){


}

void DialogStock::SaveRecipe(QString menu_id, V_RECIPE new_recipe){
    menu[menu_id].recipe = new_recipe;
}

void DialogStock::SetUIForm(){
    ui->LB_CUP_1->setText(stock["PAPER_CUP_1"].menu_name);
    ui->LB_CUP_2->setText(stock["PP_CUP_1"].menu_name);

    ui->PB_CUP_1->setMaximum(stock["PAPER_CUP_1"].maximum);
    ui->PB_CUP_2->setMaximum(stock["PP_CUP_1"].maximum);

    // ---------------------

    ui->LB_SYRUP_1->setText(stock["SYRUP_1"].menu_name);
    ui->LB_SYRUP_2->setText(stock["SYRUP_2"].menu_name);
    ui->LB_SYRUP_3->setText(stock["SYRUP_3"].menu_name);
    ui->LB_SYRUP_4->setText(stock["SYRUP_4"].menu_name);
    ui->LB_SYRUP_5->setText(stock["SYRUP_5"].menu_name);
//    ui->LB_SYRUP_6->setText(stock["SYRUP_6"].menu_name);

    ui->PB_SYRUP_1->setMaximum(stock["SYRUP_1"].maximum);
    ui->PB_SYRUP_2->setMaximum(stock["SYRUP_2"].maximum);
    ui->PB_SYRUP_3->setMaximum(stock["SYRUP_3"].maximum);
    ui->PB_SYRUP_4->setMaximum(stock["SYRUP_4"].maximum);
    ui->PB_SYRUP_5->setMaximum(stock["SYRUP_5"].maximum);
//    ui->PB_SYRUP_6->setMaximum(stock["SYRUP_6"].maximum);

    // ---------------------


    // ---------------------
    ui->LB_ICE_1->setText(stock["ICE"].menu_name);
    ui->LB_COFFEE->setText(stock["COFFEE"].menu_name);
    ui->LB_MILK->setText(stock["MILK"].menu_name);
    ui->PB_ICE_1->setMaximum(1);
    ui->PB_COFFEE->setMaximum(1);
    ui->PB_MILK->setMaximum(1);



    // ---------------------------
    ui->CB_STOCK_NAME->addItem("PAPER_CUP_1");
    ui->CB_STOCK_NAME->addItem("PP_CUP_1");

    ui->CB_STOCK_NAME->addItem("SYRUP_1");
    ui->CB_STOCK_NAME->addItem("SYRUP_2");
    ui->CB_STOCK_NAME->addItem("SYRUP_3");
    ui->CB_STOCK_NAME->addItem("SYRUP_4");
    ui->CB_STOCK_NAME->addItem("SYRUP_5");
    ui->CB_STOCK_NAME->addItem("SYRUP_6");
}

void DialogStock::UpdateUI(){
    ui->PB_CUP_1->setValue(stock["PAPER_CUP_1"].current);
    ui->PB_CUP_2->setValue(stock["PP_CUP_1"].current);

    ui->PB_CUP_1->setFormat(QString().sprintf("%d / %d", stock["PAPER_CUP_1"].current, stock["PAPER_CUP_1"].maximum));
    ui->PB_CUP_2->setFormat(QString().sprintf("%d / %d", stock["PP_CUP_1"].current, stock["PP_CUP_1"].maximum));

    //------------------------

    ui->PB_SYRUP_1->setValue(stock["SYRUP_1"].current);
    ui->PB_SYRUP_2->setValue(stock["SYRUP_2"].current);
    ui->PB_SYRUP_3->setValue(stock["SYRUP_3"].current);
    ui->PB_SYRUP_4->setValue(stock["SYRUP_4"].current);
//    ui->PB_SYRUP_5->setValue(1);//stock["SYRUP_5"].current);
//    ui->PB_SYRUP_6->setValue(stock["SYRUP_6"].current);
    ui->PB_SYRUP_1->setFormat(QString().sprintf("%d / %d", stock["SYRUP_1"].current, stock["SYRUP_1"].maximum));
    ui->PB_SYRUP_2->setFormat(QString().sprintf("%d / %d", stock["SYRUP_2"].current, stock["SYRUP_2"].maximum));
    ui->PB_SYRUP_3->setFormat(QString().sprintf("%d / %d", stock["SYRUP_3"].current, stock["SYRUP_3"].maximum));
    ui->PB_SYRUP_4->setFormat(QString().sprintf("%d / %d", stock["SYRUP_4"].current, stock["SYRUP_4"].maximum));
//    ui->PB_SYRUP_5->setFormat(QString().sprintf("%d / %d", stock["SYRUP_5"].current, stock["SYRUP_5"].maximum));
//    ui->PB_SYRUP_6->setFormat(QString().sprintf("%d / %d", stock["SYRUP_6"].current, stock["SYRUP_6"].maximum));

    //------------------------

    if(stock["SYRUP_5"].error == 1){
        ui->PB_SYRUP_5->setValue(0);
    }else{
        ui->PB_SYRUP_5->setValue(1000);
    }

    //------------------------
    if(stock["ICE"].error == 1){
        ui->PB_ICE_1->setValue(0);
    }else{
        ui->PB_ICE_1->setValue(1);
    }


    if(stock["COFFEE"].error == 1){
        ui->PB_COFFEE->setValue(0);
    }else{
        ui->PB_COFFEE->setValue(1);
    }


    if(stock["MILK"].error == 1){
        ui->PB_MILK->setValue(0);
    }else{
        ui->PB_MILK->setValue(1);
    }
}

void DialogStock::UseStock(QString stock_name, int amount){
    stock[stock_name].current = stock[stock_name].current - amount;
    if(stock[stock_name].current < 0){
        stock[stock_name].current = 0;
    }
    UpdateStock(stock_name);
}

void DialogStock::UpdateStock(QString stock_name){
    QSqlQuery query(db);
    int cur = stock[stock_name].current;

    QString update_str = QString().sprintf("UPDATE Table_Stock SET current = %d WHERE stock = \'%s\'", cur, stock_name.toStdString().data());
    query.exec(update_str);
}

void DialogStock::SetStock(QString stock_name, int amount){
    QSqlQuery query(db);
    if(amount > stock[stock_name].maximum)
        amount = stock[stock_name].maximum;
    int cur = stock[stock_name].current = amount;


    QString update_str = QString().sprintf("UPDATE Table_Stock SET current = %d WHERE stock = \'%s\'", cur, stock_name.toStdString().data());
    query.exec(update_str);
}

int DialogStock::GetStock(QString stock_name){
    return stock[stock_name].current;
}

void DialogStock::FillFull(QString stock_name){
    SetStock(stock_name, stock[stock_name].maximum);
}
void DialogStock::FillHalf(QString stock_name){
    SetStock(stock_name, stock[stock_name].maximum/2);
}


void DialogStock::SetDeviceError(QString stock_name){
    stock[stock_name].error = 1;
}
void DialogStock::ClearDeviceError(QString stock_name){
    stock[stock_name].error = 0;
}
int DialogStock::IsDeviceError(QString stock_name){
    return stock[stock_name].error;
}


void DialogStock::UpdateStockReserved(){
    QStringList stock_keys = stock.keys();
    for(int i=0; i<stock_keys.size(); i++){
        QString stock_id = stock_keys[i];
        stock[stock_id].reserved = 0;
    }

    if(pschedule == NULL)
        return;

    QVector<ST_RECIPE_INFO> list_waiting;
    list_waiting = pschedule->list_waiting;
    if(pschedule->list_inprogress.size() > 0){
        list_waiting.push_back(pschedule->list_inprogress[0]);
    }

    for(int i=0; i<list_waiting.size(); i++){
        V_RECIPE re = list_waiting[i].recipe;
        for(int j=0; j<re.size(); j++){
            QString ingredient = re[j].ingredient;
            QString amount = re[j].amount;

            if(ingredient == "PAPER_CUP"){
                stock["PAPER_CUP_1"].reserved += 1;
            }else if(ingredient == "PET_CUP"){
                stock["PET_CUP_1"].reserved += 1;
            }else if(ingredient == "SYRUP_5" || ingredient == "ICE" || ingredient == "COFFEE" || ingredient == "MILK" || ingredient == "OUTLET"){
                ;
            }else{
                stock[ingredient].reserved += amount.toUInt();
            }
        }
    }
}

void DialogStock::UpdateWaitingTime(){
    if(pschedule == NULL)
        return;

    QVector<ST_RECIPE_INFO> list_waiting;
    list_waiting = pschedule->list_waiting;
    if(pschedule->list_inprogress.size() > 0){
        list_waiting.push_back(pschedule->list_inprogress[0]);
    }

    int total_time = 0;
    for(int i=0; i<list_waiting.size(); i++){
        QString temp_id = list_waiting[i].menu_id;
        int temp_time = menu[temp_id].time;
        total_time += temp_time;
    }
    ApproximateWaitingTime = total_time;
}

void DialogStock::UpdateMenuAvailable(){
    QStringList menu_keys = menu.keys();
    for(int i=0; i<menu_keys.size(); i++){
        QString menu_id = menu_keys[i];
        V_RECIPE re = menu[menu_id].recipe;

        bool available = true;
        for(int j=0; j<re.size(); j++){
            QString ingredient = re[j].ingredient;
            QString amount = re[j].amount;
            if(ingredient == "CUP"){
                int cur_stock1, cur_stock2;
                if(stock["PAPER_CUP_1"].error == 1){
                    cur_stock1 = 0;
                }else{
                    cur_stock1 = stock["PAPER_CUP_1"].current - stock["PAPER_CUP_1"].minimum;
                }
                if(stock["PP_CUP_1"].error == 1){
                    cur_stock2 = 0;
                }else{
                    cur_stock2 = stock["PP_CUP_1"].current - stock["PP_CUP_1"].minimum;
                }

                int cur_stock;
                int reserved;

                if(amount == "HOT"){
                    cur_stock = cur_stock1;
                    reserved = stock["PAPER_CUP_1"].reserved;
                }else{
                    cur_stock = cur_stock1 + cur_stock2;
                    reserved = stock["PP_CUP_1"].reserved;
                }
                if(cur_stock-reserved < 1){
                    available = false;
                    break;
                }
            }else if(ingredient == "MILK"){
                if(stock["MILK"].error == 1){
                    available = false;
                    break;
                }
            }else if(ingredient == "ICE"){
                if(stock["ICE"].error == 1){
                    available = false;
                    break;
                }
            }else if(ingredient == "COFFEE"){
                if(amount == "LH" || amount == "LI"){
                    // latte
                    if(stock["MILK"].error == 1){
                        available = false;
                        break;
                    }
                    if(stock["COFFEE"].error == 1){
                        available = false;
                        break;
                    }
                }else{
                    if(stock["COFFEE"].error == 1){
                        available = false;
                        break;
                    }
                }
            }else if(ingredient != "OUTLET"){
                int cur_stock = stock[ingredient].current - stock[ingredient].minimum;
                int reserved = stock[ingredient].reserved;
                if(cur_stock-reserved < amount.toInt()){
                    available = false;
                    break;
                }
                if(ingredient.left(5) == "SYRUP"){
                    if(stock[ingredient].error == 1){
                        available = false;
                        break;
                    }
                }
            }
        }
        menu[menu_id].available = available;
//        qDebug() << menu[menu_id].menu_name << available << stock["SYRUP_5"].error;
    }
}

void DialogStock::on_BTN_CUP_HALF_1_clicked(){
    plog->write("[USER INPUT] CUP 1 HALF REFILL");
    FillHalf("PAPER_CUP_1");
}
void DialogStock::on_BTN_CUP_FULL_1_clicked(){
    plog->write("[USER INPUT] CUP 1 FULL REFILL");
    FillFull("PAPER_CUP_1");
}
void DialogStock::on_BTN_CUP_HALF_2_clicked(){
    plog->write("[USER INPUT] CUP 2 HALF REFILL");
    FillHalf("PP_CUP_1");
}
void DialogStock::on_BTN_CUP_FULL_2_clicked(){
    plog->write("[USER INPUT] CUP 2 FULL REFILL");
    FillFull("PP_CUP_1");
}


void DialogStock::on_BTN_SYRUP_REPLACE_1_clicked(){
    plog->write("[USER INPUT] SYRUP 1 ZERO");
    SetStock("SYRUP_1",0);
}
void DialogStock::on_BTN_SYRUP_REPLACE_2_clicked(){
    plog->write("[USER INPUT] SYRUP 2 ZERO");
    SetStock("SYRUP_2",0);
}
void DialogStock::on_BTN_SYRUP_REPLACE_3_clicked(){
    plog->write("[USER INPUT] SYRUP 3 ZERO");
    SetStock("SYRUP_3",0);
}
void DialogStock::on_BTN_SYRUP_REPLACE_4_clicked(){
    plog->write("[USER INPUT] SYRUP 4 ZERO");
    SetStock("SYRUP_4",0);
}
void DialogStock::on_BTN_SYRUP_REPLACE_5_clicked(){
    plog->write("[USER INPUT] SYRUP 5 ZERO");
//    SetStock("SYRUP_5",0);
//    stock["SYRUP_5"].error = 1;
    use_soda = 0;
}


void DialogStock::on_BTN_SET_STOCK_MANUAL_clicked(){
    plog->write("[USER INPUT] SET STOCK "+ui->CB_STOCK_NAME->currentText() + QString().sprintf(" -> %d",ui->LE_MANUAL_STOCK_AMOUNT->text().toInt()));
    SetStock(ui->CB_STOCK_NAME->currentText(), ui->LE_MANUAL_STOCK_AMOUNT->text().toInt());
}

void DialogStock::on_BTN_MILK_USE_clicked(){
    plog->write("[USER INPUT] MILK USE : YES");
    stock["MILK"].error = 0;
}

void DialogStock::on_BTN_MILK_NOT_USE_clicked(){
    plog->write("[USER INPUT] MILK USE : NO");
    stock["MILK"].error = 1;
}

void DialogStock::on_BTN_SYRUP_USE_clicked(){
    plog->write("[USER INPUT] SYRUP USE : YES");
    forced_syrup_use = true;

}

void DialogStock::on_BTN_SYRUP_NOT_USE_clicked(){
    plog->write("[USER INPUT] SYRUP USE : NO");
    forced_syrup_use = false;
}

void DialogStock::on_BTN_SYRUP_ADD_1_clicked()
{
    plog->write("[USER INPUT] SYRUP 1 ADD 1L");
    SetStock("SYRUP_1",stock["SYRUP_1"].current+1000);
}
void DialogStock::on_BTN_SYRUP_ADD_2_clicked()
{
    plog->write("[USER INPUT] SYRUP 2 ADD 1L");
    SetStock("SYRUP_2",stock["SYRUP_2"].current+1000);
}
void DialogStock::on_BTN_SYRUP_ADD_3_clicked()
{
    plog->write("[USER INPUT] SYRUP 3 ADD 1L");
    SetStock("SYRUP_3",stock["SYRUP_3"].current+1000);
}
void DialogStock::on_BTN_SYRUP_ADD_4_clicked()
{
    plog->write("[USER INPUT] SYRUP 4 ADD 1L");
    SetStock("SYRUP_4",stock["SYRUP_4"].current+1000);
}
void DialogStock::on_BTN_SYRUP_ADD_5_clicked()
{
    plog->write("[USER INPUT] SYRUP 5 ADD 1L");
//    stock["SYRUP_5"].error = 0;
    use_soda = 1;
}
#endif
