#ifndef TESTGAME_H
#define TESTGAME_H

#include "game.h"
#include <QObject>
#include <QtTest/QtTest>
#include <QTest>
#include <QSignalSpy>

#include <memory>

class TestGame : public QObject
{
    Q_OBJECT

public:
    TestGame(std::shared_ptr<QGraphicsScene> scene,
             std::shared_ptr<QGraphicsScene> miniMapScene);

private slots:

    void initTestCase();
    void testConstructor();
    void testMoney();

private:

    std::shared_ptr<Game> game_ = NULL;
    std::shared_ptr<QGraphicsScene> scene_ = NULL;
    std::shared_ptr<QGraphicsScene> miniMapScene_ = NULL;
};

#endif // TESTGAME_H
