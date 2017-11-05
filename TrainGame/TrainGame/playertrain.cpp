#include "playertrain.h"

PlayerTrain::PlayerTrain(QString name, short shape, unsigned short price, double speed, unsigned short repairCost):
    name_(name),
    shape_(shape),
    price_(price),
    speed_(speed),
    repairCost_(repairCost_)
{
    //juna 1 oikeat positiot ja skaalaus
//    QImage kuva(":/kuvat/train.png");
//    QImage kuvaScaled = kuva.scaled(200,200,Qt::KeepAspectRatio);
//    setPixmap(QPixmap::fromImage(kuvaScaled));
//    setPos(-69, 0);

    //juna 2 oikea positio ja skaalaus
//    QImage kuva(":/kuvat/train2.png");
//    QImage kuvaScaled = kuva.scaled(75,200);
//    setPixmap(QPixmap::fromImage(kuvaScaled));
//    setPos(-35, 0);

//    QImage kuva(":/kuvat/train3.png");
//    QImage kuvaScaled = kuva.scaled(90,250,Qt::KeepAspectRatio);
//    setPixmap(QPixmap::fromImage(kuvaScaled));
//    setPos(-40, 0);

    QImage kuva(":/kuvat/train4.png");
    QImage kuvaScaled = kuva.scaled(70,230,Qt::KeepAspectRatio);
    setPixmap(QPixmap::fromImage(kuvaScaled));
    setPos(-35, -30);







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

