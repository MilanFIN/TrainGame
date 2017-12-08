#include "testgame.h"

TestGame::TestGame(std::shared_ptr<QGraphicsScene> scene, std::shared_ptr<QGraphicsScene> miniMapScene)
{
    scene_ = scene;
    miniMapScene_ = miniMapScene;
}

void TestGame::initTestCase()
{
    game_ = std::make_shared<Game>(scene_, miniMapScene_);
}

void TestGame::testConstructor()
{
    Q_ASSERT(game_->getPlayerModel() != NULL);
    Q_ASSERT(game_->getObstacleModel() != NULL);
    Q_ASSERT(game_->getRailModel() != NULL);
    Q_ASSERT(game_->getAiTrainModel() != NULL);

}

void TestGame::testMoney()
{
    Q_ASSERT(game_->getPlayerMoney() == 300);
    game_->addMoney(50);
    Q_ASSERT(game_->getPlayerMoney() == 350);
}

