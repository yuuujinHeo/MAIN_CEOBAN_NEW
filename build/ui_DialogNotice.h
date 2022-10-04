/********************************************************************************
** Form generated from reading UI file 'DialogNotice.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGNOTICE_H
#define UI_DIALOGNOTICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogNotice
{
public:
    QStackedWidget *SW_MAIN;
    QWidget *PAGE_INIT;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *LB_INIT_ERROR_CODE;
    QPushButton *BTN_INIT_CANCEL;
    QStackedWidget *SW_INIT_CON;
    QWidget *CON_ROBOT;
    QLabel *IMAGE_INIT_CON_ROBOT;
    QPushButton *BTN_INIT_CON_ROBOT_1;
    QPushButton *BTN_INIT_CON_ROBOT_2;
    QPushButton *BTN_INIT_CON_ROBOT_INIT;
    QLineEdit *LE_CON_ROBOT_CMD;
    QLineEdit *LE_CON_ROBOT_DATA;
    QWidget *CON_BOARD;
    QPushButton *BTN_INIT_CON_BOARD_INIT;
    QLineEdit *LE_CON_BOARD;
    QPushButton *BTN_INIT_CON_BOARD_1;
    QLabel *IMAGE_INIT_CON_BOARD;
    QPushButton *BTN_INIT_CON_BOARD_2;
    QWidget *ROBOT_INIT;
    QLabel *IMAGE_INIT_ROBOT;
    QPushButton *BTN_INIT_ROBOT_INIT;
    QLineEdit *LE_INIT_ROBOT_BASE;
    QLineEdit *LE_INIT_ROBOT_INBOX;
    QLineEdit *LE_INIT_ROBOT_COL;
    QPushButton *BTN_INIT_ROBOT_PROGRAM_EXIT;
    QLabel *LB_INIT_ROBOT_BASE;
    QFrame *line;
    QLabel *LB_INIT_ERROR_DETAIL;
    QWidget *PAGE_OPER;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *LB_OP_ERROR_CODE;
    QPushButton *BTN_OP_CANCEL;
    QLabel *LB_OP_ERROR_DETAIL;
    QStackedWidget *SW_OP;
    QWidget *INIT_FIRST;
    QPushButton *BTN_OP_INIT_FIRST;
    QWidget *ROBOT_INIT_2;
    QLabel *IMAGE_INIT_ROBOT_2;
    QPushButton *BTN_INIT_ROBOT_INIT_2;
    QLineEdit *LE_INIT_ROBOT_BASE_2;
    QLineEdit *LE_INIT_ROBOT_INBOX_2;
    QLineEdit *LE_INIT_ROBOT_COL_2;
    QPushButton *BTN_INIT_ROBOT_PROGRAM_EXIT_2;
    QLabel *LB_INIT_ROBOT_BASE_2;
    QLabel *LB_INIT_ROBOT_BASE_3;
    QWidget *DOOR_2;
    QLabel *IMAGE_INIT_DOOR_2;
    QPushButton *BTN_INIT_DOOR_INIT_2;
    QLineEdit *LE_DOOR_2;
    QWidget *OUTLET_2;
    QLabel *IMAGE_OP_OUTLET;
    QPushButton *BTN_OP_OUTLET_1;
    QPushButton *BTN_OP_OUTLET_START;
    QFrame *frame_outlet;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QPushButton *BTN_OUTLET_CELL_3;
    QPushButton *BTN_OUTLET_CELL_4;
    QLineEdit *LE_OUTLET_CELL_2;
    QPushButton *BTN_OUTLET_CELL_2;
    QLineEdit *LE_OUTLET_CELL_4;
    QLineEdit *LE_OUTLET_CELL_1;
    QPushButton *BTN_OUTLET_CELL_5;
    QPushButton *BTN_OUTLET_CELL_6;
    QLineEdit *LE_OUTLET_CELL_5;
    QPushButton *BTN_OUTLET_CELL_1;
    QLineEdit *LE_OUTLET_CELL_3;
    QLineEdit *LE_OUTLET_CELL_6;
    QLabel *label_3;
    QLabel *label_6;
    QPushButton *BTN_OP_OUTLET_INIT;
    QFrame *line_2;
    QWidget *PAGE_SUPER_STOP;
    QGroupBox *groupBox_3;
    QStackedWidget *SW_SS;
    QWidget *SUPERSTOP;
    QLabel *LB_SS_DETAIL;
    QFrame *line_4;
    QPushButton *BTN_SS_CANCEL;
    QStackedWidget *SW_SS_DETAIL;
    QWidget *ROBOT1_4;
    QLabel *IMAGE_SS;
    QPushButton *BTN_SS;
    QPushButton *BTN_SS_INIT;
    QPushButton *BTN_SS_2;
    QPushButton *BTN_SS_3;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *LB_SS_ERROR_CODE;
    QWidget *PAGE_NOTICE;
    QGroupBox *groupBox_4;
    QStackedWidget *SW_INIT_5;
    QWidget *ERROR_CONNECTION_5;
    QLabel *LB_ICE_ERROR_DETAIL_5;
    QFrame *line_5;
    QPushButton *BTN_INIT_CANCEL_5;
    QStackedWidget *SW_INIT_CON_5;
    QWidget *ROBOT1_5;
    QLabel *LB_ICE_ERROR_IMAGE_5;
    QPushButton *BTN_INIT_NEXT1_5;
    QPushButton *BTN_INIT_NEXT2_5;
    QPushButton *BTN_INIT_AGAIN_5;
    QWidget *ROBOT2_5;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLabel *LB_ICE_ERROR_CODE_5;
    QWidget *ERROR_ROBOT_5;
    QWidget *ERROR_CON2NECTION_5;

    void setupUi(QDialog *DialogNotice)
    {
        if (DialogNotice->objectName().isEmpty())
            DialogNotice->setObjectName(QString::fromUtf8("DialogNotice"));
        DialogNotice->resize(600, 500);
        DialogNotice->setStyleSheet(QString::fromUtf8(""));
        SW_MAIN = new QStackedWidget(DialogNotice);
        SW_MAIN->setObjectName(QString::fromUtf8("SW_MAIN"));
        SW_MAIN->setGeometry(QRect(0, 0, 600, 500));
        PAGE_INIT = new QWidget();
        PAGE_INIT->setObjectName(QString::fromUtf8("PAGE_INIT"));
        groupBox = new QGroupBox(PAGE_INIT);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 600, 500));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox  {\n"
"    margin-top: 10px;\n"
"	font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"\n"
"QGroupBox::title  {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 10px 8000px 10px 8000px;\n"
"    background-color: red;\n"
"    color: rgb(255, 255, 255);\n"
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
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"\n"
"\n"
"\n"
""));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 70, 166, 28));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        LB_INIT_ERROR_CODE = new QLabel(layoutWidget);
        LB_INIT_ERROR_CODE->setObjectName(QString::fromUtf8("LB_INIT_ERROR_CODE"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font1.setPointSize(13);
        LB_INIT_ERROR_CODE->setFont(font1);
        LB_INIT_ERROR_CODE->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(LB_INIT_ERROR_CODE);

        BTN_INIT_CANCEL = new QPushButton(groupBox);
        BTN_INIT_CANCEL->setObjectName(QString::fromUtf8("BTN_INIT_CANCEL"));
        BTN_INIT_CANCEL->setGeometry(QRect(520, 70, 61, 41));
        SW_INIT_CON = new QStackedWidget(groupBox);
        SW_INIT_CON->setObjectName(QString::fromUtf8("SW_INIT_CON"));
        SW_INIT_CON->setGeometry(QRect(10, 170, 581, 311));
        CON_ROBOT = new QWidget();
        CON_ROBOT->setObjectName(QString::fromUtf8("CON_ROBOT"));
        IMAGE_INIT_CON_ROBOT = new QLabel(CON_ROBOT);
        IMAGE_INIT_CON_ROBOT->setObjectName(QString::fromUtf8("IMAGE_INIT_CON_ROBOT"));
        IMAGE_INIT_CON_ROBOT->setGeometry(QRect(10, 10, 450, 250));
        IMAGE_INIT_CON_ROBOT->setPixmap(QPixmap(QString::fromUtf8(":/build/image/error/ro1.png")));
        IMAGE_INIT_CON_ROBOT->setScaledContents(true);
        IMAGE_INIT_CON_ROBOT->setAlignment(Qt::AlignCenter);
        BTN_INIT_CON_ROBOT_1 = new QPushButton(CON_ROBOT);
        BTN_INIT_CON_ROBOT_1->setObjectName(QString::fromUtf8("BTN_INIT_CON_ROBOT_1"));
        BTN_INIT_CON_ROBOT_1->setGeometry(QRect(490, 80, 75, 51));
        BTN_INIT_CON_ROBOT_2 = new QPushButton(CON_ROBOT);
        BTN_INIT_CON_ROBOT_2->setObjectName(QString::fromUtf8("BTN_INIT_CON_ROBOT_2"));
        BTN_INIT_CON_ROBOT_2->setGeometry(QRect(490, 140, 75, 51));
        BTN_INIT_CON_ROBOT_INIT = new QPushButton(CON_ROBOT);
        BTN_INIT_CON_ROBOT_INIT->setObjectName(QString::fromUtf8("BTN_INIT_CON_ROBOT_INIT"));
        BTN_INIT_CON_ROBOT_INIT->setGeometry(QRect(490, 200, 75, 51));
        LE_CON_ROBOT_CMD = new QLineEdit(CON_ROBOT);
        LE_CON_ROBOT_CMD->setObjectName(QString::fromUtf8("LE_CON_ROBOT_CMD"));
        LE_CON_ROBOT_CMD->setGeometry(QRect(490, 40, 71, 31));
        LE_CON_ROBOT_CMD->setAlignment(Qt::AlignCenter);
        LE_CON_ROBOT_CMD->setReadOnly(true);
        LE_CON_ROBOT_DATA = new QLineEdit(CON_ROBOT);
        LE_CON_ROBOT_DATA->setObjectName(QString::fromUtf8("LE_CON_ROBOT_DATA"));
        LE_CON_ROBOT_DATA->setGeometry(QRect(490, 10, 71, 31));
        LE_CON_ROBOT_DATA->setAlignment(Qt::AlignCenter);
        LE_CON_ROBOT_DATA->setReadOnly(true);
        SW_INIT_CON->addWidget(CON_ROBOT);
        BTN_INIT_CON_ROBOT_1->raise();
        IMAGE_INIT_CON_ROBOT->raise();
        BTN_INIT_CON_ROBOT_2->raise();
        BTN_INIT_CON_ROBOT_INIT->raise();
        LE_CON_ROBOT_CMD->raise();
        LE_CON_ROBOT_DATA->raise();
        CON_BOARD = new QWidget();
        CON_BOARD->setObjectName(QString::fromUtf8("CON_BOARD"));
        BTN_INIT_CON_BOARD_INIT = new QPushButton(CON_BOARD);
        BTN_INIT_CON_BOARD_INIT->setObjectName(QString::fromUtf8("BTN_INIT_CON_BOARD_INIT"));
        BTN_INIT_CON_BOARD_INIT->setGeometry(QRect(490, 200, 75, 51));
        LE_CON_BOARD = new QLineEdit(CON_BOARD);
        LE_CON_BOARD->setObjectName(QString::fromUtf8("LE_CON_BOARD"));
        LE_CON_BOARD->setGeometry(QRect(490, 10, 71, 31));
        LE_CON_BOARD->setAlignment(Qt::AlignCenter);
        LE_CON_BOARD->setReadOnly(true);
        BTN_INIT_CON_BOARD_1 = new QPushButton(CON_BOARD);
        BTN_INIT_CON_BOARD_1->setObjectName(QString::fromUtf8("BTN_INIT_CON_BOARD_1"));
        BTN_INIT_CON_BOARD_1->setGeometry(QRect(490, 80, 75, 51));
        IMAGE_INIT_CON_BOARD = new QLabel(CON_BOARD);
        IMAGE_INIT_CON_BOARD->setObjectName(QString::fromUtf8("IMAGE_INIT_CON_BOARD"));
        IMAGE_INIT_CON_BOARD->setGeometry(QRect(10, 10, 450, 250));
        IMAGE_INIT_CON_BOARD->setPixmap(QPixmap(QString::fromUtf8(":/build/image/error/ro1.png")));
        IMAGE_INIT_CON_BOARD->setScaledContents(true);
        IMAGE_INIT_CON_BOARD->setAlignment(Qt::AlignCenter);
        BTN_INIT_CON_BOARD_2 = new QPushButton(CON_BOARD);
        BTN_INIT_CON_BOARD_2->setObjectName(QString::fromUtf8("BTN_INIT_CON_BOARD_2"));
        BTN_INIT_CON_BOARD_2->setGeometry(QRect(490, 140, 75, 51));
        SW_INIT_CON->addWidget(CON_BOARD);
        ROBOT_INIT = new QWidget();
        ROBOT_INIT->setObjectName(QString::fromUtf8("ROBOT_INIT"));
        IMAGE_INIT_ROBOT = new QLabel(ROBOT_INIT);
        IMAGE_INIT_ROBOT->setObjectName(QString::fromUtf8("IMAGE_INIT_ROBOT"));
        IMAGE_INIT_ROBOT->setGeometry(QRect(10, 10, 450, 250));
        IMAGE_INIT_ROBOT->setPixmap(QPixmap(QString::fromUtf8(":/build/image/error/rp1.png")));
        IMAGE_INIT_ROBOT->setScaledContents(true);
        IMAGE_INIT_ROBOT->setAlignment(Qt::AlignCenter);
        BTN_INIT_ROBOT_INIT = new QPushButton(ROBOT_INIT);
        BTN_INIT_ROBOT_INIT->setObjectName(QString::fromUtf8("BTN_INIT_ROBOT_INIT"));
        BTN_INIT_ROBOT_INIT->setGeometry(QRect(490, 170, 75, 51));
        LE_INIT_ROBOT_BASE = new QLineEdit(ROBOT_INIT);
        LE_INIT_ROBOT_BASE->setObjectName(QString::fromUtf8("LE_INIT_ROBOT_BASE"));
        LE_INIT_ROBOT_BASE->setGeometry(QRect(490, 50, 71, 31));
        LE_INIT_ROBOT_BASE->setAlignment(Qt::AlignCenter);
        LE_INIT_ROBOT_BASE->setReadOnly(true);
        LE_INIT_ROBOT_INBOX = new QLineEdit(ROBOT_INIT);
        LE_INIT_ROBOT_INBOX->setObjectName(QString::fromUtf8("LE_INIT_ROBOT_INBOX"));
        LE_INIT_ROBOT_INBOX->setGeometry(QRect(490, 80, 71, 31));
        LE_INIT_ROBOT_INBOX->setAlignment(Qt::AlignCenter);
        LE_INIT_ROBOT_INBOX->setReadOnly(true);
        LE_INIT_ROBOT_COL = new QLineEdit(ROBOT_INIT);
        LE_INIT_ROBOT_COL->setObjectName(QString::fromUtf8("LE_INIT_ROBOT_COL"));
        LE_INIT_ROBOT_COL->setGeometry(QRect(490, 110, 71, 31));
        LE_INIT_ROBOT_COL->setAlignment(Qt::AlignCenter);
        LE_INIT_ROBOT_COL->setReadOnly(true);
        BTN_INIT_ROBOT_PROGRAM_EXIT = new QPushButton(ROBOT_INIT);
        BTN_INIT_ROBOT_PROGRAM_EXIT->setObjectName(QString::fromUtf8("BTN_INIT_ROBOT_PROGRAM_EXIT"));
        BTN_INIT_ROBOT_PROGRAM_EXIT->setGeometry(QRect(140, 110, 171, 51));
        LB_INIT_ROBOT_BASE = new QLabel(ROBOT_INIT);
        LB_INIT_ROBOT_BASE->setObjectName(QString::fromUtf8("LB_INIT_ROBOT_BASE"));
        LB_INIT_ROBOT_BASE->setGeometry(QRect(490, 30, 71, 16));
        LB_INIT_ROBOT_BASE->setAlignment(Qt::AlignCenter);
        SW_INIT_CON->addWidget(ROBOT_INIT);
        IMAGE_INIT_ROBOT->raise();
        BTN_INIT_ROBOT_INIT->raise();
        LE_INIT_ROBOT_BASE->raise();
        LE_INIT_ROBOT_INBOX->raise();
        LE_INIT_ROBOT_COL->raise();
        LB_INIT_ROBOT_BASE->raise();
        BTN_INIT_ROBOT_PROGRAM_EXIT->raise();
        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(30, 150, 541, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        LB_INIT_ERROR_DETAIL = new QLabel(groupBox);
        LB_INIT_ERROR_DETAIL->setObjectName(QString::fromUtf8("LB_INIT_ERROR_DETAIL"));
        LB_INIT_ERROR_DETAIL->setGeometry(QRect(30, 100, 541, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font2.setPointSize(10);
        LB_INIT_ERROR_DETAIL->setFont(font2);
        LB_INIT_ERROR_DETAIL->setAlignment(Qt::AlignCenter);
        SW_MAIN->addWidget(PAGE_INIT);
        PAGE_OPER = new QWidget();
        PAGE_OPER->setObjectName(QString::fromUtf8("PAGE_OPER"));
        groupBox_2 = new QGroupBox(PAGE_OPER);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 600, 500));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox  {\n"
"    margin-top: 10px;\n"
"	font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"\n"
"QGroupBox::title  {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 10px 8000px 10px 8000px;\n"
"    background-color: red;\n"
"    color: rgb(255, 255, 255);\n"
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
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"\n"
"\n"
"\n"
""));
        layoutWidget_2 = new QWidget(groupBox_2);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 70, 166, 28));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        LB_OP_ERROR_CODE = new QLabel(layoutWidget_2);
        LB_OP_ERROR_CODE->setObjectName(QString::fromUtf8("LB_OP_ERROR_CODE"));
        LB_OP_ERROR_CODE->setFont(font1);
        LB_OP_ERROR_CODE->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(LB_OP_ERROR_CODE);

        BTN_OP_CANCEL = new QPushButton(groupBox_2);
        BTN_OP_CANCEL->setObjectName(QString::fromUtf8("BTN_OP_CANCEL"));
        BTN_OP_CANCEL->setGeometry(QRect(520, 70, 61, 41));
        LB_OP_ERROR_DETAIL = new QLabel(groupBox_2);
        LB_OP_ERROR_DETAIL->setObjectName(QString::fromUtf8("LB_OP_ERROR_DETAIL"));
        LB_OP_ERROR_DETAIL->setGeometry(QRect(30, 100, 541, 51));
        LB_OP_ERROR_DETAIL->setFont(font2);
        LB_OP_ERROR_DETAIL->setAlignment(Qt::AlignCenter);
        SW_OP = new QStackedWidget(groupBox_2);
        SW_OP->setObjectName(QString::fromUtf8("SW_OP"));
        SW_OP->setGeometry(QRect(10, 170, 581, 311));
        INIT_FIRST = new QWidget();
        INIT_FIRST->setObjectName(QString::fromUtf8("INIT_FIRST"));
        BTN_OP_INIT_FIRST = new QPushButton(INIT_FIRST);
        BTN_OP_INIT_FIRST->setObjectName(QString::fromUtf8("BTN_OP_INIT_FIRST"));
        BTN_OP_INIT_FIRST->setGeometry(QRect(200, 80, 181, 51));
        SW_OP->addWidget(INIT_FIRST);
        ROBOT_INIT_2 = new QWidget();
        ROBOT_INIT_2->setObjectName(QString::fromUtf8("ROBOT_INIT_2"));
        IMAGE_INIT_ROBOT_2 = new QLabel(ROBOT_INIT_2);
        IMAGE_INIT_ROBOT_2->setObjectName(QString::fromUtf8("IMAGE_INIT_ROBOT_2"));
        IMAGE_INIT_ROBOT_2->setGeometry(QRect(10, 10, 450, 250));
        IMAGE_INIT_ROBOT_2->setPixmap(QPixmap(QString::fromUtf8(":/build/image/error/rp1.png")));
        IMAGE_INIT_ROBOT_2->setScaledContents(true);
        IMAGE_INIT_ROBOT_2->setAlignment(Qt::AlignCenter);
        BTN_INIT_ROBOT_INIT_2 = new QPushButton(ROBOT_INIT_2);
        BTN_INIT_ROBOT_INIT_2->setObjectName(QString::fromUtf8("BTN_INIT_ROBOT_INIT_2"));
        BTN_INIT_ROBOT_INIT_2->setGeometry(QRect(490, 170, 75, 51));
        LE_INIT_ROBOT_BASE_2 = new QLineEdit(ROBOT_INIT_2);
        LE_INIT_ROBOT_BASE_2->setObjectName(QString::fromUtf8("LE_INIT_ROBOT_BASE_2"));
        LE_INIT_ROBOT_BASE_2->setGeometry(QRect(490, 50, 71, 31));
        LE_INIT_ROBOT_BASE_2->setAlignment(Qt::AlignCenter);
        LE_INIT_ROBOT_BASE_2->setReadOnly(true);
        LE_INIT_ROBOT_INBOX_2 = new QLineEdit(ROBOT_INIT_2);
        LE_INIT_ROBOT_INBOX_2->setObjectName(QString::fromUtf8("LE_INIT_ROBOT_INBOX_2"));
        LE_INIT_ROBOT_INBOX_2->setGeometry(QRect(490, 80, 71, 31));
        LE_INIT_ROBOT_INBOX_2->setAlignment(Qt::AlignCenter);
        LE_INIT_ROBOT_INBOX_2->setReadOnly(true);
        LE_INIT_ROBOT_COL_2 = new QLineEdit(ROBOT_INIT_2);
        LE_INIT_ROBOT_COL_2->setObjectName(QString::fromUtf8("LE_INIT_ROBOT_COL_2"));
        LE_INIT_ROBOT_COL_2->setGeometry(QRect(490, 110, 71, 31));
        LE_INIT_ROBOT_COL_2->setAlignment(Qt::AlignCenter);
        LE_INIT_ROBOT_COL_2->setReadOnly(true);
        BTN_INIT_ROBOT_PROGRAM_EXIT_2 = new QPushButton(ROBOT_INIT_2);
        BTN_INIT_ROBOT_PROGRAM_EXIT_2->setObjectName(QString::fromUtf8("BTN_INIT_ROBOT_PROGRAM_EXIT_2"));
        BTN_INIT_ROBOT_PROGRAM_EXIT_2->setGeometry(QRect(150, 120, 171, 51));
        LB_INIT_ROBOT_BASE_2 = new QLabel(ROBOT_INIT_2);
        LB_INIT_ROBOT_BASE_2->setObjectName(QString::fromUtf8("LB_INIT_ROBOT_BASE_2"));
        LB_INIT_ROBOT_BASE_2->setGeometry(QRect(490, 30, 71, 16));
        LB_INIT_ROBOT_BASE_2->setAlignment(Qt::AlignCenter);
        LB_INIT_ROBOT_BASE_3 = new QLabel(ROBOT_INIT_2);
        LB_INIT_ROBOT_BASE_3->setObjectName(QString::fromUtf8("LB_INIT_ROBOT_BASE_3"));
        LB_INIT_ROBOT_BASE_3->setGeometry(QRect(490, 10, 71, 16));
        LB_INIT_ROBOT_BASE_3->setAlignment(Qt::AlignCenter);
        SW_OP->addWidget(ROBOT_INIT_2);
        DOOR_2 = new QWidget();
        DOOR_2->setObjectName(QString::fromUtf8("DOOR_2"));
        IMAGE_INIT_DOOR_2 = new QLabel(DOOR_2);
        IMAGE_INIT_DOOR_2->setObjectName(QString::fromUtf8("IMAGE_INIT_DOOR_2"));
        IMAGE_INIT_DOOR_2->setGeometry(QRect(20, 10, 450, 250));
        IMAGE_INIT_DOOR_2->setPixmap(QPixmap(QString::fromUtf8(":/build/image/error/pd1.png")));
        IMAGE_INIT_DOOR_2->setScaledContents(true);
        IMAGE_INIT_DOOR_2->setAlignment(Qt::AlignCenter);
        BTN_INIT_DOOR_INIT_2 = new QPushButton(DOOR_2);
        BTN_INIT_DOOR_INIT_2->setObjectName(QString::fromUtf8("BTN_INIT_DOOR_INIT_2"));
        BTN_INIT_DOOR_INIT_2->setGeometry(QRect(490, 100, 75, 51));
        LE_DOOR_2 = new QLineEdit(DOOR_2);
        LE_DOOR_2->setObjectName(QString::fromUtf8("LE_DOOR_2"));
        LE_DOOR_2->setGeometry(QRect(490, 50, 71, 31));
        LE_DOOR_2->setAlignment(Qt::AlignCenter);
        LE_DOOR_2->setReadOnly(true);
        SW_OP->addWidget(DOOR_2);
        OUTLET_2 = new QWidget();
        OUTLET_2->setObjectName(QString::fromUtf8("OUTLET_2"));
        IMAGE_OP_OUTLET = new QLabel(OUTLET_2);
        IMAGE_OP_OUTLET->setObjectName(QString::fromUtf8("IMAGE_OP_OUTLET"));
        IMAGE_OP_OUTLET->setGeometry(QRect(20, 20, 450, 250));
        IMAGE_OP_OUTLET->setPixmap(QPixmap(QString::fromUtf8(":/build/image/error/od1.png")));
        IMAGE_OP_OUTLET->setScaledContents(true);
        IMAGE_OP_OUTLET->setAlignment(Qt::AlignCenter);
        BTN_OP_OUTLET_1 = new QPushButton(OUTLET_2);
        BTN_OP_OUTLET_1->setObjectName(QString::fromUtf8("BTN_OP_OUTLET_1"));
        BTN_OP_OUTLET_1->setGeometry(QRect(480, 40, 75, 51));
        BTN_OP_OUTLET_START = new QPushButton(OUTLET_2);
        BTN_OP_OUTLET_START->setObjectName(QString::fromUtf8("BTN_OP_OUTLET_START"));
        BTN_OP_OUTLET_START->setGeometry(QRect(480, 100, 75, 51));
        frame_outlet = new QFrame(OUTLET_2);
        frame_outlet->setObjectName(QString::fromUtf8("frame_outlet"));
        frame_outlet->setGeometry(QRect(130, 100, 231, 151));
        frame_outlet->setFrameShape(QFrame::StyledPanel);
        frame_outlet->setFrameShadow(QFrame::Raised);
        layoutWidget1 = new QWidget(frame_outlet);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 212, 134));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        BTN_OUTLET_CELL_3 = new QPushButton(layoutWidget1);
        BTN_OUTLET_CELL_3->setObjectName(QString::fromUtf8("BTN_OUTLET_CELL_3"));
        BTN_OUTLET_CELL_3->setMinimumSize(QSize(0, 30));
        BTN_OUTLET_CELL_3->setMaximumSize(QSize(50, 30));

        gridLayout->addWidget(BTN_OUTLET_CELL_3, 3, 1, 1, 1);

        BTN_OUTLET_CELL_4 = new QPushButton(layoutWidget1);
        BTN_OUTLET_CELL_4->setObjectName(QString::fromUtf8("BTN_OUTLET_CELL_4"));
        BTN_OUTLET_CELL_4->setMinimumSize(QSize(0, 30));
        BTN_OUTLET_CELL_4->setMaximumSize(QSize(50, 30));

        gridLayout->addWidget(BTN_OUTLET_CELL_4, 1, 3, 1, 1);

        LE_OUTLET_CELL_2 = new QLineEdit(layoutWidget1);
        LE_OUTLET_CELL_2->setObjectName(QString::fromUtf8("LE_OUTLET_CELL_2"));
        LE_OUTLET_CELL_2->setMinimumSize(QSize(30, 30));
        LE_OUTLET_CELL_2->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(LE_OUTLET_CELL_2, 2, 0, 1, 1);

        BTN_OUTLET_CELL_2 = new QPushButton(layoutWidget1);
        BTN_OUTLET_CELL_2->setObjectName(QString::fromUtf8("BTN_OUTLET_CELL_2"));
        BTN_OUTLET_CELL_2->setMinimumSize(QSize(0, 30));
        BTN_OUTLET_CELL_2->setMaximumSize(QSize(50, 30));

        gridLayout->addWidget(BTN_OUTLET_CELL_2, 2, 1, 1, 1);

        LE_OUTLET_CELL_4 = new QLineEdit(layoutWidget1);
        LE_OUTLET_CELL_4->setObjectName(QString::fromUtf8("LE_OUTLET_CELL_4"));
        LE_OUTLET_CELL_4->setMinimumSize(QSize(30, 30));
        LE_OUTLET_CELL_4->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(LE_OUTLET_CELL_4, 1, 2, 1, 1);

        LE_OUTLET_CELL_1 = new QLineEdit(layoutWidget1);
        LE_OUTLET_CELL_1->setObjectName(QString::fromUtf8("LE_OUTLET_CELL_1"));
        LE_OUTLET_CELL_1->setMinimumSize(QSize(30, 30));
        LE_OUTLET_CELL_1->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(LE_OUTLET_CELL_1, 1, 0, 1, 1);

        BTN_OUTLET_CELL_5 = new QPushButton(layoutWidget1);
        BTN_OUTLET_CELL_5->setObjectName(QString::fromUtf8("BTN_OUTLET_CELL_5"));
        BTN_OUTLET_CELL_5->setMinimumSize(QSize(0, 30));
        BTN_OUTLET_CELL_5->setMaximumSize(QSize(50, 30));

        gridLayout->addWidget(BTN_OUTLET_CELL_5, 2, 3, 1, 1);

        BTN_OUTLET_CELL_6 = new QPushButton(layoutWidget1);
        BTN_OUTLET_CELL_6->setObjectName(QString::fromUtf8("BTN_OUTLET_CELL_6"));
        BTN_OUTLET_CELL_6->setMinimumSize(QSize(0, 30));
        BTN_OUTLET_CELL_6->setMaximumSize(QSize(50, 30));

        gridLayout->addWidget(BTN_OUTLET_CELL_6, 3, 3, 1, 1);

        LE_OUTLET_CELL_5 = new QLineEdit(layoutWidget1);
        LE_OUTLET_CELL_5->setObjectName(QString::fromUtf8("LE_OUTLET_CELL_5"));
        LE_OUTLET_CELL_5->setMinimumSize(QSize(30, 30));
        LE_OUTLET_CELL_5->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(LE_OUTLET_CELL_5, 2, 2, 1, 1);

        BTN_OUTLET_CELL_1 = new QPushButton(layoutWidget1);
        BTN_OUTLET_CELL_1->setObjectName(QString::fromUtf8("BTN_OUTLET_CELL_1"));
        BTN_OUTLET_CELL_1->setMinimumSize(QSize(0, 30));
        BTN_OUTLET_CELL_1->setMaximumSize(QSize(50, 30));

        gridLayout->addWidget(BTN_OUTLET_CELL_1, 1, 1, 1, 1);

        LE_OUTLET_CELL_3 = new QLineEdit(layoutWidget1);
        LE_OUTLET_CELL_3->setObjectName(QString::fromUtf8("LE_OUTLET_CELL_3"));
        LE_OUTLET_CELL_3->setMinimumSize(QSize(30, 30));
        LE_OUTLET_CELL_3->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(LE_OUTLET_CELL_3, 3, 0, 1, 1);

        LE_OUTLET_CELL_6 = new QLineEdit(layoutWidget1);
        LE_OUTLET_CELL_6->setObjectName(QString::fromUtf8("LE_OUTLET_CELL_6"));
        LE_OUTLET_CELL_6->setMinimumSize(QSize(30, 30));
        LE_OUTLET_CELL_6->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(LE_OUTLET_CELL_6, 3, 2, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font3.setPointSize(12);
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 2);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font3);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 0, 2, 1, 2);

        BTN_OP_OUTLET_INIT = new QPushButton(OUTLET_2);
        BTN_OP_OUTLET_INIT->setObjectName(QString::fromUtf8("BTN_OP_OUTLET_INIT"));
        BTN_OP_OUTLET_INIT->setGeometry(QRect(480, 160, 75, 51));
        SW_OP->addWidget(OUTLET_2);
        line_2 = new QFrame(groupBox_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(30, 150, 541, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        SW_MAIN->addWidget(PAGE_OPER);
        PAGE_SUPER_STOP = new QWidget();
        PAGE_SUPER_STOP->setObjectName(QString::fromUtf8("PAGE_SUPER_STOP"));
        groupBox_3 = new QGroupBox(PAGE_SUPER_STOP);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 0, 600, 500));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox  {\n"
"    margin-top: 10px;\n"
"	font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"\n"
"QGroupBox::title  {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 10px 8000px 10px 8000px;\n"
"    background-color: red;\n"
"    color: rgb(255, 255, 255);\n"
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
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"\n"
"\n"
"\n"
""));
        SW_SS = new QStackedWidget(groupBox_3);
        SW_SS->setObjectName(QString::fromUtf8("SW_SS"));
        SW_SS->setGeometry(QRect(0, 58, 600, 441));
        SW_SS->setStyleSheet(QString::fromUtf8(""));
        SUPERSTOP = new QWidget();
        SUPERSTOP->setObjectName(QString::fromUtf8("SUPERSTOP"));
        LB_SS_DETAIL = new QLabel(SUPERSTOP);
        LB_SS_DETAIL->setObjectName(QString::fromUtf8("LB_SS_DETAIL"));
        LB_SS_DETAIL->setGeometry(QRect(30, 40, 541, 61));
        LB_SS_DETAIL->setFont(font2);
        LB_SS_DETAIL->setAlignment(Qt::AlignCenter);
        line_4 = new QFrame(SUPERSTOP);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(30, 100, 541, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        BTN_SS_CANCEL = new QPushButton(SUPERSTOP);
        BTN_SS_CANCEL->setObjectName(QString::fromUtf8("BTN_SS_CANCEL"));
        BTN_SS_CANCEL->setGeometry(QRect(520, 10, 61, 41));
        SW_SS_DETAIL = new QStackedWidget(SUPERSTOP);
        SW_SS_DETAIL->setObjectName(QString::fromUtf8("SW_SS_DETAIL"));
        SW_SS_DETAIL->setGeometry(QRect(10, 120, 581, 291));
        ROBOT1_4 = new QWidget();
        ROBOT1_4->setObjectName(QString::fromUtf8("ROBOT1_4"));
        IMAGE_SS = new QLabel(ROBOT1_4);
        IMAGE_SS->setObjectName(QString::fromUtf8("IMAGE_SS"));
        IMAGE_SS->setGeometry(QRect(20, 10, 450, 250));
        IMAGE_SS->setPixmap(QPixmap(QString::fromUtf8(":/build/image/error/pof.png")));
        IMAGE_SS->setScaledContents(true);
        IMAGE_SS->setAlignment(Qt::AlignCenter);
        BTN_SS = new QPushButton(ROBOT1_4);
        BTN_SS->setObjectName(QString::fromUtf8("BTN_SS"));
        BTN_SS->setGeometry(QRect(480, 80, 75, 51));
        BTN_SS_INIT = new QPushButton(ROBOT1_4);
        BTN_SS_INIT->setObjectName(QString::fromUtf8("BTN_SS_INIT"));
        BTN_SS_INIT->setGeometry(QRect(480, 20, 75, 51));
        BTN_SS_2 = new QPushButton(ROBOT1_4);
        BTN_SS_2->setObjectName(QString::fromUtf8("BTN_SS_2"));
        BTN_SS_2->setGeometry(QRect(480, 140, 75, 51));
        BTN_SS_3 = new QPushButton(ROBOT1_4);
        BTN_SS_3->setObjectName(QString::fromUtf8("BTN_SS_3"));
        BTN_SS_3->setGeometry(QRect(480, 200, 75, 51));
        SW_SS_DETAIL->addWidget(ROBOT1_4);
        layoutWidget_3 = new QWidget(SUPERSTOP);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(20, 10, 166, 28));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_4);

        LB_SS_ERROR_CODE = new QLabel(layoutWidget_3);
        LB_SS_ERROR_CODE->setObjectName(QString::fromUtf8("LB_SS_ERROR_CODE"));
        LB_SS_ERROR_CODE->setFont(font1);
        LB_SS_ERROR_CODE->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(LB_SS_ERROR_CODE);

        SW_SS->addWidget(SUPERSTOP);
        SW_MAIN->addWidget(PAGE_SUPER_STOP);
        PAGE_NOTICE = new QWidget();
        PAGE_NOTICE->setObjectName(QString::fromUtf8("PAGE_NOTICE"));
        groupBox_4 = new QGroupBox(PAGE_NOTICE);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 0, 600, 500));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox  {\n"
"    margin-top: 10px;\n"
"	font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"\n"
"QGroupBox::title  {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 10px 8000px 10px 8000px;\n"
"    background-color: #FFCC00;\n"
"    color: rgb(255, 255, 255);\n"
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
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"\n"
"\n"
"\n"
""));
        SW_INIT_5 = new QStackedWidget(groupBox_4);
        SW_INIT_5->setObjectName(QString::fromUtf8("SW_INIT_5"));
        SW_INIT_5->setGeometry(QRect(0, 58, 600, 441));
        SW_INIT_5->setStyleSheet(QString::fromUtf8(""));
        ERROR_CONNECTION_5 = new QWidget();
        ERROR_CONNECTION_5->setObjectName(QString::fromUtf8("ERROR_CONNECTION_5"));
        LB_ICE_ERROR_DETAIL_5 = new QLabel(ERROR_CONNECTION_5);
        LB_ICE_ERROR_DETAIL_5->setObjectName(QString::fromUtf8("LB_ICE_ERROR_DETAIL_5"));
        LB_ICE_ERROR_DETAIL_5->setGeometry(QRect(30, 60, 541, 61));
        LB_ICE_ERROR_DETAIL_5->setFont(font2);
        LB_ICE_ERROR_DETAIL_5->setAlignment(Qt::AlignCenter);
        line_5 = new QFrame(ERROR_CONNECTION_5);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(30, 120, 541, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        BTN_INIT_CANCEL_5 = new QPushButton(ERROR_CONNECTION_5);
        BTN_INIT_CANCEL_5->setObjectName(QString::fromUtf8("BTN_INIT_CANCEL_5"));
        BTN_INIT_CANCEL_5->setGeometry(QRect(520, 10, 61, 41));
        SW_INIT_CON_5 = new QStackedWidget(ERROR_CONNECTION_5);
        SW_INIT_CON_5->setObjectName(QString::fromUtf8("SW_INIT_CON_5"));
        SW_INIT_CON_5->setGeometry(QRect(10, 140, 581, 291));
        ROBOT1_5 = new QWidget();
        ROBOT1_5->setObjectName(QString::fromUtf8("ROBOT1_5"));
        LB_ICE_ERROR_IMAGE_5 = new QLabel(ROBOT1_5);
        LB_ICE_ERROR_IMAGE_5->setObjectName(QString::fromUtf8("LB_ICE_ERROR_IMAGE_5"));
        LB_ICE_ERROR_IMAGE_5->setGeometry(QRect(20, 20, 450, 250));
        LB_ICE_ERROR_IMAGE_5->setPixmap(QPixmap(QString::fromUtf8(":/build/image/outlet_c.png")));
        LB_ICE_ERROR_IMAGE_5->setScaledContents(true);
        LB_ICE_ERROR_IMAGE_5->setAlignment(Qt::AlignCenter);
        BTN_INIT_NEXT1_5 = new QPushButton(ROBOT1_5);
        BTN_INIT_NEXT1_5->setObjectName(QString::fromUtf8("BTN_INIT_NEXT1_5"));
        BTN_INIT_NEXT1_5->setGeometry(QRect(490, 30, 75, 51));
        BTN_INIT_NEXT2_5 = new QPushButton(ROBOT1_5);
        BTN_INIT_NEXT2_5->setObjectName(QString::fromUtf8("BTN_INIT_NEXT2_5"));
        BTN_INIT_NEXT2_5->setGeometry(QRect(490, 90, 75, 51));
        BTN_INIT_AGAIN_5 = new QPushButton(ROBOT1_5);
        BTN_INIT_AGAIN_5->setObjectName(QString::fromUtf8("BTN_INIT_AGAIN_5"));
        BTN_INIT_AGAIN_5->setGeometry(QRect(490, 150, 75, 51));
        SW_INIT_CON_5->addWidget(ROBOT1_5);
        ROBOT2_5 = new QWidget();
        ROBOT2_5->setObjectName(QString::fromUtf8("ROBOT2_5"));
        SW_INIT_CON_5->addWidget(ROBOT2_5);
        layoutWidget_4 = new QWidget(ERROR_CONNECTION_5);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(20, 10, 166, 28));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_5);

        LB_ICE_ERROR_CODE_5 = new QLabel(layoutWidget_4);
        LB_ICE_ERROR_CODE_5->setObjectName(QString::fromUtf8("LB_ICE_ERROR_CODE_5"));
        LB_ICE_ERROR_CODE_5->setFont(font1);
        LB_ICE_ERROR_CODE_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(LB_ICE_ERROR_CODE_5);

        SW_INIT_5->addWidget(ERROR_CONNECTION_5);
        ERROR_ROBOT_5 = new QWidget();
        ERROR_ROBOT_5->setObjectName(QString::fromUtf8("ERROR_ROBOT_5"));
        SW_INIT_5->addWidget(ERROR_ROBOT_5);
        ERROR_CON2NECTION_5 = new QWidget();
        ERROR_CON2NECTION_5->setObjectName(QString::fromUtf8("ERROR_CON2NECTION_5"));
        SW_INIT_5->addWidget(ERROR_CON2NECTION_5);
        SW_MAIN->addWidget(PAGE_NOTICE);

        retranslateUi(DialogNotice);

        SW_MAIN->setCurrentIndex(1);
        SW_INIT_CON->setCurrentIndex(1);
        SW_OP->setCurrentIndex(0);
        SW_SS->setCurrentIndex(0);
        SW_INIT_5->setCurrentIndex(0);
        SW_INIT_CON_5->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogNotice);
    } // setupUi

    void retranslateUi(QDialog *DialogNotice)
    {
        DialogNotice->setWindowTitle(QCoreApplication::translate("DialogNotice", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogNotice", "\354\264\210\352\270\260\355\231\224 \354\227\220\353\237\254 \353\260\234\354\203\235", nullptr));
        label->setText(QCoreApplication::translate("DialogNotice", "\354\227\220\353\237\254 \354\275\224\353\223\234 :", nullptr));
        LB_INIT_ERROR_CODE->setText(QCoreApplication::translate("DialogNotice", "CON-R1", nullptr));
        BTN_INIT_CANCEL->setText(QCoreApplication::translate("DialogNotice", "\354\267\250\354\206\214", nullptr));
        IMAGE_INIT_CON_ROBOT->setText(QString());
        BTN_INIT_CON_ROBOT_1->setText(QCoreApplication::translate("DialogNotice", "\353\213\244\354\235\2141", nullptr));
        BTN_INIT_CON_ROBOT_2->setText(QCoreApplication::translate("DialogNotice", "\353\213\244\354\235\2142", nullptr));
        BTN_INIT_CON_ROBOT_INIT->setText(QCoreApplication::translate("DialogNotice", "\354\264\210\352\270\260\355\231\224", nullptr));
        LE_CON_ROBOT_CMD->setText(QCoreApplication::translate("DialogNotice", "\354\227\260\352\262\260 \353\220\250", nullptr));
        LE_CON_ROBOT_DATA->setText(QCoreApplication::translate("DialogNotice", "\354\227\260\352\262\260 \353\220\250", nullptr));
        BTN_INIT_CON_BOARD_INIT->setText(QCoreApplication::translate("DialogNotice", "\354\264\210\352\270\260\355\231\224", nullptr));
        LE_CON_BOARD->setText(QCoreApplication::translate("DialogNotice", "\354\227\260\352\262\260 \353\220\250", nullptr));
        BTN_INIT_CON_BOARD_1->setText(QCoreApplication::translate("DialogNotice", "\353\213\244\354\235\2141", nullptr));
        IMAGE_INIT_CON_BOARD->setText(QString());
        BTN_INIT_CON_BOARD_2->setText(QCoreApplication::translate("DialogNotice", "\353\213\244\354\235\2142", nullptr));
        IMAGE_INIT_ROBOT->setText(QString());
        BTN_INIT_ROBOT_INIT->setText(QCoreApplication::translate("DialogNotice", "\354\264\210\352\270\260\355\231\224", nullptr));
        LE_INIT_ROBOT_BASE->setText(QCoreApplication::translate("DialogNotice", "\353\262\240\354\235\264\354\212\244", nullptr));
        LE_INIT_ROBOT_INBOX->setText(QCoreApplication::translate("DialogNotice", "\354\234\204\354\271\230", nullptr));
        LE_INIT_ROBOT_COL->setText(QCoreApplication::translate("DialogNotice", "\354\236\220\352\260\200\354\266\251\353\217\214", nullptr));
        BTN_INIT_ROBOT_PROGRAM_EXIT->setText(QCoreApplication::translate("DialogNotice", "\355\224\204\353\241\234\352\267\270\353\236\250 \354\242\205\353\243\214", nullptr));
        LB_INIT_ROBOT_BASE->setText(QCoreApplication::translate("DialogNotice", "(50 ~ 100)", nullptr));
        LB_INIT_ERROR_DETAIL->setText(QCoreApplication::translate("DialogNotice", "\353\241\234\353\264\207\352\263\274 \354\227\260\352\262\260\354\235\264 \353\220\230\354\247\200 \354\225\212\354\212\265\353\213\210\353\213\244.", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DialogNotice", "\354\232\264\354\230\201\354\213\234\354\236\221 \354\227\220\353\237\254 \353\260\234\354\203\235", nullptr));
        label_2->setText(QCoreApplication::translate("DialogNotice", "\354\227\220\353\237\254 \354\275\224\353\223\234 :", nullptr));
        LB_OP_ERROR_CODE->setText(QCoreApplication::translate("DialogNotice", "CON-R1", nullptr));
        BTN_OP_CANCEL->setText(QCoreApplication::translate("DialogNotice", "\354\267\250\354\206\214", nullptr));
        LB_OP_ERROR_DETAIL->setText(QCoreApplication::translate("DialogNotice", "\353\241\234\353\264\207\352\263\274 \354\227\260\352\262\260\354\235\264 \353\220\230\354\247\200 \354\225\212\354\212\265\353\213\210\353\213\244.", nullptr));
        BTN_OP_INIT_FIRST->setText(QCoreApplication::translate("DialogNotice", "\354\264\210\352\270\260\355\231\224", nullptr));
        IMAGE_INIT_ROBOT_2->setText(QString());
        BTN_INIT_ROBOT_INIT_2->setText(QCoreApplication::translate("DialogNotice", "\354\232\264\354\230\201\354\213\234\354\236\221", nullptr));
        LE_INIT_ROBOT_BASE_2->setText(QCoreApplication::translate("DialogNotice", "0", nullptr));
        LE_INIT_ROBOT_INBOX_2->setText(QCoreApplication::translate("DialogNotice", "\354\234\204\354\271\230", nullptr));
        LE_INIT_ROBOT_COL_2->setText(QCoreApplication::translate("DialogNotice", "\354\236\220\352\260\200\354\266\251\353\217\214", nullptr));
        BTN_INIT_ROBOT_PROGRAM_EXIT_2->setText(QCoreApplication::translate("DialogNotice", "\355\224\204\353\241\234\352\267\270\353\236\250 \354\242\205\353\243\214", nullptr));
        LB_INIT_ROBOT_BASE_2->setText(QCoreApplication::translate("DialogNotice", "(50 ~ 100)", nullptr));
        LB_INIT_ROBOT_BASE_3->setText(QCoreApplication::translate("DialogNotice", "\353\262\240\354\235\264\354\212\244", nullptr));
        IMAGE_INIT_DOOR_2->setText(QString());
        BTN_INIT_DOOR_INIT_2->setText(QCoreApplication::translate("DialogNotice", "\354\232\264\354\230\201\354\213\234\354\236\221", nullptr));
        LE_DOOR_2->setText(QCoreApplication::translate("DialogNotice", "\353\254\270 \354\227\264\353\246\274", nullptr));
        IMAGE_OP_OUTLET->setText(QString());
        BTN_OP_OUTLET_1->setText(QCoreApplication::translate("DialogNotice", "\353\213\244\354\235\2141", nullptr));
        BTN_OP_OUTLET_START->setText(QCoreApplication::translate("DialogNotice", "\354\232\264\354\230\201\354\213\234\354\236\221", nullptr));
        BTN_OUTLET_CELL_3->setText(QCoreApplication::translate("DialogNotice", "\353\260\260\354\266\234", nullptr));
        BTN_OUTLET_CELL_4->setText(QCoreApplication::translate("DialogNotice", "\353\260\260\354\266\234", nullptr));
        BTN_OUTLET_CELL_2->setText(QCoreApplication::translate("DialogNotice", "\353\260\260\354\266\234", nullptr));
        BTN_OUTLET_CELL_5->setText(QCoreApplication::translate("DialogNotice", "\353\260\260\354\266\234", nullptr));
        BTN_OUTLET_CELL_6->setText(QCoreApplication::translate("DialogNotice", "\353\260\260\354\266\234", nullptr));
        BTN_OUTLET_CELL_1->setText(QCoreApplication::translate("DialogNotice", "\353\260\260\354\266\234", nullptr));
        label_3->setText(QCoreApplication::translate("DialogNotice", "\353\260\260\354\266\234\352\265\254 1", nullptr));
        label_6->setText(QCoreApplication::translate("DialogNotice", "\353\260\260\354\266\234\352\265\254 2", nullptr));
        BTN_OP_OUTLET_INIT->setText(QCoreApplication::translate("DialogNotice", "\354\264\210\352\270\260\355\231\224", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("DialogNotice", "\352\260\225\354\240\234 \354\232\264\354\230\201 \354\242\205\353\243\214 \353\220\250", nullptr));
        LB_SS_DETAIL->setText(QCoreApplication::translate("DialogNotice", "\353\241\234\353\264\207\352\263\274 \354\227\260\352\262\260\354\235\264 \353\220\230\354\247\200 \354\225\212\354\212\265\353\213\210\353\213\244.", nullptr));
        BTN_SS_CANCEL->setText(QCoreApplication::translate("DialogNotice", "\354\267\250\354\206\214", nullptr));
        IMAGE_SS->setText(QString());
        BTN_SS->setText(QCoreApplication::translate("DialogNotice", "\354\273\265 \354\266\224\352\260\200\354\231\204\353\243\214", nullptr));
        BTN_SS_INIT->setText(QCoreApplication::translate("DialogNotice", "\354\264\210\352\270\260\355\231\224", nullptr));
        BTN_SS_2->setText(QCoreApplication::translate("DialogNotice", "\354\273\265 \353\260\260\354\266\234 1", nullptr));
        BTN_SS_3->setText(QCoreApplication::translate("DialogNotice", "\354\273\265 \353\260\260\354\266\234 2", nullptr));
        label_4->setText(QCoreApplication::translate("DialogNotice", "\354\227\220\353\237\254 \354\275\224\353\223\234 :", nullptr));
        LB_SS_ERROR_CODE->setText(QCoreApplication::translate("DialogNotice", "CON-R1", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("DialogNotice", "\354\203\201\355\203\234 \354\235\264\354\203\201 \354\225\214\353\246\274", nullptr));
        LB_ICE_ERROR_DETAIL_5->setText(QCoreApplication::translate("DialogNotice", "\353\241\234\353\264\207\352\263\274 \354\227\260\352\262\260\354\235\264 \353\220\230\354\247\200 \354\225\212\354\212\265\353\213\210\353\213\244.", nullptr));
        BTN_INIT_CANCEL_5->setText(QCoreApplication::translate("DialogNotice", "\354\267\250\354\206\214", nullptr));
        LB_ICE_ERROR_IMAGE_5->setText(QString());
        BTN_INIT_NEXT1_5->setText(QCoreApplication::translate("DialogNotice", "\353\213\244\354\235\2141", nullptr));
        BTN_INIT_NEXT2_5->setText(QCoreApplication::translate("DialogNotice", "\353\213\244\354\235\2142", nullptr));
        BTN_INIT_AGAIN_5->setText(QCoreApplication::translate("DialogNotice", "\354\264\210\352\270\260\355\231\224", nullptr));
        label_5->setText(QCoreApplication::translate("DialogNotice", "\354\227\220\353\237\254 \354\275\224\353\223\234 :", nullptr));
        LB_ICE_ERROR_CODE_5->setText(QCoreApplication::translate("DialogNotice", "CON-R1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogNotice: public Ui_DialogNotice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGNOTICE_H
