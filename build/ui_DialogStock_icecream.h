/********************************************************************************
** Form generated from reading UI file 'DialogStock_icecream.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSTOCK_ICECREAM_H
#define UI_DIALOGSTOCK_ICECREAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
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
    QPushButton *BTN_SET_STOCK_MANUAL;
    QComboBox *CB_STOCK_NAME;
    QLineEdit *LE_MANUAL_STOCK_AMOUNT;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
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
    QGridLayout *gridLayout;
    QProgressBar *PB_ICECREAM_1;
    QLabel *LB_SLUSH_1;
    QLabel *LB_SLUSH_2;
    QProgressBar *PB_SLUSH_2;
    QLabel *LB_ICECREAM_1;
    QPushButton *BTN_SLUSH_REFILL_1;
    QPushButton *BTN_ICECREAM_REFILL;
    QPushButton *BTN_SLUSH_REFILL_2;
    QProgressBar *PB_SLUSH_1;
    QPushButton *BTN_ICECREAM_ZERO;
    QPushButton *BTN_SLUSH_ZERO;
    QPushButton *BTN_SLUSH_ZERO_2;
    QGridLayout *gridLayout_2;
    QProgressBar *PB_BASE_2;
    QLabel *LB_BASE_2;
    QPushButton *BTN_BASE_REPLACE_2;
    QLabel *LB_BASE_1;
    QProgressBar *PB_BASE_1;
    QPushButton *BTN_BASE_REPLACE_1;
    QPushButton *BTN_BASE_ZERO;
    QPushButton *BTN_BASE_ZERO_2;

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
        BTN_SET_STOCK_MANUAL = new QPushButton(GB_STOCK);
        BTN_SET_STOCK_MANUAL->setObjectName(QString::fromUtf8("BTN_SET_STOCK_MANUAL"));
        BTN_SET_STOCK_MANUAL->setGeometry(QRect(230, 830, 121, 41));
        CB_STOCK_NAME = new QComboBox(GB_STOCK);
        CB_STOCK_NAME->setObjectName(QString::fromUtf8("CB_STOCK_NAME"));
        CB_STOCK_NAME->setGeometry(QRect(120, 780, 191, 41));
        LE_MANUAL_STOCK_AMOUNT = new QLineEdit(GB_STOCK);
        LE_MANUAL_STOCK_AMOUNT->setObjectName(QString::fromUtf8("LE_MANUAL_STOCK_AMOUNT"));
        LE_MANUAL_STOCK_AMOUNT->setGeometry(QRect(90, 830, 121, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        LE_MANUAL_STOCK_AMOUNT->setFont(font1);
        LE_MANUAL_STOCK_AMOUNT->setReadOnly(false);
        layoutWidget = new QWidget(GB_STOCK);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 80, 361, 471));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LB_CUP_1 = new QLabel(layoutWidget);
        LB_CUP_1->setObjectName(QString::fromUtf8("LB_CUP_1"));

        horizontalLayout->addWidget(LB_CUP_1);

        PB_CUP_1 = new QProgressBar(layoutWidget);
        PB_CUP_1->setObjectName(QString::fromUtf8("PB_CUP_1"));
        PB_CUP_1->setMaximumSize(QSize(150, 16777215));
        PB_CUP_1->setValue(24);

        horizontalLayout->addWidget(PB_CUP_1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        BTN_CUP_HALF_1 = new QPushButton(layoutWidget);
        BTN_CUP_HALF_1->setObjectName(QString::fromUtf8("BTN_CUP_HALF_1"));

        verticalLayout->addWidget(BTN_CUP_HALF_1);

        BTN_CUP_FULL_1 = new QPushButton(layoutWidget);
        BTN_CUP_FULL_1->setObjectName(QString::fromUtf8("BTN_CUP_FULL_1"));

        verticalLayout->addWidget(BTN_CUP_FULL_1);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LB_CUP_2 = new QLabel(layoutWidget);
        LB_CUP_2->setObjectName(QString::fromUtf8("LB_CUP_2"));

        horizontalLayout_2->addWidget(LB_CUP_2);

        PB_CUP_2 = new QProgressBar(layoutWidget);
        PB_CUP_2->setObjectName(QString::fromUtf8("PB_CUP_2"));
        PB_CUP_2->setMaximumSize(QSize(150, 16777215));
        PB_CUP_2->setValue(24);

        horizontalLayout_2->addWidget(PB_CUP_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        BTN_CUP_HALF_2 = new QPushButton(layoutWidget);
        BTN_CUP_HALF_2->setObjectName(QString::fromUtf8("BTN_CUP_HALF_2"));

        verticalLayout_2->addWidget(BTN_CUP_HALF_2);

        BTN_CUP_FULL_2 = new QPushButton(layoutWidget);
        BTN_CUP_FULL_2->setObjectName(QString::fromUtf8("BTN_CUP_FULL_2"));

        verticalLayout_2->addWidget(BTN_CUP_FULL_2);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        PB_ICECREAM_1 = new QProgressBar(layoutWidget);
        PB_ICECREAM_1->setObjectName(QString::fromUtf8("PB_ICECREAM_1"));
        PB_ICECREAM_1->setMaximumSize(QSize(200, 16777215));
        PB_ICECREAM_1->setValue(24);

        gridLayout->addWidget(PB_ICECREAM_1, 0, 1, 1, 1);

        LB_SLUSH_1 = new QLabel(layoutWidget);
        LB_SLUSH_1->setObjectName(QString::fromUtf8("LB_SLUSH_1"));
        LB_SLUSH_1->setFont(font1);

        gridLayout->addWidget(LB_SLUSH_1, 1, 0, 1, 1);

        LB_SLUSH_2 = new QLabel(layoutWidget);
        LB_SLUSH_2->setObjectName(QString::fromUtf8("LB_SLUSH_2"));
        LB_SLUSH_2->setFont(font1);

        gridLayout->addWidget(LB_SLUSH_2, 2, 0, 1, 1);

        PB_SLUSH_2 = new QProgressBar(layoutWidget);
        PB_SLUSH_2->setObjectName(QString::fromUtf8("PB_SLUSH_2"));
        PB_SLUSH_2->setMaximumSize(QSize(200, 16777215));
        PB_SLUSH_2->setValue(24);

        gridLayout->addWidget(PB_SLUSH_2, 2, 1, 1, 1);

        LB_ICECREAM_1 = new QLabel(layoutWidget);
        LB_ICECREAM_1->setObjectName(QString::fromUtf8("LB_ICECREAM_1"));
        LB_ICECREAM_1->setFont(font1);

        gridLayout->addWidget(LB_ICECREAM_1, 0, 0, 1, 1);

        BTN_SLUSH_REFILL_1 = new QPushButton(layoutWidget);
        BTN_SLUSH_REFILL_1->setObjectName(QString::fromUtf8("BTN_SLUSH_REFILL_1"));

        gridLayout->addWidget(BTN_SLUSH_REFILL_1, 1, 2, 1, 1);

        BTN_ICECREAM_REFILL = new QPushButton(layoutWidget);
        BTN_ICECREAM_REFILL->setObjectName(QString::fromUtf8("BTN_ICECREAM_REFILL"));

        gridLayout->addWidget(BTN_ICECREAM_REFILL, 0, 2, 1, 1);

        BTN_SLUSH_REFILL_2 = new QPushButton(layoutWidget);
        BTN_SLUSH_REFILL_2->setObjectName(QString::fromUtf8("BTN_SLUSH_REFILL_2"));

        gridLayout->addWidget(BTN_SLUSH_REFILL_2, 2, 2, 1, 1);

        PB_SLUSH_1 = new QProgressBar(layoutWidget);
        PB_SLUSH_1->setObjectName(QString::fromUtf8("PB_SLUSH_1"));
        PB_SLUSH_1->setMaximumSize(QSize(200, 16777215));
        PB_SLUSH_1->setValue(24);

        gridLayout->addWidget(PB_SLUSH_1, 1, 1, 1, 1);

        BTN_ICECREAM_ZERO = new QPushButton(layoutWidget);
        BTN_ICECREAM_ZERO->setObjectName(QString::fromUtf8("BTN_ICECREAM_ZERO"));

        gridLayout->addWidget(BTN_ICECREAM_ZERO, 0, 3, 1, 1);

        BTN_SLUSH_ZERO = new QPushButton(layoutWidget);
        BTN_SLUSH_ZERO->setObjectName(QString::fromUtf8("BTN_SLUSH_ZERO"));

        gridLayout->addWidget(BTN_SLUSH_ZERO, 1, 3, 1, 1);

        BTN_SLUSH_ZERO_2 = new QPushButton(layoutWidget);
        BTN_SLUSH_ZERO_2->setObjectName(QString::fromUtf8("BTN_SLUSH_ZERO_2"));

        gridLayout->addWidget(BTN_SLUSH_ZERO_2, 2, 3, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        PB_BASE_2 = new QProgressBar(layoutWidget);
        PB_BASE_2->setObjectName(QString::fromUtf8("PB_BASE_2"));
        PB_BASE_2->setMaximumSize(QSize(200, 16777215));
        PB_BASE_2->setValue(24);

        gridLayout_2->addWidget(PB_BASE_2, 1, 1, 1, 1);

        LB_BASE_2 = new QLabel(layoutWidget);
        LB_BASE_2->setObjectName(QString::fromUtf8("LB_BASE_2"));
        LB_BASE_2->setFont(font1);

        gridLayout_2->addWidget(LB_BASE_2, 1, 0, 1, 1);

        BTN_BASE_REPLACE_2 = new QPushButton(layoutWidget);
        BTN_BASE_REPLACE_2->setObjectName(QString::fromUtf8("BTN_BASE_REPLACE_2"));

        gridLayout_2->addWidget(BTN_BASE_REPLACE_2, 1, 2, 1, 1);

        LB_BASE_1 = new QLabel(layoutWidget);
        LB_BASE_1->setObjectName(QString::fromUtf8("LB_BASE_1"));
        LB_BASE_1->setFont(font1);

        gridLayout_2->addWidget(LB_BASE_1, 0, 0, 1, 1);

        PB_BASE_1 = new QProgressBar(layoutWidget);
        PB_BASE_1->setObjectName(QString::fromUtf8("PB_BASE_1"));
        PB_BASE_1->setMaximumSize(QSize(200, 16777215));
        PB_BASE_1->setValue(24);

        gridLayout_2->addWidget(PB_BASE_1, 0, 1, 1, 1);

        BTN_BASE_REPLACE_1 = new QPushButton(layoutWidget);
        BTN_BASE_REPLACE_1->setObjectName(QString::fromUtf8("BTN_BASE_REPLACE_1"));

        gridLayout_2->addWidget(BTN_BASE_REPLACE_1, 0, 2, 1, 1);

        BTN_BASE_ZERO = new QPushButton(layoutWidget);
        BTN_BASE_ZERO->setObjectName(QString::fromUtf8("BTN_BASE_ZERO"));

        gridLayout_2->addWidget(BTN_BASE_ZERO, 0, 3, 1, 1);

        BTN_BASE_ZERO_2 = new QPushButton(layoutWidget);
        BTN_BASE_ZERO_2->setObjectName(QString::fromUtf8("BTN_BASE_ZERO_2"));

        gridLayout_2->addWidget(BTN_BASE_ZERO_2, 1, 3, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);


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
        PB_ICECREAM_1->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        LB_SLUSH_1->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        LB_SLUSH_2->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_SLUSH_2->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        LB_ICECREAM_1->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        BTN_SLUSH_REFILL_1->setText(QCoreApplication::translate("DialogStock", "1L \354\266\224\352\260\200", nullptr));
        BTN_ICECREAM_REFILL->setText(QCoreApplication::translate("DialogStock", "1L \354\266\224\352\260\200", nullptr));
        BTN_SLUSH_REFILL_2->setText(QCoreApplication::translate("DialogStock", "1L \354\266\224\352\260\200", nullptr));
        PB_SLUSH_1->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_ICECREAM_ZERO->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        BTN_SLUSH_ZERO->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        BTN_SLUSH_ZERO_2->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        PB_BASE_2->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        LB_BASE_2->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        BTN_BASE_REPLACE_2->setText(QCoreApplication::translate("DialogStock", "\352\265\220\354\262\264", nullptr));
        LB_BASE_1->setText(QCoreApplication::translate("DialogStock", "TextLabel", nullptr));
        PB_BASE_1->setFormat(QCoreApplication::translate("DialogStock", "%p%", nullptr));
        BTN_BASE_REPLACE_1->setText(QCoreApplication::translate("DialogStock", "\352\265\220\354\262\264", nullptr));
        BTN_BASE_ZERO->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
        BTN_BASE_ZERO_2->setText(QCoreApplication::translate("DialogStock", "\354\227\206\354\235\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogStock: public Ui_DialogStock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSTOCK_ICECREAM_H
