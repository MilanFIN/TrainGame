#ifndef OBSTACLELOGIC_H
#define OBSTACLELOGIC_H

#include <QGraphicsScene>
#include <memory>
#include <vector>

#include "obstacleinterface.h"
#include "boulder.h"
#include "traininterface.h"

class ObstacleLogic
{
public:
    ObstacleLogic(std::shared_ptr<QGraphicsScene> scene);

    void move();
    void setSpeed(int newSpeed);
    void changeDirection();
    void spawnObstacle();
    void removeNearbyObjects(int location);
    int checkCollision(std::shared_ptr<TrainInterface> train); //returns amount of damage
private:

    //movement related
    float speed_ = 0;
    float goalSpeed_;
    bool forward_ = true;
    float previousSpeed_;
    float accel_ = 0.1;

    //other
    std::shared_ptr<QGraphicsScene> scene_;
    std::vector<std::shared_ptr<ObstacleInterface>> obstacles;
};

#endif // OBSTACLELOGIC_H
