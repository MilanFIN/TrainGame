#include "testbackground.cpp"
#include "mainwindow.h"
#include "game.h"

#include <QApplication>
#include <QGraphicsScene>
#include <memory>
#include <QObject>
#include <QTest>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    std::shared_ptr<QGraphicsScene> scene = std::make_shared<QGraphicsScene>();
    std::shared_ptr<QGraphicsScene> miniMapScene = std::make_shared<QGraphicsScene>();

    std::shared_ptr<Game> game = std::make_shared<Game>(scene, miniMapScene);
    MainWindow w(game, scene, miniMapScene);

    w.show();

    TestBackground testBackground;

    QTest::qExec(&testBackground, argc, argv);

    return a.exec();
}