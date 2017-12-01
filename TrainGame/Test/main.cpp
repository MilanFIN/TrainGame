#include "testbackground.h"
//#include "testboulder.h"
#include "testgame.h"
//#include "testshop.h"
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

    std::shared_ptr<TestBackground> testBackground = std::make_shared<TestBackground>();
//    std::shared_ptr<TestBoulder> testBoulder = std::make_shared<TestBoulder>();
    std::shared_ptr<TestGame> testGame = std::make_shared<TestGame>(scene, miniMapScene);
//    std::shared_ptr<TestShop> testShop = std::make_shared<TestShop>();

    QTest::qExec(testBackground.get(), argc, argv);
//    QTest::qExec(testBoulder.get(), argc, argv);
    QTest::qExec(testGame.get(), argc, argv);
//    QTest::qExec(testShop.get(), argc, argv);

    return a.exec();
}
