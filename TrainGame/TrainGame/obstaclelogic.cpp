#include "obstaclelogic.h"
#include "playertrain.h"
#include "obstaclefactory.h"
#include <iostream>

ObstacleLogic::ObstacleLogic(std::shared_ptr<QGraphicsScene> scene):
    scene_(scene)
{
    goalSpeed_ = 0;


}

void ObstacleLogic::move()
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


    /*
    //move obstacles and remove those too far away
    for (auto i = obstacles.begin(); i != obstacles.end();){
        (*i).get()->move((int)speed_);
        if ((*i).get()->y() > 10000 || (*i).get()->y() < -10000){
            scene_->removeItem((*i).get());
            i = obstacles.erase(i);
        }
        else {
            ++i;
        }
    }
    */


}

void ObstacleLogic::setSpeed(int newSpeed)
{
    if (forward_){
        goalSpeed_ = newSpeed;
    }
    else{
        goalSpeed_ = -newSpeed;
    }
}

void ObstacleLogic::changeDirection()
{
    forward_ = !forward_;
    goalSpeed_ = -goalSpeed_;
}



void ObstacleLogic::spawnObstacle(QList<QString> stations, QString trackCode)
{
    if (inScene_){
        scene_->removeItem(obstacle_.get());
    }
    std::shared_ptr<ObstacleInterface> obstacle_ = ObstacleFactory::GetInstance()->createObject();


}

void ObstacleLogic::removeNearbyObjects(int location)
{
/*
    //poistetaan kaikki esteet, jotka ovat tarpeeksi lähellä pelaajaa
    for (auto i = obstacles.begin(); i != obstacles.end();){
        if (abs((*i)->y() - location) < 250){
            scene_->removeItem((*i).get());
            i = obstacles.erase(i);
        }
        else {
            ++i;
        }
    }
*/
}

int ObstacleLogic::checkCollision(std::shared_ptr<PlayerTrain> train)
{
/*
    int damageDone = 0;
    //check collision between all obstacles and the train
    for (auto i = obstacles.begin(); i != obstacles.end();){
        if (train.get()->collidesWithItem((*i).get())) {//doesn work yet
            scene_->removeItem((*i).get());
            i = obstacles.erase(i);

            damageDone += 1;
        }
        else {
            ++i;
        }
    }

    return damageDone;
    */
    return 0;
}

int ObstacleLogic::getNextDistance()
{
    ++nextObstacleDistance_;
    return nextObstacleDistance_ / 10;
}
