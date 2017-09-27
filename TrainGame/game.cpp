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



    railTiles.push_back(std::make_shared<RailGraphicsItem>(0,-275));
    scene_->addItem(railTiles.at(0).get());

    scene_->addItem(&train);

    speed_ = 0;
    movementSinceLastSpawn = 0;

}

void Game::setSpeed(int newSpeed)
{
    speed_ = newSpeed;

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
    //siirretään raiteenpätkiä
    for (auto i = railTiles.begin(); i != railTiles.end(); ++i){
        (*i).get()->move(speed_);
    }

    //siirretään esteitä
    for (auto i = obstacles.begin(); i != obstacles.end(); ++i){
        (*i).get()->move(speed_);
    }


    movementSinceLastSpawn += speed_;
    std::cout << movementSinceLastSpawn << std::endl;


    //luodaan uusi pätkä, jos on liikuttu tarpeeksi
    if (movementSinceLastSpawn >= 30){
        std::shared_ptr<RailGraphicsItem> railTile = std::make_shared<RailGraphicsItem>(0,-275);
        scene_->addItem(railTile.get());
        railTiles.push_back(railTile);
        movementSinceLastSpawn -= 30;

    }


    //poistetaan näkyvistä hävinneet raiteenpätkät
    for (auto i = railTiles.begin(); i != railTiles.end();){
        if ((*i).get()->y() > 240){
            scene_->removeItem((*i).get());
            i = railTiles.erase(i);
        }
        else{
            ++i;
        }
    }

    //pelaajan junan ja esteen törmäys
    for (auto i = obstacles.begin(); i != obstacles.end();){
        if (train.collidesWithItem((*i).get())){
            scene_->removeItem((*i).get());
            i = obstacles.erase(i);

            //damage triggeri tulee tänne
        }
        else if ((*i).get()->y() > 10000 || (*i).get()->y() < -10000){
            scene_->removeItem((*i).get());
            i = obstacles.erase(i);
        }
        else {
            ++i;
        }


    }


}

void Game::spawnObstacle()
{
    //koko ja etäisyys asetetaan myöhemmin satunnaisesti
    std::shared_ptr<Obstacle> obstacle = std::make_shared<Obstacle>(1, train.y()-1000);
    scene_->addItem(obstacle.get());
    obstacles.push_back(obstacle);
}
