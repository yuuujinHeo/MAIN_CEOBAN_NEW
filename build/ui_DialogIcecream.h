/********************************************************************************
** Form generated from reading UI file 'DialogIcecream.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGICECREAM_H
#define UI_DIALOGICECREAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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

class Ui_DialogIcecream
{
public:
    QGroupBox *GB_ICECREAM;
    QLineEdit *LE_ICECREAM_CONNECTION;
    QLabel *label_110;
    QFrame *line_37;
    QFrame *line_39;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *LE_DISPENSE_COUNT;
    QLabel *label_112;
    QPushButton *BTN_SET_SCALE_2;
    QLineEdit *LE_LOADCELL_ERROR;
    QLineEdit *LE_LOADCELL_ERROR_2;
    QPushButton *BTN_SET_SCALE;
    QLineEdit *LE_OP_STATE;
    QLabel *label_114;
    QLineEdit *LE_LAST_DISPENSE_ERROR;
    QLabel *label_113;
    QLineEdit *LE_LOADCELL_SET_SCALE;
    QLabel *label_116;
    QLabel *label_119;
    QLineEdit *LE_LOADCELL_SET_SCALE_2;
    QLineEdit *LE_LOADCELL_WEIGHT;
    QLineEdit *LE_LOADCELL_WEIGHT_2;
    QLabel *label_117;
    QLineEdit *LE_LOADCELL_SCALE_2;
    QLineEdit *LE_LOADCELL_SCALE;
    QLabel *label_118;
    QLineEdit *LE_LOADCELL_TOTAL_WEIGHT;
    QPushButton *BTN_TARE;
    QCheckBox *CB_SCALE_TEST;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QFrame *FRAME_CYLINDER;
    QPushButton *BTN_DISPENSE_ICECREAM_BY_WEIGHT;
    QLabel *label_27;
    QLineEdit *LE_OUT_WEIGHT;
    QLabel *label_121;
    QPushButton *BTN_ICECREAM_CLEANING_STOP;
    QPushButton *BTN_ICECREAM_CLEANING_START;
    QFrame *FRAME_NONE;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *LE_LOADCELL_THRESHOLD;
    QLabel *label_6;
    QPushButton *BTN_ROBOT_STOP;
    QPushButton *BTN_START_MEASURE;

    void setupUi(QDialog *DialogIcecream)
    {
        if (DialogIcecream->objectName().isEmpty())
            DialogIcecream->setObjectName(QString::fromUtf8("DialogIcecream"));
        DialogIcecream->resize(400, 960);
        GB_ICECREAM = new QGroupBox(DialogIcecream);
        GB_ICECREAM->setObjectName(QString::fromUtf8("GB_ICECREAM"));
        GB_ICECREAM->setGeometry(QRect(0, 0, 400, 960));
        QFont font;
        font.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        GB_ICECREAM->setFont(font);
        GB_ICECREAM->setStyleSheet(QString::fromUtf8("QGroupBox  {\n"
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
        LE_ICECREAM_CONNECTION = new QLineEdit(GB_ICECREAM);
        LE_ICECREAM_CONNECTION->setObjectName(QString::fromUtf8("LE_ICECREAM_CONNECTION"));
        LE_ICECREAM_CONNECTION->setGeometry(QRect(120, 70, 61, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        LE_ICECREAM_CONNECTION->setFont(font1);
        LE_ICECREAM_CONNECTION->setReadOnly(true);
        label_110 = new QLabel(GB_ICECREAM);
        label_110->setObjectName(QString::fromUtf8("label_110"));
        label_110->setGeometry(QRect(10, 70, 101, 21));
        label_110->setFont(font1);
        label_110->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line_37 = new QFrame(GB_ICECREAM);
        line_37->setObjectName(QString::fromUtf8("line_37"));
        line_37->setGeometry(QRect(10, 100, 371, 16));
        QFont font2;
        font2.setPointSize(11);
        line_37->setFont(font2);
        line_37->setFrameShape(QFrame::HLine);
        line_37->setFrameShadow(QFrame::Sunken);
        line_39 = new QFrame(GB_ICECREAM);
        line_39->setObjectName(QString::fromUtf8("line_39"));
        line_39->setGeometry(QRect(10, 590, 361, 16));
        line_39->setFont(font2);
        line_39->setFrameShape(QFrame::HLine);
        line_39->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(GB_ICECREAM);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(27, 620, 351, 251));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        LE_DISPENSE_COUNT = new QLineEdit(layoutWidget);
        LE_DISPENSE_COUNT->setObjectName(QString::fromUtf8("LE_DISPENSE_COUNT"));
        LE_DISPENSE_COUNT->setMaximumSize(QSize(80, 16777215));
        LE_DISPENSE_COUNT->setFont(font1);
        LE_DISPENSE_COUNT->setReadOnly(true);

        gridLayout->addWidget(LE_DISPENSE_COUNT, 5, 1, 1, 1);

        label_112 = new QLabel(layoutWidget);
        label_112->setObjectName(QString::fromUtf8("label_112"));
        label_112->setFont(font1);
        label_112->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_112, 5, 0, 1, 1);

        BTN_SET_SCALE_2 = new QPushButton(layoutWidget);
        BTN_SET_SCALE_2->setObjectName(QString::fromUtf8("BTN_SET_SCALE_2"));
        BTN_SET_SCALE_2->setMaximumSize(QSize(80, 16777215));
        BTN_SET_SCALE_2->setFont(font1);

        gridLayout->addWidget(BTN_SET_SCALE_2, 4, 2, 1, 1);

        LE_LOADCELL_ERROR = new QLineEdit(layoutWidget);
        LE_LOADCELL_ERROR->setObjectName(QString::fromUtf8("LE_LOADCELL_ERROR"));
        LE_LOADCELL_ERROR->setMaximumSize(QSize(80, 16777215));
        LE_LOADCELL_ERROR->setFont(font1);
        LE_LOADCELL_ERROR->setReadOnly(true);

        gridLayout->addWidget(LE_LOADCELL_ERROR, 2, 1, 1, 1);

        LE_LOADCELL_ERROR_2 = new QLineEdit(layoutWidget);
        LE_LOADCELL_ERROR_2->setObjectName(QString::fromUtf8("LE_LOADCELL_ERROR_2"));
        LE_LOADCELL_ERROR_2->setMaximumSize(QSize(80, 16777215));
        LE_LOADCELL_ERROR_2->setFont(font1);
        LE_LOADCELL_ERROR_2->setReadOnly(true);

        gridLayout->addWidget(LE_LOADCELL_ERROR_2, 2, 2, 1, 1);

        BTN_SET_SCALE = new QPushButton(layoutWidget);
        BTN_SET_SCALE->setObjectName(QString::fromUtf8("BTN_SET_SCALE"));
        BTN_SET_SCALE->setMaximumSize(QSize(80, 16777215));
        BTN_SET_SCALE->setFont(font1);

        gridLayout->addWidget(BTN_SET_SCALE, 4, 1, 1, 1);

        LE_OP_STATE = new QLineEdit(layoutWidget);
        LE_OP_STATE->setObjectName(QString::fromUtf8("LE_OP_STATE"));
        LE_OP_STATE->setMaximumSize(QSize(80, 16777215));
        LE_OP_STATE->setFont(font1);
        LE_OP_STATE->setReadOnly(true);

        gridLayout->addWidget(LE_OP_STATE, 7, 1, 1, 1);

        label_114 = new QLabel(layoutWidget);
        label_114->setObjectName(QString::fromUtf8("label_114"));
        label_114->setFont(font1);
        label_114->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_114, 7, 0, 1, 1);

        LE_LAST_DISPENSE_ERROR = new QLineEdit(layoutWidget);
        LE_LAST_DISPENSE_ERROR->setObjectName(QString::fromUtf8("LE_LAST_DISPENSE_ERROR"));
        LE_LAST_DISPENSE_ERROR->setMaximumSize(QSize(80, 16777215));
        LE_LAST_DISPENSE_ERROR->setFont(font1);
        LE_LAST_DISPENSE_ERROR->setReadOnly(true);

        gridLayout->addWidget(LE_LAST_DISPENSE_ERROR, 6, 1, 1, 1);

        label_113 = new QLabel(layoutWidget);
        label_113->setObjectName(QString::fromUtf8("label_113"));
        label_113->setFont(font1);
        label_113->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_113, 6, 0, 1, 1);

        LE_LOADCELL_SET_SCALE = new QLineEdit(layoutWidget);
        LE_LOADCELL_SET_SCALE->setObjectName(QString::fromUtf8("LE_LOADCELL_SET_SCALE"));
        LE_LOADCELL_SET_SCALE->setMaximumSize(QSize(80, 16777215));
        LE_LOADCELL_SET_SCALE->setFont(font1);
        LE_LOADCELL_SET_SCALE->setReadOnly(false);

        gridLayout->addWidget(LE_LOADCELL_SET_SCALE, 3, 1, 1, 1);

        label_116 = new QLabel(layoutWidget);
        label_116->setObjectName(QString::fromUtf8("label_116"));
        label_116->setFont(font1);
        label_116->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_116, 0, 0, 1, 1);

        label_119 = new QLabel(layoutWidget);
        label_119->setObjectName(QString::fromUtf8("label_119"));
        label_119->setFont(font1);
        label_119->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_119, 3, 0, 1, 1);

        LE_LOADCELL_SET_SCALE_2 = new QLineEdit(layoutWidget);
        LE_LOADCELL_SET_SCALE_2->setObjectName(QString::fromUtf8("LE_LOADCELL_SET_SCALE_2"));
        LE_LOADCELL_SET_SCALE_2->setMaximumSize(QSize(80, 16777215));
        LE_LOADCELL_SET_SCALE_2->setFont(font1);
        LE_LOADCELL_SET_SCALE_2->setReadOnly(false);

        gridLayout->addWidget(LE_LOADCELL_SET_SCALE_2, 3, 2, 1, 1);

        LE_LOADCELL_WEIGHT = new QLineEdit(layoutWidget);
        LE_LOADCELL_WEIGHT->setObjectName(QString::fromUtf8("LE_LOADCELL_WEIGHT"));
        LE_LOADCELL_WEIGHT->setMaximumSize(QSize(80, 16777215));
        LE_LOADCELL_WEIGHT->setFont(font1);
        LE_LOADCELL_WEIGHT->setReadOnly(true);

        gridLayout->addWidget(LE_LOADCELL_WEIGHT, 0, 1, 1, 1);

        LE_LOADCELL_WEIGHT_2 = new QLineEdit(layoutWidget);
        LE_LOADCELL_WEIGHT_2->setObjectName(QString::fromUtf8("LE_LOADCELL_WEIGHT_2"));
        LE_LOADCELL_WEIGHT_2->setMaximumSize(QSize(80, 16777215));
        LE_LOADCELL_WEIGHT_2->setFont(font1);
        LE_LOADCELL_WEIGHT_2->setReadOnly(true);

        gridLayout->addWidget(LE_LOADCELL_WEIGHT_2, 0, 2, 1, 1);

        label_117 = new QLabel(layoutWidget);
        label_117->setObjectName(QString::fromUtf8("label_117"));
        label_117->setFont(font1);
        label_117->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_117, 1, 0, 1, 1);

        LE_LOADCELL_SCALE_2 = new QLineEdit(layoutWidget);
        LE_LOADCELL_SCALE_2->setObjectName(QString::fromUtf8("LE_LOADCELL_SCALE_2"));
        LE_LOADCELL_SCALE_2->setMaximumSize(QSize(80, 16777215));
        LE_LOADCELL_SCALE_2->setFont(font1);
        LE_LOADCELL_SCALE_2->setReadOnly(true);

        gridLayout->addWidget(LE_LOADCELL_SCALE_2, 1, 2, 1, 1);

        LE_LOADCELL_SCALE = new QLineEdit(layoutWidget);
        LE_LOADCELL_SCALE->setObjectName(QString::fromUtf8("LE_LOADCELL_SCALE"));
        LE_LOADCELL_SCALE->setMaximumSize(QSize(80, 16777215));
        LE_LOADCELL_SCALE->setFont(font1);
        LE_LOADCELL_SCALE->setReadOnly(true);

        gridLayout->addWidget(LE_LOADCELL_SCALE, 1, 1, 1, 1);

        label_118 = new QLabel(layoutWidget);
        label_118->setObjectName(QString::fromUtf8("label_118"));
        label_118->setFont(font1);
        label_118->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_118, 2, 0, 1, 1);

        LE_LOADCELL_TOTAL_WEIGHT = new QLineEdit(layoutWidget);
        LE_LOADCELL_TOTAL_WEIGHT->setObjectName(QString::fromUtf8("LE_LOADCELL_TOTAL_WEIGHT"));
        LE_LOADCELL_TOTAL_WEIGHT->setFont(font1);
        LE_LOADCELL_TOTAL_WEIGHT->setReadOnly(true);

        gridLayout->addWidget(LE_LOADCELL_TOTAL_WEIGHT, 0, 3, 1, 1);

        BTN_TARE = new QPushButton(layoutWidget);
        BTN_TARE->setObjectName(QString::fromUtf8("BTN_TARE"));
        BTN_TARE->setFont(font1);

        gridLayout->addWidget(BTN_TARE, 1, 3, 1, 1);

        CB_SCALE_TEST = new QCheckBox(layoutWidget);
        CB_SCALE_TEST->setObjectName(QString::fromUtf8("CB_SCALE_TEST"));

        gridLayout->addWidget(CB_SCALE_TEST, 2, 3, 1, 1);

        layoutWidget1 = new QWidget(GB_ICECREAM);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 870, 283, 48));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        verticalLayout_2->addWidget(label_2);

        FRAME_CYLINDER = new QFrame(GB_ICECREAM);
        FRAME_CYLINDER->setObjectName(QString::fromUtf8("FRAME_CYLINDER"));
        FRAME_CYLINDER->setGeometry(QRect(20, 130, 361, 251));
        FRAME_CYLINDER->setFrameShape(QFrame::StyledPanel);
        FRAME_CYLINDER->setFrameShadow(QFrame::Raised);
        BTN_DISPENSE_ICECREAM_BY_WEIGHT = new QPushButton(FRAME_CYLINDER);
        BTN_DISPENSE_ICECREAM_BY_WEIGHT->setObjectName(QString::fromUtf8("BTN_DISPENSE_ICECREAM_BY_WEIGHT"));
        BTN_DISPENSE_ICECREAM_BY_WEIGHT->setEnabled(true);
        BTN_DISPENSE_ICECREAM_BY_WEIGHT->setGeometry(QRect(20, 40, 121, 61));
        BTN_DISPENSE_ICECREAM_BY_WEIGHT->setFont(font1);
        label_27 = new QLabel(FRAME_CYLINDER);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setEnabled(true);
        label_27->setGeometry(QRect(130, 10, 21, 21));
        label_27->setFont(font1);
        LE_OUT_WEIGHT = new QLineEdit(FRAME_CYLINDER);
        LE_OUT_WEIGHT->setObjectName(QString::fromUtf8("LE_OUT_WEIGHT"));
        LE_OUT_WEIGHT->setEnabled(true);
        LE_OUT_WEIGHT->setGeometry(QRect(70, 10, 51, 21));
        LE_OUT_WEIGHT->setFont(font1);
        LE_OUT_WEIGHT->setAlignment(Qt::AlignCenter);
        label_121 = new QLabel(FRAME_CYLINDER);
        label_121->setObjectName(QString::fromUtf8("label_121"));
        label_121->setEnabled(true);
        label_121->setGeometry(QRect(10, 10, 61, 21));
        label_121->setFont(font1);
        label_121->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        BTN_ICECREAM_CLEANING_STOP = new QPushButton(FRAME_CYLINDER);
        BTN_ICECREAM_CLEANING_STOP->setObjectName(QString::fromUtf8("BTN_ICECREAM_CLEANING_STOP"));
        BTN_ICECREAM_CLEANING_STOP->setEnabled(true);
        BTN_ICECREAM_CLEANING_STOP->setGeometry(QRect(180, 140, 121, 61));
        BTN_ICECREAM_CLEANING_STOP->setFont(font1);
        BTN_ICECREAM_CLEANING_START = new QPushButton(FRAME_CYLINDER);
        BTN_ICECREAM_CLEANING_START->setObjectName(QString::fromUtf8("BTN_ICECREAM_CLEANING_START"));
        BTN_ICECREAM_CLEANING_START->setEnabled(true);
        BTN_ICECREAM_CLEANING_START->setGeometry(QRect(50, 140, 121, 61));
        BTN_ICECREAM_CLEANING_START->setFont(font1);
        FRAME_NONE = new QFrame(GB_ICECREAM);
        FRAME_NONE->setObjectName(QString::fromUtf8("FRAME_NONE"));
        FRAME_NONE->setGeometry(QRect(20, 500, 361, 80));
        FRAME_NONE->setFrameShape(QFrame::StyledPanel);
        FRAME_NONE->setFrameShadow(QFrame::Raised);
        layoutWidget2 = new QWidget(FRAME_NONE);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 163, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        LE_LOADCELL_THRESHOLD = new QLineEdit(layoutWidget2);
        LE_LOADCELL_THRESHOLD->setObjectName(QString::fromUtf8("LE_LOADCELL_THRESHOLD"));
        LE_LOADCELL_THRESHOLD->setFont(font1);
        LE_LOADCELL_THRESHOLD->setReadOnly(false);

        horizontalLayout->addWidget(LE_LOADCELL_THRESHOLD);

        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        BTN_ROBOT_STOP = new QPushButton(FRAME_NONE);
        BTN_ROBOT_STOP->setObjectName(QString::fromUtf8("BTN_ROBOT_STOP"));
        BTN_ROBOT_STOP->setGeometry(QRect(270, 30, 81, 41));
        BTN_ROBOT_STOP->setFont(font1);
        BTN_START_MEASURE = new QPushButton(FRAME_NONE);
        BTN_START_MEASURE->setObjectName(QString::fromUtf8("BTN_START_MEASURE"));
        BTN_START_MEASURE->setGeometry(QRect(180, 30, 81, 41));
        BTN_START_MEASURE->setFont(font1);

        retranslateUi(DialogIcecream);

        QMetaObject::connectSlotsByName(DialogIcecream);
    } // setupUi

    void retranslateUi(QDialog *DialogIcecream)
    {
        DialogIcecream->setWindowTitle(QCoreApplication::translate("DialogIcecream", "Dialog", nullptr));
        GB_ICECREAM->setTitle(QCoreApplication::translate("DialogIcecream", "\354\225\204\354\235\264\354\212\244\355\201\254\353\246\274", nullptr));
        label_110->setText(QCoreApplication::translate("DialogIcecream", "\354\236\245\354\271\230 \354\227\260\352\262\260 \354\203\201\355\203\234", nullptr));
        label_112->setText(QCoreApplication::translate("DialogIcecream", "\354\266\234\354\210\230 \354\271\264\354\232\264\355\212\270", nullptr));
        BTN_SET_SCALE_2->setText(QCoreApplication::translate("DialogIcecream", "\354\204\244\354\240\225", nullptr));
        BTN_SET_SCALE->setText(QCoreApplication::translate("DialogIcecream", "\354\204\244\354\240\225", nullptr));
        label_114->setText(QCoreApplication::translate("DialogIcecream", "\355\230\204\354\236\254 \353\217\231\354\236\221\354\203\201\355\203\234", nullptr));
        label_113->setText(QCoreApplication::translate("DialogIcecream", "\354\265\234\354\242\205 \353\260\260\354\266\234\354\227\220\353\237\254", nullptr));
        label_116->setText(QCoreApplication::translate("DialogIcecream", "\353\241\234\353\223\234\354\205\200 \353\254\264\352\262\214", nullptr));
        label_119->setText(QCoreApplication::translate("DialogIcecream", "scale \354\204\244\354\240\225", nullptr));
        label_117->setText(QCoreApplication::translate("DialogIcecream", "\353\241\234\353\223\234\354\205\200 scale", nullptr));
        label_118->setText(QCoreApplication::translate("DialogIcecream", "\353\241\234\353\223\234\354\205\200 \354\227\220\353\237\254", nullptr));
        BTN_TARE->setText(QCoreApplication::translate("DialogIcecream", "\354\230\201\354\240\220", nullptr));
        CB_SCALE_TEST->setText(QCoreApplication::translate("DialogIcecream", "\355\205\214\354\212\244\355\212\270", nullptr));
        label->setText(QCoreApplication::translate("DialogIcecream", "E1: \352\270\260\354\241\264 \353\260\260\354\266\234 \353\217\231\354\236\221\354\235\264 \353\201\235\353\202\230\354\247\200 \354\225\212\354\225\230\353\212\224\353\215\260 \353\252\205\353\240\271 \353\260\233\354\235\214", nullptr));
        label_2->setText(QCoreApplication::translate("DialogIcecream", "E2: \354\265\234\353\214\200 \354\266\234\354\210\230 \354\213\234\352\260\204 \354\264\210\352\263\274", nullptr));
        BTN_DISPENSE_ICECREAM_BY_WEIGHT->setText(QCoreApplication::translate("DialogIcecream", "\354\225\204\354\235\264\354\212\244\355\201\254\353\246\274 \353\260\260\354\266\234", nullptr));
        label_27->setText(QCoreApplication::translate("DialogIcecream", "g", nullptr));
        LE_OUT_WEIGHT->setText(QCoreApplication::translate("DialogIcecream", "200", nullptr));
        label_121->setText(QCoreApplication::translate("DialogIcecream", "\353\254\264\352\262\214 \353\260\260\354\266\234", nullptr));
        BTN_ICECREAM_CLEANING_STOP->setText(QCoreApplication::translate("DialogIcecream", "\354\262\255\354\206\214 \354\242\205\353\243\214", nullptr));
        BTN_ICECREAM_CLEANING_START->setText(QCoreApplication::translate("DialogIcecream", "\354\262\255\354\206\214 \354\213\234\354\236\221", nullptr));
        label_5->setText(QCoreApplication::translate("DialogIcecream", "\353\254\264\352\262\214 \353\260\260\354\266\234", nullptr));
        label_6->setText(QCoreApplication::translate("DialogIcecream", "g", nullptr));
        BTN_ROBOT_STOP->setText(QCoreApplication::translate("DialogIcecream", "\352\260\225\354\240\234 \354\242\205\353\243\214", nullptr));
        BTN_START_MEASURE->setText(QCoreApplication::translate("DialogIcecream", "\354\270\241\354\240\225 \354\213\234\354\236\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogIcecream: public Ui_DialogIcecream {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGICECREAM_H
