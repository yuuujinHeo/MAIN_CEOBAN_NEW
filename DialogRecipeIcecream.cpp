#include "DialogRecipeIcecream.h"
#include "ui_DialogRecipeIcecream.h"
#include <QMessageBox>
#include <Logger.h>

extern Logger *plog;
DialogRecipeIcecream::DialogRecipeIcecream(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRecipeIcecream)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    currentSelectSlush = 0;
    currentSelectBase = 0;
    numofPumpingBase = 0;
    currentSelectSyrup = 0;
    currentEditIndex = 0;
}

DialogRecipeIcecream::~DialogRecipeIcecream()
{
    emit cancel();
    delete ui;
}

void DialogRecipeIcecream::AddMenu(){
    this->setEnabled(true);
    ui->stackedWidget->setCurrentIndex(0);
    ui->LE_ADD_MENU_ID->setText("");
    ui->LE_ADD_MENU_NAME->setText("");
    this->show();
}

void DialogRecipeIcecream::EditMenu(int index, QString menu_id, QString menu_name){
    this->setEnabled(true);
    ui->stackedWidget->setCurrentIndex(1);
    currentEditIndex = index;
    ui->LE_EDIT_MENU_ID->setText(menu_id);
    ui->LE_EDIT_MENU_NAME->setText(menu_name);
    this->show();
}

void DialogRecipeIcecream::AddIngredient(){
    this->setEnabled(true);
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->LE_SLUSH->setText("0");
    ui->LE_ICECREAM->setText("0");
    currentSelectSlush = 0;
    currentSelectBase = 0;
    numofPumpingBase = 0;
    SetBTNColor(ui->BTN_BASE_STRAWBERRY,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_STRAWBERRY_2,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_CHOCO,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_CHOCO_2,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_1PUMP,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_2PUMP,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_3PUMP,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_1PUMP_2,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_2PUMP_2,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_3PUMP_2,COLOR_NONE);
    SetBTNColor(ui->BTN_SYRUP_VANILA_2,COLOR_NONE);
    SetBTNColor(ui->BTN_SYRUP_HAZ_2,COLOR_NONE);
    SetBTNColor(ui->BTN_SYRUP_VANILA_3,COLOR_NONE);
    SetBTNColor(ui->BTN_SYRUP_HAZ_3,COLOR_NONE);
    this->show();
}

