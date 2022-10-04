#include "DialogRecipe.h"
#include "ui_DialogRecipe.h"
#include <QMessageBox>
#include <Logger.h>

extern Logger *plog;
DialogRecipe::DialogRecipe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRecipe)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
}

DialogRecipe::~DialogRecipe()
{
    emit cancel();
    delete ui;
}

void DialogRecipe::AddMenu(){
    this->setEnabled(true);
    ui->stackedWidget->setCurrentIndex(0);
    ui->LE_ADD_MENU_ID->setText("");
    ui->LE_ADD_MENU_NAME->setText("");
    this->show();
}

void DialogRecipe::EditMenu(int index, QString menu_id, QString menu_name){
    this->setEnabled(true);
    ui->stackedWidget->setCurrentIndex(1);
    currentEditIndex = index;
    ui->LE_EDIT_MENU_ID->setText(menu_id);
    ui->LE_EDIT_MENU_NAME->setText(menu_name);
    this->show();
}

void DialogRecipe::AddIngredient(){
    this->setEnabled(true);
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->LE_SODA->setText("0");
    ui->LE_SYRUP->setText("0");
    ui->LE_ICE->setText("0");
    ui->LE_WATER->setText("0");
    currentSelectSyrup = 0;
    this->show();
}

void DialogRecipe::EditIngredient(int index, ST_RECIPE_STEP ingredient){
    this->setEnabled(true);
    ui->stackedWidget->setCurrentIndex(3);
    if(ingredient.ingredient == "COFFEE"){
        ui->SW_EDIT_RECIPE->setCurrentIndex(2);
    }else if(ingredient.ingredient == "SYRUP_5"){
        ui->SW_EDIT_RECIPE->setCurrentIndex(3);
        ui->LE_SODA_2->setText(ingredient.amount);
    }else if(ingredient.ingredient.left(5) == "SYRUP"){
        ui->SW_EDIT_RECIPE->setCurrentIndex(4);
        ui->LE_SYRUP_2->setText(ingredient.amount);
        currentSelectSyrup = 0;
    }else if(ingredient.ingredient == "ICE"){
        ui->SW_EDIT_RECIPE->setCurrentIndex(1);
        QStringList amount = ingredient.amount.split("/");
        ui->LE_ICE_2->setText(amount[0]);
        ui->LE_WATER_2->setText(amount[1]);
    }
    currentEditIndex = index;
    this->show();
}

void DialogRecipe::on_BTN_SODA_OK_clicked()
{
    if(ui->LE_SODA->text() == "0" || ui->LE_SODA->text() == ""){
        QMessageBox::information(this, "저장 실패", "값을 입력해주세요.");
    }else if(ui->LE_SODA->text().toInt() > 500 || ui->LE_SODA->text().toInt() < 5){
        QMessageBox::information(this, "저장 실패", "배출할 소다의 양이 너무 적거나 많습니다.");
    }else{
        ST_RECIPE_STEP temp_step;
        temp_step.amount = ui->LE_SODA->text();
        temp_step.ingredient = "SYRUP_5";
        plog->write("[RECIPE] ADD INGREDIENT : STEP("+temp_step.ingredient+"), AMOUNT("+temp_step.amount+")");
        emit add_ingredient(temp_step);
        this->close();
    }
}

void DialogRecipe::on_BTN_SODA_OK_2_clicked()
{
    if(ui->LE_SODA_2->text() == "0" || ui->LE_SODA_2->text() == ""){
        QMessageBox::information(this, "저장 실패", "값을 입력해주세요.");
    }else if(ui->LE_SODA_2->text().toInt() > 500 || ui->LE_SODA_2->text().toInt() < 5){
        QMessageBox::information(this, "저장 실패", "배출할 소다의 양이 너무 적거나 많습니다.");
    }else{
        ST_RECIPE_STEP temp_step;
        temp_step.amount = ui->LE_SODA_2->text();
        temp_step.ingredient = "SYRUP_5";
        plog->write("[RECIPE] EDIT INGREDIENT : STEP("+temp_step.ingredient+"), AMOUNT("+temp_step.amount+")");
        emit edit_ingredient(currentEditIndex,temp_step);
        this->close();
    }
}
void DialogRecipe::on_BTN_SYRUP_VANILA_clicked()
{
    currentSelectSyrup = 1;
    SetBTNColor(ui->BTN_SYRUP_VANILA,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_HAZ,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_GRAPE,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_LEMON,COLOR_UNDETERMINED);
}

