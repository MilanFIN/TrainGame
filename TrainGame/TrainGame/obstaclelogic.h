#ifndef OBSTACLELOGIC_H
#define OBSTACLELOGIC_H

#include <QGraphicsScene>
#include <memory>
#include <vector>
#include <QObject>

#include "obstacleinterface.h"
#include "boulder.h"
#include "traininterface.h"
#include "playertrain.h"

class ObstacleLogic: public QObject
{
    Q_OBJECT
public:
    ObstacleLogic(std::shared_ptr<QGraphicsScene> scene);

    void move();
    void setSpeed(int newSpeed);
    void changeDirection();
    void spawnObstacle();
    void removeNearbyObjects(int location);
    int checkCollision(std::shared_ptr<PlayerTrain> train); //returns amount of damage
private:

    //movement related
    float speed_ = 0;
    float goalSpeed_;
    bool forward_ = true;
    float previousSpeed_;
    float accel_ = 1;

    //other
    std::shared_ptr<QGraphicsScene> scene_;
    std::vector<std::shared_ptr<ObstacleInterface>> obstacles;
};

#endif // OBSTACLELOGIC_H
