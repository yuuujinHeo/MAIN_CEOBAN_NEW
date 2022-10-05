/********************************************************************************
** Form generated from reading UI file 'DialogError.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGERROR_H
#define UI_DIALOGERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogError
{
public:
    QGroupBox *groupBox;
    QListWidget *LW_ERROR;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *LE_DEVICE_ERROR_PAPER_CUP_2;
    QLabel *label_159;
    QLabel *label_163;
    QLineEdit *LE_DEVICE_ERROR_COFFEE;
    QLabel *label_155;
    QPushButton *BTN_ERROR_CLEAR_COFFEE;
    QLineEdit *LE_DEVICE_ERROR_PAPER_CUP_1;
    QPushButton *BTN_ERROR_CLEAR_PP_CUP_2;
    QPushButton *BTN_ERROR_CLEAR_PAPER_CUP_1;
    QLabel *label_153;
    QLabel *label_150;
    QLineEdit *LE_DEVICE_ERROR_OUTLET_2;
    QLabel *label_149;
    QPushButton *BTN_ERROR_CLEAR_ROBOT_3;
    QLineEdit *LE_DEVICE_ERROR_PP_CUP_1;
    QLabel *label_161;
    QLabel *label_152;
    QPushButton *BTN_ERROR_CLEAR_PP_CUP_1;
    QLabel *label_154;
    QLineEdit *LE_DEVICE_ERROR_ICE_1;
    QLineEdit *LE_DEVICE_ERROR_OUTLET_1;
    QLineEdit *LE_DEVICE_ERROR_ROBOT_1;
    QPushButton *BTN_ERROR_CLEAR_PP_CUP_3;
    QPushButton *BTN_ERROR_CLEAR_OUTLET_1;
    QPushButton *BTN_ERROR_CLEAR_OUTLET_2;
    QPushButton *BTN_ERROR_CLEAR_ICE_1;
    QLineEdit *LE_DEVICE_ERROR_PP_CUP_2;
    QLabel *label_151;
    QLineEdit *LE_DEVICE_ERROR_SODA;
    QPushButton *BTN_ERROR_CLEAR_SODA;

    void setupUi(QDialog *DialogError)
    {
        if (DialogError->objectName().isEmpty())
            DialogError->setObjectName(QString::fromUtf8("DialogError"));
        DialogError->resize(600, 400);
        DialogError->setStyleSheet(QString::fromUtf8("QGroupBox  {\n"
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
        groupBox = new QGroupBox(DialogError);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 600, 400));
        LW_ERROR = new QListWidget(groupBox);
        LW_ERROR->setObjectName(QString::fromUtf8("LW_ERROR"));
        LW_ERROR->setGeometry(QRect(40, 90, 261, 271));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(330, 60, 240, 336));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        LE_DEVICE_ERROR_PAPER_CUP_2 = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_PAPER_CUP_2->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_PAPER_CUP_2"));
        LE_DEVICE_ERROR_PAPER_CUP_2->setMaximumSize(QSize(50, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        LE_DEVICE_ERROR_PAPER_CUP_2->setFont(font);
        LE_DEVICE_ERROR_PAPER_CUP_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_PAPER_CUP_2->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_PAPER_CUP_2, 1, 1, 1, 1);

        label_159 = new QLabel(layoutWidget);
        label_159->setObjectName(QString::fromUtf8("label_159"));
        label_159->setFont(font);
        label_159->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_159, 4, 0, 1, 1);

        label_163 = new QLabel(layoutWidget);
        label_163->setObjectName(QString::fromUtf8("label_163"));
        label_163->setFont(font);
        label_163->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_163, 5, 0, 1, 1);

        LE_DEVICE_ERROR_COFFEE = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_COFFEE->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_COFFEE"));
        LE_DEVICE_ERROR_COFFEE->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_COFFEE->setFont(font);
        LE_DEVICE_ERROR_COFFEE->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_COFFEE->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_COFFEE, 7, 1, 1, 1);

        label_155 = new QLabel(layoutWidget);
        label_155->setObjectName(QString::fromUtf8("label_155"));
        label_155->setFont(font);
        label_155->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_155, 3, 0, 1, 1);

        BTN_ERROR_CLEAR_COFFEE = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_COFFEE->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_COFFEE"));
        BTN_ERROR_CLEAR_COFFEE->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(BTN_ERROR_CLEAR_COFFEE, 7, 2, 1, 1);

        LE_DEVICE_ERROR_PAPER_CUP_1 = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_PAPER_CUP_1->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_PAPER_CUP_1"));
        LE_DEVICE_ERROR_PAPER_CUP_1->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_PAPER_CUP_1->setFont(font);
        LE_DEVICE_ERROR_PAPER_CUP_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_PAPER_CUP_1->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_PAPER_CUP_1, 0, 1, 1, 1);

        BTN_ERROR_CLEAR_PP_CUP_2 = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_PP_CUP_2->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_PP_CUP_2"));
        BTN_ERROR_CLEAR_PP_CUP_2->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(BTN_ERROR_CLEAR_PP_CUP_2, 2, 2, 1, 1);

        BTN_ERROR_CLEAR_PAPER_CUP_1 = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_PAPER_CUP_1->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_PAPER_CUP_1"));
        BTN_ERROR_CLEAR_PAPER_CUP_1->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(BTN_ERROR_CLEAR_PAPER_CUP_1, 0, 2, 1, 1);

        label_153 = new QLabel(layoutWidget);
        label_153->setObjectName(QString::fromUtf8("label_153"));
        label_153->setFont(font);
        label_153->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_153, 0, 0, 1, 1);

        label_150 = new QLabel(layoutWidget);
        label_150->setObjectName(QString::fromUtf8("label_150"));
        label_150->setFont(font);
        label_150->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_150, 9, 0, 1, 1);

        LE_DEVICE_ERROR_OUTLET_2 = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_OUTLET_2->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_OUTLET_2"));
        LE_DEVICE_ERROR_OUTLET_2->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_OUTLET_2->setFont(font);
        LE_DEVICE_ERROR_OUTLET_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_OUTLET_2->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_OUTLET_2, 5, 1, 1, 1);

        label_149 = new QLabel(layoutWidget);
        label_149->setObjectName(QString::fromUtf8("label_149"));
        label_149->setFont(font);
        label_149->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_149, 7, 0, 1, 1);

        BTN_ERROR_CLEAR_ROBOT_3 = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_ROBOT_3->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_ROBOT_3"));
        BTN_ERROR_CLEAR_ROBOT_3->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(BTN_ERROR_CLEAR_ROBOT_3, 6, 2, 1, 1);

        LE_DEVICE_ERROR_PP_CUP_1 = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_PP_CUP_1->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_PP_CUP_1"));
        LE_DEVICE_ERROR_PP_CUP_1->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_PP_CUP_1->setFont(font);
        LE_DEVICE_ERROR_PP_CUP_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_PP_CUP_1->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_PP_CUP_1, 2, 1, 1, 1);

        label_161 = new QLabel(layoutWidget);
        label_161->setObjectName(QString::fromUtf8("label_161"));
        label_161->setFont(font);
        label_161->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_161, 6, 0, 1, 1);

        label_152 = new QLabel(layoutWidget);
        label_152->setObjectName(QString::fromUtf8("label_152"));
        label_152->setFont(font);
        label_152->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_152, 1, 0, 1, 1);

        BTN_ERROR_CLEAR_PP_CUP_1 = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_PP_CUP_1->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_PP_CUP_1"));
        BTN_ERROR_CLEAR_PP_CUP_1->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(BTN_ERROR_CLEAR_PP_CUP_1, 1, 2, 1, 1);

        label_154 = new QLabel(layoutWidget);
        label_154->setObjectName(QString::fromUtf8("label_154"));
        label_154->setFont(font);
        label_154->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_154, 2, 0, 1, 1);

        LE_DEVICE_ERROR_ICE_1 = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_ICE_1->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_ICE_1"));
        LE_DEVICE_ERROR_ICE_1->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_ICE_1->setFont(font);
        LE_DEVICE_ERROR_ICE_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_ICE_1->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_ICE_1, 9, 1, 1, 1);

        LE_DEVICE_ERROR_OUTLET_1 = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_OUTLET_1->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_OUTLET_1"));
        LE_DEVICE_ERROR_OUTLET_1->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_OUTLET_1->setFont(font);
        LE_DEVICE_ERROR_OUTLET_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_OUTLET_1->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_OUTLET_1, 4, 1, 1, 1);

        LE_DEVICE_ERROR_ROBOT_1 = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_ROBOT_1->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_ROBOT_1"));
        LE_DEVICE_ERROR_ROBOT_1->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_ROBOT_1->setFont(font);
        LE_DEVICE_ERROR_ROBOT_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_ROBOT_1->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_ROBOT_1, 6, 1, 1, 1);

        BTN_ERROR_CLEAR_PP_CUP_3 = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_PP_CUP_3->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_PP_CUP_3"));
        BTN_ERROR_CLEAR_PP_CUP_3->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(BTN_ERROR_CLEAR_PP_CUP_3, 3, 2, 1, 1);

        BTN_ERROR_CLEAR_OUTLET_1 = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_OUTLET_1->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_OUTLET_1"));
        BTN_ERROR_CLEAR_OUTLET_1->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(BTN_ERROR_CLEAR_OUTLET_1, 4, 2, 1, 1);

        BTN_ERROR_CLEAR_OUTLET_2 = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_OUTLET_2->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_OUTLET_2"));
        BTN_ERROR_CLEAR_OUTLET_2->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(BTN_ERROR_CLEAR_OUTLET_2, 5, 2, 1, 1);

        BTN_ERROR_CLEAR_ICE_1 = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_ICE_1->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_ICE_1"));
        BTN_ERROR_CLEAR_ICE_1->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(BTN_ERROR_CLEAR_ICE_1, 9, 2, 1, 1);

        LE_DEVICE_ERROR_PP_CUP_2 = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_PP_CUP_2->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_PP_CUP_2"));
        LE_DEVICE_ERROR_PP_CUP_2->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_PP_CUP_2->setFont(font);
        LE_DEVICE_ERROR_PP_CUP_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_PP_CUP_2->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_PP_CUP_2, 3, 1, 1, 1);

        label_151 = new QLabel(layoutWidget);
        label_151->setObjectName(QString::fromUtf8("label_151"));
        label_151->setFont(font);
        label_151->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_151, 8, 0, 1, 1);

        LE_DEVICE_ERROR_SODA = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_SODA->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_SODA"));
        LE_DEVICE_ERROR_SODA->setMaximumSize(QSize(50, 16777215));
        LE_DEVICE_ERROR_SODA->setFont(font);
        LE_DEVICE_ERROR_SODA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_SODA->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_SODA, 8, 1, 1, 1);

        BTN_ERROR_CLEAR_SODA = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_SODA->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_SODA"));
        BTN_ERROR_CLEAR_SODA->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(BTN_ERROR_CLEAR_SODA, 8, 2, 1, 1);


        retranslateUi(DialogError);

        QMetaObject::connectSlotsByName(DialogError);
    } // setupUi

    void retranslateUi(QDialog *DialogError)
    {
        DialogError->setWindowTitle(QCoreApplication::translate("DialogError", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogError", "\353\260\234\354\203\235\355\225\234 \354\227\220\353\237\254 \353\252\251\353\241\235", nullptr));
        LE_DEVICE_ERROR_PAPER_CUP_2->setText(QString());
        label_159->setText(QCoreApplication::translate("DialogError", "\353\260\260\354\266\234\352\265\2541", nullptr));
        label_163->setText(QCoreApplication::translate("DialogError", "\353\260\260\354\266\234\352\265\2542", nullptr));
        LE_DEVICE_ERROR_COFFEE->setText(QString());
        label_155->setText(QCoreApplication::translate("DialogError", "\355\216\230\355\212\270\354\273\2652", nullptr));
        BTN_ERROR_CLEAR_COFFEE->setText(QCoreApplication::translate("DialogError", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        LE_DEVICE_ERROR_PAPER_CUP_1->setText(QString());
        BTN_ERROR_CLEAR_PP_CUP_2->setText(QCoreApplication::translate("DialogError", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        BTN_ERROR_CLEAR_PAPER_CUP_1->setText(QCoreApplication::translate("DialogError", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        label_153->setText(QCoreApplication::translate("DialogError", "\354\242\205\354\235\264\354\273\2651", nullptr));
        label_150->setText(QCoreApplication::translate("DialogError", "\354\240\234\353\271\231\352\270\2601", nullptr));
        LE_DEVICE_ERROR_OUTLET_2->setText(QString());
        label_149->setText(QCoreApplication::translate("DialogError", "\354\273\244\355\224\274\353\250\270\354\213\240", nullptr));
        BTN_ERROR_CLEAR_ROBOT_3->setText(QCoreApplication::translate("DialogError", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        LE_DEVICE_ERROR_PP_CUP_1->setText(QString());
        label_161->setText(QCoreApplication::translate("DialogError", "\353\241\234\353\264\207", nullptr));
        label_152->setText(QCoreApplication::translate("DialogError", "\354\242\205\354\235\264\354\273\2652", nullptr));
        BTN_ERROR_CLEAR_PP_CUP_1->setText(QCoreApplication::translate("DialogError", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        label_154->setText(QCoreApplication::translate("DialogError", "\355\216\230\355\212\270\354\273\2651", nullptr));
        LE_DEVICE_ERROR_ICE_1->setText(QString());
        LE_DEVICE_ERROR_OUTLET_1->setText(QString());
        LE_DEVICE_ERROR_ROBOT_1->setText(QString());
        BTN_ERROR_CLEAR_PP_CUP_3->setText(QCoreApplication::translate("DialogError", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        BTN_ERROR_CLEAR_OUTLET_1->setText(QCoreApplication::translate("DialogError", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        BTN_ERROR_CLEAR_OUTLET_2->setText(QCoreApplication::translate("DialogError", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        BTN_ERROR_CLEAR_ICE_1->setText(QCoreApplication::translate("DialogError", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        LE_DEVICE_ERROR_PP_CUP_2->setText(QString());
        label_151->setText(QCoreApplication::translate("DialogError", "\354\206\214\353\213\244", nullptr));
        LE_DEVICE_ERROR_SODA->setText(QString());
        BTN_ERROR_CLEAR_SODA->setText(QCoreApplication::translate("DialogError", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogError: public Ui_DialogError {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGERROR_H