void DialogRecipe::on_BTN_SYRUP_HAZ_clicked()
{
    currentSelectSyrup = 2;
    SetBTNColor(ui->BTN_SYRUP_VANILA,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_HAZ,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_GRAPE,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_LEMON,COLOR_UNDETERMINED);
}

void DialogRecipe::on_BTN_SYRUP_GRAPE_clicked()
{
    currentSelectSyrup = 3;
    SetBTNColor(ui->BTN_SYRUP_VANILA,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_HAZ,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_GRAPE,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_LEMON,COLOR_UNDETERMINED);
}

void DialogRecipe::on_BTN_SYRUP_LEMON_clicked()
{
    currentSelectSyrup = 4;
    SetBTNColor(ui->BTN_SYRUP_VANILA,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_HAZ,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_GRAPE,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_LEMON,COLOR_BLUE);
}

void DialogRecipe::on_BTN_SYRUP_VANILA_2_clicked()
{
    currentSelectSyrup = 1;
    SetBTNColor(ui->BTN_SYRUP_VANILA_2,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_HAZ_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_GRAPE_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_LEMON_2,COLOR_UNDETERMINED);
}

void DialogRecipe::on_BTN_SYRUP_HAZ_2_clicked()
{
    currentSelectSyrup = 2;
    SetBTNColor(ui->BTN_SYRUP_VANILA_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_HAZ_2,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_GRAPE_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_LEMON_2,COLOR_UNDETERMINED);
}

void DialogRecipe::on_BTN_SYRUP_GRAPE_2_clicked()
{
    currentSelectSyrup = 3;
    SetBTNColor(ui->BTN_SYRUP_VANILA_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_HAZ_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_GRAPE_2,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_LEMON_2,COLOR_UNDETERMINED);
}

void DialogRecipe::on_BTN_SYRUP_LEMON_2_clicked()
{
    currentSelectSyrup = 4;
    SetBTNColor(ui->BTN_SYRUP_VANILA_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_HAZ_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_GRAPE_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_LEMON_2,COLOR_BLUE);
}

void DialogRecipe::on_BTN_SYRUP_OK_clicked()
{
    if(currentSelectSyrup == 0){
        QMessageBox::information(this, "저장 실패", "추가할 시럽을 선택해주세요.");
    }else if(ui->LE_SYRUP->text() == "0" || ui->LE_SYRUP->text() == ""){
        QMessageBox::information(this, "저장 실패", "값을 입력해주세요.");
    }else if(ui->LE_SYRUP->text().toInt() > 100 || ui->LE_SYRUP->text().toInt() < 5){
        QMessageBox::information(this, "저장 실패", "배출할 시럽의 양이 너무 적거나 많습니다.");
    }else{
        ST_RECIPE_STEP temp_step;
        temp_step.amount = ui->LE_SYRUP->text();
        switch(currentSelectSyrup){
        case 1:
            temp_step.ingredient = "SYRUP_1";
            break;
        case 2:
            temp_step.ingredient = "SYRUP_2";
            break;
        case 3:
            temp_step.ingredient = "SYRUP_3";
            break;
        case 4:
            temp_step.ingredient = "SYRUP_4";
            break;
        }
        plog->write("[RECIPE] ADD INGREDIENT : STEP("+temp_step.ingredient+"), AMOUNT("+temp_step.amount+")");
        emit add_ingredient(temp_step);
        this->close();
    }
}

