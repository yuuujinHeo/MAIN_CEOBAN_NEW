﻿#ifndef DIALOGSTOCK_H
#define DIALOGSTOCK_H

#include <QDialog>
#include <QTimer>

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include <QDebug>
#include "GlobalHeader.h"

#define DB_NAME_RECIPE  "DB/recipe"


#define MILK_APPROXIMATION_USE_AMOUNT       200


namespace Ui {
class DialogStock;
}

class DialogStock : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStock(QWidget *parent = nullptr);
    ~DialogStock();

    void LoadDatabase();
    void SetUIForm();
    void UpdateUI();


    void SaveDatabase(QVector<ST_MENU> new_db);
    void BackupDatabase();
    void SaveRecipe(QString menu_id, V_RECIPE new_recipe);


    void UseStock(QString stock_name, int amount);
    void UpdateStock(QString stock_name);
    void SetStock(QString stock_name, int amount);

    int GetStock(QString stock_name);
    void FillFull(QString stock_name);
    void FillHalf(QString stock_name);

    void SetDeviceError(QString stock_name);
    void ClearDeviceError(QString stock_name);
    int IsDeviceError(QString stock_name);

    void UpdateWaitingTime();
    void UpdateStockReserved();
    void UpdateMenuAvailable();


    QMap<QString, QString> coffee_key_btn;
    QMap<QString, QString> coffee_desc_btn;

    QMap<QString, ST_STOCK> stock;
    QMap<QString, ST_MENU>  menu;
    QMap<QString, V_RECIPE> recipe;

    QMap<QString, int> syrup_to_pump;
    QMap<QString, QString> syrup_to_name;


    int ApproximateWaitingTime;
    bool forced_syrup_use;

public slots:
    void onTimer();

private slots:
    void on_BTN_CUP_HALF_1_clicked();
    void on_BTN_CUP_FULL_1_clicked();
    void on_BTN_CUP_HALF_2_clicked();
    void on_BTN_CUP_FULL_2_clicked();
    void on_BTN_CUP_HALF_3_clicked();
    void on_BTN_CUP_FULL_3_clicked();
    void on_BTN_CUP_HALF_4_clicked();
    void on_BTN_CUP_FULL_4_clicked();

    void on_BTN_SYRUP_REPLACE_1_clicked();
    void on_BTN_SYRUP_REPLACE_2_clicked();
    void on_BTN_SYRUP_REPLACE_3_clicked();
    void on_BTN_SYRUP_REPLACE_4_clicked();
    void on_BTN_SYRUP_REPLACE_5_clicked();
    void on_BTN_SYRUP_REPLACE_6_clicked();
    void on_BTN_SYRUP_REPLACE_7_clicked();
    void on_BTN_SYRUP_REPLACE_8_clicked();
    void on_BTN_SYRUP_REPLACE_9_clicked();
    void on_BTN_SYRUP_REPLACE_10_clicked();
    void on_BTN_SYRUP_REPLACE_11_clicked();
    void on_BTN_SYRUP_REPLACE_12_clicked();

    void on_BTN_SET_STOCK_MANUAL_clicked();

    void on_BTN_MILK_USE_clicked();
    void on_BTN_MILK_NOT_USE_clicked();

    void on_BTN_SYRUP_USE_clicked();
    void on_BTN_SYRUP_NOT_USE_clicked();

    void on_BTN_SYRUP_ADD_1_clicked();
    void on_BTN_SYRUP_ADD_2_clicked();
    void on_BTN_SYRUP_ADD_3_clicked();
    void on_BTN_SYRUP_ADD_4_clicked();
    void on_BTN_SYRUP_ADD_5_clicked();
    void on_BTN_SYRUP_ADD_6_clicked();
    void on_BTN_SYRUP_ADD_7_clicked();
    void on_BTN_SYRUP_ADD_8_clicked();
    void on_BTN_SYRUP_ADD_9_clicked();
    void on_BTN_SYRUP_ADD_10_clicked();
    void on_BTN_SYRUP_ADD_11_clicked();
    void on_BTN_SYRUP_ADD_12_clicked();

private:
    Ui::DialogStock *ui;
    QTimer   timer;

    QSqlDatabase    db;

};
#endif // DIALOGSTOCK_H
