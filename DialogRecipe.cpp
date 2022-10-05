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
    ui->tabWidget->setCurrentIndex(0);
    ui->LE_SODA->setText("0");
    ui->LE_SYRUP->setText("0");
    ui->LE_ICE->setText("0");
    currentSelectSyrup = 0;
    currentSelectSoda = 0;
    this->show();
}

void DialogRecipe::EditIngredient(int index, ST_RECIPE_STEP ingredient){
    this->setEnabled(true);
    ui->stackedWidget->setCurrentIndex(3);
    if(ingredient.ingredient == "COFFEE"){
        ui->SW_EDIT_RECIPE->setCurrentIndex(1);
        ui->tabWidget_2->setCurrentIndex(0);
    }else if(ingredient.ingredient == "SODA" || ingredient.ingredient == "COLD" || ingredient.ingredient == "HOT"){
        ui->SW_EDIT_RECIPE->setCurrentIndex(2);
        ui->LE_SODA_2->setText(ingredient.amount);
        currentSelectSoda = 0;
    }else if(ingredient.ingredient.left(5) == "SYRUP"){
        ui->SW_EDIT_RECIPE->setCurrentIndex(3);
        ui->LE_SYRUP_2->setText(ingredient.amount);
        currentSelectSyrup = 0;
    }else if(ingredient.ingredient == "ICE"){
        ui->SW_EDIT_RECIPE->setCurrentIndex(0);
        ui->LE_ICE_2->setText(ingredient.amount);
    }
    currentEditIndex = index;
    this->show();
}

void DialogRecipe::on_BTN_SODA_OK_clicked()
{
    if(currentSelectSoda == 0){
        QMessageBox::information(this, "저장 실패", "추가할 타입을 선택해주세요.");
    }else if(ui->LE_SODA->text() == "0" || ui->LE_SODA->text() == ""){
        QMessageBox::information(this, "저장 실패", "값을 입력해주세요.");
    }else if(ui->LE_SODA->text().toInt() > 500 || ui->LE_SODA->text().toInt() < 5){
        QMessageBox::information(this, "저장 실패", "배출할 소다의 양이 너무 적거나 많습니다.");
    }else{
        ST_RECIPE_STEP temp_step;
        temp_step.amount = ui->LE_SODA->text();
        switch(currentSelectSoda){
        case 1:
            temp_step.ingredient = "SODA";
            break;
        case 2:
            temp_step.ingredient = "COLD";
            break;
        case 3:
            temp_step.ingredient = "HOT";
            break;
        }
        plog->write("[RECIPE] ADD INGREDIENT : STEP("+temp_step.ingredient+"), AMOUNT("+temp_step.amount+")");
        emit add_ingredient(temp_step);
        this->close();
    }
}

