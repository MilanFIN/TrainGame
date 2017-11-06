#include "backgroundlogic.h"

#include <iostream>
#include <QDebug>


BackgroundLogic::BackgroundLogic(std::shared_ptr<QGraphicsScene> scene):
    scene_(scene)
{
    bg.push_back(std::make_shared<Background>(-2500));
    scene_->addItem(bg.at(0).get());

    goalSpeed_ = 0;
    previousSpeed_ = 0;
    movementSinceLastBgSpawn_ = 0;
}

BackgroundLogic::~BackgroundLogic() {

}

void BackgroundLogic::move() {

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

    //siirretään backgroundia
    for (auto x = bg.begin(); x != bg.end(); ++x) {
        (*x).get()->move((int)speed_);
    }

    movementSinceLastBgSpawn_ += speed_;
    previousSpeed_ = speed_;

    qInfo() << movementSinceLastBgSpawn_;

//    if (movementSinceLastBgSpawn >= 4000) {

//        std::shared_ptr<Background> newBg = std::make_shared<Background>(-5450);
//        scene_->addItem(newBg.get());
//        bg.push_back(newBg);
//        movementSinceLastBgSpawn -= 4000;
//    }

    if (movementSinceLastBgSpawn_ >= 1500 && firstTime_ == true && forward_ == true) {
        std::shared_ptr<Background> newBg = std::make_shared<Background>(-5450);
        scene_->addItem(newBg.get());
        bg.push_back(newBg);
        movementSinceLastBgSpawn_ = 0;
        firstTime_ = false;

    }



    //poistetaan näkyvistä hävinnyt background
    for (auto x = bg.begin(); x != bg.end();) {
        if ((*x).get()->y() > 5500) {
            scene_->removeItem((*x).get());
            x = bg.erase(x);
        }
        else if ((*x).get()->y() < -5500) {
            scene_->removeItem((*x).get());
            x = bg.erase(x);
        }
        else {
            ++x;
        }

    }
}



void BackgroundLogic::setSpeed(int newSpeed)
{
    if (forward_){
        goalSpeed_ = newSpeed;
    }
    else{
        goalSpeed_ = -newSpeed;
    }
}

void BackgroundLogic::changeDirection()
{
    forward_ = !forward_;
    goalSpeed_ = -goalSpeed_;
}
