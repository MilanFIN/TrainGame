#ifndef OBSTACLEINTERFACE_H
#define OBSTACLEINTERFACE_H

#include <QGraphicsPixmapItem>

class ObstacleInterface : public QGraphicsPixmapItem
{
public:
    ObstacleInterface() = default;
    virtual ~ObstacleInterface() = default;
    virtual void move(int speed) = 0;
    virtual int getDamage() = 0;
};

#endif // OBSTACLEINTERFACE_H
