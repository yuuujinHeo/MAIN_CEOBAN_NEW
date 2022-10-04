/********************************************************************************
** Form generated from reading UI file 'DialogIceDispenser.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGICEDISPENSER_H
#define UI_DIALOGICEDISPENSER_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogIceDispenser
{
public:
    QGroupBox *GB_ICE;
    QFrame *line_2;
    QLineEdit *LE_ICE_CONNECTION;
    QLabel *label_110;
    QLabel *LB_ERROR_TYPE;
    QLabel *label_111;
    QLineEdit *LE_ICE_DATA_CONNECTION;
    QFrame *line_5;
    QFrame *line_3;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_27;
    QLabel *LB_STATUS_COMM_MODE;
    QLabel *label_29;
    QLabel *LB_STATUS_COMP_WORKING;
    QLabel *label_30;
    QLabel *LB_STATUS_GEAR_WORKING;
    QLabel *label_28;
    QLabel *LB_STATUS_OUT_SOL_DETECT;
    QLabel *label_25;
    QLabel *LB_STATUS_CUP_LEVER_DETECT;
    QLabel *label_26;
    QLabel *LB_STATUS_FULL_ICE;
    QLabel *label_41;
    QLineEdit *LE_ICE_ERROR;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label_31;
    QLabel *LB_STATUS_LAST_ICE_TIME;
    QLabel *label_32;
    QLabel *label_43;
    QLabel *LB_STATUS_LAST_WATER_TIME;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *LB_STATUS_AMBIENT_TEMP_LOW;
    QLabel *label_36;
    QLabel *LB_STATUS_AMBIENT_TEMP_HIGH;
    QLabel *label_44;
    QLabel *LB_STATUS_AMBIENT_TEMP_NOW;
    QLabel *label_45;
    QLabel *LB_STATUS_EVAPORATOR_TEMP;
    QLabel *label_46;
    QLabel *LB_STATUS_CONDENSOR_TEMP;
    QLabel *label_47;
    QLineEdit *LE_ICE_CHECK_COUNT;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *LE_ICE_TEST_ICE_OUT_TIME;
    QLabel *label_22;
    QLineEdit *LE_ICE_TEST_WATER_OUT_TIME;
    QLabel *label_21;
    QPushButton *BTN_ICE_TEST_ICE_OUT;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_3;
    QLineEdit *LE_ICE_SETTING_ICE_OUT_TIME_MIN;
    QLabel *label_11;
    QLabel *label_18;
    QLineEdit *LE_ICE_SETTING_ICE_OUT_TIME_SEC;
    QLabel *label_12;
    QLabel *label_19;
    QPushButton *BTN_ICE_CHANGE_ICE_OUT_TIME;
    QVBoxLayout *verticalLayout;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout_4;
    QLineEdit *LE_ICE_SETTING_AMBIENT_TEMP_LOW;
    QLabel *label_15;
    QLineEdit *LE_ICE_SETTING_AMBIENT_TEMP_HIGH;
    QLabel *label_14;
    QPushButton *BTN_ICE_CHANGE_AMBIENT_TEMP;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QPushButton *BTN_ICE_CHANGE_COMM_MODE;
    QVBoxLayout *verticalLayout_3;
    QComboBox *CB_ICE_COMM_MODE;
    QComboBox *CB_ICE_CUP_IGNORE;
    QGridLayout *gridLayout_5;
    QLabel *label_23;
    QPushButton *BTN_ICE_TEST_REBOOT;
    QLabel *label_24;
    QPushButton *BTN_ICE_TEST_STATUS_CLEAR;

    void setupUi(QDialog *DialogIceDispenser)
    {
        if (DialogIceDispenser->objectName().isEmpty())
            DialogIceDispenser->setObjectName(QString::fromUtf8("DialogIceDispenser"));
        DialogIceDispenser->resize(400, 960);
        GB_ICE = new QGroupBox(DialogIceDispenser);
        GB_ICE->setObjectName(QString::fromUtf8("GB_ICE"));
        GB_ICE->setGeometry(QRect(0, 0, 400, 960));
        QFont font;
        font.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        GB_ICE->setFont(font);
        GB_ICE->setStyleSheet(QString::fromUtf8("QGroupBox  {\n"
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
"\n"
"\n"
"\n"
""));
        line_2 = new QFrame(GB_ICE);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(20, 330, 351, 20));
        QFont font1;
        font1.setPointSize(9);
        line_2->setFont(font1);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        LE_ICE_CONNECTION = new QLineEdit(GB_ICE);
        LE_ICE_CONNECTION->setObjectName(QString::fromUtf8("LE_ICE_CONNECTION"));
        LE_ICE_CONNECTION->setGeometry(QRect(120, 70, 51, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        LE_ICE_CONNECTION->setFont(font2);
        LE_ICE_CONNECTION->setReadOnly(true);
        label_110 = new QLabel(GB_ICE);
        label_110->setObjectName(QString::fromUtf8("label_110"));
        label_110->setGeometry(QRect(10, 70, 101, 21));
        label_110->setFont(font2);
        label_110->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LB_ERROR_TYPE = new QLabel(GB_ICE);
        LB_ERROR_TYPE->setObjectName(QString::fromUtf8("LB_ERROR_TYPE"));
        LB_ERROR_TYPE->setGeometry(QRect(30, 310, 151, 21));
        LB_ERROR_TYPE->setFont(font2);
        label_111 = new QLabel(GB_ICE);
        label_111->setObjectName(QString::fromUtf8("label_111"));
        label_111->setGeometry(QRect(200, 70, 91, 21));
        label_111->setFont(font2);
        label_111->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_ICE_DATA_CONNECTION = new QLineEdit(GB_ICE);
        LE_ICE_DATA_CONNECTION->setObjectName(QString::fromUtf8("LE_ICE_DATA_CONNECTION"));
        LE_ICE_DATA_CONNECTION->setGeometry(QRect(300, 70, 51, 21));
        LE_ICE_DATA_CONNECTION->setFont(font2);
        LE_ICE_DATA_CONNECTION->setReadOnly(true);
        line_5 = new QFrame(GB_ICE);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(20, 680, 361, 20));
        line_5->setFont(font1);
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(GB_ICE);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(20, 100, 351, 16));
        line_3->setFont(font1);
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(GB_ICE);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 120, 154, 183));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_27 = new QLabel(layoutWidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setFont(font2);
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_27, 0, 0, 1, 1);

        LB_STATUS_COMM_MODE = new QLabel(layoutWidget);
        LB_STATUS_COMM_MODE->setObjectName(QString::fromUtf8("LB_STATUS_COMM_MODE"));
        LB_STATUS_COMM_MODE->setFont(font2);
        LB_STATUS_COMM_MODE->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LB_STATUS_COMM_MODE, 0, 1, 1, 1);

        label_29 = new QLabel(layoutWidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font2);
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_29, 1, 0, 1, 1);

        LB_STATUS_COMP_WORKING = new QLabel(layoutWidget);
        LB_STATUS_COMP_WORKING->setObjectName(QString::fromUtf8("LB_STATUS_COMP_WORKING"));
        LB_STATUS_COMP_WORKING->setFont(font2);
        LB_STATUS_COMP_WORKING->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LB_STATUS_COMP_WORKING, 1, 1, 1, 1);

        label_30 = new QLabel(layoutWidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setFont(font2);
        label_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_30, 2, 0, 1, 1);

        LB_STATUS_GEAR_WORKING = new QLabel(layoutWidget);
        LB_STATUS_GEAR_WORKING->setObjectName(QString::fromUtf8("LB_STATUS_GEAR_WORKING"));
        LB_STATUS_GEAR_WORKING->setFont(font2);
        LB_STATUS_GEAR_WORKING->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LB_STATUS_GEAR_WORKING, 2, 1, 1, 1);

        label_28 = new QLabel(layoutWidget);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font2);
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_28, 3, 0, 1, 1);

        LB_STATUS_OUT_SOL_DETECT = new QLabel(layoutWidget);
        LB_STATUS_OUT_SOL_DETECT->setObjectName(QString::fromUtf8("LB_STATUS_OUT_SOL_DETECT"));
        LB_STATUS_OUT_SOL_DETECT->setFont(font2);
        LB_STATUS_OUT_SOL_DETECT->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LB_STATUS_OUT_SOL_DETECT, 3, 1, 1, 1);

        label_25 = new QLabel(layoutWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setFont(font2);
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_25, 4, 0, 1, 1);

        LB_STATUS_CUP_LEVER_DETECT = new QLabel(layoutWidget);
        LB_STATUS_CUP_LEVER_DETECT->setObjectName(QString::fromUtf8("LB_STATUS_CUP_LEVER_DETECT"));
        LB_STATUS_CUP_LEVER_DETECT->setFont(font2);
        LB_STATUS_CUP_LEVER_DETECT->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LB_STATUS_CUP_LEVER_DETECT, 4, 1, 1, 1);

        label_26 = new QLabel(layoutWidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setFont(font2);
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_26, 5, 0, 1, 1);

        LB_STATUS_FULL_ICE = new QLabel(layoutWidget);
        LB_STATUS_FULL_ICE->setObjectName(QString::fromUtf8("LB_STATUS_FULL_ICE"));
        LB_STATUS_FULL_ICE->setFont(font2);
        LB_STATUS_FULL_ICE->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LB_STATUS_FULL_ICE, 5, 1, 1, 1);

        label_41 = new QLabel(layoutWidget);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setFont(font2);
        label_41->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_41, 6, 0, 1, 1);

        LE_ICE_ERROR = new QLineEdit(layoutWidget);
        LE_ICE_ERROR->setObjectName(QString::fromUtf8("LE_ICE_ERROR"));
        LE_ICE_ERROR->setFont(font2);
        LE_ICE_ERROR->setAlignment(Qt::AlignCenter);
        LE_ICE_ERROR->setReadOnly(true);

        gridLayout->addWidget(LE_ICE_ERROR, 6, 1, 1, 1);

        layoutWidget1 = new QWidget(GB_ICE);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(190, 120, 175, 209));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_31 = new QLabel(layoutWidget1);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setFont(font2);
        label_31->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_31, 0, 0, 1, 1);

        LB_STATUS_LAST_ICE_TIME = new QLabel(layoutWidget1);
        LB_STATUS_LAST_ICE_TIME->setObjectName(QString::fromUtf8("LB_STATUS_LAST_ICE_TIME"));
        LB_STATUS_LAST_ICE_TIME->setFont(font2);
        LB_STATUS_LAST_ICE_TIME->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(LB_STATUS_LAST_ICE_TIME, 0, 1, 1, 1);

        label_32 = new QLabel(layoutWidget1);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setFont(font2);
        label_32->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_32, 0, 2, 1, 1);

        label_43 = new QLabel(layoutWidget1);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setFont(font2);
        label_43->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_43, 1, 0, 1, 1);

        LB_STATUS_LAST_WATER_TIME = new QLabel(layoutWidget1);
        LB_STATUS_LAST_WATER_TIME->setObjectName(QString::fromUtf8("LB_STATUS_LAST_WATER_TIME"));
        LB_STATUS_LAST_WATER_TIME->setFont(font2);
        LB_STATUS_LAST_WATER_TIME->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(LB_STATUS_LAST_WATER_TIME, 1, 1, 1, 1);

        label_33 = new QLabel(layoutWidget1);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setFont(font2);
        label_33->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_33, 1, 2, 1, 1);

        label_34 = new QLabel(layoutWidget1);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setFont(font2);
        label_34->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_34, 2, 0, 1, 1);

        LB_STATUS_AMBIENT_TEMP_LOW = new QLabel(layoutWidget1);
        LB_STATUS_AMBIENT_TEMP_LOW->setObjectName(QString::fromUtf8("LB_STATUS_AMBIENT_TEMP_LOW"));
        LB_STATUS_AMBIENT_TEMP_LOW->setFont(font2);
        LB_STATUS_AMBIENT_TEMP_LOW->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(LB_STATUS_AMBIENT_TEMP_LOW, 2, 1, 1, 1);

        label_36 = new QLabel(layoutWidget1);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setFont(font2);
        label_36->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_36, 3, 0, 1, 1);

        LB_STATUS_AMBIENT_TEMP_HIGH = new QLabel(layoutWidget1);
        LB_STATUS_AMBIENT_TEMP_HIGH->setObjectName(QString::fromUtf8("LB_STATUS_AMBIENT_TEMP_HIGH"));
        LB_STATUS_AMBIENT_TEMP_HIGH->setFont(font2);
        LB_STATUS_AMBIENT_TEMP_HIGH->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(LB_STATUS_AMBIENT_TEMP_HIGH, 3, 1, 1, 1);

        label_44 = new QLabel(layoutWidget1);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setFont(font2);
        label_44->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_44, 4, 0, 1, 1);

        LB_STATUS_AMBIENT_TEMP_NOW = new QLabel(layoutWidget1);
        LB_STATUS_AMBIENT_TEMP_NOW->setObjectName(QString::fromUtf8("LB_STATUS_AMBIENT_TEMP_NOW"));
        LB_STATUS_AMBIENT_TEMP_NOW->setFont(font2);
        LB_STATUS_AMBIENT_TEMP_NOW->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(LB_STATUS_AMBIENT_TEMP_NOW, 4, 1, 1, 1);

        label_45 = new QLabel(layoutWidget1);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setFont(font2);
        label_45->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_45, 5, 0, 1, 1);

        LB_STATUS_EVAPORATOR_TEMP = new QLabel(layoutWidget1);
        LB_STATUS_EVAPORATOR_TEMP->setObjectName(QString::fromUtf8("LB_STATUS_EVAPORATOR_TEMP"));
        LB_STATUS_EVAPORATOR_TEMP->setFont(font2);
        LB_STATUS_EVAPORATOR_TEMP->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(LB_STATUS_EVAPORATOR_TEMP, 5, 1, 1, 1);

        label_46 = new QLabel(layoutWidget1);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setFont(font2);
        label_46->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_46, 6, 0, 1, 1);

        LB_STATUS_CONDENSOR_TEMP = new QLabel(layoutWidget1);
        LB_STATUS_CONDENSOR_TEMP->setObjectName(QString::fromUtf8("LB_STATUS_CONDENSOR_TEMP"));
        LB_STATUS_CONDENSOR_TEMP->setFont(font2);
        LB_STATUS_CONDENSOR_TEMP->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(LB_STATUS_CONDENSOR_TEMP, 6, 1, 1, 1);

        label_47 = new QLabel(layoutWidget1);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setFont(font2);
        label_47->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_47, 7, 0, 1, 1);

        LE_ICE_CHECK_COUNT = new QLineEdit(layoutWidget1);
        LE_ICE_CHECK_COUNT->setObjectName(QString::fromUtf8("LE_ICE_CHECK_COUNT"));
        LE_ICE_CHECK_COUNT->setFont(font2);
        LE_ICE_CHECK_COUNT->setAlignment(Qt::AlignCenter);
        LE_ICE_CHECK_COUNT->setReadOnly(true);

        gridLayout_2->addWidget(LE_ICE_CHECK_COUNT, 7, 1, 1, 2);

        layoutWidget2 = new QWidget(GB_ICE);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(50, 360, 291, 52));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        LE_ICE_TEST_ICE_OUT_TIME = new QLineEdit(layoutWidget2);
        LE_ICE_TEST_ICE_OUT_TIME->setObjectName(QString::fromUtf8("LE_ICE_TEST_ICE_OUT_TIME"));
        LE_ICE_TEST_ICE_OUT_TIME->setMaximumSize(QSize(30, 16777215));
        LE_ICE_TEST_ICE_OUT_TIME->setFont(font2);
        LE_ICE_TEST_ICE_OUT_TIME->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(LE_ICE_TEST_ICE_OUT_TIME);

        label_22 = new QLabel(layoutWidget2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font2);

        horizontalLayout->addWidget(label_22);

        LE_ICE_TEST_WATER_OUT_TIME = new QLineEdit(layoutWidget2);
        LE_ICE_TEST_WATER_OUT_TIME->setObjectName(QString::fromUtf8("LE_ICE_TEST_WATER_OUT_TIME"));
        LE_ICE_TEST_WATER_OUT_TIME->setMaximumSize(QSize(30, 16777215));
        LE_ICE_TEST_WATER_OUT_TIME->setFont(font2);
        LE_ICE_TEST_WATER_OUT_TIME->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(LE_ICE_TEST_WATER_OUT_TIME);

        label_21 = new QLabel(layoutWidget2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font2);

        horizontalLayout->addWidget(label_21);

        BTN_ICE_TEST_ICE_OUT = new QPushButton(layoutWidget2);
        BTN_ICE_TEST_ICE_OUT->setObjectName(QString::fromUtf8("BTN_ICE_TEST_ICE_OUT"));
        BTN_ICE_TEST_ICE_OUT->setMinimumSize(QSize(100, 50));
        BTN_ICE_TEST_ICE_OUT->setFont(font2);

        horizontalLayout->addWidget(BTN_ICE_TEST_ICE_OUT);

        layoutWidget3 = new QWidget(GB_ICE);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 840, 361, 90));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_10 = new QLabel(layoutWidget3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font2);

        verticalLayout_2->addWidget(label_10);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        LE_ICE_SETTING_ICE_OUT_TIME_MIN = new QLineEdit(layoutWidget3);
        LE_ICE_SETTING_ICE_OUT_TIME_MIN->setObjectName(QString::fromUtf8("LE_ICE_SETTING_ICE_OUT_TIME_MIN"));
        LE_ICE_SETTING_ICE_OUT_TIME_MIN->setMaximumSize(QSize(30, 16777215));
        LE_ICE_SETTING_ICE_OUT_TIME_MIN->setFont(font2);
        LE_ICE_SETTING_ICE_OUT_TIME_MIN->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(LE_ICE_SETTING_ICE_OUT_TIME_MIN, 0, 0, 1, 1);

        label_11 = new QLabel(layoutWidget3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font2);

        gridLayout_3->addWidget(label_11, 0, 1, 1, 1);

        label_18 = new QLabel(layoutWidget3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font2);

        gridLayout_3->addWidget(label_18, 0, 2, 1, 1);

        LE_ICE_SETTING_ICE_OUT_TIME_SEC = new QLineEdit(layoutWidget3);
        LE_ICE_SETTING_ICE_OUT_TIME_SEC->setObjectName(QString::fromUtf8("LE_ICE_SETTING_ICE_OUT_TIME_SEC"));
        LE_ICE_SETTING_ICE_OUT_TIME_SEC->setMaximumSize(QSize(30, 16777215));
        LE_ICE_SETTING_ICE_OUT_TIME_SEC->setFont(font2);
        LE_ICE_SETTING_ICE_OUT_TIME_SEC->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(LE_ICE_SETTING_ICE_OUT_TIME_SEC, 1, 0, 1, 1);

        label_12 = new QLabel(layoutWidget3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font2);

        gridLayout_3->addWidget(label_12, 1, 1, 1, 1);

        label_19 = new QLabel(layoutWidget3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font2);

        gridLayout_3->addWidget(label_19, 1, 2, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_3);

        BTN_ICE_CHANGE_ICE_OUT_TIME = new QPushButton(layoutWidget3);
        BTN_ICE_CHANGE_ICE_OUT_TIME->setObjectName(QString::fromUtf8("BTN_ICE_CHANGE_ICE_OUT_TIME"));
        BTN_ICE_CHANGE_ICE_OUT_TIME->setMinimumSize(QSize(50, 50));
        BTN_ICE_CHANGE_ICE_OUT_TIME->setMaximumSize(QSize(50, 16777215));
        BTN_ICE_CHANGE_ICE_OUT_TIME->setFont(font2);

        horizontalLayout_2->addWidget(BTN_ICE_CHANGE_ICE_OUT_TIME);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_13 = new QLabel(layoutWidget3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font2);

        verticalLayout->addWidget(label_13);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        LE_ICE_SETTING_AMBIENT_TEMP_LOW = new QLineEdit(layoutWidget3);
        LE_ICE_SETTING_AMBIENT_TEMP_LOW->setObjectName(QString::fromUtf8("LE_ICE_SETTING_AMBIENT_TEMP_LOW"));
        LE_ICE_SETTING_AMBIENT_TEMP_LOW->setMaximumSize(QSize(30, 16777215));
        LE_ICE_SETTING_AMBIENT_TEMP_LOW->setFont(font2);
        LE_ICE_SETTING_AMBIENT_TEMP_LOW->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(LE_ICE_SETTING_AMBIENT_TEMP_LOW, 0, 0, 1, 1);

        label_15 = new QLabel(layoutWidget3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font2);

        gridLayout_4->addWidget(label_15, 0, 1, 1, 1);

        LE_ICE_SETTING_AMBIENT_TEMP_HIGH = new QLineEdit(layoutWidget3);
        LE_ICE_SETTING_AMBIENT_TEMP_HIGH->setObjectName(QString::fromUtf8("LE_ICE_SETTING_AMBIENT_TEMP_HIGH"));
        LE_ICE_SETTING_AMBIENT_TEMP_HIGH->setMaximumSize(QSize(30, 16777215));
        LE_ICE_SETTING_AMBIENT_TEMP_HIGH->setFont(font2);
        LE_ICE_SETTING_AMBIENT_TEMP_HIGH->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(LE_ICE_SETTING_AMBIENT_TEMP_HIGH, 1, 0, 1, 1);

        label_14 = new QLabel(layoutWidget3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font2);

        gridLayout_4->addWidget(label_14, 1, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_4);

        BTN_ICE_CHANGE_AMBIENT_TEMP = new QPushButton(layoutWidget3);
        BTN_ICE_CHANGE_AMBIENT_TEMP->setObjectName(QString::fromUtf8("BTN_ICE_CHANGE_AMBIENT_TEMP"));
        BTN_ICE_CHANGE_AMBIENT_TEMP->setMinimumSize(QSize(50, 50));
        BTN_ICE_CHANGE_AMBIENT_TEMP->setMaximumSize(QSize(50, 16777215));
        BTN_ICE_CHANGE_AMBIENT_TEMP->setFont(font2);

        horizontalLayout_3->addWidget(BTN_ICE_CHANGE_AMBIENT_TEMP);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);

        layoutWidget4 = new QWidget(GB_ICE);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 710, 361, 120));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_9 = new QLabel(layoutWidget4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);

        horizontalLayout_5->addWidget(label_9);

        BTN_ICE_CHANGE_COMM_MODE = new QPushButton(layoutWidget4);
        BTN_ICE_CHANGE_COMM_MODE->setObjectName(QString::fromUtf8("BTN_ICE_CHANGE_COMM_MODE"));
        BTN_ICE_CHANGE_COMM_MODE->setMinimumSize(QSize(0, 50));
        BTN_ICE_CHANGE_COMM_MODE->setFont(font2);

        horizontalLayout_5->addWidget(BTN_ICE_CHANGE_COMM_MODE);


        verticalLayout_4->addLayout(horizontalLayout_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        CB_ICE_COMM_MODE = new QComboBox(layoutWidget4);
        CB_ICE_COMM_MODE->addItem(QString());
        CB_ICE_COMM_MODE->addItem(QString());
        CB_ICE_COMM_MODE->setObjectName(QString::fromUtf8("CB_ICE_COMM_MODE"));
        CB_ICE_COMM_MODE->setFont(font2);

        verticalLayout_3->addWidget(CB_ICE_COMM_MODE);

        CB_ICE_CUP_IGNORE = new QComboBox(layoutWidget4);
        CB_ICE_CUP_IGNORE->addItem(QString());
        CB_ICE_CUP_IGNORE->addItem(QString());
        CB_ICE_CUP_IGNORE->setObjectName(QString::fromUtf8("CB_ICE_CUP_IGNORE"));
        CB_ICE_CUP_IGNORE->setFont(font2);

        verticalLayout_3->addWidget(CB_ICE_CUP_IGNORE);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_6->addLayout(verticalLayout_4);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_23 = new QLabel(layoutWidget4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font2);

        gridLayout_5->addWidget(label_23, 0, 0, 1, 1);

        BTN_ICE_TEST_REBOOT = new QPushButton(layoutWidget4);
        BTN_ICE_TEST_REBOOT->setObjectName(QString::fromUtf8("BTN_ICE_TEST_REBOOT"));
        BTN_ICE_TEST_REBOOT->setMinimumSize(QSize(0, 50));
        BTN_ICE_TEST_REBOOT->setFont(font2);

        gridLayout_5->addWidget(BTN_ICE_TEST_REBOOT, 0, 1, 1, 1);

        label_24 = new QLabel(layoutWidget4);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setFont(font2);

        gridLayout_5->addWidget(label_24, 1, 0, 1, 1);

        BTN_ICE_TEST_STATUS_CLEAR = new QPushButton(layoutWidget4);
        BTN_ICE_TEST_STATUS_CLEAR->setObjectName(QString::fromUtf8("BTN_ICE_TEST_STATUS_CLEAR"));
        BTN_ICE_TEST_STATUS_CLEAR->setMinimumSize(QSize(0, 50));
        BTN_ICE_TEST_STATUS_CLEAR->setFont(font2);

        gridLayout_5->addWidget(BTN_ICE_TEST_STATUS_CLEAR, 1, 1, 1, 1);


        horizontalLayout_6->addLayout(gridLayout_5);


        retranslateUi(DialogIceDispenser);

        CB_ICE_COMM_MODE->setCurrentIndex(1);
        CB_ICE_CUP_IGNORE->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogIceDispenser);
    } // setupUi

    void retranslateUi(QDialog *DialogIceDispenser)
    {
        DialogIceDispenser->setWindowTitle(QCoreApplication::translate("DialogIceDispenser", "Dialog", nullptr));
        GB_ICE->setTitle(QCoreApplication::translate("DialogIceDispenser", "\354\226\274\354\235\214 \353\224\224\354\212\244\355\216\234\354\204\234", nullptr));
        label_110->setText(QCoreApplication::translate("DialogIceDispenser", "\354\236\245\354\271\230 \354\227\260\352\262\260 \354\203\201\355\203\234", nullptr));
        LB_ERROR_TYPE->setText(QString());
        label_111->setText(QCoreApplication::translate("DialogIceDispenser", "\353\215\260\354\235\264\355\204\260 \354\203\201\355\203\234", nullptr));
        label_27->setText(QCoreApplication::translate("DialogIceDispenser", "\355\206\265\354\213\240\353\252\250\353\223\234: ", nullptr));
        LB_STATUS_COMM_MODE->setText(QCoreApplication::translate("DialogIceDispenser", "RS232", nullptr));
        label_29->setText(QCoreApplication::translate("DialogIceDispenser", "\354\275\244\355\221\270\353\240\210\354\205\224:", nullptr));
        LB_STATUS_COMP_WORKING->setText(QCoreApplication::translate("DialogIceDispenser", "\353\217\231\354\236\221\354\244\221", nullptr));
        label_30->setText(QCoreApplication::translate("DialogIceDispenser", "\352\270\260\354\226\264\353\252\250\355\204\260:", nullptr));
        LB_STATUS_GEAR_WORKING->setText(QCoreApplication::translate("DialogIceDispenser", "\353\217\231\354\236\221\354\244\221", nullptr));
        label_28->setText(QCoreApplication::translate("DialogIceDispenser", "\354\266\234\353\271\231SOL:", nullptr));
        LB_STATUS_OUT_SOL_DETECT->setText(QCoreApplication::translate("DialogIceDispenser", "\352\260\220\354\247\200", nullptr));
        label_25->setText(QCoreApplication::translate("DialogIceDispenser", "\354\273\265\353\240\210\353\262\204:", nullptr));
        LB_STATUS_CUP_LEVER_DETECT->setText(QCoreApplication::translate("DialogIceDispenser", "\352\260\220\354\247\200", nullptr));
        label_26->setText(QCoreApplication::translate("DialogIceDispenser", "\353\247\214\353\271\231:", nullptr));
        LB_STATUS_FULL_ICE->setText(QCoreApplication::translate("DialogIceDispenser", "ON", nullptr));
        label_41->setText(QCoreApplication::translate("DialogIceDispenser", "\354\227\220\353\237\254", nullptr));
        label_31->setText(QCoreApplication::translate("DialogIceDispenser", "\354\266\234\353\271\231 \354\213\234\352\260\204:", nullptr));
        LB_STATUS_LAST_ICE_TIME->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_32->setText(QCoreApplication::translate("DialogIceDispenser", "\354\264\210", nullptr));
        label_43->setText(QCoreApplication::translate("DialogIceDispenser", "\354\266\234\354\210\230 \354\213\234\352\260\204:", nullptr));
        LB_STATUS_LAST_WATER_TIME->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_33->setText(QCoreApplication::translate("DialogIceDispenser", "\354\264\210", nullptr));
        label_34->setText(QCoreApplication::translate("DialogIceDispenser", "\354\230\250\353\217\204 \354\204\244\354\240\225(\354\240\200):", nullptr));
        LB_STATUS_AMBIENT_TEMP_LOW->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_36->setText(QCoreApplication::translate("DialogIceDispenser", "\354\230\250\353\217\204 \354\204\244\354\240\225(\352\263\240):", nullptr));
        LB_STATUS_AMBIENT_TEMP_HIGH->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_44->setText(QCoreApplication::translate("DialogIceDispenser", "\354\230\250\353\217\204 \354\204\244\354\240\225(\355\230\204):", nullptr));
        LB_STATUS_AMBIENT_TEMP_NOW->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_45->setText(QCoreApplication::translate("DialogIceDispenser", "\354\246\235\353\260\234\352\270\260 \354\230\250\353\217\204:", nullptr));
        LB_STATUS_EVAPORATOR_TEMP->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_46->setText(QCoreApplication::translate("DialogIceDispenser", "\354\275\230\353\215\264\354\204\234 \354\230\250\353\217\204:", nullptr));
        LB_STATUS_CONDENSOR_TEMP->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_47->setText(QCoreApplication::translate("DialogIceDispenser", "\354\262\264\355\201\254\354\271\264\354\232\264\355\212\270:", nullptr));
        LE_ICE_CHECK_COUNT->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        LE_ICE_TEST_ICE_OUT_TIME->setText(QCoreApplication::translate("DialogIceDispenser", "3", nullptr));
        label_22->setText(QCoreApplication::translate("DialogIceDispenser", "\354\264\210 (\354\226\274\354\235\214)", nullptr));
        LE_ICE_TEST_WATER_OUT_TIME->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_21->setText(QCoreApplication::translate("DialogIceDispenser", "\354\264\210 (\353\254\274)", nullptr));
        BTN_ICE_TEST_ICE_OUT->setText(QCoreApplication::translate("DialogIceDispenser", "\354\266\234\353\271\231 / \354\266\234\354\210\230", nullptr));
        label_10->setText(QCoreApplication::translate("DialogIceDispenser", "\354\226\274\354\235\214 \355\210\254\354\266\234 \355\203\200\354\236\204 \354\225\204\354\233\203 \354\204\244\354\240\225", nullptr));
        LE_ICE_SETTING_ICE_OUT_TIME_MIN->setText(QCoreApplication::translate("DialogIceDispenser", "1", nullptr));
        label_11->setText(QCoreApplication::translate("DialogIceDispenser", "\353\266\204", nullptr));
        label_18->setText(QCoreApplication::translate("DialogIceDispenser", "(0~9)", nullptr));
        LE_ICE_SETTING_ICE_OUT_TIME_SEC->setText(QCoreApplication::translate("DialogIceDispenser", "10", nullptr));
        label_12->setText(QCoreApplication::translate("DialogIceDispenser", "\354\264\210", nullptr));
        label_19->setText(QCoreApplication::translate("DialogIceDispenser", "(0~59)", nullptr));
        BTN_ICE_CHANGE_ICE_OUT_TIME->setText(QCoreApplication::translate("DialogIceDispenser", "\354\240\201\354\232\251", nullptr));
        label_13->setText(QCoreApplication::translate("DialogIceDispenser", "\353\266\204\354\234\204\352\270\260 \354\230\250\353\217\204 \354\204\244\354\240\225 \353\263\200\352\262\275", nullptr));
        LE_ICE_SETTING_AMBIENT_TEMP_LOW->setText(QCoreApplication::translate("DialogIceDispenser", "5", nullptr));
        label_15->setText(QCoreApplication::translate("DialogIceDispenser", "\354\240\200\354\230\250(0~10)", nullptr));
        LE_ICE_SETTING_AMBIENT_TEMP_HIGH->setText(QCoreApplication::translate("DialogIceDispenser", "50", nullptr));
        label_14->setText(QCoreApplication::translate("DialogIceDispenser", "\352\263\240\354\230\250(40~70)", nullptr));
        BTN_ICE_CHANGE_AMBIENT_TEMP->setText(QCoreApplication::translate("DialogIceDispenser", "\354\240\201\354\232\251", nullptr));
        label_9->setText(QCoreApplication::translate("DialogIceDispenser", "\355\206\265\354\213\240\353\252\250\353\223\234 \353\263\200\352\262\275", nullptr));
        BTN_ICE_CHANGE_COMM_MODE->setText(QCoreApplication::translate("DialogIceDispenser", "\354\240\201\354\232\251", nullptr));
        CB_ICE_COMM_MODE->setItemText(0, QCoreApplication::translate("DialogIceDispenser", "\354\235\274\353\260\230\353\252\250\353\223\234", nullptr));
        CB_ICE_COMM_MODE->setItemText(1, QCoreApplication::translate("DialogIceDispenser", "\355\206\265\354\213\240\353\252\250\353\223\234", nullptr));

        CB_ICE_CUP_IGNORE->setItemText(0, QCoreApplication::translate("DialogIceDispenser", "\354\273\265\354\235\264\355\203\210\354\213\234\354\244\221\354\247\200", nullptr));
        CB_ICE_CUP_IGNORE->setItemText(1, QCoreApplication::translate("DialogIceDispenser", "\354\273\265\354\235\264\355\203\210\353\254\264\354\213\234", nullptr));

        label_23->setText(QCoreApplication::translate("DialogIceDispenser", "\354\240\234\353\271\231\352\270\260 \353\246\254\354\205\213", nullptr));
        BTN_ICE_TEST_REBOOT->setText(QCoreApplication::translate("DialogIceDispenser", "\353\246\254\354\205\213", nullptr));
        label_24->setText(QCoreApplication::translate("DialogIceDispenser", "\354\203\201\355\203\234 \355\201\264\353\246\254\354\226\264", nullptr));
        BTN_ICE_TEST_STATUS_CLEAR->setText(QCoreApplication::translate("DialogIceDispenser", "\355\201\264\353\246\254\354\226\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogIceDispenser: public Ui_DialogIceDispenser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGICEDISPENSER_H
