#include "game.h"
#include <iostream>


Game::Game(std::shared_ptr<QGraphicsScene> scene, QObject *parent) : QObject(parent),
  scene_(scene)
{

    railLogic_ = new RailLogic(scene);
    playerLogic_ = new PlayerLogic(scene);
    obstacleLogic_ = new ObstacleLogic(scene);


    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(66);


    QTimer *obstacleSpawner = new QTimer(this);
    connect(obstacleSpawner, SIGNAL(timeout()), this, SLOT(spawn()));
    obstacleSpawner->start(5000);


    goalSpeed_ = 0;
    previousSpeed_ = 0;
    movementSinceLastSpawn = 0;


}

void Game::setSpeed(int newSpeed)
{
    railLogic_->setSpeed(newSpeed);
    obstacleLogic_->setSpeed(newSpeed);

    int recievedDamage = obstacleLogic_->checkCollision(playerLogic_->activeTrain());
}

void Game::changeDirection()
{
    railLogic_->changeDirection();
    obstacleLogic_->changeDirection();
}

void Game::removeBlockage()
{
    obstacleLogic_->removeNearbyObjects(playerLogic_->location());
}

void Game::move()
{
    railLogic_->move();
    obstacleLogic_->move();
}

void Game::spawn()
{
    obstacleLogic_->spawnObstacle();
}
