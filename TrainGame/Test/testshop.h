#ifndef TESTSHOP_H
#define TESTSHOP_H

#include "shop.h"
#include <QObject>
#include <QtTest/QtTest>
#include <QDebug>

#include <memory>

class TestShop : public QObject
{
    Q_OBJECT

private slots:

    void testBuyableTrains();

};


#endif // TESTSHOP_H
