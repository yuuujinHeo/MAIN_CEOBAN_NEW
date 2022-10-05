#include "GlobalHeader.h"

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.move(3000, 0);
    w.showFullScreen();

    return a.exec();
}