void DialogRecipeIcecream::EditIngredient(int index, ST_RECIPE_STEP ingredient){
    this->setEnabled(true);
    ui->stackedWidget->setCurrentIndex(3);
    if(ingredient.ingredient == "ICECREAM"){
        ui->SW_EDIT_RECIPE->setCurrentIndex(1);
        ui->LE_ICECREAM->setText(ingredient.amount);
    }else if(ingredient.ingredient == "SLUSH_1"){
        ui->SW_EDIT_RECIPE->setCurrentIndex(3);
        ui->LE_SLUSH->setText(ingredient.amount);
        currentSelectSlush = 1;
        SetBTNColor(ui->BTN_SYRUP_VANILA_2,COLOR_BLUE);
        SetBTNColor(ui->BTN_SYRUP_HAZ_2,COLOR_NONE);
    }else if(ingredient.ingredient == "SLUSH_2"){
        ui->SW_EDIT_RECIPE->setCurrentIndex(3);
        ui->LE_SLUSH->setText(ingredient.amount);
        currentSelectSlush = 2;
        SetBTNColor(ui->BTN_SYRUP_VANILA_2,COLOR_NONE);
        SetBTNColor(ui->BTN_SYRUP_HAZ_2,COLOR_BLUE);
    }else if(ingredient.ingredient == "BASE_1"){
        ui->SW_EDIT_RECIPE->setCurrentIndex(2);
        currentSelectBase = 1;
        SetBTNColor(ui->BTN_BASE_STRAWBERRY,COLOR_BLUE);
        SetBTNColor(ui->BTN_BASE_CHOCO,COLOR_NONE);

        if(ingredient.amount == "1"){
            numofPumpingBase = 1;
            SetBTNColor(ui->BTN_BASE_1PUMP,COLOR_BLUE);
            SetBTNColor(ui->BTN_BASE_2PUMP,COLOR_NONE);
            SetBTNColor(ui->BTN_BASE_3PUMP,COLOR_NONE);
        }else if(ingredient.amount == "2"){
            numofPumpingBase = 2;
            SetBTNColor(ui->BTN_BASE_1PUMP,COLOR_NONE);
            SetBTNColor(ui->BTN_BASE_2PUMP,COLOR_BLUE);
            SetBTNColor(ui->BTN_BASE_3PUMP,COLOR_NONE);
        }else if(ingredient.amount == "3"){
            numofPumpingBase = 3;
            SetBTNColor(ui->BTN_BASE_1PUMP,COLOR_NONE);
            SetBTNColor(ui->BTN_BASE_2PUMP,COLOR_NONE);
            SetBTNColor(ui->BTN_BASE_3PUMP,COLOR_BLUE);
        }
    }else if(ingredient.ingredient == "BASE_2"){
        ui->SW_EDIT_RECIPE->setCurrentIndex(2);
        currentSelectBase = 2;
        SetBTNColor(ui->BTN_BASE_STRAWBERRY,COLOR_NONE);
        SetBTNColor(ui->BTN_BASE_CHOCO,COLOR_BLUE);

        if(ingredient.amount == "1"){
            numofPumpingBase = 1;
            SetBTNColor(ui->BTN_BASE_1PUMP,COLOR_BLUE);
            SetBTNColor(ui->BTN_BASE_2PUMP,COLOR_NONE);
            SetBTNColor(ui->BTN_BASE_3PUMP,COLOR_NONE);
        }else if(ingredient.amount == "2"){
            numofPumpingBase = 2;
            SetBTNColor(ui->BTN_BASE_1PUMP,COLOR_NONE);
            SetBTNColor(ui->BTN_BASE_2PUMP,COLOR_BLUE);
            SetBTNColor(ui->BTN_BASE_3PUMP,COLOR_NONE);
        }else if(ingredient.amount == "3"){
            numofPumpingBase = 3;
            SetBTNColor(ui->BTN_BASE_1PUMP,COLOR_NONE);
            SetBTNColor(ui->BTN_BASE_2PUMP,COLOR_NONE);
            SetBTNColor(ui->BTN_BASE_3PUMP,COLOR_BLUE);
        }
    }
    currentEditIndex = index;
    this->show();
}


void DialogRecipeIcecream::on_BTN_SODA_OK_2_clicked()
{
    if(currentSelectBase == 0 || numofPumpingBase == 0){
        QMessageBox::information(this, "저장 실패", "베이스의 종류의 펌프 횟수를 선택해주세요.");
    }else{
        ST_RECIPE_STEP temp_step;
        temp_step.ingredient = "BASE_"+QString::number(currentSelectBase);
        temp_step.amount = QString::number(numofPumpingBase);
        plog->write("[RECIPE] EDIT INGREDIENT : STEP("+temp_step.ingredient+"), AMOUNT("+temp_step.amount+")");
        emit edit_ingredient(currentEditIndex,temp_step);
        this->close();
    }
}
void DialogRecipeIcecream::on_BTN_SYRUP_VANILA_2_clicked()
{
    currentSelectSlush = 1;
    SetBTNColor(ui->BTN_SYRUP_VANILA_2,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_HAZ_2,COLOR_UNDETERMINED);
}

void DialogRecipeIcecream::on_BTN_SYRUP_HAZ_2_clicked()
{
    currentSelectSlush = 2;
    SetBTNColor(ui->BTN_SYRUP_VANILA_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_HAZ_2,COLOR_BLUE);
}


