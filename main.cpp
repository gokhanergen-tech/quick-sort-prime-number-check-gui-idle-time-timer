#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMinimumWidth(800);
    w.setMinimumHeight(500);
    w.show();
    return a.exec();
}
