#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include "game.h"
#include "memory"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
/*
    QSharedPointer<QGraphicsScene> scene =
        QSharedPointer<QGraphicsScene>(new QGraphicsScene);


    QSharedPointer<Game> game =
        QSharedPointer<Game>(new Game(scene));
*/


    std::shared_ptr<QGraphicsScene> scene = std::make_shared<QGraphicsScene>();
    std::shared_ptr<Game> game = std::make_shared<Game>(scene);
    MainWindow w(game, scene);
    w.show();



    return a.exec();
}
