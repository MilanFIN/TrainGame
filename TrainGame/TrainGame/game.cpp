#include "game.h"
#include <iostream>


Game::Game(std::shared_ptr<QGraphicsScene> scene, QObject *parent) : QObject(parent),
  scene_(scene)
{
    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(66);

    QTimer *obstacleSpawner = new QTimer(this);
    connect(obstacleSpawner, SIGNAL(timeout()), this, SLOT(spawnObstacle()));
    obstacleSpawner->start(5000);




    goalSpeed_ = 0;
    previousSpeed_ = 0;
    movementSinceLastSpawn = 0;

    railLogic_ = new RailLogic(scene);
    playerLogic_ = new PlayerLogic(scene);


}

void Game::setSpeed(int newSpeed)
{
    railLogic_->setSpeed(newSpeed);
}

void Game::changeDirection()
{
    railLogic_->changeDirection();
}

void Game::removeBlockage()
{

    //poistetaan kaikki esteet, jotka ovat tarpeeksi lähellä pelaajaa
    for (auto i = obstacles.begin(); i != obstacles.end();){
        if ((*i).get()->y() > -250 && (*i).get()->y() < 0){
            scene_->removeItem((*i).get());
            i = obstacles.erase(i);
        }
        else {
            ++i;
        }
    }

}

void Game::move()
{

    railLogic_->move();


}

void Game::spawnObstacle()
{
    //koko ja etäisyys asetetaan myöhemmin satunnaisesti
    std::shared_ptr<Obstacle> obstacle = std::make_shared<Obstacle>(1, -1000);
    scene_->addItem(obstacle.get());
    obstacles.push_back(obstacle);
}
