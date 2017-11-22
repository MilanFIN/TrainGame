#include "obstaclelogic.h"
#include "playertrain.h"
#include "obstaclefactory.h"
#include <iostream>

ObstacleLogic::ObstacleLogic(std::shared_ptr<QGraphicsScene> scene):
    scene_(scene)
{
    goalSpeed_ = 0;
    inScene_ = false;

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

    //move obstacle
    obstacle_.get()->move((int)speed_);


    //
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



void ObstacleLogic::spawnObstacle(QList<QString> stations, QString trackCode, QList<QString> stationNames)
{
    if (inScene_){
        scene_->removeItem(obstacle_.get());
        inScene_ = false;
    }
    obstacle_ = ObstacleFactory::GetInstance()->createObject();

    obstacleStartStation_ = stations.at(0);
    obstacleEndStation_ = stations.at(1);
    ObstacleTrackCode_ = trackCode;

    emit obstacleCreated(stationNames.at(0) + " - " + stationNames.at(1), trackCode, "haitta");
}

void ObstacleLogic::removeNearbyObjects(int location)
{
    if (inScene_){
        if (abs(obstacle_.get()->y() - location) < 250){
            scene_->removeItem(obstacle_.get());
            inScene_ = false;
            emit obstacleRemoved(10, 100);
        }
    }

}

int ObstacleLogic::checkCollision(std::shared_ptr<PlayerTrain> train)
{
    int damageDone = 0;

    if (inScene_){
        if (train.get()->collidesWithItem(obstacle_.get())) {//doesn work yet
            scene_->removeItem(obstacle_.get());
            inScene_ = false;

            damageDone += 20;
            //annetaan vaan palkkio, muttei famea koska törmättiin
            emit obstacleRemoved(0, 100);
        }
    }

    return damageDone;

}

int ObstacleLogic::getNextDistance()
{
    ++nextObstacleDistance_;
    return nextObstacleDistance_ / 10;
}

void ObstacleLogic::addObstacleToScene(QString next, QString previous, QString track)
{
    if (ObstacleTrackCode_ == track){
        if ((next == obstacleStartStation_ && previous == obstacleEndStation_)
                || previous == obstacleStartStation_ && next == obstacleEndStation_){
            obstacle_.get()->setPos(obstacle_.get()->x(), -300);

            if (!inScene_){
                scene_->addItem(obstacle_.get());

                inScene_ = true;
                std::cout << "lisätty" << std::endl;
            }
        }
    }
    else {
        if (inScene_){
            scene_->removeItem(obstacle_.get());
            inScene_ = false;
            std::cout << "poistettu" << std::endl;

        }

    }

}
