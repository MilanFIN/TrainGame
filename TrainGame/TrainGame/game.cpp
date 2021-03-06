#include "game.h"


Game::Game(std::shared_ptr<QGraphicsScene> scene,
           std::shared_ptr<QGraphicsScene> miniMapScene,
           QObject *parent) : QObject(parent),
    scene_(scene)
{

    railLogic_ = std::make_shared<RailLogic>(scene, miniMapScene);
    playerLogic_ = std::make_shared<PlayerLogic>(scene);
    obstacleLogic_ = std::make_shared<ObstacleLogic>(scene);
    bgLogic_ = std::make_shared<BackgroundLogic>(scene);
    aiTrainManager_ = std::make_shared<VrTrainManager>(scene);

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
    setSpeed(0);
}

void Game::shopTabChosen()
{
    runGame_ = false;
    playerLogic_->getAvailableTrainsFromShop();
    playerLogic_->getOwnedTrains();
    setSpeed(0);
}

void Game::depotTabChosen()
{
    runGame_ = false;
    playerLogic_->getTrainsToBeRepaired();
    setSpeed(0);

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
    obstacleLogic_.get()->
            addObstacleToScene(railLogic_.get()->getNextStation(),
                               railLogic_.get()->getLastStation(),
                               railLogic_.get()->getCurrentTrack());
}

void Game::addMoney(int amount)
{
    playerLogic_->increaseMoney(amount);
}

void Game::addFame(int amount)
{
    playerLogic_->addFame(amount);
}

void Game::updateNavi()
{
    QString prev;
    QString next;
    bool harm;
    obstacleLogic_->getObstacleLocation(prev, next, harm);
    railLogic_->updateNavi(next, prev);
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
    if (playerLogic_->getFame() <= -110) {
        moveTimer->stop();
        emit endGameSignal();
    }

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

    if (playerLogic_->activeTrain()->getShape() <= 0){
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
    railLogic_.get()->getRandomStationAndTrack(distance, stations,
                                               track, stationNames, harmful);

    obstacleLogic_.get()->spawnObstacle(stations,
                                        track, stationNames, harmful);

    railLogic_->updateObstacleOnMiniMap(stations.at(0), stations.at(1));

    railLogic_->updateNavi(stations.at(0), stations.at(1));
}

void Game::checkCollisions()
{

    if (!runGame_){
        return;
    }
    //check if obstacles hit the player
    int recievedDamage = obstacleLogic_.get()->
            checkCollision(playerLogic_.get()->activeTrain());

    // players activeTraing takes damage
    playerLogic_.get()->takeDamage(recievedDamage);
    recievedDamage = 0;
    recievedDamage = aiTrainManager_->
            checkPlayerCollision(playerLogic_.get()->activeTrain());
    if (recievedDamage != 0){
        emit decreaseFame(-100);
        playerLogic_->addFame(-100);
    }
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

