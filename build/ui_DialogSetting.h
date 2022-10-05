/********************************************************************************
** Form generated from reading UI file 'DialogSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSETTING_H
#define UI_DIALOGSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSetting
{
public:
    QGroupBox *GB_SETTING;
    QTabWidget *TW_SETTING;
    QWidget *ERROR;
    QLabel *label_148;
    QGroupBox *GB_SUPER_STOP;
    QLabel *label_203;
    QLineEdit *LE_SUPER_STOP_BOARD_CONNECTION;
    QLabel *label_209;
    QLineEdit *LE_SUPER_STOP_ROBOT_DATA;
    QLabel *label_210;
    QLineEdit *LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK;
    QLineEdit *LE_SUPER_STOP_OUTLET_CONNECTION;
    QLabel *label_211;
    QLabel *label_212;
    QLineEdit *LE_SUPER_STOP_OUTLET_CONTROL;
    QLabel *label_213;
    QLineEdit *LE_SUPER_STOP_OUTLET_SENSOR;
    QLabel *label_214;
    QLineEdit *LE_SUPER_STOP_PLATFORM_OPEN;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_3;
    QLineEdit *LE_DEVICE_ERROR_PAPER_CUP_2;
    QLabel *label_159;
    QLabel *label_163;
    QLineEdit *LE_DEVICE_ERROR_COFFEE;
    QLabel *label_161;
    QPushButton *BTN_ERROR_CLEAR_COFFEE;
    QLineEdit *LE_DEVICE_ERROR_PAPER_CUP_1;
    QPushButton *BTN_ERROR_CLEAR_PP_CUP_1;
    QPushButton *BTN_ERROR_CLEAR_PAPER_CUP_1;
    QLabel *label_153;
    QLabel *label_150;
    QLineEdit *LE_DEVICE_ERROR_OUTLET_2;
    QLabel *label_149;
    QPushButton *BTN_ERROR_CLEAR_ROBOT_3;
    QLineEdit *LE_DEVICE_ERROR_PP_CUP_1;
    QLabel *label_164;
    QLabel *label_152;
    QPushButton *BTN_ERROR_CLEAR_PAPER_CUP_2;
    QLabel *label_165;
    QLineEdit *LE_DEVICE_ERROR_ICE_1;
    QLineEdit *LE_DEVICE_ERROR_OUTLET_1;
    QLineEdit *LE_DEVICE_ERROR_ROBOT_1;
    QPushButton *BTN_ERROR_CLEAR_PP_CUP_2;
    QPushButton *BTN_ERROR_CLEAR_OUTLET_1;
    QPushButton *BTN_ERROR_CLEAR_OUTLET_2;
    QPushButton *BTN_ERROR_CLEAR_ICE_1;
    QLineEdit *LE_DEVICE_ERROR_PP_CUP_2;
    QLabel *label_166;
    QLineEdit *LE_DEVICE_ERROR_SODA;
    QPushButton *BTN_ERROR_CLEAR_SODA;
    QWidget *TEST;
    QPushButton *BTN_TEST_ORDER;
    QTableWidget *TW_TEST_MENU;
    QLineEdit *LE_SET_PASSWD;
    QLabel *label;
    QPushButton *BTN_SET_UNLOCK;
    QPushButton *BTN_SET_LOCK;
    QPushButton *BTN_OPEN_RECIPE_2;
    QPushButton *BTN_OPEN_RECIPE;
    QPushButton *BTN_DB_RELOAD;

    void setupUi(QDialog *DialogSetting)
    {
        if (DialogSetting->objectName().isEmpty())
            DialogSetting->setObjectName(QString::fromUtf8("DialogSetting"));
        DialogSetting->resize(400, 960);
        GB_SETTING = new QGroupBox(DialogSetting);
        GB_SETTING->setObjectName(QString::fromUtf8("GB_SETTING"));
        GB_SETTING->setGeometry(QRect(0, 0, 400, 960));
        QFont font;
        font.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        GB_SETTING->setFont(font);
        GB_SETTING->setStyleSheet(QString::fromUtf8("QGroupBox  {\n"
"    margin-top: 10px;\n"
"	font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"\n"
"QGroupBox::title  {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 10px 8000px 10px 8000px;\n"
"    background-color: #595959;\n"
"    color: rgb(255, 255, 255);\n"
"}\n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QComboBox{\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"	background-color: #ffffff\n"
"}\n"
"QPushButton{\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"	background-color: #ffffff\n"
"}\n"
"QLineEdit{\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"	background-color: #ffffff\n"
"}\n"
"QTabWidget{\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"	background-color: #ffffff\n"
"}\n"
"\n"
"\n"
""));
        TW_SETTING = new QTabWidget(GB_SETTING);
        TW_SETTING->setObjectName(QString::fromUtf8("TW_SETTING"));
        TW_SETTING->setGeometry(QRect(10, 60, 381, 721));
        TW_SETTING->setTabShape(QTabWidget::Rounded);
        TW_SETTING->setDocumentMode(false);
        TW_SETTING->setTabsClosable(false);
        TW_SETTING->setTabBarAutoHide(false);
        ERROR = new QWidget();
        ERROR->setObjectName(QString::fromUtf8("ERROR"));
        label_148 = new QLabel(ERROR);
        label_148->setObjectName(QString::fromUtf8("label_148"));
        label_148->setGeometry(QRect(10, 10, 71, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_148->setFont(font1);
        label_148->setAlignment(Qt::AlignCenter);
        GB_SUPER_STOP = new QGroupBox(ERROR);
        GB_SUPER_STOP->setObjectName(QString::fromUtf8("GB_SUPER_STOP"));
        GB_SUPER_STOP->setGeometry(QRect(10, 350, 361, 241));
        GB_SUPER_STOP->setStyleSheet(QString::fromUtf8("QGroupBox  {\n"
"    border: 1px solid gray;\n"
"    border-color: #FF5D1717;\n"
"    margin-top: 10px;\n"
"    font-size: 12px;\n"
"    border-radius: 1px;\n"
"}\n"
"\n"
"QGroupBox::title  {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 5px 8000px 5px 8000px;\n"
"    background-color: #FF5D1717;\n"
"    color: rgb(255, 255, 255);\n"
"}"));
        label_203 = new QLabel(GB_SUPER_STOP);
        label_203->setObjectName(QString::fromUtf8("label_203"));
        label_203->setGeometry(QRect(40, 60, 251, 21));
        label_203->setFont(font1);
        LE_SUPER_STOP_BOARD_CONNECTION = new QLineEdit(GB_SUPER_STOP);
        LE_SUPER_STOP_BOARD_CONNECTION->setObjectName(QString::fromUtf8("LE_SUPER_STOP_BOARD_CONNECTION"));
        LE_SUPER_STOP_BOARD_CONNECTION->setGeometry(QRect(10, 60, 21, 21));
        LE_SUPER_STOP_BOARD_CONNECTION->setFont(font1);
        LE_SUPER_STOP_BOARD_CONNECTION->setReadOnly(true);
        label_209 = new QLabel(GB_SUPER_STOP);
        label_209->setObjectName(QString::fromUtf8("label_209"));
        label_209->setGeometry(QRect(40, 90, 251, 21));
        label_209->setFont(font1);
        LE_SUPER_STOP_ROBOT_DATA = new QLineEdit(GB_SUPER_STOP);
        LE_SUPER_STOP_ROBOT_DATA->setObjectName(QString::fromUtf8("LE_SUPER_STOP_ROBOT_DATA"));
        LE_SUPER_STOP_ROBOT_DATA->setGeometry(QRect(10, 90, 21, 21));
        LE_SUPER_STOP_ROBOT_DATA->setFont(font1);
        LE_SUPER_STOP_ROBOT_DATA->setReadOnly(true);
        label_210 = new QLabel(GB_SUPER_STOP);
        label_210->setObjectName(QString::fromUtf8("label_210"));
        label_210->setGeometry(QRect(40, 120, 251, 21));
        label_210->setFont(font1);
        LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK = new QLineEdit(GB_SUPER_STOP);
        LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK->setObjectName(QString::fromUtf8("LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK"));
        LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK->setGeometry(QRect(10, 120, 21, 21));
        LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK->setFont(font1);
        LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK->setReadOnly(true);
        LE_SUPER_STOP_OUTLET_CONNECTION = new QLineEdit(GB_SUPER_STOP);
        LE_SUPER_STOP_OUTLET_CONNECTION->setObjectName(QString::fromUtf8("LE_SUPER_STOP_OUTLET_CONNECTION"));
        LE_SUPER_STOP_OUTLET_CONNECTION->setGeometry(QRect(10, 150, 21, 21));
        LE_SUPER_STOP_OUTLET_CONNECTION->setFont(font1);
        LE_SUPER_STOP_OUTLET_CONNECTION->setReadOnly(true);
        label_211 = new QLabel(GB_SUPER_STOP);
        label_211->setObjectName(QString::fromUtf8("label_211"));
        label_211->setGeometry(QRect(40, 150, 251, 21));
        label_211->setFont(font1);
        label_212 = new QLabel(GB_SUPER_STOP);
        label_212->setObjectName(QString::fromUtf8("label_212"));
        label_212->setGeometry(QRect(40, 180, 251, 21));
        label_212->setFont(font1);
        LE_SUPER_STOP_OUTLET_CONTROL = new QLineEdit(GB_SUPER_STOP);
        LE_SUPER_STOP_OUTLET_CONTROL->setObjectName(QString::fromUtf8("LE_SUPER_STOP_OUTLET_CONTROL"));
        LE_SUPER_STOP_OUTLET_CONTROL->setGeometry(QRect(10, 180, 21, 21));
        LE_SUPER_STOP_OUTLET_CONTROL->setFont(font1);
        LE_SUPER_STOP_OUTLET_CONTROL->setReadOnly(true);
        label_213 = new QLabel(GB_SUPER_STOP);
        label_213->setObjectName(QString::fromUtf8("label_213"));
        label_213->setGeometry(QRect(40, 210, 251, 21));
        label_213->setFont(font1);
        LE_SUPER_STOP_OUTLET_SENSOR = new QLineEdit(GB_SUPER_STOP);
        LE_SUPER_STOP_OUTLET_SENSOR->setObjectName(QString::fromUtf8("LE_SUPER_STOP_OUTLET_SENSOR"));
        LE_SUPER_STOP_OUTLET_SENSOR->setGeometry(QRect(10, 210, 21, 21));
        LE_SUPER_STOP_OUTLET_SENSOR->setFont(font1);
        LE_SUPER_STOP_OUTLET_SENSOR->setReadOnly(true);
        label_214 = new QLabel(GB_SUPER_STOP);
        label_214->setObjectName(QString::fromUtf8("label_214"));
        label_214->setGeometry(QRect(40, 30, 251, 21));
        label_214->setFont(font1);
        LE_SUPER_STOP_PLATFORM_OPEN = new QLineEdit(GB_SUPER_STOP);
        LE_SUPER_STOP_PLATFORM_OPEN->setObjectName(QString::fromUtf8("LE_SUPER_STOP_PLATFORM_OPEN"));
        LE_SUPER_STOP_PLATFORM_OPEN->setGeometry(QRect(10, 30, 21, 21));
        LE_SUPER_STOP_PLATFORM_OPEN->setFont(font1);
        LE_SUPER_STOP_PLATFORM_OPEN->setReadOnly(true);
        layoutWidget_2 = new QWidget(ERROR);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(60, 30, 281, 281));
        gridLayout_3 = new QGridLayout(layoutWidget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        LE_DEVICE_ERROR_PAPER_CUP_2 = new QLineEdit(layoutWidget_2);
        LE_DEVICE_ERROR_PAPER_CUP_2->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_PAPER_CUP_2"));
        LE_DEVICE_ERROR_PAPER_CUP_2->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_PAPER_CUP_2->setFont(font1);
        LE_DEVICE_ERROR_PAPER_CUP_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_PAPER_CUP_2->setReadOnly(true);

        gridLayout_3->addWidget(LE_DEVICE_ERROR_PAPER_CUP_2, 1, 1, 1, 1);

        label_159 = new QLabel(layoutWidget_2);
        label_159->setObjectName(QString::fromUtf8("label_159"));
        label_159->setFont(font1);
        label_159->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_159, 4, 0, 1, 1);

        label_163 = new QLabel(layoutWidget_2);
        label_163->setObjectName(QString::fromUtf8("label_163"));
        label_163->setFont(font1);
        label_163->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_163, 5, 0, 1, 1);

        LE_DEVICE_ERROR_COFFEE = new QLineEdit(layoutWidget_2);
        LE_DEVICE_ERROR_COFFEE->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_COFFEE"));
        LE_DEVICE_ERROR_COFFEE->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_COFFEE->setFont(font1);
        LE_DEVICE_ERROR_COFFEE->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_COFFEE->setReadOnly(true);

        gridLayout_3->addWidget(LE_DEVICE_ERROR_COFFEE, 7, 1, 1, 1);

        label_161 = new QLabel(layoutWidget_2);
        label_161->setObjectName(QString::fromUtf8("label_161"));
        label_161->setFont(font1);
        label_161->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_161, 3, 0, 1, 1);

        BTN_ERROR_CLEAR_COFFEE = new QPushButton(layoutWidget_2);
        BTN_ERROR_CLEAR_COFFEE->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_COFFEE"));
        BTN_ERROR_CLEAR_COFFEE->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(BTN_ERROR_CLEAR_COFFEE, 7, 2, 1, 1);

        LE_DEVICE_ERROR_PAPER_CUP_1 = new QLineEdit(layoutWidget_2);
        LE_DEVICE_ERROR_PAPER_CUP_1->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_PAPER_CUP_1"));
        LE_DEVICE_ERROR_PAPER_CUP_1->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_PAPER_CUP_1->setFont(font1);
        LE_DEVICE_ERROR_PAPER_CUP_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_PAPER_CUP_1->setReadOnly(true);

        gridLayout_3->addWidget(LE_DEVICE_ERROR_PAPER_CUP_1, 0, 1, 1, 1);

        BTN_ERROR_CLEAR_PP_CUP_1 = new QPushButton(layoutWidget_2);
        BTN_ERROR_CLEAR_PP_CUP_1->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_PP_CUP_1"));
        BTN_ERROR_CLEAR_PP_CUP_1->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(BTN_ERROR_CLEAR_PP_CUP_1, 2, 2, 1, 1);

        BTN_ERROR_CLEAR_PAPER_CUP_1 = new QPushButton(layoutWidget_2);
        BTN_ERROR_CLEAR_PAPER_CUP_1->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_PAPER_CUP_1"));
        BTN_ERROR_CLEAR_PAPER_CUP_1->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(BTN_ERROR_CLEAR_PAPER_CUP_1, 0, 2, 1, 1);

        label_153 = new QLabel(layoutWidget_2);
        label_153->setObjectName(QString::fromUtf8("label_153"));
        label_153->setFont(font1);
        label_153->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_153, 0, 0, 1, 1);

        label_150 = new QLabel(layoutWidget_2);
        label_150->setObjectName(QString::fromUtf8("label_150"));
        label_150->setFont(font1);
        label_150->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_150, 9, 0, 1, 1);

        LE_DEVICE_ERROR_OUTLET_2 = new QLineEdit(layoutWidget_2);
        LE_DEVICE_ERROR_OUTLET_2->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_OUTLET_2"));
        LE_DEVICE_ERROR_OUTLET_2->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_OUTLET_2->setFont(font1);
        LE_DEVICE_ERROR_OUTLET_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_OUTLET_2->setReadOnly(true);

        gridLayout_3->addWidget(LE_DEVICE_ERROR_OUTLET_2, 5, 1, 1, 1);

        label_149 = new QLabel(layoutWidget_2);
        label_149->setObjectName(QString::fromUtf8("label_149"));
        label_149->setFont(font1);
        label_149->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_149, 7, 0, 1, 1);

        BTN_ERROR_CLEAR_ROBOT_3 = new QPushButton(layoutWidget_2);
        BTN_ERROR_CLEAR_ROBOT_3->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_ROBOT_3"));
        BTN_ERROR_CLEAR_ROBOT_3->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(BTN_ERROR_CLEAR_ROBOT_3, 6, 2, 1, 1);

        LE_DEVICE_ERROR_PP_CUP_1 = new QLineEdit(layoutWidget_2);
        LE_DEVICE_ERROR_PP_CUP_1->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_PP_CUP_1"));
        LE_DEVICE_ERROR_PP_CUP_1->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_PP_CUP_1->setFont(font1);
        LE_DEVICE_ERROR_PP_CUP_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_PP_CUP_1->setReadOnly(true);

        gridLayout_3->addWidget(LE_DEVICE_ERROR_PP_CUP_1, 2, 1, 1, 1);

        label_164 = new QLabel(layoutWidget_2);
        label_164->setObjectName(QString::fromUtf8("label_164"));
        label_164->setFont(font1);
        label_164->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_164, 6, 0, 1, 1);

        label_152 = new QLabel(layoutWidget_2);
        label_152->setObjectName(QString::fromUtf8("label_152"));
        label_152->setFont(font1);
        label_152->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_152, 1, 0, 1, 1);

        BTN_ERROR_CLEAR_PAPER_CUP_2 = new QPushButton(layoutWidget_2);
        BTN_ERROR_CLEAR_PAPER_CUP_2->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_PAPER_CUP_2"));
        BTN_ERROR_CLEAR_PAPER_CUP_2->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(BTN_ERROR_CLEAR_PAPER_CUP_2, 1, 2, 1, 1);

        label_165 = new QLabel(layoutWidget_2);
        label_165->setObjectName(QString::fromUtf8("label_165"));
        label_165->setFont(font1);
        label_165->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_165, 2, 0, 1, 1);

        LE_DEVICE_ERROR_ICE_1 = new QLineEdit(layoutWidget_2);
        LE_DEVICE_ERROR_ICE_1->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_ICE_1"));
        LE_DEVICE_ERROR_ICE_1->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_ICE_1->setFont(font1);
        LE_DEVICE_ERROR_ICE_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_ICE_1->setReadOnly(true);

        gridLayout_3->addWidget(LE_DEVICE_ERROR_ICE_1, 9, 1, 1, 1);

        LE_DEVICE_ERROR_OUTLET_1 = new QLineEdit(layoutWidget_2);
        LE_DEVICE_ERROR_OUTLET_1->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_OUTLET_1"));
        LE_DEVICE_ERROR_OUTLET_1->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_OUTLET_1->setFont(font1);
        LE_DEVICE_ERROR_OUTLET_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_OUTLET_1->setReadOnly(true);

        gridLayout_3->addWidget(LE_DEVICE_ERROR_OUTLET_1, 4, 1, 1, 1);

        LE_DEVICE_ERROR_ROBOT_1 = new QLineEdit(layoutWidget_2);
        LE_DEVICE_ERROR_ROBOT_1->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_ROBOT_1"));
        LE_DEVICE_ERROR_ROBOT_1->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_ROBOT_1->setFont(font1);
        LE_DEVICE_ERROR_ROBOT_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_ROBOT_1->setReadOnly(true);

        gridLayout_3->addWidget(LE_DEVICE_ERROR_ROBOT_1, 6, 1, 1, 1);

        BTN_ERROR_CLEAR_PP_CUP_2 = new QPushButton(layoutWidget_2);
        BTN_ERROR_CLEAR_PP_CUP_2->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_PP_CUP_2"));
        BTN_ERROR_CLEAR_PP_CUP_2->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(BTN_ERROR_CLEAR_PP_CUP_2, 3, 2, 1, 1);

        BTN_ERROR_CLEAR_OUTLET_1 = new QPushButton(layoutWidget_2);
        BTN_ERROR_CLEAR_OUTLET_1->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_OUTLET_1"));
        BTN_ERROR_CLEAR_OUTLET_1->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(BTN_ERROR_CLEAR_OUTLET_1, 4, 2, 1, 1);

        BTN_ERROR_CLEAR_OUTLET_2 = new QPushButton(layoutWidget_2);
        BTN_ERROR_CLEAR_OUTLET_2->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_OUTLET_2"));
        BTN_ERROR_CLEAR_OUTLET_2->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(BTN_ERROR_CLEAR_OUTLET_2, 5, 2, 1, 1);

        BTN_ERROR_CLEAR_ICE_1 = new QPushButton(layoutWidget_2);
        BTN_ERROR_CLEAR_ICE_1->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_ICE_1"));
        BTN_ERROR_CLEAR_ICE_1->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(BTN_ERROR_CLEAR_ICE_1, 9, 2, 1, 1);

        LE_DEVICE_ERROR_PP_CUP_2 = new QLineEdit(layoutWidget_2);
        LE_DEVICE_ERROR_PP_CUP_2->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_PP_CUP_2"));
        LE_DEVICE_ERROR_PP_CUP_2->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_PP_CUP_2->setFont(font1);
        LE_DEVICE_ERROR_PP_CUP_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_PP_CUP_2->setReadOnly(true);

        gridLayout_3->addWidget(LE_DEVICE_ERROR_PP_CUP_2, 3, 1, 1, 1);

        label_166 = new QLabel(layoutWidget_2);
        label_166->setObjectName(QString::fromUtf8("label_166"));
        label_166->setFont(font1);
        label_166->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_166, 8, 0, 1, 1);

        LE_DEVICE_ERROR_SODA = new QLineEdit(layoutWidget_2);
        LE_DEVICE_ERROR_SODA->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_SODA"));
        LE_DEVICE_ERROR_SODA->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_SODA->setFont(font1);
        LE_DEVICE_ERROR_SODA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_SODA->setReadOnly(true);

        gridLayout_3->addWidget(LE_DEVICE_ERROR_SODA, 8, 1, 1, 1);

        BTN_ERROR_CLEAR_SODA = new QPushButton(layoutWidget_2);
        BTN_ERROR_CLEAR_SODA->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_SODA"));
        BTN_ERROR_CLEAR_SODA->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(BTN_ERROR_CLEAR_SODA, 8, 2, 1, 1);

        TW_SETTING->addTab(ERROR, QString());
        TEST = new QWidget();
        TEST->setObjectName(QString::fromUtf8("TEST"));
        BTN_TEST_ORDER = new QPushButton(TEST);
        BTN_TEST_ORDER->setObjectName(QString::fromUtf8("BTN_TEST_ORDER"));
        BTN_TEST_ORDER->setGeometry(QRect(270, 420, 89, 51));
        TW_TEST_MENU = new QTableWidget(TEST);
        TW_TEST_MENU->setObjectName(QString::fromUtf8("TW_TEST_MENU"));
        TW_TEST_MENU->setGeometry(QRect(10, 20, 351, 391));
        TW_TEST_MENU->horizontalHeader()->setDefaultSectionSize(150);
        TW_SETTING->addTab(TEST, QString());
        LE_SET_PASSWD = new QLineEdit(GB_SETTING);
        LE_SET_PASSWD->setObjectName(QString::fromUtf8("LE_SET_PASSWD"));
        LE_SET_PASSWD->setGeometry(QRect(70, 850, 131, 31));
        label = new QLabel(GB_SETTING);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 820, 321, 16));
        BTN_SET_UNLOCK = new QPushButton(GB_SETTING);
        BTN_SET_UNLOCK->setObjectName(QString::fromUtf8("BTN_SET_UNLOCK"));
        BTN_SET_UNLOCK->setGeometry(QRect(220, 850, 75, 31));
        BTN_SET_LOCK = new QPushButton(GB_SETTING);
        BTN_SET_LOCK->setObjectName(QString::fromUtf8("BTN_SET_LOCK"));
        BTN_SET_LOCK->setGeometry(QRect(300, 850, 75, 31));
        BTN_OPEN_RECIPE_2 = new QPushButton(GB_SETTING);
        BTN_OPEN_RECIPE_2->setObjectName(QString::fromUtf8("BTN_OPEN_RECIPE_2"));
        BTN_OPEN_RECIPE_2->setGeometry(QRect(280, 900, 89, 41));
        BTN_OPEN_RECIPE = new QPushButton(GB_SETTING);
        BTN_OPEN_RECIPE->setObjectName(QString::fromUtf8("BTN_OPEN_RECIPE"));
        BTN_OPEN_RECIPE->setGeometry(QRect(180, 900, 89, 41));
        BTN_DB_RELOAD = new QPushButton(GB_SETTING);
        BTN_DB_RELOAD->setObjectName(QString::fromUtf8("BTN_DB_RELOAD"));
        BTN_DB_RELOAD->setGeometry(QRect(80, 900, 89, 41));

        retranslateUi(DialogSetting);

        TW_SETTING->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogSetting);
    } // setupUi

    void retranslateUi(QDialog *DialogSetting)
    {
        DialogSetting->setWindowTitle(QCoreApplication::translate("DialogSetting", "Dialog", nullptr));
        GB_SETTING->setTitle(QCoreApplication::translate("DialogSetting", "\354\204\244\354\240\225", nullptr));
        label_148->setText(QCoreApplication::translate("DialogSetting", "\354\236\245\353\271\204 \354\227\220\353\237\254", nullptr));
        GB_SUPER_STOP->setTitle(QCoreApplication::translate("DialogSetting", "SUPER STOP", nullptr));
        label_203->setText(QCoreApplication::translate("DialogSetting", "Board Connection Error (LAN2CAN)", nullptr));
        label_209->setText(QCoreApplication::translate("DialogSetting", "Robot Data Error", nullptr));
        label_210->setText(QCoreApplication::translate("DialogSetting", "Robot Miss Command Check Error", nullptr));
        label_211->setText(QCoreApplication::translate("DialogSetting", "Outlet Connection Error", nullptr));
        label_212->setText(QCoreApplication::translate("DialogSetting", "Outlet Control Error", nullptr));
        label_213->setText(QCoreApplication::translate("DialogSetting", "Outlet Sensor Error", nullptr));
        label_214->setText(QCoreApplication::translate("DialogSetting", "Platform Open Error", nullptr));
        LE_DEVICE_ERROR_PAPER_CUP_2->setText(QString());
        label_159->setText(QCoreApplication::translate("DialogSetting", "\353\260\260\354\266\234\352\265\2541", nullptr));
        label_163->setText(QCoreApplication::translate("DialogSetting", "\353\260\260\354\266\234\352\265\2542", nullptr));
        LE_DEVICE_ERROR_COFFEE->setText(QString());
        label_161->setText(QCoreApplication::translate("DialogSetting", "\355\216\230\355\212\270\354\273\2652", nullptr));
        BTN_ERROR_CLEAR_COFFEE->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        LE_DEVICE_ERROR_PAPER_CUP_1->setText(QString());
        BTN_ERROR_CLEAR_PP_CUP_1->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        BTN_ERROR_CLEAR_PAPER_CUP_1->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        label_153->setText(QCoreApplication::translate("DialogSetting", "\354\242\205\354\235\264\354\273\2651", nullptr));
        label_150->setText(QCoreApplication::translate("DialogSetting", "\354\240\234\353\271\231\352\270\2601", nullptr));
        LE_DEVICE_ERROR_OUTLET_2->setText(QString());
        label_149->setText(QCoreApplication::translate("DialogSetting", "\354\273\244\355\224\274\353\250\270\354\213\240", nullptr));
        BTN_ERROR_CLEAR_ROBOT_3->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        LE_DEVICE_ERROR_PP_CUP_1->setText(QString());
        label_164->setText(QCoreApplication::translate("DialogSetting", "\353\241\234\353\264\207", nullptr));
        label_152->setText(QCoreApplication::translate("DialogSetting", "\354\242\205\354\235\264\354\273\2652", nullptr));
        BTN_ERROR_CLEAR_PAPER_CUP_2->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        label_165->setText(QCoreApplication::translate("DialogSetting", "\355\216\230\355\212\270\354\273\2651", nullptr));
        LE_DEVICE_ERROR_ICE_1->setText(QString());
        LE_DEVICE_ERROR_OUTLET_1->setText(QString());
        LE_DEVICE_ERROR_ROBOT_1->setText(QString());
        BTN_ERROR_CLEAR_PP_CUP_2->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        BTN_ERROR_CLEAR_OUTLET_1->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        BTN_ERROR_CLEAR_OUTLET_2->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        BTN_ERROR_CLEAR_ICE_1->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        LE_DEVICE_ERROR_PP_CUP_2->setText(QString());
        label_166->setText(QCoreApplication::translate("DialogSetting", "\354\206\214\353\213\244", nullptr));
        LE_DEVICE_ERROR_SODA->setText(QString());
        BTN_ERROR_CLEAR_SODA->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        TW_SETTING->setTabText(TW_SETTING->indexOf(ERROR), QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254", nullptr));
        BTN_TEST_ORDER->setText(QCoreApplication::translate("DialogSetting", "\355\205\214\354\212\244\355\212\270 \354\243\274\353\254\270", nullptr));
        TW_SETTING->setTabText(TW_SETTING->indexOf(TEST), QCoreApplication::translate("DialogSetting", "\355\205\214\354\212\244\355\212\270", nullptr));
        label->setText(QCoreApplication::translate("DialogSetting", "\352\264\200\353\246\254\354\236\220 \354\236\240\352\270\210\354\235\204 \355\225\264\354\240\234\355\225\230\353\240\244\353\251\264 \353\271\204\353\260\200\353\262\210\355\230\270\353\245\274 \354\236\205\353\240\245\355\225\230\354\204\270\354\232\224.", nullptr));
        BTN_SET_UNLOCK->setText(QCoreApplication::translate("DialogSetting", "\354\236\240\352\270\210\355\225\264\354\240\234", nullptr));
        BTN_SET_LOCK->setText(QCoreApplication::translate("DialogSetting", "\354\236\240\352\270\210", nullptr));
        BTN_OPEN_RECIPE_2->setText(QCoreApplication::translate("DialogSetting", "\353\240\210\354\213\234\355\224\274\n"
"\354\210\230\354\240\225 \354\231\204\353\243\214", nullptr));
        BTN_OPEN_RECIPE->setText(QCoreApplication::translate("DialogSetting", "\353\240\210\354\213\234\355\224\274 \354\210\230\354\240\225", nullptr));
        BTN_DB_RELOAD->setText(QCoreApplication::translate("DialogSetting", "DB Reload", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSetting: public Ui_DialogSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSETTING_H
