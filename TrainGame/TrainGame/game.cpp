#include "game.h"
#include <iostream>


Game::Game(std::shared_ptr<QGraphicsScene> scene, QObject *parent) : QObject(parent),
  scene_(scene)
{

    railLogic_ = std::make_shared<RailLogic>(scene);
    playerLogic_ = std::make_shared<PlayerLogic>(scene);
    obstacleLogic_ = std::make_shared<ObstacleLogic>(scene);




    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(66);


    QTimer *CollisionTimer = new QTimer(this);
    connect(CollisionTimer, SIGNAL(timeout()), this, SLOT(checkCollisions()));
    CollisionTimer->start(300);

    QTimer *obstacleSpawner = new QTimer(this);
    connect(obstacleSpawner, SIGNAL(timeout()), this, SLOT(spawn()));
    obstacleSpawner->start(5000);


    goalSpeed_ = 0;
    previousSpeed_ = 0;
    movementSinceLastSpawn = 0;


}

void Game::setSpeed(int newSpeed)
{
    railLogic_.get()->setSpeed(newSpeed);
    obstacleLogic_.get()->setSpeed(newSpeed);

}

void Game::changeDirection()
{
    railLogic_.get()->changeDirection();
    obstacleLogic_.get()->changeDirection();
}

void Game::removeBlockage()
{
    obstacleLogic_.get()->removeNearbyObjects(playerLogic_.get()->location());
}

void Game::changeDestination(int index)
{
    railLogic_->changeDestinationCandidateIndex(index);
}

void Game::changeBacktrack(int index)
{
    railLogic_->changeBackTrackCandidateIndex(index);
}

void Game::gameTabChosen()
{
    railLogic_->signalStationInfoToUi();
}

void Game::shopTabChosen()
{
    playerLogic_->getAvailableTrainsFromShop();
    playerLogic_->getOwnedTrains();
}

void Game::wantedOwnedTrainInfo(QString trainName)
{
    playerLogic_->getOwnedTrainInfo(trainName);
}

void Game::wantedTrainInfo(QString trainName)
{
    playerLogic_->getTrainInfo(trainName);
}

int Game::getPlayerCash()
{
    return playerLogic_->getCurrentMoney();
}

RailLogic* Game::getRailModel()
{
    return railLogic_.get();
}

PlayerLogic *Game::getPlayerModel()
{
    return playerLogic_.get();
}

void Game::move()
{
    railLogic_.get()->move();
    obstacleLogic_.get()->move();
}

void Game::spawn()
{
    obstacleLogic_.get()->spawnObstacle();
}

void Game::checkCollisions()
{
    //check if obstacles hit the player
    int recievedDamage = obstacleLogic_.get()->checkCollision(playerLogic_.get()->activeTrain());
    //check if player has arrived to a station
    railLogic_.get()->checkCollisionWithStations(playerLogic_.get()->activeTrain());
}

