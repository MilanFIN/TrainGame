#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include "game.h"
#include <memory>
#include <QObject>

#include "raillogic.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    std::shared_ptr<QGraphicsScene> scene = std::make_shared<QGraphicsScene>();
    std::shared_ptr<Game> game = std::make_shared<Game>(scene);
    MainWindow w(game, scene);


    w.show();



    return a.exec();
}