void DialogRecipeIcecream::on_BTN_SYRUP_OK_2_clicked()
{
    if(currentSelectSlush == 0){
        QMessageBox::information(this, "저장 실패", "슬러시의 맛을 선택해주세요.");
    }else if(ui->LE_SLUSH->text() == "0" || ui->LE_SLUSH->text() == ""){
        QMessageBox::information(this, "저장 실패", "값을 입력해주세요.");
    }else if(ui->LE_SLUSH->text().toInt() > 500 || ui->LE_SLUSH->text().toInt() <10){
        QMessageBox::information(this, "저장 실패", "배출양이 너무 적거나 많습니다.");
    }else{
        ST_RECIPE_STEP temp_step;
        temp_step.amount = ui->LE_SLUSH->text();
        switch(currentSelectSlush){
        case 1:
            temp_step.ingredient = "SLUSH_1";
            break;
        case 2:
            temp_step.ingredient = "SLUSH_2";
            break;
        }
        plog->write("[RECIPE] EDIT INGREDIENT : STEP("+temp_step.ingredient+"), AMOUNT("+temp_step.amount+")");
        emit edit_ingredient(currentEditIndex,temp_step);
        this->close();
    }
}


void DialogRecipeIcecream::on_BTN_EDIT_MENU_OK_clicked()
{
    if(ui->LE_EDIT_MENU_ID->text() != "" && ui->LE_EDIT_MENU_NAME->text() != ""){
        ST_MENU_INFO temp_menu;
        temp_menu.menu_id = ui->LE_EDIT_MENU_ID->text();
        temp_menu.menu_name = ui->LE_EDIT_MENU_NAME->text();
        plog->write("[RECIPE] EDIT MENU "+QString::number(currentEditIndex)+" : PIN("+temp_menu.menu_id+"), NAME("+temp_menu.menu_name+")");
        emit edit_menu(currentEditIndex, temp_menu);
        this->close();
    }else{
        QMessageBox::information(this, "저장 실패", "빈칸을 채워주세요.");
    }
}


void DialogRecipeIcecream::on_BTN_ADD_MENU_OK_clicked()
{
    if(ui->LE_ADD_MENU_ID->text() != "" && ui->LE_ADD_MENU_NAME->text() != ""){
        ST_MENU_INFO temp_menu;
        temp_menu.menu_id = ui->LE_ADD_MENU_ID->text();
        temp_menu.menu_name = ui->LE_ADD_MENU_NAME->text();
        plog->write("[RECIPE] ADD MENU : PIN("+temp_menu.menu_id+"), NAME("+temp_menu.menu_name+")");
        emit add_menu(temp_menu);
        this->close();
    }else{
        QMessageBox::information(this, "저장 실패", "빈칸을 채워주세요.");
    }
}

void DialogRecipeIcecream::on_BTN_ICE_OK_clicked()
{
    if(ui->LE_ICECREAM_2->text() == ""){
        QMessageBox::information(this, "저장 실패", "값을 입력해주세요.");
    }else if(ui->LE_ICECREAM_2->text().toInt() < 10 || ui->LE_ICECREAM_2->text().toInt() > 300){
        QMessageBox::information(this, "저장 실패", "배출하는 양을 g단위로 확인해주세요. 값이 너무 크거나 작습니다.");
    }else{
        ST_RECIPE_STEP temp_step;
        temp_step.ingredient = "ICECREAM";
        temp_step.amount = ui->LE_ICECREAM_2->text();
        plog->write("[RECIPE] ADD INGREDIENT : STEP("+temp_step.ingredient+"), AMOUNT("+temp_step.amount+")");
        emit add_ingredient(temp_step);
        this->close();
    }
}

void DialogRecipeIcecream::on_BTN_ICE_OK_2_clicked()
{
    if(ui->LE_ICECREAM->text() == ""){
        QMessageBox::information(this, "저장 실패", "값을 입력해주세요.");
    }else if(ui->LE_ICECREAM->text().toInt() < 10 || ui->LE_ICECREAM->text().toInt() > 300){
        QMessageBox::information(this, "저장 실패", "배출하는 양을 g단위로 확인해주세요. 값이 너무 크거나 작습니다.");
    }else{
        ST_RECIPE_STEP temp_step;
        temp_step.ingredient = "ICECREAM";
        temp_step.amount = ui->LE_ICECREAM->text();
        plog->write("[RECIPE] EDIT INGREDIENT : STEP("+temp_step.ingredient+"), AMOUNT("+temp_step.amount+")");
        emit edit_ingredient(currentEditIndex,temp_step);
        this->close();
    }
}

void DialogRecipeIcecream::on_BTN_RECIPE_ICE_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void DialogRecipeIcecream::on_BTN_RECIPE_COFFEE_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void DialogRecipeIcecream::on_BTN_RECIPE_SODA_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

