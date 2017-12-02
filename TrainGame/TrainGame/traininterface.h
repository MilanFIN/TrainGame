#ifndef TRAININTERFACE_H
#define TRAININTERFACE_H

#include <QGraphicsPixmapItem>
#include <QObject>

class TrainInterface : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    TrainInterface() = default;
    virtual ~TrainInterface() = default;


    // TODO: train object must be shareable
    // so player can own it or them


//    // returns train's name
//    virtual QString getName() const = 0;

//    // set "health" of the train
//    virtual void setShape(int shapePoints) = 0;

//    // return current shape of the train
//    virtual int getCurrentShape() const = 0;

//    virtual void setSpeed(short speedUnit) = 0;
//    virtual short getSpeed() const = 0;

//    virtual void repair() = 0;

//    virtual void takeDamage(short amount) = 0;

//    // if train is broken it cannot be used for playing
//    virtual bool isAbleToWork() = 0;

};

#endif // TRAININTERFACE_H
