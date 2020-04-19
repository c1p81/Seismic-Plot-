#include "mainwindow.h"

#include <QApplication>

QVector<double> x[100];
QVector<double> y[100];

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
