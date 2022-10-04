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
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_4;
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
    QFrame *frame_2;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QPushButton *BTN_SYRUP_USE;
    QPushButton *BTN_SYRUP_NOT_USE;
    QFrame *frame;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_5;
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
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_10;
    QLabel *LB_ICE_1;
    QProgressBar *PB_ICE_1;
    QHBoxLayout *horizontalLayout_11;
    QLabel *LB_COFFEE;
    QProgressBar *PB_COFFEE;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_2;
    QPushButton *BTN_MILK_USE;
    QPushButton *BTN_MILK_NOT_USE;
    QHBoxLayout *horizontalLayout_12;
    QLabel *LB_MILK;
    QProgressBar *PB_MILK;

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
        layoutWidget->setGeometry(QRect(20, 737, 361, 101));
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

        layoutWidget1 = new QWidget(GB_STOCK);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 90, 361, 551));
        verticalLayout_8 = new QVBoxLayout(layoutWidget1);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LB_CUP_1 = new QLabel(layoutWidget1);
        LB_CUP_1->setObjectName(QString::fromUtf8("LB_CUP_1"));

        horizontalLayout->addWidget(LB_CUP_1);

        PB_CUP_1 = new QProgressBar(layoutWidget1);
        PB_CUP_1->setObjectName(QString::fromUtf8("PB_CUP_1"));
        PB_CUP_1->setMaximumSize(QSize(150, 16777215));
        PB_CUP_1->setValue(24);

        horizontalLayout->addWidget(PB_CUP_1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        BTN_CUP_HALF_1 = new QPushButton(layoutWidget1);
        BTN_CUP_HALF_1->setObjectName(QString::fromUtf8("BTN_CUP_HALF_1"));
        BTN_CUP_HALF_1->setMinimumSize(QSize(100, 30));
        BTN_CUP_HALF_1->setMaximumSize(QSize(100, 16777215));

        verticalLayout->addWidget(BTN_CUP_HALF_1);

        BTN_CUP_FULL_1 = new QPushButton(layoutWidget1);
        BTN_CUP_FULL_1->setObjectName(QString::fromUtf8("BTN_CUP_FULL_1"));
        BTN_CUP_FULL_1->setMinimumSize(QSize(100, 30));
        BTN_CUP_FULL_1->setMaximumSize(QSize(100, 16777215));

        verticalLayout->addWidget(BTN_CUP_FULL_1);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LB_CUP_2 = new QLabel(layoutWidget1);
        LB_CUP_2->setObjectName(QString::fromUtf8("LB_CUP_2"));

        horizontalLayout_2->addWidget(LB_CUP_2);

        PB_CUP_2 = new QProgressBar(layoutWidget1);
        PB_CUP_2->setObjectName(QString::fromUtf8("PB_CUP_2"));
        PB_CUP_2->setMaximumSize(QSize(150, 16777215));
        PB_CUP_2->setValue(24);

        horizontalLayout_2->addWidget(PB_CUP_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        BTN_CUP_HALF_2 = new QPushButton(layoutWidget1);
        BTN_CUP_HALF_2->setObjectName(QString::fromUtf8("BTN_CUP_HALF_2"));
        BTN_CUP_HALF_2->setMinimumSize(QSize(100, 30));
        BTN_CUP_HALF_2->setMaximumSize(QSize(100, 16777215));

        verticalLayout_2->addWidget(BTN_CUP_HALF_2);

        BTN_CUP_FULL_2 = new QPushButton(layoutWidget1);
        BTN_CUP_FULL_2->setObjectName(QString::fromUtf8("BTN_CUP_FULL_2"));
        BTN_CUP_FULL_2->setMinimumSize(QSize(100, 30));
        BTN_CUP_FULL_2->setMaximumSize(QSize(100, 16777215));

        verticalLayout_2->addWidget(BTN_CUP_FULL_2);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_8->addLayout(verticalLayout_4);

        frame_2 = new QFrame(layoutWidget1);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        layoutWidget2 = new QWidget(frame_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 5, 357, 32));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label);

        BTN_SYRUP_USE = new QPushButton(layoutWidget2);
        BTN_SYRUP_USE->setObjectName(QString::fromUtf8("BTN_SYRUP_USE"));
        BTN_SYRUP_USE->setMinimumSize(QSize(100, 30));
        BTN_SYRUP_USE->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(BTN_SYRUP_USE);

        BTN_SYRUP_NOT_USE = new QPushButton(layoutWidget2);
        BTN_SYRUP_NOT_USE->setObjectName(QString::fromUtf8("BTN_SYRUP_NOT_USE"));
        BTN_SYRUP_NOT_USE->setMinimumSize(QSize(100, 30));
        BTN_SYRUP_NOT_USE->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(BTN_SYRUP_NOT_USE);


        verticalLayout_8->addWidget(frame_2);

        frame = new QFrame(layoutWidget1);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 225));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget3 = new QWidget(frame);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 0, 359, 224));
        verticalLayout_5 = new QVBoxLayout(layoutWidget3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        LB_SYRUP_1 = new QLabel(layoutWidget3);
        LB_SYRUP_1->setObjectName(QString::fromUtf8("LB_SYRUP_1"));
        LB_SYRUP_1->setFont(font1);

        horizontalLayout_4->addWidget(LB_SYRUP_1);

        PB_SYRUP_1 = new QProgressBar(layoutWidget3);
        PB_SYRUP_1->setObjectName(QString::fromUtf8("PB_SYRUP_1"));
        PB_SYRUP_1->setMaximumSize(QSize(150, 16777215));
        PB_SYRUP_1->setValue(24);

        horizontalLayout_4->addWidget(PB_SYRUP_1);

        BTN_SYRUP_ADD_1 = new QPushButton(layoutWidget3);
        BTN_SYRUP_ADD_1->setObjectName(QString::fromUtf8("BTN_SYRUP_ADD_1"));
        BTN_SYRUP_ADD_1->setMinimumSize(QSize(60, 30));
        BTN_SYRUP_ADD_1->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(BTN_SYRUP_ADD_1);

        BTN_SYRUP_REPLACE_1 = new QPushButton(layoutWidget3);
        BTN_SYRUP_REPLACE_1->setObjectName(QString::fromUtf8("BTN_SYRUP_REPLACE_1"));
        BTN_SYRUP_REPLACE_1->setMinimumSize(QSize(60, 30));
        BTN_SYRUP_REPLACE_1->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(BTN_SYRUP_REPLACE_1);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        LB_SYRUP_2 = new QLabel(layoutWidget3);
        LB_SYRUP_2->setObjectName(QString::fromUtf8("LB_SYRUP_2"));
        LB_SYRUP_2->setFont(font1);

        horizontalLayout_5->addWidget(LB_SYRUP_2);

        PB_SYRUP_2 = new QProgressBar(layoutWidget3);
        PB_SYRUP_2->setObjectName(QString::fromUtf8("PB_SYRUP_2"));
        PB_SYRUP_2->setMaximumSize(QSize(150, 16777215));
        PB_SYRUP_2->setValue(24);

        horizontalLayout_5->addWidget(PB_SYRUP_2);

        BTN_SYRUP_ADD_2 = new QPushButton(layoutWidget3);
        BTN_SYRUP_ADD_2->setObjectName(QString::fromUtf8("BTN_SYRUP_ADD_2"));
        BTN_SYRUP_ADD_2->setMinimumSize(QSize(60, 30));
        BTN_SYRUP_ADD_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(BTN_SYRUP_ADD_2);

        BTN_SYRUP_REPLACE_2 = new QPushButton(layoutWidget3);
        BTN_SYRUP_REPLACE_2->setObjectName(QString::fromUtf8("BTN_SYRUP_REPLACE_2"));
        BTN_SYRUP_REPLACE_2->setMinimumSize(QSize(60, 30));
        BTN_SYRUP_REPLACE_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(BTN_SYRUP_REPLACE_2);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        LB_SYRUP_3 = new QLabel(layoutWidget3);
        LB_SYRUP_3->setObjectName(QString::fromUtf8("LB_SYRUP_3"));
        LB_SYRUP_3->setFont(font1);

        horizontalLayout_6->addWidget(LB_SYRUP_3);

        PB_SYRUP_3 = new QProgressBar(layoutWidget3);
        PB_SYRUP_3->setObjectName(QString::fromUtf8("PB_SYRUP_3"));
        PB_SYRUP_3->setMaximumSize(QSize(150, 16777215));
        PB_SYRUP_3->setValue(24);

        horizontalLayout_6->addWidget(PB_SYRUP_3);

        BTN_SYRUP_ADD_3 = new QPushButton(layoutWidget3);
        BTN_SYRUP_ADD_3->setObjectName(QString::fromUtf8("BTN_SYRUP_ADD_3"));
        BTN_SYRUP_ADD_3->setMinimumSize(QSize(60, 30));
        BTN_SYRUP_ADD_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(BTN_SYRUP_ADD_3);

        BTN_SYRUP_REPLACE_3 = new QPushButton(layoutWidget3);
        BTN_SYRUP_REPLACE_3->setObjectName(QString::fromUtf8("BTN_SYRUP_REPLACE_3"));
        BTN_SYRUP_REPLACE_3->setMinimumSize(QSize(60, 30));
        BTN_SYRUP_REPLACE_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(BTN_SYRUP_REPLACE_3);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        LB_SYRUP_4 = new QLabel(layoutWidget3);
        LB_SYRUP_4->setObjectName(QString::fromUtf8("LB_SYRUP_4"));
        LB_SYRUP_4->setFont(font1);

        horizontalLayout_7->addWidget(LB_SYRUP_4);

        PB_SYRUP_4 = new QProgressBar(layoutWidget3);
        PB_SYRUP_4->setObjectName(QString::fromUtf8("PB_SYRUP_4"));
        PB_SYRUP_4->setMaximumSize(QSize(150, 16777215));
        PB_SYRUP_4->setValue(24);

        horizontalLayout_7->addWidget(PB_SYRUP_4);

        BTN_SYRUP_ADD_4 = new QPushButton(layoutWidget3);
        BTN_SYRUP_ADD_4->setObjectName(QString::fromUtf8("BTN_SYRUP_ADD_4"));
        BTN_SYRUP_ADD_4->setMinimumSize(QSize(60, 30));
        BTN_SYRUP_ADD_4->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_7->addWidget(BTN_SYRUP_ADD_4);

        BTN_SYRUP_REPLACE_4 = new QPushButton(layoutWidget3);
        BTN_SYRUP_REPLACE_4->setObjectName(QString::fromUtf8("BTN_SYRUP_REPLACE_4"));
        BTN_SYRUP_REPLACE_4->setMinimumSize(QSize(60, 30));
        BTN_SYRUP_REPLACE_4->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_7->addWidget(BTN_SYRUP_REPLACE_4);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        LB_SYRUP_5 = new QLabel(layoutWidget3);
        LB_SYRUP_5->setObjectName(QString::fromUtf8("LB_SYRUP_5"));
        LB_SYRUP_5->setFont(font1);

        horizontalLayout_8->addWidget(LB_SYRUP_5);

        PB_SYRUP_5 = new QProgressBar(layoutWidget3);
        PB_SYRUP_5->setObjectName(QString::fromUtf8("PB_SYRUP_5"));
        PB_SYRUP_5->setMaximumSize(QSize(150, 16777215));
        PB_SYRUP_5->setValue(24);

        horizontalLayout_8->addWidget(PB_SYRUP_5);

        BTN_SYRUP_ADD_5 = new QPushButton(layoutWidget3);
        BTN_SYRUP_ADD_5->setObjectName(QString::fromUtf8("BTN_SYRUP_ADD_5"));
        BTN_SYRUP_ADD_5->setMinimumSize(QSize(60, 30));
        BTN_SYRUP_ADD_5->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(BTN_SYRUP_ADD_5);

        BTN_SYRUP_REPLACE_5 = new QPushButton(layoutWidget3);
        BTN_SYRUP_REPLACE_5->setObjectName(QString::fromUtf8("BTN_SYRUP_REPLACE_5"));
        BTN_SYRUP_REPLACE_5->setMinimumSize(QSize(60, 30));
        BTN_SYRUP_REPLACE_5->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(BTN_SYRUP_REPLACE_5);


        verticalLayout_5->addLayout(horizontalLayout_8);


        verticalLayout_8->addWidget(frame);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        LB_ICE_1 = new QLabel(layoutWidget1);
        LB_ICE_1->setObjectName(QString::fromUtf8("LB_ICE_1"));

        horizontalLayout_10->addWidget(LB_ICE_1);

        PB_ICE_1 = new QProgressBar(layoutWidget1);
        PB_ICE_1->setObjectName(QString::fromUtf8("PB_ICE_1"));
        PB_ICE_1->setMaximumSize(QSize(200, 16777215));
        PB_ICE_1->setValue(24);

        horizontalLayout_10->addWidget(PB_ICE_1);


        verticalLayout_7->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        LB_COFFEE = new QLabel(layoutWidget1);
        LB_COFFEE->setObjectName(QString::fromUtf8("LB_COFFEE"));

        horizontalLayout_11->addWidget(LB_COFFEE);

        PB_COFFEE = new QProgressBar(layoutWidget1);
        PB_COFFEE->setObjectName(QString::fromUtf8("PB_COFFEE"));
        PB_COFFEE->setMaximumSize(QSize(200, 16777215));
        PB_COFFEE->setValue(24);

        horizontalLayout_11->addWidget(PB_COFFEE);


        verticalLayout_7->addLayout(horizontalLayout_11);


        verticalLayout_8->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_13->addWidget(label_2);

        BTN_MILK_USE = new QPushButton(layoutWidget1);
        BTN_MILK_USE->setObjectName(QString::fromUtf8("BTN_MILK_USE"));
        BTN_MILK_USE->setMinimumSize(QSize(100, 30));
        BTN_MILK_USE->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_13->addWidget(BTN_MILK_USE);

        BTN_MILK_NOT_USE = new QPushButton(layoutWidget1);
        BTN_MILK_NOT_USE->setObjectName(QString::fromUtf8("BTN_MILK_NOT_USE"));
        BTN_MILK_NOT_USE->setMinimumSize(QSize(100, 30));
        BTN_MILK_NOT_USE->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_13->addWidget(BTN_MILK_NOT_USE);


        verticalLayout_6->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        LB_MILK = new QLabel(layoutWidget1);
        LB_MILK->setObjectName(QString::fromUtf8("LB_MILK"));

        horizontalLayout_12->addWidget(LB_MILK);

        PB_MILK = new QProgressBar(layoutWidget1);
        PB_MILK->setObjectName(QString::fromUtf8("PB_MILK"));
        PB_MILK->setMaximumSize(QSize(200, 16777215));
        PB_MILK->setValue(24);

        horizontalLayout_12->addWidget(PB_MILK);


        verticalLayout_6->addLayout(horizontalLayout_12);


        verticalLayout_8->addLayout(verticalLayout_6);


        retranslateUi(DialogStock);

        QMetaObject::connectSlotsByName(DialogStock);
    } // setupUi

    void retranslateUi(QDialog *DialogStock)
    {
        DialogStock->setWindowTitle(QCoreApplication::translate("DialogStock", "Dialog", nullptr));
        GB_STOCK->setTitle(QCoreApplication::translate("DialogStock", "\354\236\254\352\263\240", nullptr));
        BTN_SET_STOCK_MANUAL->setText(QCoreApplication::translate("DialogStock", "\354\210\230\353\217\231 \354\236\254\352\263\240 \354\247\200\354\240\225", nullptr));
        LB_CUP_1->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_CUP_1->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_CUP_HALF_1->setText(QCoreApplication::translate("DialogStock", "\354\240\210\353\260\230", nullptr));
        BTN_CUP_FULL_1->setText(QCoreApplication::translate("DialogStock", "FULL", nullptr));
        LB_CUP_2->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_CUP_2->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_CUP_HALF_2->setText(QCoreApplication::translate("DialogStock", "\354\240\210\353\260\230", nullptr));
        BTN_CUP_FULL_2->setText(QCoreApplication::translate("DialogStock", "FULL", nullptr));
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
        BTN_SYRUP_ADD_5->setText(QCoreApplication::translate("DialogStock", "\354\202\254\354\232\251", nullptr));
        BTN_SYRUP_REPLACE_5->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        LB_ICE_1->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_ICE_1->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        LB_COFFEE->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_COFFEE->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        label_2->setText(QCoreApplication::translate("DialogStock", "\354\232\260\354\234\240 :", nullptr));
        BTN_MILK_USE->setText(QCoreApplication::translate("DialogStock", "\354\202\254\354\232\251", nullptr));
        BTN_MILK_NOT_USE->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        LB_MILK->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_MILK->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogStock: public Ui_DialogStock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSTOCK_H
