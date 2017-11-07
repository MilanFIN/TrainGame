#ifndef PLAYERTRAIN_H
#define PLAYERTRAIN_H

#include <QGraphicsPixmapItem>
#include "traininterface.h"

class PlayerTrain: public TrainInterface
{
public:
    PlayerTrain(QString name, short shape, unsigned short price, double speed, unsigned short repairCost);


    QString getName();

    double getSpeed() const;
    unsigned short getPrice() const;
    short getShape() const;
    unsigned short getRepairCost() const;

    // if train is not owned it cannot be used in game.
    bool isAbleToPlay() const;
    bool isOwned() const;


    unsigned short takeDamage(int dmgAmount);
    void setPlayable();
    void setOwned();

    void setPixmapToShow(QString name);
private:


    QString name_;
    bool isPlayable_;
    bool isOwned_;
    short const absoluteShape_;


    short shape_;
    unsigned short price_;
    double speed_;
    unsigned short repairCost_;

};

#endif // PLAYERTRAIN_H
