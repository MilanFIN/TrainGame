#include "testshop.h"

void TestShop::testBuyableTrains()
{
    std::shared_ptr<Shop> shop = std::make_shared<Shop>();
    std::vector<std::shared_ptr<PlayerTrain>> vec = shop->buyableTrains();

    for (std::shared_ptr<PlayerTrain> item : vec) {

        //testataan että junat on oikeanlaisia

        //jotain tälläistä
        //std::string str = "Hello world";
        //QString qstr = QString::fromStdString(str);

        //Q_ASSERT(item->getName() != "Lättähattujuna");

    }

}