void DialogRecipeIcecream::on_BTN_RECIPE_SYRUP_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(4);
}

void DialogRecipeIcecream::on_BTN_ICE_CANCEL_clicked()
{
    this->close();
    emit cancel();
}

void DialogRecipeIcecream::on_BTN_ICE_CANCEL_2_clicked()
{
    this->close();
    emit cancel();
}

void DialogRecipeIcecream::on_BTN_COF_CANCEL_2_clicked()
{
    this->close();
    emit cancel();
}

void DialogRecipeIcecream::on_BTN_SODA_CANCEL_2_clicked()
{
    this->close();
    emit cancel();
}

void DialogRecipeIcecream::on_BTN_SYRUP_CANCEL_2_clicked()
{
    this->close();
    emit cancel();
}

void DialogRecipeIcecream::on_BTN_EDIT_MENU_CANCEL_clicked()
{
    this->close();
    emit cancel();
}

void DialogRecipeIcecream::on_BTN_ADD_MENU_CANCEL_clicked()
{
    this->close();
    emit cancel();
}


void DialogRecipeIcecream::on_BTN_COF_ESP_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "E1";
    plog->write("[RECIPE] ADD INGREDIENT : ESP");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}

void DialogRecipeIcecream::on_BTN_COF_ESP2_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "E2";
    plog->write("[RECIPE] ADD INGREDIENT : ESP2");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}

void DialogRecipeIcecream::on_BTN_COF_ICELAT_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "LI";
    plog->write("[RECIPE] ADD INGREDIENT : ICELAT");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}

void DialogRecipeIcecream::on_BTN_COF_AME_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "A1";
    plog->write("[RECIPE] ADD INGREDIENT : AME");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}

void DialogRecipeIcecream::on_BTN_COF_AME2_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "A2";
    plog->write("[RECIPE] ADD INGREDIENT : AME2");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}

void DialogRecipeIcecream::on_BTN_COF_LAT_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "LH";
    plog->write("[RECIPE] ADD INGREDIENT : LAT");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}

void DialogRecipeIcecream::on_BTN_COF_MILK_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "MH";
    plog->write("[RECIPE] ADD INGREDIENT : MILK");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}

void DialogRecipeIcecream::on_BTN_COF_ICEMILK_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "MI";
    plog->write("[RECIPE] ADD INGREDIENT : ICEMILK");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}

void DialogRecipeIcecream::on_BTN_BASE_STRAWBERRY_clicked()
{
    currentSelectBase = 1;
    SetBTNColor(ui->BTN_BASE_STRAWBERRY,COLOR_BLUE);
    SetBTNColor(ui->BTN_BASE_CHOCO,COLOR_NONE);
}

void DialogRecipeIcecream::on_BTN_BASE_CHOCO_clicked()
{
    currentSelectBase = 2;
    SetBTNColor(ui->BTN_BASE_STRAWBERRY,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_CHOCO,COLOR_BLUE);
}

void DialogRecipeIcecream::on_BTN_BASE_1PUMP_clicked()
{
    numofPumpingBase = 1;
    SetBTNColor(ui->BTN_BASE_1PUMP,COLOR_BLUE);
    SetBTNColor(ui->BTN_BASE_2PUMP,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_3PUMP,COLOR_NONE);
}

void DialogRecipeIcecream::on_BTN_BASE_2PUMP_clicked()
{
    numofPumpingBase = 2;
    SetBTNColor(ui->BTN_BASE_1PUMP,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_2PUMP,COLOR_BLUE);
    SetBTNColor(ui->BTN_BASE_3PUMP,COLOR_NONE);
}

void DialogRecipeIcecream::on_BTN_BASE_3PUMP_clicked()
{
    numofPumpingBase = 3;
    SetBTNColor(ui->BTN_BASE_1PUMP,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_2PUMP,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_3PUMP,COLOR_BLUE);
}

void DialogRecipeIcecream::on_BTN_SYRUP_VANILA_3_clicked()
{
    currentSelectSlush = 1;
    SetBTNColor(ui->BTN_SYRUP_VANILA_3,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_HAZ_3,COLOR_UNDETERMINED);
}

