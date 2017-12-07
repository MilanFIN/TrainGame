#include "mainwindow.h"
#include "startwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include "game.h"
#include <memory>
#include <QObject>

#include "raillogic.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    StartWindow i;


    std::shared_ptr<QGraphicsScene> scene = std::make_shared<QGraphicsScene>();
    std::shared_ptr<QGraphicsScene> miniMapScene = std::make_shared<QGraphicsScene>();

    std::shared_ptr<Game> game = std::make_shared<Game>(scene, miniMapScene);
    MainWindow w(game, scene, miniMapScene);
    i.exec();


    w.show();



    return a.exec();
}

