#include "playerlogic.h"
#include "shop.h"
#include "testplayerlogic.h"
#include "playertrain.h"

#include <QSignalSpy>
#include <QtTest>
#include <QString>
#include <memory>
#include <vector>

TestPlayerLogic::TestPlayerLogic(std::shared_ptr<QGraphicsScene> scene): scene_(scene)
{}

void TestPlayerLogic::defaultConstrcutor()
{
    std::shared_ptr<PlayerLogic> player = std::make_shared<PlayerLogic>();

    QSignalSpy spy(player.get(), SIGNAL(ownedTrains(std::vector<std::shared_ptr<PlayerTrain>>)));

    player->getOwnedTrains();
    QCOMPARE(spy.count(), 1);

    QVERIFY2(player->getCurrentMoney() == 300, "Player default money");
    QVERIFY2(player->activeTrain() == nullptr, "Default activetrain is not empty shared_ptr");
}

void TestPlayerLogic::testVariant(PlayerLogic *player)
{
    QVERIFY2(player->getCurrentMoney() > 0, "Invariant broken, players money is under 0");
}

void TestPlayerLogic::buyTrain()
{

    std::shared_ptr<PlayerLogic> player = std::make_shared<PlayerLogic>(scene_);
    QSignalSpy spy(player.get(), SIGNAL(shopActionFailed(QString)));

    QString trainName = QString("pomppuresiina");
    QString failName = QString("falseTrainName");
    int i = 0;

    // trainName that doesn't belong to game
    player->buyTrain(failName, i);
    QList<QVariant> args = spy.takeFirst();
    QVERIFY(args.at(0).type() == QVariant::String);

    QSignalSpy spyy(player.get(), SIGNAL(availableTrains(std::vector<std::shared_ptr<PlayerTrain> >)));
    //legal action
    player->buyTrain(trainName, i);
    QCOMPARE(spy.count(), 1);
}
