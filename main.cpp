#include "GlobalHeader.h"

#ifdef ICECREAM_VER
#include "mainwindow_icecream.h"
#else
#include "mainwindow.h"
#endif
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.move(3000, 0);
    w.showFullScreen();

//    DisplayWindow d;
//    d.show();
//    d.move(0,0);
//    d.showFullScreen();
    return a.exec();
}
