/********************************************************************************
** Form generated from reading UI file 'DialogStock.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSTOCK_H
#define UI_DIALOGSTOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogStock
{
public:
    QGroupBox *GB_STOCK;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QComboBox *CB_STOCK_NAME;
    QHBoxLayout *horizontalLayout_14;
    QLineEdit *LE_MANUAL_STOCK_AMOUNT;
    QPushButton *BTN_SET_STOCK_MANUAL;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *widget;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_10;
    QLabel *LB_ICE_1;
    QProgressBar *PB_ICE_1;
    QHBoxLayout *horizontalLayout_11;
    QLabel *LB_COFFEE;
    QProgressBar *PB_COFFEE;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_2;
    QPushButton *BTN_MILK_USE;
    QPushButton *BTN_MILK_NOT_USE;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *LB_MILK;
    QProgressBar *PB_MILK;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout;
    QLabel *LB_CUP_1;
    QProgressBar *PB_CUP_1;
    QVBoxLayout *verticalLayout;
    QPushButton *BTN_CUP_HALF_1;
    QPushButton *BTN_CUP_FULL_1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LB_CUP_2;
    QProgressBar *PB_CUP_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *BTN_CUP_HALF_2;
    QPushButton *BTN_CUP_FULL_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *LB_CUP_3;
    QProgressBar *PB_CUP_3;
    QVBoxLayout *verticalLayout_10;
    QPushButton *BTN_CUP_HALF_3;
    QPushButton *BTN_CUP_FULL_3;
    QHBoxLayout *horizontalLayout_15;
    QLabel *LB_CUP_4;
    QProgressBar *PB_CUP_4;
    QVBoxLayout *verticalLayout_11;
    QPushButton *BTN_CUP_HALF_4;
    QPushButton *BTN_CUP_FULL_4;
    QWidget *tab_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QPushButton *BTN_SYRUP_USE;
    QPushButton *BTN_SYRUP_NOT_USE;
    QFrame *frame;
    QWidget *widget4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *LB_SYRUP_1;
    QProgressBar *PB_SYRUP_1;
    QPushButton *BTN_SYRUP_ADD_1;
    QPushButton *BTN_SYRUP_REPLACE_1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *LB_SYRUP_2;
    QProgressBar *PB_SYRUP_2;
    QPushButton *BTN_SYRUP_ADD_2;
    QPushButton *BTN_SYRUP_REPLACE_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *LB_SYRUP_3;
    QProgressBar *PB_SYRUP_3;
    QPushButton *BTN_SYRUP_ADD_3;
    QPushButton *BTN_SYRUP_REPLACE_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *LB_SYRUP_4;
    QProgressBar *PB_SYRUP_4;
    QPushButton *BTN_SYRUP_ADD_4;
    QPushButton *BTN_SYRUP_REPLACE_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *LB_SYRUP_5;
    QProgressBar *PB_SYRUP_5;
    QPushButton *BTN_SYRUP_ADD_5;
    QPushButton *BTN_SYRUP_REPLACE_5;
    QHBoxLayout *horizontalLayout_16;
    QLabel *LB_SYRUP_6;
    QProgressBar *PB_SYRUP_6;
    QPushButton *BTN_SYRUP_ADD_6;
    QPushButton *BTN_SYRUP_REPLACE_6;
    QHBoxLayout *horizontalLayout_17;
    QLabel *LB_SYRUP_7;
    QProgressBar *PB_SYRUP_7;
    QPushButton *BTN_SYRUP_ADD_7;
    QPushButton *BTN_SYRUP_REPLACE_7;
    QHBoxLayout *horizontalLayout_18;
    QLabel *LB_SYRUP_8;
    QProgressBar *PB_SYRUP_8;
    QPushButton *BTN_SYRUP_ADD_8;
    QPushButton *BTN_SYRUP_REPLACE_8;
    QHBoxLayout *horizontalLayout_19;
    QLabel *LB_SYRUP_9;
    QProgressBar *PB_SYRUP_9;
    QPushButton *BTN_SYRUP_ADD_9;
    QPushButton *BTN_SYRUP_REPLACE_9;
    QHBoxLayout *horizontalLayout_20;
    QLabel *LB_SYRUP_10;
    QProgressBar *PB_SYRUP_10;
    QPushButton *BTN_SYRUP_ADD_10;
    QPushButton *BTN_SYRUP_REPLACE_10;
    QHBoxLayout *horizontalLayout_21;
    QLabel *LB_SYRUP_11;
    QProgressBar *PB_SYRUP_11;
    QPushButton *BTN_SYRUP_ADD_11;
    QPushButton *BTN_SYRUP_REPLACE_11;
    QHBoxLayout *horizontalLayout_22;
    QLabel *LB_SYRUP_12;
    QProgressBar *PB_SYRUP_12;
    QPushButton *BTN_SYRUP_ADD_12;
    QPushButton *BTN_SYRUP_REPLACE_12;

    void setupUi(QDialog *DialogStock)
    {
        if (DialogStock->objectName().isEmpty())
            DialogStock->setObjectName(QString::fromUtf8("DialogStock"));
        DialogStock->resize(400, 960);
        GB_STOCK = new QGroupBox(DialogStock);
        GB_STOCK->setObjectName(QString::fromUtf8("GB_STOCK"));
        GB_STOCK->setGeometry(QRect(0, 0, 400, 960));
        QFont font;
        font.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        GB_STOCK->setFont(font);
        GB_STOCK->setStyleSheet(QString::fromUtf8("QGroupBox  {\n"
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
        layoutWidget = new QWidget(GB_STOCK);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 840, 361, 101));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        CB_STOCK_NAME = new QComboBox(layoutWidget);
        CB_STOCK_NAME->setObjectName(QString::fromUtf8("CB_STOCK_NAME"));
        CB_STOCK_NAME->setMinimumSize(QSize(50, 40));

        verticalLayout_3->addWidget(CB_STOCK_NAME);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        LE_MANUAL_STOCK_AMOUNT = new QLineEdit(layoutWidget);
        LE_MANUAL_STOCK_AMOUNT->setObjectName(QString::fromUtf8("LE_MANUAL_STOCK_AMOUNT"));
        LE_MANUAL_STOCK_AMOUNT->setMinimumSize(QSize(0, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        LE_MANUAL_STOCK_AMOUNT->setFont(font1);
        LE_MANUAL_STOCK_AMOUNT->setReadOnly(false);

        horizontalLayout_14->addWidget(LE_MANUAL_STOCK_AMOUNT);

        BTN_SET_STOCK_MANUAL = new QPushButton(layoutWidget);
        BTN_SET_STOCK_MANUAL->setObjectName(QString::fromUtf8("BTN_SET_STOCK_MANUAL"));
        BTN_SET_STOCK_MANUAL->setMinimumSize(QSize(100, 50));

        horizontalLayout_14->addWidget(BTN_SET_STOCK_MANUAL);


        verticalLayout_3->addLayout(horizontalLayout_14);

        tabWidget = new QTabWidget(GB_STOCK);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 70, 381, 761));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 320, 359, 107));
        verticalLayout_7 = new QVBoxLayout(widget);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        LB_ICE_1 = new QLabel(widget);
        LB_ICE_1->setObjectName(QString::fromUtf8("LB_ICE_1"));

        horizontalLayout_10->addWidget(LB_ICE_1);

        PB_ICE_1 = new QProgressBar(widget);
        PB_ICE_1->setObjectName(QString::fromUtf8("PB_ICE_1"));
        PB_ICE_1->setMaximumSize(QSize(200, 16777215));
        PB_ICE_1->setValue(24);

        horizontalLayout_10->addWidget(PB_ICE_1);


        verticalLayout_7->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        LB_COFFEE = new QLabel(widget);
        LB_COFFEE->setObjectName(QString::fromUtf8("LB_COFFEE"));

        horizontalLayout_11->addWidget(LB_COFFEE);

        PB_COFFEE = new QProgressBar(widget);
        PB_COFFEE->setObjectName(QString::fromUtf8("PB_COFFEE"));
        PB_COFFEE->setMaximumSize(QSize(200, 16777215));
        PB_COFFEE->setValue(24);

        horizontalLayout_11->addWidget(PB_COFFEE);


        verticalLayout_7->addLayout(horizontalLayout_11);

        widget1 = new QWidget(tab);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 445, 357, 31));
        horizontalLayout_13 = new QHBoxLayout(widget1);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_13->addWidget(label_2);

        BTN_MILK_USE = new QPushButton(widget1);
        BTN_MILK_USE->setObjectName(QString::fromUtf8("BTN_MILK_USE"));
        BTN_MILK_USE->setMinimumSize(QSize(100, 30));
        BTN_MILK_USE->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_13->addWidget(BTN_MILK_USE);

        BTN_MILK_NOT_USE = new QPushButton(widget1);
        BTN_MILK_NOT_USE->setObjectName(QString::fromUtf8("BTN_MILK_NOT_USE"));
        BTN_MILK_NOT_USE->setMinimumSize(QSize(100, 30));
        BTN_MILK_NOT_USE->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_13->addWidget(BTN_MILK_NOT_USE);

        widget2 = new QWidget(tab);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(10, 490, 357, 61));
        horizontalLayout_12 = new QHBoxLayout(widget2);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        LB_MILK = new QLabel(widget2);
        LB_MILK->setObjectName(QString::fromUtf8("LB_MILK"));

        horizontalLayout_12->addWidget(LB_MILK);

        PB_MILK = new QProgressBar(widget2);
        PB_MILK->setObjectName(QString::fromUtf8("PB_MILK"));
        PB_MILK->setMaximumSize(QSize(200, 16777215));
        PB_MILK->setValue(24);

        horizontalLayout_12->addWidget(PB_MILK);

        widget3 = new QWidget(tab);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(10, 10, 361, 300));
        verticalLayout_9 = new QVBoxLayout(widget3);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LB_CUP_1 = new QLabel(widget3);
        LB_CUP_1->setObjectName(QString::fromUtf8("LB_CUP_1"));

        horizontalLayout->addWidget(LB_CUP_1);

        PB_CUP_1 = new QProgressBar(widget3);
        PB_CUP_1->setObjectName(QString::fromUtf8("PB_CUP_1"));
        PB_CUP_1->setMaximumSize(QSize(150, 16777215));
        PB_CUP_1->setValue(24);

        horizontalLayout->addWidget(PB_CUP_1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        BTN_CUP_HALF_1 = new QPushButton(widget3);
        BTN_CUP_HALF_1->setObjectName(QString::fromUtf8("BTN_CUP_HALF_1"));
        BTN_CUP_HALF_1->setMinimumSize(QSize(100, 30));
        BTN_CUP_HALF_1->setMaximumSize(QSize(100, 16777215));

        verticalLayout->addWidget(BTN_CUP_HALF_1);

        BTN_CUP_FULL_1 = new QPushButton(widget3);
        BTN_CUP_FULL_1->setObjectName(QString::fromUtf8("BTN_CUP_FULL_1"));
        BTN_CUP_FULL_1->setMinimumSize(QSize(100, 30));
        BTN_CUP_FULL_1->setMaximumSize(QSize(100, 16777215));

        verticalLayout->addWidget(BTN_CUP_FULL_1);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_9->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LB_CUP_2 = new QLabel(widget3);
        LB_CUP_2->setObjectName(QString::fromUtf8("LB_CUP_2"));

        horizontalLayout_2->addWidget(LB_CUP_2);

        PB_CUP_2 = new QProgressBar(widget3);
        PB_CUP_2->setObjectName(QString::fromUtf8("PB_CUP_2"));
        PB_CUP_2->setMaximumSize(QSize(150, 16777215));
        PB_CUP_2->setValue(24);

        horizontalLayout_2->addWidget(PB_CUP_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        BTN_CUP_HALF_2 = new QPushButton(widget3);
        BTN_CUP_HALF_2->setObjectName(QString::fromUtf8("BTN_CUP_HALF_2"));
        BTN_CUP_HALF_2->setMinimumSize(QSize(100, 30));
        BTN_CUP_HALF_2->setMaximumSize(QSize(100, 16777215));

        verticalLayout_2->addWidget(BTN_CUP_HALF_2);

        BTN_CUP_FULL_2 = new QPushButton(widget3);
        BTN_CUP_FULL_2->setObjectName(QString::fromUtf8("BTN_CUP_FULL_2"));
        BTN_CUP_FULL_2->setMinimumSize(QSize(100, 30));
        BTN_CUP_FULL_2->setMaximumSize(QSize(100, 16777215));

        verticalLayout_2->addWidget(BTN_CUP_FULL_2);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_9->addLayout(horizontalLayout_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        LB_CUP_3 = new QLabel(widget3);
        LB_CUP_3->setObjectName(QString::fromUtf8("LB_CUP_3"));

        horizontalLayout_9->addWidget(LB_CUP_3);

        PB_CUP_3 = new QProgressBar(widget3);
        PB_CUP_3->setObjectName(QString::fromUtf8("PB_CUP_3"));
        PB_CUP_3->setMaximumSize(QSize(150, 16777215));
        PB_CUP_3->setValue(24);

        horizontalLayout_9->addWidget(PB_CUP_3);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        BTN_CUP_HALF_3 = new QPushButton(widget3);
        BTN_CUP_HALF_3->setObjectName(QString::fromUtf8("BTN_CUP_HALF_3"));
        BTN_CUP_HALF_3->setMinimumSize(QSize(100, 30));
        BTN_CUP_HALF_3->setMaximumSize(QSize(100, 16777215));

        verticalLayout_10->addWidget(BTN_CUP_HALF_3);

        BTN_CUP_FULL_3 = new QPushButton(widget3);
        BTN_CUP_FULL_3->setObjectName(QString::fromUtf8("BTN_CUP_FULL_3"));
        BTN_CUP_FULL_3->setMinimumSize(QSize(100, 30));
        BTN_CUP_FULL_3->setMaximumSize(QSize(100, 16777215));

        verticalLayout_10->addWidget(BTN_CUP_FULL_3);


        horizontalLayout_9->addLayout(verticalLayout_10);


        verticalLayout_9->addLayout(horizontalLayout_9);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        LB_CUP_4 = new QLabel(widget3);
        LB_CUP_4->setObjectName(QString::fromUtf8("LB_CUP_4"));

        horizontalLayout_15->addWidget(LB_CUP_4);

        PB_CUP_4 = new QProgressBar(widget3);
        PB_CUP_4->setObjectName(QString::fromUtf8("PB_CUP_4"));
        PB_CUP_4->setMaximumSize(QSize(150, 16777215));
        PB_CUP_4->setValue(24);

        horizontalLayout_15->addWidget(PB_CUP_4);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        BTN_CUP_HALF_4 = new QPushButton(widget3);
        BTN_CUP_HALF_4->setObjectName(QString::fromUtf8("BTN_CUP_HALF_4"));
        BTN_CUP_HALF_4->setMinimumSize(QSize(100, 30));
        BTN_CUP_HALF_4->setMaximumSize(QSize(100, 16777215));

        verticalLayout_11->addWidget(BTN_CUP_HALF_4);

        BTN_CUP_FULL_4 = new QPushButton(widget3);
        BTN_CUP_FULL_4->setObjectName(QString::fromUtf8("BTN_CUP_FULL_4"));
        BTN_CUP_FULL_4->setMinimumSize(QSize(100, 30));
        BTN_CUP_FULL_4->setMaximumSize(QSize(100, 16777215));

        verticalLayout_11->addWidget(BTN_CUP_FULL_4);


        horizontalLayout_15->addLayout(verticalLayout_11);


        verticalLayout_9->addLayout(horizontalLayout_15);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 357, 32));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label);

        BTN_SYRUP_USE = new QPushButton(layoutWidget1);
        BTN_SYRUP_USE->setObjectName(QString::fromUtf8("BTN_SYRUP_USE"));
        BTN_SYRUP_USE->setMinimumSize(QSize(100, 30));
        BTN_SYRUP_USE->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(BTN_SYRUP_USE);

        BTN_SYRUP_NOT_USE = new QPushButton(layoutWidget1);
        BTN_SYRUP_NOT_USE->setObjectName(QString::fromUtf8("BTN_SYRUP_NOT_USE"));
        BTN_SYRUP_NOT_USE->setMinimumSize(QSize(100, 30));
        BTN_SYRUP_NOT_USE->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(BTN_SYRUP_NOT_USE);

        frame = new QFrame(tab_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 50, 361, 641));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        widget4 = new QWidget(frame);
        widget4->setObjectName(QString::fromUtf8("widget4"));
        widget4->setGeometry(QRect(0, 10, 361, 611));
        verticalLayout_4 = new QVBoxLayout(widget4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        LB_SYRUP_1 = new QLabel(widget4);
        LB_SYRUP_1->setObjectName(QString::fromUtf8("LB_SYRUP_1"));
        LB_SYRUP_1->setFont(font1);

        horizontalLayout_4->addWidget(LB_SYRUP_1);

        PB_SYRUP_1 = new QProgressBar(widget4);
        PB_SYRUP_1->setObjectName(QString::fromUtf8("PB_SYRUP_1"));
        PB_SYRUP_1->setMaximumSize(QSize(150, 16777215));
        PB_SYRUP_1->setValue(24);

        horizontalLayout_4->addWidget(PB_SYRUP_1);

        BTN_SYRUP_ADD_1 = new QPushButton(widget4);
        BTN_SYRUP_ADD_1->setObjectName(QString::fromUtf8("BTN_SYRUP_ADD_1"));
        BTN_SYRUP_ADD_1->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_ADD_1->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(BTN_SYRUP_ADD_1);

        BTN_SYRUP_REPLACE_1 = new QPushButton(widget4);
        BTN_SYRUP_REPLACE_1->setObjectName(QString::fromUtf8("BTN_SYRUP_REPLACE_1"));
        BTN_SYRUP_REPLACE_1->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_REPLACE_1->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(BTN_SYRUP_REPLACE_1);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        LB_SYRUP_2 = new QLabel(widget4);
        LB_SYRUP_2->setObjectName(QString::fromUtf8("LB_SYRUP_2"));
        LB_SYRUP_2->setFont(font1);

        horizontalLayout_5->addWidget(LB_SYRUP_2);

        PB_SYRUP_2 = new QProgressBar(widget4);
        PB_SYRUP_2->setObjectName(QString::fromUtf8("PB_SYRUP_2"));
        PB_SYRUP_2->setMaximumSize(QSize(150, 16777215));
        PB_SYRUP_2->setValue(24);

        horizontalLayout_5->addWidget(PB_SYRUP_2);

        BTN_SYRUP_ADD_2 = new QPushButton(widget4);
        BTN_SYRUP_ADD_2->setObjectName(QString::fromUtf8("BTN_SYRUP_ADD_2"));
        BTN_SYRUP_ADD_2->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_ADD_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(BTN_SYRUP_ADD_2);

        BTN_SYRUP_REPLACE_2 = new QPushButton(widget4);
        BTN_SYRUP_REPLACE_2->setObjectName(QString::fromUtf8("BTN_SYRUP_REPLACE_2"));
        BTN_SYRUP_REPLACE_2->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_REPLACE_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(BTN_SYRUP_REPLACE_2);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        LB_SYRUP_3 = new QLabel(widget4);
        LB_SYRUP_3->setObjectName(QString::fromUtf8("LB_SYRUP_3"));
        LB_SYRUP_3->setFont(font1);

        horizontalLayout_6->addWidget(LB_SYRUP_3);

        PB_SYRUP_3 = new QProgressBar(widget4);
        PB_SYRUP_3->setObjectName(QString::fromUtf8("PB_SYRUP_3"));
        PB_SYRUP_3->setMaximumSize(QSize(150, 16777215));
        PB_SYRUP_3->setValue(24);

        horizontalLayout_6->addWidget(PB_SYRUP_3);

        BTN_SYRUP_ADD_3 = new QPushButton(widget4);
        BTN_SYRUP_ADD_3->setObjectName(QString::fromUtf8("BTN_SYRUP_ADD_3"));
        BTN_SYRUP_ADD_3->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_ADD_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(BTN_SYRUP_ADD_3);

        BTN_SYRUP_REPLACE_3 = new QPushButton(widget4);
        BTN_SYRUP_REPLACE_3->setObjectName(QString::fromUtf8("BTN_SYRUP_REPLACE_3"));
        BTN_SYRUP_REPLACE_3->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_REPLACE_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(BTN_SYRUP_REPLACE_3);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        LB_SYRUP_4 = new QLabel(widget4);
        LB_SYRUP_4->setObjectName(QString::fromUtf8("LB_SYRUP_4"));
        LB_SYRUP_4->setFont(font1);

        horizontalLayout_7->addWidget(LB_SYRUP_4);

        PB_SYRUP_4 = new QProgressBar(widget4);
        PB_SYRUP_4->setObjectName(QString::fromUtf8("PB_SYRUP_4"));
        PB_SYRUP_4->setMaximumSize(QSize(150, 16777215));
        PB_SYRUP_4->setValue(24);

        horizontalLayout_7->addWidget(PB_SYRUP_4);

        BTN_SYRUP_ADD_4 = new QPushButton(widget4);
        BTN_SYRUP_ADD_4->setObjectName(QString::fromUtf8("BTN_SYRUP_ADD_4"));
        BTN_SYRUP_ADD_4->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_ADD_4->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_7->addWidget(BTN_SYRUP_ADD_4);

        BTN_SYRUP_REPLACE_4 = new QPushButton(widget4);
        BTN_SYRUP_REPLACE_4->setObjectName(QString::fromUtf8("BTN_SYRUP_REPLACE_4"));
        BTN_SYRUP_REPLACE_4->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_REPLACE_4->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_7->addWidget(BTN_SYRUP_REPLACE_4);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        LB_SYRUP_5 = new QLabel(widget4);
        LB_SYRUP_5->setObjectName(QString::fromUtf8("LB_SYRUP_5"));
        LB_SYRUP_5->setFont(font1);

        horizontalLayout_8->addWidget(LB_SYRUP_5);

        PB_SYRUP_5 = new QProgressBar(widget4);
        PB_SYRUP_5->setObjectName(QString::fromUtf8("PB_SYRUP_5"));
        PB_SYRUP_5->setMaximumSize(QSize(150, 16777215));
        PB_SYRUP_5->setValue(24);

        horizontalLayout_8->addWidget(PB_SYRUP_5);

        BTN_SYRUP_ADD_5 = new QPushButton(widget4);
        BTN_SYRUP_ADD_5->setObjectName(QString::fromUtf8("BTN_SYRUP_ADD_5"));
        BTN_SYRUP_ADD_5->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_ADD_5->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(BTN_SYRUP_ADD_5);

        BTN_SYRUP_REPLACE_5 = new QPushButton(widget4);
        BTN_SYRUP_REPLACE_5->setObjectName(QString::fromUtf8("BTN_SYRUP_REPLACE_5"));
        BTN_SYRUP_REPLACE_5->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_REPLACE_5->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(BTN_SYRUP_REPLACE_5);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        LB_SYRUP_6 = new QLabel(widget4);
        LB_SYRUP_6->setObjectName(QString::fromUtf8("LB_SYRUP_6"));
        LB_SYRUP_6->setFont(font1);

        horizontalLayout_16->addWidget(LB_SYRUP_6);

        PB_SYRUP_6 = new QProgressBar(widget4);
        PB_SYRUP_6->setObjectName(QString::fromUtf8("PB_SYRUP_6"));
        PB_SYRUP_6->setMaximumSize(QSize(150, 16777215));
        PB_SYRUP_6->setValue(24);

        horizontalLayout_16->addWidget(PB_SYRUP_6);

        BTN_SYRUP_ADD_6 = new QPushButton(widget4);
        BTN_SYRUP_ADD_6->setObjectName(QString::fromUtf8("BTN_SYRUP_ADD_6"));
        BTN_SYRUP_ADD_6->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_ADD_6->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_16->addWidget(BTN_SYRUP_ADD_6);

        BTN_SYRUP_REPLACE_6 = new QPushButton(widget4);
        BTN_SYRUP_REPLACE_6->setObjectName(QString::fromUtf8("BTN_SYRUP_REPLACE_6"));
        BTN_SYRUP_REPLACE_6->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_REPLACE_6->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_16->addWidget(BTN_SYRUP_REPLACE_6);


        verticalLayout_4->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        LB_SYRUP_7 = new QLabel(widget4);
        LB_SYRUP_7->setObjectName(QString::fromUtf8("LB_SYRUP_7"));
        LB_SYRUP_7->setFont(font1);

        horizontalLayout_17->addWidget(LB_SYRUP_7);

        PB_SYRUP_7 = new QProgressBar(widget4);
        PB_SYRUP_7->setObjectName(QString::fromUtf8("PB_SYRUP_7"));
        PB_SYRUP_7->setMaximumSize(QSize(150, 16777215));
        PB_SYRUP_7->setValue(24);

        horizontalLayout_17->addWidget(PB_SYRUP_7);

        BTN_SYRUP_ADD_7 = new QPushButton(widget4);
        BTN_SYRUP_ADD_7->setObjectName(QString::fromUtf8("BTN_SYRUP_ADD_7"));
        BTN_SYRUP_ADD_7->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_ADD_7->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_17->addWidget(BTN_SYRUP_ADD_7);

        BTN_SYRUP_REPLACE_7 = new QPushButton(widget4);
        BTN_SYRUP_REPLACE_7->setObjectName(QString::fromUtf8("BTN_SYRUP_REPLACE_7"));
        BTN_SYRUP_REPLACE_7->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_REPLACE_7->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_17->addWidget(BTN_SYRUP_REPLACE_7);


        verticalLayout_4->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        LB_SYRUP_8 = new QLabel(widget4);
        LB_SYRUP_8->setObjectName(QString::fromUtf8("LB_SYRUP_8"));
        LB_SYRUP_8->setFont(font1);

        horizontalLayout_18->addWidget(LB_SYRUP_8);

        PB_SYRUP_8 = new QProgressBar(widget4);
        PB_SYRUP_8->setObjectName(QString::fromUtf8("PB_SYRUP_8"));
        PB_SYRUP_8->setMaximumSize(QSize(150, 16777215));
        PB_SYRUP_8->setValue(24);

        horizontalLayout_18->addWidget(PB_SYRUP_8);

        BTN_SYRUP_ADD_8 = new QPushButton(widget4);
        BTN_SYRUP_ADD_8->setObjectName(QString::fromUtf8("BTN_SYRUP_ADD_8"));
        BTN_SYRUP_ADD_8->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_ADD_8->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_18->addWidget(BTN_SYRUP_ADD_8);

        BTN_SYRUP_REPLACE_8 = new QPushButton(widget4);
        BTN_SYRUP_REPLACE_8->setObjectName(QString::fromUtf8("BTN_SYRUP_REPLACE_8"));
        BTN_SYRUP_REPLACE_8->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_REPLACE_8->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_18->addWidget(BTN_SYRUP_REPLACE_8);


        verticalLayout_4->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        LB_SYRUP_9 = new QLabel(widget4);
        LB_SYRUP_9->setObjectName(QString::fromUtf8("LB_SYRUP_9"));
        LB_SYRUP_9->setFont(font1);

        horizontalLayout_19->addWidget(LB_SYRUP_9);

        PB_SYRUP_9 = new QProgressBar(widget4);
        PB_SYRUP_9->setObjectName(QString::fromUtf8("PB_SYRUP_9"));
        PB_SYRUP_9->setMaximumSize(QSize(150, 16777215));
        PB_SYRUP_9->setValue(24);

        horizontalLayout_19->addWidget(PB_SYRUP_9);

        BTN_SYRUP_ADD_9 = new QPushButton(widget4);
        BTN_SYRUP_ADD_9->setObjectName(QString::fromUtf8("BTN_SYRUP_ADD_9"));
        BTN_SYRUP_ADD_9->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_ADD_9->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_19->addWidget(BTN_SYRUP_ADD_9);

        BTN_SYRUP_REPLACE_9 = new QPushButton(widget4);
        BTN_SYRUP_REPLACE_9->setObjectName(QString::fromUtf8("BTN_SYRUP_REPLACE_9"));
        BTN_SYRUP_REPLACE_9->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_REPLACE_9->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_19->addWidget(BTN_SYRUP_REPLACE_9);


        verticalLayout_4->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        LB_SYRUP_10 = new QLabel(widget4);
        LB_SYRUP_10->setObjectName(QString::fromUtf8("LB_SYRUP_10"));
        LB_SYRUP_10->setFont(font1);

        horizontalLayout_20->addWidget(LB_SYRUP_10);

        PB_SYRUP_10 = new QProgressBar(widget4);
        PB_SYRUP_10->setObjectName(QString::fromUtf8("PB_SYRUP_10"));
        PB_SYRUP_10->setMaximumSize(QSize(150, 16777215));
        PB_SYRUP_10->setValue(24);

        horizontalLayout_20->addWidget(PB_SYRUP_10);

        BTN_SYRUP_ADD_10 = new QPushButton(widget4);
        BTN_SYRUP_ADD_10->setObjectName(QString::fromUtf8("BTN_SYRUP_ADD_10"));
        BTN_SYRUP_ADD_10->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_ADD_10->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_20->addWidget(BTN_SYRUP_ADD_10);

        BTN_SYRUP_REPLACE_10 = new QPushButton(widget4);
        BTN_SYRUP_REPLACE_10->setObjectName(QString::fromUtf8("BTN_SYRUP_REPLACE_10"));
        BTN_SYRUP_REPLACE_10->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_REPLACE_10->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_20->addWidget(BTN_SYRUP_REPLACE_10);


        verticalLayout_4->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        LB_SYRUP_11 = new QLabel(widget4);
        LB_SYRUP_11->setObjectName(QString::fromUtf8("LB_SYRUP_11"));
        LB_SYRUP_11->setFont(font1);

        horizontalLayout_21->addWidget(LB_SYRUP_11);

        PB_SYRUP_11 = new QProgressBar(widget4);
        PB_SYRUP_11->setObjectName(QString::fromUtf8("PB_SYRUP_11"));
        PB_SYRUP_11->setMaximumSize(QSize(150, 16777215));
        PB_SYRUP_11->setValue(24);

        horizontalLayout_21->addWidget(PB_SYRUP_11);

        BTN_SYRUP_ADD_11 = new QPushButton(widget4);
        BTN_SYRUP_ADD_11->setObjectName(QString::fromUtf8("BTN_SYRUP_ADD_11"));
        BTN_SYRUP_ADD_11->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_ADD_11->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_21->addWidget(BTN_SYRUP_ADD_11);

        BTN_SYRUP_REPLACE_11 = new QPushButton(widget4);
        BTN_SYRUP_REPLACE_11->setObjectName(QString::fromUtf8("BTN_SYRUP_REPLACE_11"));
        BTN_SYRUP_REPLACE_11->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_REPLACE_11->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_21->addWidget(BTN_SYRUP_REPLACE_11);


        verticalLayout_4->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        LB_SYRUP_12 = new QLabel(widget4);
        LB_SYRUP_12->setObjectName(QString::fromUtf8("LB_SYRUP_12"));
        LB_SYRUP_12->setFont(font1);

        horizontalLayout_22->addWidget(LB_SYRUP_12);

        PB_SYRUP_12 = new QProgressBar(widget4);
        PB_SYRUP_12->setObjectName(QString::fromUtf8("PB_SYRUP_12"));
        PB_SYRUP_12->setMaximumSize(QSize(150, 16777215));
        PB_SYRUP_12->setValue(24);

        horizontalLayout_22->addWidget(PB_SYRUP_12);

        BTN_SYRUP_ADD_12 = new QPushButton(widget4);
        BTN_SYRUP_ADD_12->setObjectName(QString::fromUtf8("BTN_SYRUP_ADD_12"));
        BTN_SYRUP_ADD_12->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_ADD_12->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_22->addWidget(BTN_SYRUP_ADD_12);

        BTN_SYRUP_REPLACE_12 = new QPushButton(widget4);
        BTN_SYRUP_REPLACE_12->setObjectName(QString::fromUtf8("BTN_SYRUP_REPLACE_12"));
        BTN_SYRUP_REPLACE_12->setMinimumSize(QSize(60, 40));
        BTN_SYRUP_REPLACE_12->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_22->addWidget(BTN_SYRUP_REPLACE_12);


        verticalLayout_4->addLayout(horizontalLayout_22);

        tabWidget->addTab(tab_2, QString());

        retranslateUi(DialogStock);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DialogStock);
    } // setupUi

    void retranslateUi(QDialog *DialogStock)
    {
        DialogStock->setWindowTitle(QCoreApplication::translate("DialogStock", "Dialog", nullptr));
        GB_STOCK->setTitle(QCoreApplication::translate("DialogStock", "\354\236\254\352\263\240", nullptr));
        BTN_SET_STOCK_MANUAL->setText(QCoreApplication::translate("DialogStock", "\354\210\230\353\217\231 \354\236\254\352\263\240 \354\247\200\354\240\225", nullptr));
        LB_ICE_1->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_ICE_1->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        LB_COFFEE->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_COFFEE->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        label_2->setText(QCoreApplication::translate("DialogStock", "\354\232\260\354\234\240 :", nullptr));
        BTN_MILK_USE->setText(QCoreApplication::translate("DialogStock", "\354\202\254\354\232\251", nullptr));
        BTN_MILK_NOT_USE->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        LB_MILK->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_MILK->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        LB_CUP_1->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_CUP_1->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_CUP_HALF_1->setText(QCoreApplication::translate("DialogStock", "\354\240\210\353\260\230", nullptr));
        BTN_CUP_FULL_1->setText(QCoreApplication::translate("DialogStock", "FULL", nullptr));
        LB_CUP_2->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_CUP_2->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_CUP_HALF_2->setText(QCoreApplication::translate("DialogStock", "\354\240\210\353\260\230", nullptr));
        BTN_CUP_FULL_2->setText(QCoreApplication::translate("DialogStock", "FULL", nullptr));
        LB_CUP_3->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_CUP_3->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_CUP_HALF_3->setText(QCoreApplication::translate("DialogStock", "\354\240\210\353\260\230", nullptr));
        BTN_CUP_FULL_3->setText(QCoreApplication::translate("DialogStock", "FULL", nullptr));
        LB_CUP_4->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_CUP_4->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_CUP_HALF_4->setText(QCoreApplication::translate("DialogStock", "\354\240\210\353\260\230", nullptr));
        BTN_CUP_FULL_4->setText(QCoreApplication::translate("DialogStock", "FULL", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DialogStock", "stock", nullptr));
        label->setText(QCoreApplication::translate("DialogStock", "\354\213\234\353\237\275 : ", nullptr));
        BTN_SYRUP_USE->setText(QCoreApplication::translate("DialogStock", "\354\202\254\354\232\251", nullptr));
        BTN_SYRUP_NOT_USE->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        LB_SYRUP_1->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_SYRUP_1->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_SYRUP_ADD_1->setText(QCoreApplication::translate("DialogStock", "1L \354\266\224\352\260\200", nullptr));
        BTN_SYRUP_REPLACE_1->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        LB_SYRUP_2->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_SYRUP_2->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_SYRUP_ADD_2->setText(QCoreApplication::translate("DialogStock", "1L \354\266\224\352\260\200", nullptr));
        BTN_SYRUP_REPLACE_2->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        LB_SYRUP_3->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_SYRUP_3->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_SYRUP_ADD_3->setText(QCoreApplication::translate("DialogStock", "1L \354\266\224\352\260\200", nullptr));
        BTN_SYRUP_REPLACE_3->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        LB_SYRUP_4->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_SYRUP_4->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_SYRUP_ADD_4->setText(QCoreApplication::translate("DialogStock", "1L \354\266\224\352\260\200", nullptr));
        BTN_SYRUP_REPLACE_4->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        LB_SYRUP_5->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_SYRUP_5->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_SYRUP_ADD_5->setText(QCoreApplication::translate("DialogStock", "1L \354\266\224\352\260\200", nullptr));
        BTN_SYRUP_REPLACE_5->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        LB_SYRUP_6->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_SYRUP_6->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_SYRUP_ADD_6->setText(QCoreApplication::translate("DialogStock", "1L \354\266\224\352\260\200", nullptr));
        BTN_SYRUP_REPLACE_6->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        LB_SYRUP_7->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_SYRUP_7->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_SYRUP_ADD_7->setText(QCoreApplication::translate("DialogStock", "1L \354\266\224\352\260\200", nullptr));
        BTN_SYRUP_REPLACE_7->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        LB_SYRUP_8->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_SYRUP_8->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_SYRUP_ADD_8->setText(QCoreApplication::translate("DialogStock", "1L \354\266\224\352\260\200", nullptr));
        BTN_SYRUP_REPLACE_8->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        LB_SYRUP_9->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_SYRUP_9->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_SYRUP_ADD_9->setText(QCoreApplication::translate("DialogStock", "1L \354\266\224\352\260\200", nullptr));
        BTN_SYRUP_REPLACE_9->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        LB_SYRUP_10->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_SYRUP_10->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_SYRUP_ADD_10->setText(QCoreApplication::translate("DialogStock", "1L \354\266\224\352\260\200", nullptr));
        BTN_SYRUP_REPLACE_10->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        LB_SYRUP_11->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_SYRUP_11->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_SYRUP_ADD_11->setText(QCoreApplication::translate("DialogStock", "1L \354\266\224\352\260\200", nullptr));
        BTN_SYRUP_REPLACE_11->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        LB_SYRUP_12->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_SYRUP_12->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_SYRUP_ADD_12->setText(QCoreApplication::translate("DialogStock", "1L \354\266\224\352\260\200", nullptr));
        BTN_SYRUP_REPLACE_12->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("DialogStock", "Syrup", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogStock: public Ui_DialogStock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSTOCK_H
