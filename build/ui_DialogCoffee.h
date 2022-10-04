/********************************************************************************
** Form generated from reading UI file 'DialogCoffee.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCOFFEE_H
#define UI_DIALOGCOFFEE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogCoffee
{
public:
    QGroupBox *GB_COFFEE;
    QLineEdit *LE_COFFEE_CONNECTION;
    QLabel *label_110;
    QLabel *label_111;
    QLineEdit *LE_COFFEE_DATA_CONNECTION;
    QPushButton *BTN_BEAN_HOPPER_REFILLED;
    QListWidget *LW_INFO_MSG;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QComboBox *CB_LIST;
    QPushButton *BTN_COFFEE_MAKE;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_13;
    QLineEdit *LE_MACHINE_JUST_RESET;
    QLineEdit *LE_MACHINE_REQUEST_SET;
    QLineEdit *LE_MACHINE_INFO_MSG_SET;
    QLineEdit *LE_MACHINE_PRODUCT_DUMP;
    QLineEdit *LE_MACHINE_EDIT_MODE;
    QLineEdit *LE_MACHINE_WATER_LEVEL;
    QLineEdit *LE_MACHINE_STAND_BY;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_12;
    QLineEdit *LE_COFFEE_DETAIL_UNDEF;
    QLineEdit *LE_COFFEE_DETAIL_GRINDING;
    QLineEdit *LE_COFFEE_DETAIL_TAMPING_PREBREW;
    QLineEdit *LE_COFFEE_DETAIL_DISPENSING;
    QLineEdit *LE_COFFEE_DETAIL_PRESS_DROPCAKE;
    QLineEdit *LE_COFFEE_DETAIL_UNKNOWN;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_14;
    QLineEdit *LE_MILK_DETAIL_UNDEF;
    QLineEdit *LE_MILK_DETAIL_SUCTION_DETECTION;
    QLineEdit *LE_MILK_DETAIL_DISPENSING;
    QLineEdit *LE_MILK_DETAIL_RINSE;
    QLineEdit *LE_MILK_DETAIL_UNKNOWN;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_16;
    QLineEdit *LE_COFFEE_L_M_STATUS_NOT_READY;
    QLineEdit *LE_COFFEE_L_M_STATUS_READY;
    QLineEdit *LE_COFFEE_L_M_STATUS_ONLY_COFFEE_READY;
    QLineEdit *LE_COFFEE_L_M_STATUS_ONLY_MILK_READY;
    QLineEdit *LE_COFFEE_L_M_STATUS_UNDEF;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_20;
    QLineEdit *LE_WATER_M_STATUS_NOT_READY;
    QLineEdit *LE_WATER_M_STATUS_READY;
    QLineEdit *LE_WATER_M_STATUS_ONLY_COFFEE_READY;
    QLineEdit *LE_WATER_M_STATUS_ONLY_MILK_READY;
    QLineEdit *LE_WATER_M_STATUS_UNDEF;
    QWidget *widget3;
    QGridLayout *gridLayout;
    QLabel *label_31;
    QLabel *label_35;
    QLineEdit *LE_WATER_M_PROCESS;
    QLineEdit *LE_WATER_M_ACTION;
    QLabel *label_25;
    QLineEdit *LE_COFFEE_L_M_PROCESS;
    QLineEdit *LE_COFFEE_L_M_ACTION;
    QLabel *label_21;
    QLabel *label_26;
    QLineEdit *LE_COFFEE_L_PRODUCT_KEY;
    QLabel *label_30;
    QLineEdit *LE_WATER_PRODUCT_KEY;
    QWidget *widget4;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *LE_PIP;
    QLineEdit *LE_PIE;
    QLineEdit *LE_PN;
    QLineEdit *LE_SA;
    QLineEdit *LE_DA;
    QGridLayout *gridLayout_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *LE_MI;
    QLineEdit *LE_MP;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_8;
    QLineEdit *LE_DL;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_9;
    QLineEdit *LE_DATA;
    QGridLayout *gridLayout_3;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *LE_CRC;
    QLineEdit *LE_CRC_2;

    void setupUi(QDialog *DialogCoffee)
    {
        if (DialogCoffee->objectName().isEmpty())
            DialogCoffee->setObjectName(QString::fromUtf8("DialogCoffee"));
        DialogCoffee->resize(400, 960);
        GB_COFFEE = new QGroupBox(DialogCoffee);
        GB_COFFEE->setObjectName(QString::fromUtf8("GB_COFFEE"));
        GB_COFFEE->setGeometry(QRect(0, 0, 400, 960));
        QFont font;
        font.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        GB_COFFEE->setFont(font);
        GB_COFFEE->setStyleSheet(QString::fromUtf8("QGroupBox  {\n"
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
"QListWidget{\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"	background-color: #ffffff\n"
"}\n"
"QCheckBox{\n"
"	font: 10pt \"\355"
                        "\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"\n"
"\n"
"\n"
""));
        LE_COFFEE_CONNECTION = new QLineEdit(GB_COFFEE);
        LE_COFFEE_CONNECTION->setObjectName(QString::fromUtf8("LE_COFFEE_CONNECTION"));
        LE_COFFEE_CONNECTION->setGeometry(QRect(110, 70, 61, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        LE_COFFEE_CONNECTION->setFont(font1);
        LE_COFFEE_CONNECTION->setReadOnly(true);
        label_110 = new QLabel(GB_COFFEE);
        label_110->setObjectName(QString::fromUtf8("label_110"));
        label_110->setGeometry(QRect(0, 70, 101, 21));
        label_110->setFont(font1);
        label_110->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_111 = new QLabel(GB_COFFEE);
        label_111->setObjectName(QString::fromUtf8("label_111"));
        label_111->setGeometry(QRect(200, 70, 101, 21));
        label_111->setFont(font1);
        label_111->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_COFFEE_DATA_CONNECTION = new QLineEdit(GB_COFFEE);
        LE_COFFEE_DATA_CONNECTION->setObjectName(QString::fromUtf8("LE_COFFEE_DATA_CONNECTION"));
        LE_COFFEE_DATA_CONNECTION->setGeometry(QRect(310, 70, 61, 21));
        LE_COFFEE_DATA_CONNECTION->setFont(font1);
        LE_COFFEE_DATA_CONNECTION->setReadOnly(true);
        BTN_BEAN_HOPPER_REFILLED = new QPushButton(GB_COFFEE);
        BTN_BEAN_HOPPER_REFILLED->setObjectName(QString::fromUtf8("BTN_BEAN_HOPPER_REFILLED"));
        BTN_BEAN_HOPPER_REFILLED->setGeometry(QRect(20, 780, 221, 25));
        LW_INFO_MSG = new QListWidget(GB_COFFEE);
        LW_INFO_MSG->setObjectName(QString::fromUtf8("LW_INFO_MSG"));
        LW_INFO_MSG->setGeometry(QRect(20, 660, 361, 81));
        line = new QFrame(GB_COFFEE);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(20, 100, 361, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(GB_COFFEE);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(20, 180, 361, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(GB_COFFEE);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(20, 750, 361, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        widget = new QWidget(GB_COFFEE);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 130, 301, 42));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        CB_LIST = new QComboBox(widget);
        CB_LIST->setObjectName(QString::fromUtf8("CB_LIST"));
        CB_LIST->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(CB_LIST);

        BTN_COFFEE_MAKE = new QPushButton(widget);
        BTN_COFFEE_MAKE->setObjectName(QString::fromUtf8("BTN_COFFEE_MAKE"));
        BTN_COFFEE_MAKE->setMinimumSize(QSize(50, 40));
        BTN_COFFEE_MAKE->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(BTN_COFFEE_MAKE);

        widget1 = new QWidget(GB_COFFEE);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(20, 210, 361, 182));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_13 = new QLabel(widget1);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font1);
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_13);

        LE_MACHINE_JUST_RESET = new QLineEdit(widget1);
        LE_MACHINE_JUST_RESET->setObjectName(QString::fromUtf8("LE_MACHINE_JUST_RESET"));
        LE_MACHINE_JUST_RESET->setFont(font1);
        LE_MACHINE_JUST_RESET->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(LE_MACHINE_JUST_RESET);

        LE_MACHINE_REQUEST_SET = new QLineEdit(widget1);
        LE_MACHINE_REQUEST_SET->setObjectName(QString::fromUtf8("LE_MACHINE_REQUEST_SET"));
        LE_MACHINE_REQUEST_SET->setFont(font1);
        LE_MACHINE_REQUEST_SET->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(LE_MACHINE_REQUEST_SET);

        LE_MACHINE_INFO_MSG_SET = new QLineEdit(widget1);
        LE_MACHINE_INFO_MSG_SET->setObjectName(QString::fromUtf8("LE_MACHINE_INFO_MSG_SET"));
        LE_MACHINE_INFO_MSG_SET->setFont(font1);
        LE_MACHINE_INFO_MSG_SET->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(LE_MACHINE_INFO_MSG_SET);

        LE_MACHINE_PRODUCT_DUMP = new QLineEdit(widget1);
        LE_MACHINE_PRODUCT_DUMP->setObjectName(QString::fromUtf8("LE_MACHINE_PRODUCT_DUMP"));
        LE_MACHINE_PRODUCT_DUMP->setFont(font1);
        LE_MACHINE_PRODUCT_DUMP->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(LE_MACHINE_PRODUCT_DUMP);

        LE_MACHINE_EDIT_MODE = new QLineEdit(widget1);
        LE_MACHINE_EDIT_MODE->setObjectName(QString::fromUtf8("LE_MACHINE_EDIT_MODE"));
        LE_MACHINE_EDIT_MODE->setFont(font1);
        LE_MACHINE_EDIT_MODE->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(LE_MACHINE_EDIT_MODE);

        LE_MACHINE_WATER_LEVEL = new QLineEdit(widget1);
        LE_MACHINE_WATER_LEVEL->setObjectName(QString::fromUtf8("LE_MACHINE_WATER_LEVEL"));
        LE_MACHINE_WATER_LEVEL->setFont(font1);
        LE_MACHINE_WATER_LEVEL->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(LE_MACHINE_WATER_LEVEL);

        LE_MACHINE_STAND_BY = new QLineEdit(widget1);
        LE_MACHINE_STAND_BY->setObjectName(QString::fromUtf8("LE_MACHINE_STAND_BY"));
        LE_MACHINE_STAND_BY->setFont(font1);
        LE_MACHINE_STAND_BY->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(LE_MACHINE_STAND_BY);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_12 = new QLabel(widget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font1);
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_12);

        LE_COFFEE_DETAIL_UNDEF = new QLineEdit(widget1);
        LE_COFFEE_DETAIL_UNDEF->setObjectName(QString::fromUtf8("LE_COFFEE_DETAIL_UNDEF"));
        LE_COFFEE_DETAIL_UNDEF->setFont(font1);
        LE_COFFEE_DETAIL_UNDEF->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(LE_COFFEE_DETAIL_UNDEF);

        LE_COFFEE_DETAIL_GRINDING = new QLineEdit(widget1);
        LE_COFFEE_DETAIL_GRINDING->setObjectName(QString::fromUtf8("LE_COFFEE_DETAIL_GRINDING"));
        LE_COFFEE_DETAIL_GRINDING->setFont(font1);
        LE_COFFEE_DETAIL_GRINDING->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(LE_COFFEE_DETAIL_GRINDING);

        LE_COFFEE_DETAIL_TAMPING_PREBREW = new QLineEdit(widget1);
        LE_COFFEE_DETAIL_TAMPING_PREBREW->setObjectName(QString::fromUtf8("LE_COFFEE_DETAIL_TAMPING_PREBREW"));
        LE_COFFEE_DETAIL_TAMPING_PREBREW->setFont(font1);
        LE_COFFEE_DETAIL_TAMPING_PREBREW->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(LE_COFFEE_DETAIL_TAMPING_PREBREW);

        LE_COFFEE_DETAIL_DISPENSING = new QLineEdit(widget1);
        LE_COFFEE_DETAIL_DISPENSING->setObjectName(QString::fromUtf8("LE_COFFEE_DETAIL_DISPENSING"));
        LE_COFFEE_DETAIL_DISPENSING->setFont(font1);
        LE_COFFEE_DETAIL_DISPENSING->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(LE_COFFEE_DETAIL_DISPENSING);

        LE_COFFEE_DETAIL_PRESS_DROPCAKE = new QLineEdit(widget1);
        LE_COFFEE_DETAIL_PRESS_DROPCAKE->setObjectName(QString::fromUtf8("LE_COFFEE_DETAIL_PRESS_DROPCAKE"));
        LE_COFFEE_DETAIL_PRESS_DROPCAKE->setFont(font1);
        LE_COFFEE_DETAIL_PRESS_DROPCAKE->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(LE_COFFEE_DETAIL_PRESS_DROPCAKE);


        verticalLayout_5->addLayout(verticalLayout_2);

        LE_COFFEE_DETAIL_UNKNOWN = new QLineEdit(widget1);
        LE_COFFEE_DETAIL_UNKNOWN->setObjectName(QString::fromUtf8("LE_COFFEE_DETAIL_UNKNOWN"));
        LE_COFFEE_DETAIL_UNKNOWN->setFont(font1);
        LE_COFFEE_DETAIL_UNKNOWN->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(LE_COFFEE_DETAIL_UNKNOWN);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_14 = new QLabel(widget1);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);
        label_14->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_14);

        LE_MILK_DETAIL_UNDEF = new QLineEdit(widget1);
        LE_MILK_DETAIL_UNDEF->setObjectName(QString::fromUtf8("LE_MILK_DETAIL_UNDEF"));
        LE_MILK_DETAIL_UNDEF->setFont(font1);
        LE_MILK_DETAIL_UNDEF->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(LE_MILK_DETAIL_UNDEF);

        LE_MILK_DETAIL_SUCTION_DETECTION = new QLineEdit(widget1);
        LE_MILK_DETAIL_SUCTION_DETECTION->setObjectName(QString::fromUtf8("LE_MILK_DETAIL_SUCTION_DETECTION"));
        LE_MILK_DETAIL_SUCTION_DETECTION->setFont(font1);
        LE_MILK_DETAIL_SUCTION_DETECTION->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(LE_MILK_DETAIL_SUCTION_DETECTION);

        LE_MILK_DETAIL_DISPENSING = new QLineEdit(widget1);
        LE_MILK_DETAIL_DISPENSING->setObjectName(QString::fromUtf8("LE_MILK_DETAIL_DISPENSING"));
        LE_MILK_DETAIL_DISPENSING->setFont(font1);
        LE_MILK_DETAIL_DISPENSING->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(LE_MILK_DETAIL_DISPENSING);

        LE_MILK_DETAIL_RINSE = new QLineEdit(widget1);
        LE_MILK_DETAIL_RINSE->setObjectName(QString::fromUtf8("LE_MILK_DETAIL_RINSE"));
        LE_MILK_DETAIL_RINSE->setFont(font1);
        LE_MILK_DETAIL_RINSE->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(LE_MILK_DETAIL_RINSE);


        verticalLayout_4->addLayout(verticalLayout_3);

        LE_MILK_DETAIL_UNKNOWN = new QLineEdit(widget1);
        LE_MILK_DETAIL_UNKNOWN->setObjectName(QString::fromUtf8("LE_MILK_DETAIL_UNKNOWN"));
        LE_MILK_DETAIL_UNKNOWN->setFont(font1);
        LE_MILK_DETAIL_UNKNOWN->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(LE_MILK_DETAIL_UNKNOWN);


        horizontalLayout_2->addLayout(verticalLayout_4);

        widget2 = new QWidget(GB_COFFEE);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(20, 400, 361, 136));
        horizontalLayout_4 = new QHBoxLayout(widget2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_16 = new QLabel(widget2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font1);
        label_16->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_16);

        LE_COFFEE_L_M_STATUS_NOT_READY = new QLineEdit(widget2);
        LE_COFFEE_L_M_STATUS_NOT_READY->setObjectName(QString::fromUtf8("LE_COFFEE_L_M_STATUS_NOT_READY"));
        LE_COFFEE_L_M_STATUS_NOT_READY->setFont(font1);
        LE_COFFEE_L_M_STATUS_NOT_READY->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(LE_COFFEE_L_M_STATUS_NOT_READY);

        LE_COFFEE_L_M_STATUS_READY = new QLineEdit(widget2);
        LE_COFFEE_L_M_STATUS_READY->setObjectName(QString::fromUtf8("LE_COFFEE_L_M_STATUS_READY"));
        LE_COFFEE_L_M_STATUS_READY->setFont(font1);
        LE_COFFEE_L_M_STATUS_READY->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(LE_COFFEE_L_M_STATUS_READY);

        LE_COFFEE_L_M_STATUS_ONLY_COFFEE_READY = new QLineEdit(widget2);
        LE_COFFEE_L_M_STATUS_ONLY_COFFEE_READY->setObjectName(QString::fromUtf8("LE_COFFEE_L_M_STATUS_ONLY_COFFEE_READY"));
        LE_COFFEE_L_M_STATUS_ONLY_COFFEE_READY->setFont(font1);
        LE_COFFEE_L_M_STATUS_ONLY_COFFEE_READY->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(LE_COFFEE_L_M_STATUS_ONLY_COFFEE_READY);

        LE_COFFEE_L_M_STATUS_ONLY_MILK_READY = new QLineEdit(widget2);
        LE_COFFEE_L_M_STATUS_ONLY_MILK_READY->setObjectName(QString::fromUtf8("LE_COFFEE_L_M_STATUS_ONLY_MILK_READY"));
        LE_COFFEE_L_M_STATUS_ONLY_MILK_READY->setFont(font1);
        LE_COFFEE_L_M_STATUS_ONLY_MILK_READY->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(LE_COFFEE_L_M_STATUS_ONLY_MILK_READY);

        LE_COFFEE_L_M_STATUS_UNDEF = new QLineEdit(widget2);
        LE_COFFEE_L_M_STATUS_UNDEF->setObjectName(QString::fromUtf8("LE_COFFEE_L_M_STATUS_UNDEF"));
        LE_COFFEE_L_M_STATUS_UNDEF->setFont(font1);
        LE_COFFEE_L_M_STATUS_UNDEF->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(LE_COFFEE_L_M_STATUS_UNDEF);


        horizontalLayout_4->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_20 = new QLabel(widget2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font1);
        label_20->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_20);

        LE_WATER_M_STATUS_NOT_READY = new QLineEdit(widget2);
        LE_WATER_M_STATUS_NOT_READY->setObjectName(QString::fromUtf8("LE_WATER_M_STATUS_NOT_READY"));
        LE_WATER_M_STATUS_NOT_READY->setFont(font1);
        LE_WATER_M_STATUS_NOT_READY->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(LE_WATER_M_STATUS_NOT_READY);

        LE_WATER_M_STATUS_READY = new QLineEdit(widget2);
        LE_WATER_M_STATUS_READY->setObjectName(QString::fromUtf8("LE_WATER_M_STATUS_READY"));
        LE_WATER_M_STATUS_READY->setFont(font1);
        LE_WATER_M_STATUS_READY->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(LE_WATER_M_STATUS_READY);

        LE_WATER_M_STATUS_ONLY_COFFEE_READY = new QLineEdit(widget2);
        LE_WATER_M_STATUS_ONLY_COFFEE_READY->setObjectName(QString::fromUtf8("LE_WATER_M_STATUS_ONLY_COFFEE_READY"));
        LE_WATER_M_STATUS_ONLY_COFFEE_READY->setFont(font1);
        LE_WATER_M_STATUS_ONLY_COFFEE_READY->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(LE_WATER_M_STATUS_ONLY_COFFEE_READY);

        LE_WATER_M_STATUS_ONLY_MILK_READY = new QLineEdit(widget2);
        LE_WATER_M_STATUS_ONLY_MILK_READY->setObjectName(QString::fromUtf8("LE_WATER_M_STATUS_ONLY_MILK_READY"));
        LE_WATER_M_STATUS_ONLY_MILK_READY->setFont(font1);
        LE_WATER_M_STATUS_ONLY_MILK_READY->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(LE_WATER_M_STATUS_ONLY_MILK_READY);

        LE_WATER_M_STATUS_UNDEF = new QLineEdit(widget2);
        LE_WATER_M_STATUS_UNDEF->setObjectName(QString::fromUtf8("LE_WATER_M_STATUS_UNDEF"));
        LE_WATER_M_STATUS_UNDEF->setFont(font1);
        LE_WATER_M_STATUS_UNDEF->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(LE_WATER_M_STATUS_UNDEF);


        horizontalLayout_4->addLayout(verticalLayout_9);

        widget3 = new QWidget(GB_COFFEE);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(20, 550, 361, 100));
        gridLayout = new QGridLayout(widget3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_31 = new QLabel(widget3);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setFont(font1);
        label_31->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_31, 2, 1, 1, 1);

        label_35 = new QLabel(widget3);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setFont(font1);
        label_35->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_35, 2, 2, 1, 1);

        LE_WATER_M_PROCESS = new QLineEdit(widget3);
        LE_WATER_M_PROCESS->setObjectName(QString::fromUtf8("LE_WATER_M_PROCESS"));
        LE_WATER_M_PROCESS->setFont(font1);
        LE_WATER_M_PROCESS->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LE_WATER_M_PROCESS, 3, 2, 1, 1);

        LE_WATER_M_ACTION = new QLineEdit(widget3);
        LE_WATER_M_ACTION->setObjectName(QString::fromUtf8("LE_WATER_M_ACTION"));
        LE_WATER_M_ACTION->setFont(font1);
        LE_WATER_M_ACTION->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LE_WATER_M_ACTION, 1, 2, 1, 1);

        label_25 = new QLabel(widget3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setFont(font1);
        label_25->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_25, 0, 1, 1, 1);

        LE_COFFEE_L_M_PROCESS = new QLineEdit(widget3);
        LE_COFFEE_L_M_PROCESS->setObjectName(QString::fromUtf8("LE_COFFEE_L_M_PROCESS"));
        LE_COFFEE_L_M_PROCESS->setFont(font1);
        LE_COFFEE_L_M_PROCESS->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LE_COFFEE_L_M_PROCESS, 3, 1, 1, 1);

        LE_COFFEE_L_M_ACTION = new QLineEdit(widget3);
        LE_COFFEE_L_M_ACTION->setObjectName(QString::fromUtf8("LE_COFFEE_L_M_ACTION"));
        LE_COFFEE_L_M_ACTION->setFont(font1);
        LE_COFFEE_L_M_ACTION->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LE_COFFEE_L_M_ACTION, 1, 1, 1, 1);

        label_21 = new QLabel(widget3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font1);
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_21, 0, 2, 1, 1);

        label_26 = new QLabel(widget3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setFont(font1);
        label_26->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_26, 0, 0, 1, 1);

        LE_COFFEE_L_PRODUCT_KEY = new QLineEdit(widget3);
        LE_COFFEE_L_PRODUCT_KEY->setObjectName(QString::fromUtf8("LE_COFFEE_L_PRODUCT_KEY"));
        LE_COFFEE_L_PRODUCT_KEY->setFont(font1);
        LE_COFFEE_L_PRODUCT_KEY->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LE_COFFEE_L_PRODUCT_KEY, 1, 0, 1, 1);

        label_30 = new QLabel(widget3);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setFont(font1);
        label_30->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_30, 2, 0, 1, 1);

        LE_WATER_PRODUCT_KEY = new QLineEdit(widget3);
        LE_WATER_PRODUCT_KEY->setObjectName(QString::fromUtf8("LE_WATER_PRODUCT_KEY"));
        LE_WATER_PRODUCT_KEY->setFont(font1);
        LE_WATER_PRODUCT_KEY->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LE_WATER_PRODUCT_KEY, 3, 0, 1, 1);

        widget4 = new QWidget(GB_COFFEE);
        widget4->setObjectName(QString::fromUtf8("widget4"));
        widget4->setGeometry(QRect(20, 810, 361, 142));
        verticalLayout_10 = new QVBoxLayout(widget4);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label = new QLabel(widget4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(30, 16777215));
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(30, 16777215));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(widget4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(30, 16777215));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(widget4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_4, 0, 3, 1, 1);

        label_5 = new QLabel(widget4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_5, 0, 4, 1, 1);

        LE_PIP = new QLineEdit(widget4);
        LE_PIP->setObjectName(QString::fromUtf8("LE_PIP"));
        LE_PIP->setMaximumSize(QSize(30, 16777215));
        LE_PIP->setFont(font1);

        gridLayout_4->addWidget(LE_PIP, 1, 0, 1, 1);

        LE_PIE = new QLineEdit(widget4);
        LE_PIE->setObjectName(QString::fromUtf8("LE_PIE"));
        LE_PIE->setMaximumSize(QSize(30, 16777215));
        LE_PIE->setFont(font1);

        gridLayout_4->addWidget(LE_PIE, 1, 1, 1, 1);

        LE_PN = new QLineEdit(widget4);
        LE_PN->setObjectName(QString::fromUtf8("LE_PN"));
        LE_PN->setMaximumSize(QSize(30, 16777215));
        LE_PN->setFont(font1);

        gridLayout_4->addWidget(LE_PN, 1, 2, 1, 1);

        LE_SA = new QLineEdit(widget4);
        LE_SA->setObjectName(QString::fromUtf8("LE_SA"));
        LE_SA->setMaximumSize(QSize(30, 16777215));
        LE_SA->setFont(font1);

        gridLayout_4->addWidget(LE_SA, 1, 3, 1, 1);

        LE_DA = new QLineEdit(widget4);
        LE_DA->setObjectName(QString::fromUtf8("LE_DA"));
        LE_DA->setMaximumSize(QSize(30, 16777215));
        LE_DA->setFont(font1);

        gridLayout_4->addWidget(LE_DA, 1, 4, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_4);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_6 = new QLabel(widget4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(30, 16777215));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_6, 0, 0, 1, 1);

        label_7 = new QLabel(widget4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(30, 16777215));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_7, 0, 1, 1, 1);

        LE_MI = new QLineEdit(widget4);
        LE_MI->setObjectName(QString::fromUtf8("LE_MI"));
        LE_MI->setMaximumSize(QSize(30, 16777215));
        LE_MI->setFont(font1);

        gridLayout_5->addWidget(LE_MI, 1, 0, 1, 1);

        LE_MP = new QLineEdit(widget4);
        LE_MP->setObjectName(QString::fromUtf8("LE_MP"));
        LE_MP->setMaximumSize(QSize(30, 16777215));
        LE_MP->setFont(font1);

        gridLayout_5->addWidget(LE_MP, 1, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_8 = new QLabel(widget4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(30, 16777215));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_8);

        LE_DL = new QLineEdit(widget4);
        LE_DL->setObjectName(QString::fromUtf8("LE_DL"));
        LE_DL->setMaximumSize(QSize(30, 16777215));
        LE_DL->setFont(font1);

        verticalLayout_7->addWidget(LE_DL);


        horizontalLayout_3->addLayout(verticalLayout_7);


        verticalLayout_10->addLayout(horizontalLayout_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_9 = new QLabel(widget4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_9);

        LE_DATA = new QLineEdit(widget4);
        LE_DATA->setObjectName(QString::fromUtf8("LE_DATA"));
        LE_DATA->setMinimumSize(QSize(350, 0));
        LE_DATA->setFont(font1);

        verticalLayout_6->addWidget(LE_DATA);


        verticalLayout_10->addLayout(verticalLayout_6);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_10 = new QLabel(widget4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_10, 0, 0, 1, 1);

        label_11 = new QLabel(widget4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_11, 0, 1, 1, 1);

        LE_CRC = new QLineEdit(widget4);
        LE_CRC->setObjectName(QString::fromUtf8("LE_CRC"));
        LE_CRC->setFont(font1);

        gridLayout_3->addWidget(LE_CRC, 1, 0, 1, 1);

        LE_CRC_2 = new QLineEdit(widget4);
        LE_CRC_2->setObjectName(QString::fromUtf8("LE_CRC_2"));
        LE_CRC_2->setFont(font1);

        gridLayout_3->addWidget(LE_CRC_2, 1, 1, 1, 1);


        verticalLayout_10->addLayout(gridLayout_3);


        retranslateUi(DialogCoffee);

        QMetaObject::connectSlotsByName(DialogCoffee);
    } // setupUi

    void retranslateUi(QDialog *DialogCoffee)
    {
        DialogCoffee->setWindowTitle(QCoreApplication::translate("DialogCoffee", "Dialog", nullptr));
        GB_COFFEE->setTitle(QCoreApplication::translate("DialogCoffee", "\354\273\244\355\224\274 (Eversys)", nullptr));
        label_110->setText(QCoreApplication::translate("DialogCoffee", "\354\236\245\354\271\230 \354\227\260\352\262\260 \354\203\201\355\203\234", nullptr));
        label_111->setText(QCoreApplication::translate("DialogCoffee", "\353\215\260\354\235\264\355\204\260 \354\227\260\352\262\260 \354\203\201\355\203\234", nullptr));
        BTN_BEAN_HOPPER_REFILLED->setText(QCoreApplication::translate("DialogCoffee", "Bean Hopper Refilled", nullptr));
        BTN_COFFEE_MAKE->setText(QCoreApplication::translate("DialogCoffee", "\353\260\260\354\266\234", nullptr));
        label_13->setText(QCoreApplication::translate("DialogCoffee", "Machine Status", nullptr));
        LE_MACHINE_JUST_RESET->setText(QCoreApplication::translate("DialogCoffee", "Just Reset", nullptr));
        LE_MACHINE_REQUEST_SET->setText(QCoreApplication::translate("DialogCoffee", "Request Set", nullptr));
        LE_MACHINE_INFO_MSG_SET->setText(QCoreApplication::translate("DialogCoffee", "Info Msg Set", nullptr));
        LE_MACHINE_PRODUCT_DUMP->setText(QCoreApplication::translate("DialogCoffee", "Product Dump", nullptr));
        LE_MACHINE_EDIT_MODE->setText(QCoreApplication::translate("DialogCoffee", "Edit Mode", nullptr));
        LE_MACHINE_WATER_LEVEL->setText(QCoreApplication::translate("DialogCoffee", "Water Level", nullptr));
        LE_MACHINE_STAND_BY->setText(QCoreApplication::translate("DialogCoffee", "Stand By", nullptr));
        label_12->setText(QCoreApplication::translate("DialogCoffee", "Coffee Detail", nullptr));
        LE_COFFEE_DETAIL_UNDEF->setText(QCoreApplication::translate("DialogCoffee", "Undef", nullptr));
        LE_COFFEE_DETAIL_GRINDING->setText(QCoreApplication::translate("DialogCoffee", "Grinding", nullptr));
        LE_COFFEE_DETAIL_TAMPING_PREBREW->setText(QCoreApplication::translate("DialogCoffee", "Tamping&PreBrew", nullptr));
        LE_COFFEE_DETAIL_DISPENSING->setText(QCoreApplication::translate("DialogCoffee", "Dispensing", nullptr));
        LE_COFFEE_DETAIL_PRESS_DROPCAKE->setText(QCoreApplication::translate("DialogCoffee", "Press&DropCake", nullptr));
        LE_COFFEE_DETAIL_UNKNOWN->setText(QCoreApplication::translate("DialogCoffee", "-", nullptr));
        label_14->setText(QCoreApplication::translate("DialogCoffee", "Milk Detail", nullptr));
        LE_MILK_DETAIL_UNDEF->setText(QCoreApplication::translate("DialogCoffee", "Undef", nullptr));
        LE_MILK_DETAIL_SUCTION_DETECTION->setText(QCoreApplication::translate("DialogCoffee", "Suction&Detection", nullptr));
        LE_MILK_DETAIL_DISPENSING->setText(QCoreApplication::translate("DialogCoffee", "Dispensing", nullptr));
        LE_MILK_DETAIL_RINSE->setText(QCoreApplication::translate("DialogCoffee", "Rinse", nullptr));
        LE_MILK_DETAIL_UNKNOWN->setText(QCoreApplication::translate("DialogCoffee", "-", nullptr));
        label_16->setText(QCoreApplication::translate("DialogCoffee", "(M)Coffee L Status", nullptr));
        LE_COFFEE_L_M_STATUS_NOT_READY->setText(QCoreApplication::translate("DialogCoffee", "Not Ready", nullptr));
        LE_COFFEE_L_M_STATUS_READY->setText(QCoreApplication::translate("DialogCoffee", "Ready", nullptr));
        LE_COFFEE_L_M_STATUS_ONLY_COFFEE_READY->setText(QCoreApplication::translate("DialogCoffee", "Only Coffee Ready", nullptr));
        LE_COFFEE_L_M_STATUS_ONLY_MILK_READY->setText(QCoreApplication::translate("DialogCoffee", "Only Milk Ready", nullptr));
        LE_COFFEE_L_M_STATUS_UNDEF->setText(QCoreApplication::translate("DialogCoffee", "Undef", nullptr));
        label_20->setText(QCoreApplication::translate("DialogCoffee", "(M)Water Status", nullptr));
        LE_WATER_M_STATUS_NOT_READY->setText(QCoreApplication::translate("DialogCoffee", "Not Ready", nullptr));
        LE_WATER_M_STATUS_READY->setText(QCoreApplication::translate("DialogCoffee", "Ready", nullptr));
        LE_WATER_M_STATUS_ONLY_COFFEE_READY->setText(QCoreApplication::translate("DialogCoffee", "Only Coffee Ready", nullptr));
        LE_WATER_M_STATUS_ONLY_MILK_READY->setText(QCoreApplication::translate("DialogCoffee", "Only Milk Ready", nullptr));
        LE_WATER_M_STATUS_UNDEF->setText(QCoreApplication::translate("DialogCoffee", "Undef", nullptr));
        label_31->setText(QCoreApplication::translate("DialogCoffee", "(M)Coffee L Process", nullptr));
        label_35->setText(QCoreApplication::translate("DialogCoffee", "(M)Water Process", nullptr));
        LE_WATER_M_PROCESS->setText(QCoreApplication::translate("DialogCoffee", "-", nullptr));
        LE_WATER_M_ACTION->setText(QCoreApplication::translate("DialogCoffee", "-", nullptr));
        label_25->setText(QCoreApplication::translate("DialogCoffee", "(M)Coffee L Action", nullptr));
        LE_COFFEE_L_M_PROCESS->setText(QCoreApplication::translate("DialogCoffee", "-", nullptr));
        LE_COFFEE_L_M_ACTION->setText(QCoreApplication::translate("DialogCoffee", "-", nullptr));
        label_21->setText(QCoreApplication::translate("DialogCoffee", "(M)Water Action", nullptr));
        label_26->setText(QCoreApplication::translate("DialogCoffee", "Coffee L Pro Key", nullptr));
        LE_COFFEE_L_PRODUCT_KEY->setText(QCoreApplication::translate("DialogCoffee", "-", nullptr));
        label_30->setText(QCoreApplication::translate("DialogCoffee", "Water Pro Key", nullptr));
        LE_WATER_PRODUCT_KEY->setText(QCoreApplication::translate("DialogCoffee", "-", nullptr));
        label->setText(QCoreApplication::translate("DialogCoffee", "PIP", nullptr));
        label_2->setText(QCoreApplication::translate("DialogCoffee", "PIE", nullptr));
        label_3->setText(QCoreApplication::translate("DialogCoffee", "PN", nullptr));
        label_4->setText(QCoreApplication::translate("DialogCoffee", "SA", nullptr));
        label_5->setText(QCoreApplication::translate("DialogCoffee", "DA", nullptr));
        label_6->setText(QCoreApplication::translate("DialogCoffee", "MI", nullptr));
        label_7->setText(QCoreApplication::translate("DialogCoffee", "MP", nullptr));
        label_8->setText(QCoreApplication::translate("DialogCoffee", "DL", nullptr));
        label_9->setText(QCoreApplication::translate("DialogCoffee", "Data", nullptr));
        label_10->setText(QCoreApplication::translate("DialogCoffee", "CRC", nullptr));
        label_11->setText(QCoreApplication::translate("DialogCoffee", "Calc CRC", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogCoffee: public Ui_DialogCoffee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCOFFEE_H
