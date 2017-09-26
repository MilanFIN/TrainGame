#include "game.h"
#include <iostream>


Game::Game(std::shared_ptr<QGraphicsScene> scene, QObject *parent) : QObject(parent),
  scene_(scene)
{

    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(66);



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

void Game::move()
{
    //siirretään raiteenpätkiä
    for (auto i = railTiles.begin(); i != railTiles.end(); ++i){
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


}
