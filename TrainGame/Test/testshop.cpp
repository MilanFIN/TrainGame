#include "shop.h"
#include <QObject>
#include <QtTest/QtTest>
#include <QDebug>

#include <memory>

class TestShop : public QObject
{
    Q_OBJECT

public slots:

    void testBuyableTrains();

};


void TestShop::testBuyableTrains()
{
    std::shared_ptr<Shop> shop = std::make_shared<Shop>();
    std::vector<std::shared_ptr<PlayerTrain>> vec = shop->buyableTrains();

    for (std::shared_ptr<PlayerTrain> item : vec) {

        qInfo() << item->getName();
        //testataan että junat on oikeanlaisia
    }

}

#include "testshop.moc"
