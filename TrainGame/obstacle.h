#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsPixmapItem>


//radalla olevan esteen määrittelevä luokka
class Obstacle : public QGraphicsPixmapItem
{
public:
    Obstacle(int size, int distance);
    void move(int speed);
};

#endif // OBSTACLE_H