void DialogRecipe::on_BTN_SODA_OK_2_clicked()
{
    if(currentSelectSoda == 0){
        QMessageBox::information(this, "저장 실패", "추가할 타입을 선택해주세요.");
    }else if(ui->LE_SODA_2->text() == "0" || ui->LE_SODA_2->text() == ""){
        QMessageBox::information(this, "저장 실패", "값을 입력해주세요.");
    }else if(ui->LE_SODA_2->text().toInt() > 500 || ui->LE_SODA_2->text().toInt() < 5){
        QMessageBox::information(this, "저장 실패", "배출할 소다의 양이 너무 적거나 많습니다.");
    }else{
        ST_RECIPE_STEP temp_step;
        temp_step.amount = ui->LE_SODA->text();
        switch(currentSelectSoda){
        case 1:
            temp_step.ingredient = "SODA";
            break;
        case 2:
            temp_step.ingredient = "COLD";
            break;
        case 3:
            temp_step.ingredient = "HOT";
            break;
        }
        plog->write("[RECIPE] EDIT INGREDIENT : STEP("+temp_step.ingredient+"), AMOUNT("+temp_step.amount+")");
        emit edit_ingredient(currentEditIndex,temp_step);
        this->close();
    }
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
        case 5:
            temp_step.ingredient = "SYRUP_5";
            break;
        case 6:
            temp_step.ingredient = "SYRUP_6";
            break;
        case 7:
            temp_step.ingredient = "SYRUP_7";
            break;
        case 8:
            temp_step.ingredient = "SYRUP_8";
            break;
        case 9:
            temp_step.ingredient = "SYRUP_9";
            break;
        case 10:
            temp_step.ingredient = "SYRUP_10";
            break;
        case 11:
            temp_step.ingredient = "SYRUP_11";
            break;
        case 12:
            temp_step.ingredient = "SYRUP_12";
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
    if(ui->LE_ICE->text() == "" ){
        QMessageBox::information(this, "저장 실패", "값을 입력해주세요. (기본 값 : 0)");
    }else if(ui->LE_ICE->text().toInt() > 5000){
        QMessageBox::information(this, "저장 실패", "배출할 얼음의 양이 너무 많습니다. (5000ms 미만)");
    }else{
        ST_RECIPE_STEP temp_step;
        temp_step.ingredient = "ICE";
        temp_step.amount = ui->LE_ICE->text();
        plog->write("[RECIPE] ADD INGREDIENT : STEP("+temp_step.ingredient+"), AMOUNT("+temp_step.amount+")");
        emit add_ingredient(temp_step);
        this->close();
    }
}
void DialogRecipe::on_BTN_ICE_OK_2_clicked()
{
    if(ui->LE_ICE_2->text() == ""){
        QMessageBox::information(this, "저장 실패", "값을 입력해주세요. (기본 값 : 0)");
    }else if(ui->LE_ICE_2->text().toInt() > 5000){
        QMessageBox::information(this, "저장 실패", "배출할 얼음의 양이 너무 많습니다. (5000ms 미만)");
    }else{
        ST_RECIPE_STEP temp_step;
        temp_step.ingredient = "ICE";
        temp_step.amount = ui->LE_ICE_2->text();
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

void DialogRecipe::on_BTN_COF_E1_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "E1";
    plog->write("[RECIPE] ADD INGREDIENT : E1");
    emit add_ingredient(temp_step);
    this->close();

}
void DialogRecipe::on_BTN_COF_E2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "E2";
    plog->write("[RECIPE] ADD INGREDIENT : E2");
    emit add_ingredient(temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_LH1_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "LH1";
    plog->write("[RECIPE] ADD INGREDIENT : LH1");
    emit add_ingredient(temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_LH2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "LH2";
    plog->write("[RECIPE] ADD INGREDIENT : LH2");
    emit add_ingredient(temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_LH3_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "LH3";
    plog->write("[RECIPE] ADD INGREDIENT : LH3");
    emit add_ingredient(temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_LI1_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "LI1";
    plog->write("[RECIPE] ADD INGREDIENT : LI1");
    emit add_ingredient(temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_LI2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "LI2";
    plog->write("[RECIPE] ADD INGREDIENT : LI2");
    emit add_ingredient(temp_step);
    this->close();

}
void DialogRecipe::on_BTN_COF_LI3_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "LI3";
    plog->write("[RECIPE] ADD INGREDIENT : LI3");
    emit add_ingredient(temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_PE1_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "PE1";
    plog->write("[RECIPE] ADD INGREDIENT : PE1");
    emit add_ingredient(temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_PE2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "PE2";
    plog->write("[RECIPE] ADD INGREDIENT : PE2");
    emit add_ingredient(temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_PLH1_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "PLH1";
    plog->write("[RECIPE] ADD INGREDIENT : PLH1");
    emit add_ingredient(temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_PLH2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "PLH2";
    plog->write("[RECIPE] ADD INGREDIENT : PLH2");
    emit add_ingredient(temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_PLI1_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "PLI1";
    plog->write("[RECIPE] ADD INGREDIENT : PLI1");
    emit add_ingredient(temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_PLI2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "PLI2";
    plog->write("[RECIPE] ADD INGREDIENT : PLI2");
    emit add_ingredient(temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_MFH1_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "MFH1";
    plog->write("[RECIPE] ADD INGREDIENT : MFH1");
    emit add_ingredient(temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_MFH2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "MFH2";
    plog->write("[RECIPE] ADD INGREDIENT : MFH2");
    emit add_ingredient(temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_MFI1_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "MFI1";
    plog->write("[RECIPE] ADD INGREDIENT : MFI1");
    emit add_ingredient(temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_MFI2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "MFI2";
    plog->write("[RECIPE] ADD INGREDIENT : MFI2");
    emit add_ingredient(temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_MFI3_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "MFI3";
    plog->write("[RECIPE] ADD INGREDIENT : MFI3");
    emit add_ingredient(temp_step);
    this->close();
}

void DialogRecipe::on_BTN_COF_E1_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "E1";
    plog->write("[RECIPE] EDIT INGREDIENT : E1");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();

}
void DialogRecipe::on_BTN_COF_E2_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "E2";
    plog->write("[RECIPE] EDIT INGREDIENT : E2");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_LH1_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "LH1";
    plog->write("[RECIPE] EDIT INGREDIENT : LH1");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_LH2_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "LH2";
    plog->write("[RECIPE] EDIT INGREDIENT : LH2");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_LH3_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "LH3";
    plog->write("[RECIPE] EDIT INGREDIENT : LH3");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_LI1_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "LI1";
    plog->write("[RECIPE] EDIT INGREDIENT : LI1");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_LI2_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "LI2";
    plog->write("[RECIPE] EDIT INGREDIENT : LI2");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();

}
void DialogRecipe::on_BTN_COF_LI3_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "LI3";
    plog->write("[RECIPE] EDIT INGREDIENT : LI3");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_PE1_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "PE1";
    plog->write("[RECIPE] EDIT INGREDIENT : PE1");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_PE2_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "PE2";
    plog->write("[RECIPE] EDIT INGREDIENT : PE2");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_PLH1_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "PLH1";
    plog->write("[RECIPE] EDIT INGREDIENT : PLH1");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_PLH2_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "PLH2";
    plog->write("[RECIPE] EDIT INGREDIENT : PLH2");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_PLI1_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "PLI1";
    plog->write("[RECIPE] EDIT INGREDIENT : PLI1");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_PLI2_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "PLI2";
    plog->write("[RECIPE] EDIT INGREDIENT : PLI2");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_MFH1_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "MFH1";
    plog->write("[RECIPE] EDIT INGREDIENT : MFH1");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_MFH2_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "MFH2";
    plog->write("[RECIPE] EDIT INGREDIENT : MFH2");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_MFI1_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "MFI1";
    plog->write("[RECIPE] EDIT INGREDIENT : MFI1");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_MFI2_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "MFI2";
    plog->write("[RECIPE] EDIT INGREDIENT : MFI2");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}
void DialogRecipe::on_BTN_COF_MFI3_2_clicked()
{
    ST_RECIPE_STEP temp_step;
    temp_step.ingredient = "COFFEE";
    temp_step.amount = "MFI3";
    plog->write("[RECIPE] EDIT INGREDIENT : MFI3");
    emit edit_ingredient(currentEditIndex,temp_step);
    this->close();
}

void DialogRecipe::on_tabWidget_currentChanged(int index)
{
    if(index == 3){
        this->close();
        emit cancel();
    }
}

void DialogRecipe::on_BTN_SODA_SODA_clicked()
{
    currentSelectSoda = 1;
    SetBTNColor(ui->BTN_SODA_SODA,COLOR_BLUE);
    SetBTNColor(ui->BTN_SODA_COLD,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SODA_HOT,COLOR_UNDETERMINED);
}

void DialogRecipe::on_BTN_SODA_COLD_clicked()
{
    currentSelectSoda = 2;
    SetBTNColor(ui->BTN_SODA_SODA,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SODA_COLD,COLOR_BLUE);
    SetBTNColor(ui->BTN_SODA_HOT,COLOR_UNDETERMINED);
}

void DialogRecipe::on_BTN_SODA_HOT_clicked()
{
    currentSelectSoda = 3;
    SetBTNColor(ui->BTN_SODA_SODA,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SODA_COLD,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SODA_HOT,COLOR_BLUE);
}

void DialogRecipe::on_BTN_SYRUP_1_clicked()
{
    currentSelectSyrup = 1;
    SetBTNColor(ui->BTN_SYRUP_1,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_3,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_4,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_5,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_6,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_7,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_8,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_9,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_10,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_11,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_12,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_2_clicked()
{
    currentSelectSyrup = 2;
    SetBTNColor(ui->BTN_SYRUP_1,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_2,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_3,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_4,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_5,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_6,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_7,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_8,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_9,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_10,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_11,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_12,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_3_clicked()
{
    currentSelectSyrup = 3;
    SetBTNColor(ui->BTN_SYRUP_1,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_3,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_4,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_5,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_6,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_7,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_8,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_9,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_10,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_11,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_12,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_4_clicked()
{
    currentSelectSyrup = 4;
    SetBTNColor(ui->BTN_SYRUP_1,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_3,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_4,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_5,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_6,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_7,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_8,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_9,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_10,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_11,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_12,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_5_clicked()
{
    currentSelectSyrup = 5;
    SetBTNColor(ui->BTN_SYRUP_1,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_3,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_4,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_5,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_6,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_7,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_8,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_9,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_10,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_11,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_12,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_6_clicked()
{
    currentSelectSyrup = 6;
    SetBTNColor(ui->BTN_SYRUP_1,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_3,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_4,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_5,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_6,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_7,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_8,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_9,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_10,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_11,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_12,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_7_clicked()
{
    currentSelectSyrup = 7;
    SetBTNColor(ui->BTN_SYRUP_1,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_3,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_4,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_5,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_6,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_7,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_8,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_9,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_10,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_11,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_12,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_8_clicked()
{
    currentSelectSyrup = 8;
    SetBTNColor(ui->BTN_SYRUP_1,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_3,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_4,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_5,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_6,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_7,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_8,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_9,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_10,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_11,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_12,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_9_clicked()
{
    currentSelectSyrup = 9;
    SetBTNColor(ui->BTN_SYRUP_1,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_3,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_4,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_5,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_6,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_7,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_8,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_9,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_10,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_11,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_12,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_10_clicked()
{
    currentSelectSyrup = 10;
    SetBTNColor(ui->BTN_SYRUP_1,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_3,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_4,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_5,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_6,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_7,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_8,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_9,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_10,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_11,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_12,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_11_clicked()
{
    currentSelectSyrup = 11;
    SetBTNColor(ui->BTN_SYRUP_1,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_3,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_4,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_5,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_6,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_7,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_8,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_9,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_10,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_11,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_12,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_12_clicked()
{
    currentSelectSyrup = 12;
    SetBTNColor(ui->BTN_SYRUP_1,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_3,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_4,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_5,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_6,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_7,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_8,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_9,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_10,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_11,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_12,COLOR_BLUE);
}


void DialogRecipe::on_BTN_SYRUP_13_clicked()
{
    currentSelectSyrup = 1;
    SetBTNColor(ui->BTN_SYRUP_13,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_14,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_15,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_16,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_17,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_18,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_19,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_20,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_21,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_22,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_23,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_24,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_14_clicked()
{
    currentSelectSyrup = 2;
    SetBTNColor(ui->BTN_SYRUP_13,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_14,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_15,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_16,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_17,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_18,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_19,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_20,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_21,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_22,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_23,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_24,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_15_clicked()
{
    currentSelectSyrup = 3;
    SetBTNColor(ui->BTN_SYRUP_13,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_14,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_15,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_16,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_17,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_18,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_19,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_20,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_21,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_22,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_23,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_24,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_16_clicked()
{
    currentSelectSyrup = 4;
    SetBTNColor(ui->BTN_SYRUP_13,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_14,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_15,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_16,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_17,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_18,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_19,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_20,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_21,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_22,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_23,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_24,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_17_clicked()
{
    currentSelectSyrup = 5;
    SetBTNColor(ui->BTN_SYRUP_13,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_14,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_15,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_16,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_17,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_18,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_19,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_20,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_21,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_22,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_23,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_24,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_18_clicked()
{
    currentSelectSyrup = 6;
    SetBTNColor(ui->BTN_SYRUP_13,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_14,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_15,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_16,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_17,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_18,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_19,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_20,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_21,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_22,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_23,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_24,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_19_clicked()
{
    currentSelectSyrup = 7;
    SetBTNColor(ui->BTN_SYRUP_13,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_14,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_15,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_16,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_17,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_18,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_19,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_20,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_21,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_22,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_23,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_24,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_20_clicked()
{
    currentSelectSyrup = 8;
    SetBTNColor(ui->BTN_SYRUP_13,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_14,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_15,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_16,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_17,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_18,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_19,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_20,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_21,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_22,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_23,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_24,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_21_clicked()
{
    currentSelectSyrup = 9;
    SetBTNColor(ui->BTN_SYRUP_13,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_14,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_15,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_16,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_17,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_18,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_19,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_20,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_21,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_22,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_23,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_24,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_22_clicked()
{
    currentSelectSyrup = 10;
    SetBTNColor(ui->BTN_SYRUP_13,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_14,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_15,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_16,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_17,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_18,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_19,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_20,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_21,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_22,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_23,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_24,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_23_clicked()
{
    currentSelectSyrup = 11;
    SetBTNColor(ui->BTN_SYRUP_13,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_14,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_15,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_16,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_17,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_18,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_19,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_20,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_21,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_22,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_23,COLOR_BLUE);
    SetBTNColor(ui->BTN_SYRUP_24,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SYRUP_24_clicked()
{
    currentSelectSyrup = 12;
    SetBTNColor(ui->BTN_SYRUP_13,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_14,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_15,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_16,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_17,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_18,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_19,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_20,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_21,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_22,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_23,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SYRUP_24,COLOR_BLUE);
}

void DialogRecipe::on_tabWidget_2_currentChanged(int index)
{
    if(index == 3){
        emit cancel();
        this->close();
    }
}

void DialogRecipe::on_BTN_SODA_SODA_2_clicked()
{
    currentSelectSoda = 1;
    SetBTNColor(ui->BTN_SODA_SODA_2,COLOR_BLUE);
    SetBTNColor(ui->BTN_SODA_COLD_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SODA_HOT_2,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SODA_COLD_2_clicked()
{
    currentSelectSoda = 2;
    SetBTNColor(ui->BTN_SODA_SODA_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SODA_COLD_2,COLOR_BLUE);
    SetBTNColor(ui->BTN_SODA_HOT_2,COLOR_UNDETERMINED);
}
void DialogRecipe::on_BTN_SODA_HOT_2_clicked()
{
    currentSelectSoda = 3;
    SetBTNColor(ui->BTN_SODA_SODA_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SODA_COLD_2,COLOR_UNDETERMINED);
    SetBTNColor(ui->BTN_SODA_HOT_2,COLOR_BLUE);
}
