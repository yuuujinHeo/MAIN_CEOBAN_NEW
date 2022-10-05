#-------------------------------------------------
#
# Project created by QtCreator 2021-09-10T10:08:58
#
#-------------------------------------------------

QT       += core gui network websockets sql serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CeobanMain
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += resources_big

INCLUDEPATH += \
        websocket \

SOURCES += \
        DialogBarcode.cpp \
        DialogCoffee.cpp \
        DialogCupDispenser.cpp \
        DialogDoor.cpp \
        DialogError.cpp \
        DialogIceDispenser.cpp \
        DialogKiosk.cpp \
        DialogMonitor.cpp \
        DialogNotice.cpp \
        DialogOutlet.cpp \
        DialogSoda.cpp \
        DialogRecipe.cpp \
        DialogRobot.cpp \
        DialogSetting.cpp \
        DialogStock.cpp \
        DialogSyrup.cpp \
        Logger.cpp \
        RBLAN2CAN.cpp \
        Scheduler.cpp \
        displaydialog.cpp \
        main.cpp \
        mainwindow.cpp \
        websocket/QtHttpClientWrapper.cpp \
        websocket/QtHttpHeader.cpp \
        websocket/QtHttpReply.cpp \
        websocket/QtHttpRequest.cpp \
        websocket/QtHttpServer.cpp

HEADERS += \
        DialogBarcode.h \
        DialogCoffee.h \
        DialogCupDispenser.h \
        DialogDoor.h \
        DialogError.h \
        DialogIceDispenser.h \
        DialogKiosk.h \
        DialogMonitor.h \
        DialogNotice.h \
        DialogOutlet.h \
        DialogRecipe.h \
        DialogRobot.h \
        DialogSetting.h \
        DialogStock.h \
        DialogSoda.h \
        DialogSyrup.h \
        GlobalHeader.h \
        Logger.h \
        RBLAN2CAN.h \
        Scheduler.h \
        displaydialog.h \
        mainwindow.h \
        websocket/QtHttpClientWrapper.h \
        websocket/QtHttpHeader.h \
        websocket/QtHttpReply.h \
        websocket/QtHttpRequest.h \
        websocket/QtHttpServer.h



FORMS += \
        DialogBarcode.ui \
        DialogCoffee.ui \
        DialogCupDispenser.ui \
        DialogDoor.ui \
        DialogError.ui \
        DialogIceDispenser.ui \
        DialogKiosk.ui \
        DialogNotice.ui \
        DialogRecipe.ui \
        DialogSoda.ui \
        DialogMonitor.ui \
        DialogOutlet.ui \
        DialogRobot.ui \
        DialogSetting.ui \
        DialogStock.ui \
        DialogSyrup.ui \
        displaydialog.ui \
        mainwindow.ui

## Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