void DialogRecipe::on_BTN_SYRUP_OK_2_clicked()
{
    if(currentSelectSyrup == 0){
        QMessageBox::information(this, "저장 실패", "추가할 시럽을 선택해주세요.");
    }else if(ui->LE_SYRUP_2->text() == "0" || ui->LE_SYRUP_2->text() == ""){
        QMessageBox::information(this, "저장 실패", "값을 입력해주세요.");
    }else if(ui->LE_SYRUP_2->text().toInt() > 100 || ui->LE_SYRUP_2->text().toInt() < 5){
        QMessageBox::information(this, "저장 실패", "배출할 시럽의 양이 너무 적거나 많습니다.");
    }else{
        ST_RECIPE_STEP temp_step;
        temp_step.amount = ui->LE_SYRUP_2->text();
        switch(currentSelectSyrup){
        case 1:
            temp_step.ingredient = "SYRUP_1";
            break;
        case 2:
            temp_step.ingredient = "SYRUP_2";
            break;
        case 3:
            temp_step.ingredient = "SYRUP_3";
            break;
        case 4:
            temp_step.ingredient = "SYRUP_4";
            break;
        }
        plog->write("[RECIPE] EDIT INGREDIENT : STEP("+temp_step.ingredient+"), AMOUNT("+temp_step.amount+")");
        emit edit_ingredient(currentEditIndex,temp_step);
        this->close();
    }
}


void DialogRecipe::on_BTN_EDIT_MENU_OK_clicked()
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


void DialogRecipe::on_BTN_ADD_MENU_OK_clicked()
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

void DialogRecipe::on_BTN_ICE_OK_clicked()
{
    if(ui->LE_ICE->text() == "" || ui->LE_WATER->text() == ""){
        QMessageBox::information(this, "저장 실패", "값을 입력해주세요. (기본 값 : 0)");
    }else if(ui->LE_ICE->text().toInt() > 5 || ui->LE_ICE->text().toInt() > 5){
        QMessageBox::information(this, "저장 실패", "배출할 얼음과 물의 양이 너무 많습니다. (5초 미만)");
    }else{
        ST_RECIPE_STEP temp_step;
        temp_step.ingredient = "ICE";
        temp_step.amount = ui->LE_ICE->text()+"/"+ui->LE_WATER->text();
        plog->write("[RECIPE] ADD INGREDIENT : STEP("+temp_step.ingredient+"), AMOUNT("+temp_step.amount+")");
        emit add_ingredient(temp_step);
        this->close();
    }
}
void DialogRecipe::on_BTN_ICE_OK_2_clicked()
{
    if(ui->LE_ICE_2->text() == "" || ui->LE_WATER_2->text() == ""){
        QMessageBox::information(this, "저장 실패", "값을 입력해주세요. (기본 값 : 0)");
    }else if(ui->LE_ICE_2->text().toInt() > 5 || ui->LE_ICE_2->text().toInt() > 5){
        QMessageBox::information(this, "저장 실패", "배출할 얼음과 물의 양이 너무 많습니다. (5초 미만)");
    }else{
        ST_RECIPE_STEP temp_step;
        temp_step.ingredient = "ICE";
        temp_step.amount = ui->LE_ICE_2->text()+"/"+ui->LE_WATER_2->text();
        plog->write("[RECIPE] EDIT INGREDIENT : STEP("+temp_step.ingredient+"), AMOUNT("+temp_step.amount+")");
        emit edit_ingredient(currentEditIndex,temp_step);
        this->close();
    }
}

void DialogRecipe::on_BTN_RECIPE_ICE_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void DialogRecipe::on_BTN_RECIPE_COFFEE_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void DialogRecipe::on_BTN_RECIPE_SODA_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

void DialogRecipe::on_BTN_RECIPE_SYRUP_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(4);
}

void DialogRecipe::on_BTN_ICE_CANCEL_clicked()
{
    this->close();
    emit cancel();
}

