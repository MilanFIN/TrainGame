#include "mainwindow.h"
#include <QApplication>
#include "aloitus.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //Aloitus aloitus;
    //aloitus.show();


    return a.exec();
}
