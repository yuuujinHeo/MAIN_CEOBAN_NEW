#ifndef DIALOGRECIPE_H
#define DIALOGRECIPE_H

#include <QDialog>
#include "GlobalHeader.h"

namespace Ui {
class DialogRecipe;
}

class DialogRecipe : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRecipe(QWidget *parent = nullptr);
    ~DialogRecipe();

    int currentSelectSyrup;
    int currentSelectSoda;
    int currentEditIndex;

    void AddMenu();
    void EditMenu(int index, QString menu_id, QString menu_name);
    void AddIngredient();
    void EditIngredient(int index, ST_RECIPE_STEP ingredient);

signals:
    void cancel();
    void add_ingredient(ST_RECIPE_STEP ingredient);
    void add_menu(ST_MENU_INFO menu);
    void edit_menu(int index, ST_MENU_INFO menu);
    void edit_ingredient(int index, ST_RECIPE_STEP ingredient);

private slots:
    void on_BTN_COF_ESP_clicked();
    void on_BTN_COF_ESP2_clicked();
    void on_BTN_COF_ICELAT_clicked();
    void on_BTN_COF_AME_clicked();
    void on_BTN_COF_AME2_clicked();
    void on_BTN_COF_LAT_clicked();
    void on_BTN_COF_MILK_clicked();
    void on_BTN_COF_ICEMILK_clicked();
    void on_BTN_COF_CANCEL_clicked();

    void on_BTN_SODA_OK_clicked();
    void on_BTN_SODA_CANCEL_clicked();


    void on_BTN_SYRUP_OK_clicked();
    void on_BTN_SYRUP_CANCEL_clicked();

    void on_BTN_EDIT_MENU_OK_clicked();
    void on_BTN_EDIT_MENU_CANCEL_clicked();

    void on_BTN_ADD_MENU_OK_clicked();
    void on_BTN_ADD_MENU_CANCEL_clicked();

    void on_BTN_RECIPE_ICE_clicked();
    void on_BTN_RECIPE_COFFEE_clicked();
    void on_BTN_RECIPE_SODA_clicked();
    void on_BTN_RECIPE_SYRUP_clicked();

    void on_BTN_ICE_OK_clicked();
    void on_BTN_ICE_CANCEL_clicked();

    void on_BTN_SODA_OK_2_clicked();
    void on_BTN_SODA_CANCEL_2_clicked();

    void on_BTN_ICE_OK_2_clicked();
    void on_BTN_ICE_CANCEL_2_clicked();
    void on_BTN_SYRUP_OK_2_clicked();
    void on_BTN_SYRUP_CANCEL_2_clicked();

    void on_BTN_COF_ESP_2_clicked();
    void on_BTN_COF_ESP2_2_clicked();
    void on_BTN_COF_ICELAT_2_clicked();
    void on_BTN_COF_AME_2_clicked();
    void on_BTN_COF_AME2_2_clicked();
    void on_BTN_COF_LAT_2_clicked();
    void on_BTN_COF_MILK_2_clicked();
    void on_BTN_COF_ICEMILK_2_clicked();
    void on_BTN_COF_CANCEL_2_clicked();

    void on_BTN_COF_E1_clicked();
    void on_BTN_COF_E2_clicked();
    void on_BTN_COF_LH1_clicked();
    void on_BTN_COF_LH2_clicked();
    void on_BTN_COF_LH3_clicked();
    void on_BTN_COF_LI1_clicked();
    void on_BTN_COF_LI2_clicked();
    void on_BTN_COF_LI3_clicked();
    void on_BTN_COF_PE1_clicked();
    void on_BTN_COF_PE2_clicked();
    void on_BTN_COF_PLH1_clicked();
    void on_BTN_COF_PLH2_clicked();
    void on_BTN_COF_PLI1_clicked();
    void on_BTN_COF_PLI2_clicked();
    void on_BTN_COF_MFH1_clicked();
    void on_BTN_COF_MFH2_clicked();
    void on_BTN_COF_MFI1_clicked();
    void on_BTN_COF_MFI2_clicked();
    void on_BTN_COF_MFI3_clicked();
    void on_BTN_COF_E1_2_clicked();
    void on_BTN_COF_E2_2_clicked();
    void on_BTN_COF_LH1_2_clicked();
    void on_BTN_COF_LH2_2_clicked();
    void on_BTN_COF_LH3_2_clicked();
    void on_BTN_COF_LI1_2_clicked();
    void on_BTN_COF_LI2_2_clicked();
    void on_BTN_COF_LI3_2_clicked();
    void on_BTN_COF_PE1_2_clicked();
    void on_BTN_COF_PE2_2_clicked();
    void on_BTN_COF_PLH1_2_clicked();
    void on_BTN_COF_PLH2_2_clicked();
    void on_BTN_COF_PLI1_2_clicked();
    void on_BTN_COF_PLI2_2_clicked();
    void on_BTN_COF_MFH1_2_clicked();
    void on_BTN_COF_MFH2_2_clicked();
    void on_BTN_COF_MFI1_2_clicked();
    void on_BTN_COF_MFI2_2_clicked();
    void on_BTN_COF_MFI3_2_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_BTN_SODA_SODA_clicked();

    void on_BTN_SODA_COLD_clicked();

    void on_BTN_SODA_HOT_clicked();

    void on_BTN_SYRUP_1_clicked();
    void on_BTN_SYRUP_2_clicked();
    void on_BTN_SYRUP_3_clicked();
    void on_BTN_SYRUP_4_clicked();
    void on_BTN_SYRUP_5_clicked();
    void on_BTN_SYRUP_6_clicked();
    void on_BTN_SYRUP_7_clicked();
    void on_BTN_SYRUP_8_clicked();
    void on_BTN_SYRUP_9_clicked();
    void on_BTN_SYRUP_10_clicked();
    void on_BTN_SYRUP_11_clicked();
    void on_BTN_SYRUP_12_clicked();
    void on_BTN_SYRUP_13_clicked();
    void on_BTN_SYRUP_14_clicked();
    void on_BTN_SYRUP_15_clicked();
    void on_BTN_SYRUP_16_clicked();
    void on_BTN_SYRUP_17_clicked();
    void on_BTN_SYRUP_18_clicked();
    void on_BTN_SYRUP_19_clicked();
    void on_BTN_SYRUP_20_clicked();
    void on_BTN_SYRUP_21_clicked();
    void on_BTN_SYRUP_22_clicked();
    void on_BTN_SYRUP_23_clicked();
    void on_BTN_SYRUP_24_clicked();

    void on_tabWidget_2_currentChanged(int index);

    void on_BTN_SODA_SODA_2_clicked();
    void on_BTN_SODA_COLD_2_clicked();
    void on_BTN_SODA_HOT_2_clicked();

private:
    Ui::DialogRecipe *ui;
};

#endif // DIALOGRECIPE_H
