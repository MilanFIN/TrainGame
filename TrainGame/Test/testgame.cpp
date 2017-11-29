#include "game.h"
#include <QObject>
#include <QtTest/QtTest>
#include <QTest>

#include <memory>

class TestGame : public QObject
{
    Q_OBJECT

public:
    TestGame(std::shared_ptr<QGraphicsScene> scene, std::shared_ptr<QGraphicsScene> miniMapScene);

private slots:

    void testGameConstructor();
    void testMoney();

private:

    std::shared_ptr<Game> game_ = NULL;

};

TestGame::TestGame(std::shared_ptr<QGraphicsScene> scene, std::shared_ptr<QGraphicsScene> miniMapScene)
{
    game_ = std::make_shared<Game>(scene, miniMapScene);
    Q_ASSERT(game_ != NULL);
}

void TestGame::testGameConstructor()
{
    Q_ASSERT(game_->getPlayerModel() != NULL);
    Q_ASSERT(game_->getObstacleModel() != NULL);
    Q_ASSERT(game_->getRailModel() != NULL);
    Q_ASSERT(game_->getAiTrainModel() != NULL);

}

void TestGame::testMoney()
{
    Q_ASSERT(game_->getPlayerMoney() == 500);
    game_->addMoney(50);
    Q_ASSERT(game_->getPlayerMoney() == 550);
}


//#include "testgame.moc"

