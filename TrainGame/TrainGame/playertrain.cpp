#include "playertrain.h"

PlayerTrain::PlayerTrain(QString name, short shape, unsigned short price, double speed, unsigned short repairCost):
    name_(name),
    shape_(shape),
    price_(price),
    speed_(speed),
    repairCost_(repairCost_)
{
    QImage kuva(":/kuvat/train.png");
    setPixmap(QPixmap::fromImage(kuva));
    setPos(-25, 0);
    //asetetaan raiteiden päälle
    setZValue(2);

    isOwned_ = false;
    isPlayable_ = true;
}



QString PlayerTrain::getName()
{
    return name_;
}

unsigned short PlayerTrain::getPrice() const
{
    return price_;
}

short PlayerTrain::getShape() const
{
    return shape_;
}

unsigned short PlayerTrain::getRepairCost() const
{
    return repairCost_;
}

double PlayerTrain::getSpeed() const
{
    return speed_;
}

bool PlayerTrain::isAbleToPlay() const
{
    return isPlayable_;
}

unsigned short PlayerTrain::takeDamage(int dmgAmount)
{
    if (shape_ * dmgAmount <= 0) {
        isPlayable_ = false;
        shape_ = 0;

    }

    shape_ *= dmgAmount;
    return shape_;
}

void PlayerTrain::setPlayable()
{
    isPlayable_ = true;
}

void PlayerTrain::setOwned()
{
    isOwned_ = true;
}

