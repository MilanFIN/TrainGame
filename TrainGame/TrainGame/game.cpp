#include "game.h"
#include <iostream>


Game::Game(std::shared_ptr<QGraphicsScene> scene,
           std::shared_ptr<QGraphicsScene> miniMapScene, QObject *parent) : QObject(parent),
    scene_(scene)
{

    railLogic_ = std::make_shared<RailLogic>(scene, miniMapScene);
    playerLogic_ = std::make_shared<PlayerLogic>(scene);
    obstacleLogic_ = std::make_shared<ObstacleLogic>(scene);
    bgLogic_ = std::make_shared<BackgroundLogic>(scene);
    aiTrainManager_ = std::make_shared<VrTrainManager>(scene);

    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(66);

    QTimer *CollisionTimer = new QTimer(this);
    connect(CollisionTimer, SIGNAL(timeout()), this, SLOT(checkCollisions()));
    CollisionTimer->start(66);

    connect(obstacleSpawner_, SIGNAL(timeout()), this, SLOT(spawn()));
    obstacleSpawner_->start(50);

    goalSpeed_ = 0;
    previousSpeed_ = 0;
    movementSinceLastSpawn = 0;

}

void Game::setSpeed(int newSpeed)
{
    railLogic_.get()->setSpeed(newSpeed);
    obstacleLogic_.get()->setSpeed(newSpeed);
    bgLogic_.get()->setSpeed(newSpeed);

}

void Game::changeDirection()
{
    railLogic_.get()->changeDirection();
    obstacleLogic_.get()->changeDirection();
    bgLogic_.get()->changeDirection();
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
    runGame_ = true;
    railLogic_->signalStationInfoToUi();
}

void Game::shopTabChosen()
{
    runGame_ = false;
    playerLogic_->getAvailableTrainsFromShop();
    playerLogic_->getOwnedTrains();
}

void Game::depotTabChosen()
{
    runGame_ = false;
    playerLogic_->getTrainsToBeRepaired();
}

void Game::wantedOwnedTrainInfo(QString trainName)
{
    playerLogic_->getOwnedTrainInfo(trainName);
}

void Game::wantedTrainInfo(QString trainName)
{
    playerLogic_->getTrainInfo(trainName);
}

void Game::fixlistTrainInfo(QString trainName)
{
    playerLogic_->getInfoToGarage(trainName);
}

int Game::getPlayerMoney()
{
    return playerLogic_->getCurrentMoney();
}

void Game::repairPlayerTrain(int rowIndex)
{
    playerLogic_->repairTrain(rowIndex);
}

void Game::setActiveTrain(int rowIndex)
{
    playerLogic_->setActiveTrain(rowIndex);
}

void Game::buyNewTrain(QString trainName, int index)
{
    playerLogic_->buyTrain(trainName, index);
}

void Game::sellTrain(int index)
{
    playerLogic_->sellTrain(index);
}

void Game::railChanged()
{
    obstacleLogic_.get()->addObstacleToScene(railLogic_.get()->getNextStation(), railLogic_.get()->getLastStation(), railLogic_.get()->getCurrentTrack());
}

void Game::addMoney(int amount)
{
    playerLogic_->increaseMoney(amount);
}

void Game::addFame(int amount)
{
    playerLogic_->addFame(amount);
}

RailLogic* Game::getRailModel()
{
    return railLogic_.get();
}

PlayerLogic *Game::getPlayerModel()
{
    return playerLogic_.get();
}

ObstacleLogic *Game::getObstacleModel()
{
    return obstacleLogic_.get();
}

VrTrainManager *Game::getAiTrainModel(){
    return aiTrainManager_.get();
}

void Game::move()
{

    if (!runGame_){
        return;
    }

    //move aitrains

    QString next;
    QString prev;
    bool mainRail;
    int nextY;
    int prevY;

    railLogic_->getCurrentLocation(prev, next, prevY, nextY, mainRail);
    aiTrainManager_->move(prev, next, prevY, nextY, mainRail);

    if (playerLogic_->activeTrain()->getAbsoluteShape() <= 0){
        return;
    }

    double speedMultiplier = playerLogic_->activeTrain()->getSpeed();

    railLogic_.get()->move(speedMultiplier);
    obstacleLogic_.get()->move(speedMultiplier);
    bgLogic_.get()->move(speedMultiplier);

}

void Game::spawn()
{

    obstacleSpawner_->stop();

    int distance = obstacleLogic_.get()->getNextDistance();
    QList<QString> stations;
    QString track;
    QList<QString> stationNames;
    bool harmful;
    railLogic_.get()->getRandomStationAndTrack(distance,stations , track, stationNames, harmful);
    obstacleLogic_.get()->spawnObstacle(stations, track, stationNames, harmful);

}

void Game::checkCollisions()
{

    if (!runGame_){
        return;
    }
    //check if obstacles hit the player
    int recievedDamage = obstacleLogic_.get()->checkCollision(playerLogic_.get()->activeTrain());
    //pelaajan aktiiviselle junalle lämää
    playerLogic_.get()->takeDamage(recievedDamage);
    recievedDamage = aiTrainManager_->checkPlayerCollision(playerLogic_.get()->activeTrain());
    playerLogic_.get()->takeDamage(recievedDamage);

    //check if player has arrived to a station
    railLogic_.get()->checkCollisionWithStations(playerLogic_.get()->activeTrain());

    //check collisions with vr-trains and the obstacle
    QString prev;
    QString next;
    bool harmful;
    obstacleLogic_->getObstacleLocation(prev, next, harmful);
    bool crash = aiTrainManager_->checkCollisions(prev, next, harmful);
    //if crash is true, then a vr train has collided with our obstacle
    if (crash){
        obstacleLogic_->crash();
    }
}

