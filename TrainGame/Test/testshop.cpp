#include "testshop.h"

TestShop::TestShop(std::shared_ptr<QGraphicsScene> scene)
{
    scene_ = scene;
    playerLogic_ = std::make_shared<PlayerLogic>(scene);
}

void TestShop::initTestCase()
{
    shop_ = std::make_shared<Shop>();
}

void TestShop::testBuyableTrains()
{
    std::shared_ptr<Shop> shop = std::make_shared<Shop>();
    std::vector<std::shared_ptr<PlayerTrain>> vec = shop->buyableTrains();

    //Q_ASSERT(vec.size() != 0);

    std::string latta = "Lättähattu";
    std::string hoyry = "Höyryveturi";
    std::string luoti = "Luotijuna";
    QString qlatta = QString::fromStdString(latta);
    QString qhoyry = QString::fromStdString(hoyry);
    QString qluoti = QString::fromStdString(luoti);

//    for (std::shared_ptr<PlayerTrain> item : vec) {

//        Q_ASSERT(item->getName().compare(qlatta));

//    }

}

