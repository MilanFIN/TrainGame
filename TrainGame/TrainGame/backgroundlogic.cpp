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
    movementOverall_ = 0;
    movementAtLastBgCreation_ = 0;
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

    movementOverall_ += speed_;
    previousSpeed_ = speed_;

    //qInfo() << movementOverall_;

    //because game starts in the middle of background
    //we must do the first background creation differently
    if (movementOverall_ >= 1500 && firstTime_ == true && forward_ == true) {

        std::shared_ptr<Background> newBg = std::make_shared<Background>(-5980);
        scene_->addItem(newBg.get());
        bg.push_back(newBg);
        firstTime_ = false;
        movementAtLastBgCreation_ = movementOverall_;
    }

    //because game starts in the middle of background
    //we must do the first background creation differently
    else if (movementOverall_ <= -1500 && firstTime_ == true && forward_ == false) {

        std::shared_ptr<Background> newBg = std::make_shared<Background>(950);
        scene_->addItem(newBg.get());
        bg.push_back(newBg);
        firstTime_ = false;
        movementAtLastBgCreation_ = movementOverall_;
    }

    else if (movementOverall_ >= movementAtLastBgCreation_ + 5000
             && firstTime_ == false && forward_ == true) {

        std::shared_ptr<Background> newBg = std::make_shared<Background>(-5800);
        scene_->addItem(newBg.get());
        bg.push_back(newBg);
        movementAtLastBgCreation_ = movementOverall_;

        //lisätään backgroundien päällekkäisyyttä kun y koordinaatilla ei toiminut kovin varmasti
        movementOverall_ += 100;
    }

    else if (movementOverall_ <= movementAtLastBgCreation_ - 5000
             && firstTime_ == false && forward_ == false) {

        std::shared_ptr<Background> newBg = std::make_shared<Background>(800);
        scene_->addItem(newBg.get());
        bg.push_back(newBg);
        movementAtLastBgCreation_ = movementOverall_;
        movementOverall_ -= 100;
    }

//    //poistetaan näkyvistä hävinnyt background
//    for (auto x = bg.begin(); x != bg.end();) {
//        if ((*x).get()->y() > 5500) {
//            scene_->removeItem((*x).get());
//            x = bg.erase(x);
//        }
//        else if ((*x).get()->y() < -5500) {
//            scene_->removeItem((*x).get());
//            x = bg.erase(x);
//        }
//        else {
//            ++x;
//        }

//    }
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