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

    goalSpeed_ = 0;
    previousSpeed_ = 0;
    movementSinceLastSpawn = 0;

}

void Game::setSpeed(int newSpeed)
{
    if (forward_){
        goalSpeed_ = newSpeed;
    }
    else{
        goalSpeed_ = -newSpeed;
    }

}

void Game::changeDirection()
{
    forward_ = !forward_;
    goalSpeed_ = -goalSpeed_;
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

    if (forward_){
        if (speed_ > goalSpeed_){
            speed_ -= accel_;
        }
        else if (speed_ < goalSpeed_){
            speed_ += accel_;
        }
    }
    if (!forward_){
        if (speed_ < goalSpeed_){
            speed_ += accel_;
        }
        else if (speed_ > goalSpeed_){
            speed_ -= accel_;
        }
    }
    //siirretään raiteenpätkiä
    for (auto i = railTiles.begin(); i != railTiles.end(); ++i){
        (*i).get()->move((int)speed_);
    }

    //siirretään esteitä
    for (auto i = obstacles.begin(); i != obstacles.end(); ++i){
        (*i).get()->move((int)speed_);
    }


    //tarkistetaan, onko kulkusuunta ehtinyt vaihtua edellisen päiviyksen jälkeen

    if ((previousSpeed_ > 0 && speed_ < 0) || (previousSpeed_ < 0 && speed_ > 0)){
        movementSinceLastSpawn = 0;
    }

    movementSinceLastSpawn += speed_;
    previousSpeed_ = speed_;



    //luodaan uusi pätkä, jos on liikuttu tarpeeksi
    if (movementSinceLastSpawn >= 30){
        std::shared_ptr<RailGraphicsItem> railTile = std::make_shared<RailGraphicsItem>(0,-275);
        scene_->addItem(railTile.get());
        railTiles.push_back(railTile);
        movementSinceLastSpawn -= 30;
    }
    else if (movementSinceLastSpawn <= -30){
        std::shared_ptr<RailGraphicsItem> railTile = std::make_shared<RailGraphicsItem>(0,240);
        scene_->addItem(railTile.get());
        railTiles.push_back(railTile);
        movementSinceLastSpawn += 30;
    }


    //poistetaan näkyvistä hävinneet raiteenpätkät
    for (auto i = railTiles.begin(); i != railTiles.end();){
        if ((*i).get()->y() > 241){
            scene_->removeItem((*i).get());
            i = railTiles.erase(i);
        }
        else if ((*i).get()->y() < -276){
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
