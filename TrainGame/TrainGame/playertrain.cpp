#include "playertrain.h"

PlayerTrain::PlayerTrain(QString name, short shape, unsigned short price, double speed, unsigned short repairCost, QString imagePath):
    name_(name),
    shape_(shape),
    absoluteShape_(shape),
    price_(price),
    speed_(speed),
    repairCost_(repairCost),
    trainImage_(imagePath)
{
    QImage kuva(":/kuvat/train.png");
    QImage kuvaScaled = kuva.scaled(150,150,Qt::KeepAspectRatio);
    setPixmap(QPixmap::fromImage(kuvaScaled));
    setPos(-55, -30);

    //asetetaan raiteiden päälle
    setZValue(2);

    isOwned_ = false;
    isPlayable_ = true;
}

void setPixmapToShow(QString name) {

//    if (name == "Lättähattu") {

//        QImage kuva(":/kuvat/train.png");
//        QImage kuvaScaled = kuva.scaled(150,150,Qt::KeepAspectRatio);
//        setPixmap(QPixmap::fromImage(kuvaScaled));
//        setPos(-55, -30);

//     }

//    else if (name == "Luotijuna") {

//        QImage kuva(":/kuvat/train2.png");
//        QImage kuvaScaled = kuva.scaled(75,200);
//        setPixmap(QPixmap::fromImage(kuvaScaled));
//        setPos(-35, 0);
//    }

//    else if (name == "Pomppuresiina") {

//        QImage kuva(":/kuvat/train3.png");
//        QImage kuvaScaled = kuva.scaled(90,250,Qt::KeepAspectRatio);
//        setPixmap(QPixmap::fromImage(kuvaScaled));
//        setPos(-40, 0);
//    }

//    else if (name == "Höyryveturi") {

//        QImage kuva(":/kuvat/train4.png");
//        QImage kuvaScaled = kuva.scaled(70,230,Qt::KeepAspectRatio);
//        setPixmap(QPixmap::fromImage(kuvaScaled));
//        setPos(-35, -30);
//    }

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
    shape_ -= dmgAmount;
    return shape_;
}

void PlayerTrain::setPlayable()
{
    isPlayable_ = true;
}

void PlayerTrain::setOwned()
{
    if (!isOwned_) {
        isOwned_ = true;
    } else {
        isOwned_ = false;
    }

}