void DialogRecipe::on_BTN_COF_CANCEL_clicked()
{
    this->close();
    emit cancel();
}

void DialogRecipe::on_BTN_SODA_CANCEL_clicked()
{
    this->close();
    emit cancel();
}

void DialogRecipe::on_BTN_SYRUP_CANCEL_clicked()
{
    this->close();
    emit cancel();
}

void DialogRecipe::on_BTN_ICE_CANCEL_2_clicked()
{
    this->close();
    emit cancel();
}

void DialogRecipe::on_BTN_COF_CANCEL_2_clicked()
{
    this->close();
    emit cancel();
}

void DialogRecipe::on_BTN_SODA_CANCEL_2_clicked()
{
    this->close();
    emit cancel();
}

void DialogRecipe::on_BTN_SYRUP_CANCEL_2_clicked()
{
    this->close();
    emit cancel();
}

void DialogRecipe::on_BTN_EDIT_MENU_CANCEL_clicked()
{
    this->close();
    emit cancel();
}

void DialogRecipe::on_BTN_ADD_MENU_CANCEL_clicked()
{
    this->close();
    emit cancel();
}

void DialogRecipe::on_BTN_COF_ESP_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "E1";
    plog->write("[RECIPE] ADD INGREDIENT : ESP");
    emit add_ingredient(temp_step);
    this->close();
}

void DialogRecipe::on_BTN_COF_ESP2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "E2";
    plog->write("[RECIPE] ADD INGREDIENT : ESP2");
    emit add_ingredient(temp_step);
    this->close();
}

void DialogRecipe::on_BTN_COF_ICELAT_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "LI";
    plog->write("[RECIPE] ADD INGREDIENT : ICELAT");
    emit add_ingredient(temp_step);
    this->close();
}

void DialogRecipe::on_BTN_COF_AME_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "A1";
    plog->write("[RECIPE] ADD INGREDIENT : AME");
    emit add_ingredient(temp_step);
    this->close();
}

void DialogRecipe::on_BTN_COF_AME2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "A2";
    plog->write("[RECIPE] ADD INGREDIENT : AME2");
    emit add_ingredient(temp_step);
    this->close();
}

void DialogRecipe::on_BTN_COF_LAT_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "LH";
    plog->write("[RECIPE] ADD INGREDIENT : LAT");
    emit add_ingredient(temp_step);
    this->close();
}

void DialogRecipe::on_BTN_COF_MILK_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "MH";
    plog->write("[RECIPE] ADD INGREDIENT : MILK");
    emit add_ingredient(temp_step);
    this->close();
}

void DialogRecipe::on_BTN_COF_ICEMILK_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "MI";
    plog->write("[RECIPE] ADD INGREDIENT : ICEMILK");
    emit add_ingredient(temp_step);
    this->close();
}

void DialogRecipe::on_BTN_COF_ESP_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "E1";
    plog->write("[RECIPE] ADD INGREDIENT : ESP");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}

void DialogRecipe::on_BTN_COF_ESP2_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "E2";
    plog->write("[RECIPE] ADD INGREDIENT : ESP2");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}

void DialogRecipe::on_BTN_COF_ICELAT_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "LI";
    plog->write("[RECIPE] ADD INGREDIENT : ICELAT");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}

void DialogRecipe::on_BTN_COF_AME_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "A1";
    plog->write("[RECIPE] ADD INGREDIENT : AME");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}

void DialogRecipe::on_BTN_COF_AME2_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "A2";
    plog->write("[RECIPE] ADD INGREDIENT : AME2");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}

void DialogRecipe::on_BTN_COF_LAT_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "LH";
    plog->write("[RECIPE] ADD INGREDIENT : LAT");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}

void DialogRecipe::on_BTN_COF_MILK_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "MH";
    plog->write("[RECIPE] ADD INGREDIENT : MILK");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}

void DialogRecipe::on_BTN_COF_ICEMILK_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "MI";
    plog->write("[RECIPE] ADD INGREDIENT : ICEMILK");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}
