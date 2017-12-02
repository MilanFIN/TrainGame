#include "playerlogic.h"
#include "shop.h"
#include "testplayerlogic.h"
#include "playertrain.h"

#include <QSignalSpy>
#include <QtTest>
#include <QString>
#include <memory>
#include <vector>

TestPlayerLogic::TestPlayerLogic()
{

}

void TestPlayerLogic::defaultConstrcutor()
{
    std::shared_ptr<PlayerLogic> player = std::make_shared<PlayerLogic>();

    QSignalSpy spy(player.get(), SIGNAL(ownedTrains(std::vector<std::shared_ptr<PlayerTrain>>)));

    player->getOwnedTrains();

    QCOMPARE(spy.count(), 1);


    QVERIFY2(player->getCurrentMoney() == 500, "Player default money");
    QVERIFY2(player->activeTrain() == nullptr, "Default activetrain is not empty shared_ptr");
}

void TestPlayerLogic::testVariant(PlayerLogic *player)
{
    QVERIFY2(player->getCurrentMoney() > 0, "Invariant broken, players money is under 0");
}

void TestPlayerLogic::buyTrain()
{


}
