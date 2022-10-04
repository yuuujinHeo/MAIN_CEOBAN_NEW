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

    void on_BTN_SYRUP_VANILA_clicked();
    void on_BTN_SYRUP_HAZ_clicked();
    void on_BTN_SYRUP_GRAPE_clicked();
    void on_BTN_SYRUP_LEMON_clicked();

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

    void on_BTN_SYRUP_VANILA_2_clicked();
    void on_BTN_SYRUP_HAZ_2_clicked();
    void on_BTN_SYRUP_GRAPE_2_clicked();
    void on_BTN_SYRUP_LEMON_2_clicked();

    void on_BTN_COF_ESP_2_clicked();
    void on_BTN_COF_ESP2_2_clicked();
    void on_BTN_COF_ICELAT_2_clicked();
    void on_BTN_COF_AME_2_clicked();
    void on_BTN_COF_AME2_2_clicked();
    void on_BTN_COF_LAT_2_clicked();
    void on_BTN_COF_MILK_2_clicked();
    void on_BTN_COF_ICEMILK_2_clicked();
    void on_BTN_COF_CANCEL_2_clicked();

private:
    Ui::DialogRecipe *ui;
};

#endif // DIALOGRECIPE_H
