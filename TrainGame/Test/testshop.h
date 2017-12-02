#ifndef TESTSHOP_H
#define TESTSHOP_H

#include "shop.h"
#include "playerlogic.h"
#include <QObject>
#include <QtTest/QtTest>
#include <QDebug>
#include <QGraphicsScene>

#include <memory>

class TestShop : public QObject
{
    Q_OBJECT

public:
    TestShop(std::shared_ptr<QGraphicsScene> scene);

private slots:

    void initTestCase();
    void testBuyableTrains();

private:
    std::shared_ptr<Shop> shop_ = NULL;
    std::shared_ptr<QGraphicsScene> scene_ = NULL;
    std::shared_ptr<PlayerLogic> playerLogic_ = NULL;
};


#endif // TESTSHOP_H
