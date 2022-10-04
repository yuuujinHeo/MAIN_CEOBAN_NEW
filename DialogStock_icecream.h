#ifndef DIALOGSTOCKICECREAM_H
#define DIALOGSTOCKICECREAM_H

#include <QDialog>
#include <QTimer>

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include <QDebug>
#include "GlobalHeader.h"
#ifdef ICECREAM_VER
#define DB_NAME_RECIPE  "DB/recipe_icecream"


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
    void FillZero(QString stock_name);

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

public slots:
    void onTimer();

private slots:
    void on_BTN_CUP_HALF_1_clicked();

    void on_BTN_CUP_FULL_1_clicked();

    void on_BTN_CUP_HALF_2_clicked();

    void on_BTN_CUP_FULL_2_clicked();

    void on_BTN_SYRUP_REPLACE_1_clicked();

    void on_BTN_SYRUP_REPLACE_2_clicked();

    void on_BTN_SYRUP_REPLACE_3_clicked();

    void on_BTN_SYRUP_REPLACE_4_clicked();

    void on_BTN_SYRUP_REPLACE_5_clicked();

    void on_BTN_SYRUP_REPLACE_6_clicked();

    void on_BTN_SET_STOCK_MANUAL_clicked();

    void on_BTN_MILK_USE_clicked();

    void on_BTN_MILK_NOT_USE_clicked();

    void on_BTN_SYRUP_USE_clicked();

    void on_BTN_SYRUP_NOT_USE_clicked();

    void on_BTN_ICECREAM_REFILL_clicked();

    void on_BTN_SLUSH_REFILL_1_clicked();

    void on_BTN_SLUSH_REFILL_2_clicked();

    void on_BTN_BASE_REPLACE_1_clicked();

    void on_BTN_BASE_REPLACE_2_clicked();

    void on_BTN_ICECREAM_ZERO_clicked();

    void on_BTN_SLUSH_ZERO_clicked();

    void on_BTN_SLUSH_ZERO_2_clicked();

    void on_BTN_BASE_ZERO_clicked();

    void on_BTN_BASE_ZERO_2_clicked();

private:
    Ui::DialogStock *ui;
    QTimer   timer;

    QSqlDatabase    db;

};
#endif
#endif // DIALOGSTOCKICECREAM_H