void DialogRecipeIcecream::on_BTN_SYRUP_HAZ_3_clicked()
{
    currentSelectSlush = 2;
    SetBTNColor(ui->BTN_SYRUP_VANILA_3,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_HAZ_3,COLOR_BLUE);
}

void DialogRecipeIcecream::on_BTN_SYRUP_OK_3_clicked()
{
    if(currentSelectSlush == 0){
        QMessageBox::information(this, "저장 실패", "슬러시의 맛을 선택해주세요.");
    }else if(ui->LE_SLUSH_2->text() == "0" || ui->LE_SLUSH_2->text() == ""){
        QMessageBox::information(this, "저장 실패", "값을 입력해주세요.");
    }else if(ui->LE_SLUSH_2->text().toInt() > 500 || ui->LE_SLUSH_2->text().toInt() <10){
        QMessageBox::information(this, "저장 실패", "배출양이 너무 적거나 많습니다.");
    }else{
        ST_RECIPE_STEP temp_step;
        temp_step.amount = ui->LE_SLUSH_2->text();
        switch(currentSelectSlush){
        case 1:
            temp_step.ingredient = "SLUSH_1";
            break;
        case 2:
            temp_step.ingredient = "SLUSH_2";
            break;
        }
        plog->write("[RECIPE] ADD INGREDIENT : STEP("+temp_step.ingredient+"), AMOUNT("+temp_step.amount+")");
        emit add_ingredient(temp_step);
        this->close();
    }
}

void DialogRecipeIcecream::on_BTN_SYRUP_CANCEL_3_clicked()
{
    this->close();
    emit cancel();
}

void DialogRecipeIcecream::on_BTN_BASE_STRAWBERRY_2_clicked()
{
    currentSelectBase = 1;
    SetBTNColor(ui->BTN_BASE_STRAWBERRY_2,COLOR_BLUE);
    SetBTNColor(ui->BTN_BASE_CHOCO_2,COLOR_NONE);
}

void DialogRecipeIcecream::on_BTN_BASE_CHOCO_2_clicked()
{
    currentSelectBase = 2;
    SetBTNColor(ui->BTN_BASE_STRAWBERRY_2,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_CHOCO_2,COLOR_BLUE);
}

void DialogRecipeIcecream::on_BTN_BASE_1PUMP_2_clicked()
{
    numofPumpingBase = 1;
    SetBTNColor(ui->BTN_BASE_1PUMP_2,COLOR_BLUE);
    SetBTNColor(ui->BTN_BASE_2PUMP_2,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_3PUMP_2,COLOR_NONE);
}

void DialogRecipeIcecream::on_BTN_BASE_2PUMP_2_clicked()
{
    numofPumpingBase = 2;
    SetBTNColor(ui->BTN_BASE_1PUMP_2,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_2PUMP_2,COLOR_BLUE);
    SetBTNColor(ui->BTN_BASE_3PUMP_2,COLOR_NONE);
}

void DialogRecipeIcecream::on_BTN_BASE_3PUMP_2_clicked()
{
    numofPumpingBase = 3;
    SetBTNColor(ui->BTN_BASE_1PUMP_2,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_2PUMP_2,COLOR_NONE);
    SetBTNColor(ui->BTN_BASE_3PUMP_2,COLOR_BLUE);
}

void DialogRecipeIcecream::on_BTN_SODA_OK_3_clicked()
{
    if(currentSelectBase == 0 || numofPumpingBase == 0){
        QMessageBox::information(this, "저장 실패", "베이스의 종류의 펌프 횟수를 선택해주세요.");
    }else{
        ST_RECIPE_STEP temp_step;
        temp_step.ingredient = "BASE_"+QString::number(currentSelectBase);
        temp_step.amount = QString::number(numofPumpingBase);
        plog->write("[RECIPE] ADD INGREDIENT : STEP("+temp_step.ingredient+"), AMOUNT("+temp_step.amount+")");
        emit add_ingredient(temp_step);
        this->close();
    }
}

void DialogRecipeIcecream::on_BTN_SODA_CANCEL_3_clicked()
{
    this->close();
    emit cancel();
}
