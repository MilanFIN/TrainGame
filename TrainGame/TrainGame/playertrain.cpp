#include "playertrain.h"

PlayerTrain::PlayerTrain(QString name, short shape, unsigned short price, double speed, unsigned short repairCost):
    name_(name),
    shape_(shape),
    price_(price),
    speed_(speed),
    repairCost_(repairCost_)
{
    QImage kuva(":/kuvat/train.png");
    QImage kuvaScaled = kuva.scaled(200,200,Qt::KeepAspectRatio);
    setPixmap(QPixmap::fromImage(kuvaScaled));
    setPos(-69, 0);
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
    if (shape_ - dmgAmount <= 0) {
        isPlayable_ = false;
        shape_ = 0;

    }

    //because damage is always minus we use shape = shape + dmgAmount
    shape_ += dmgAmount;
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

