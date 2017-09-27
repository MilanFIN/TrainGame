#include "obstacle.h"



Obstacle::Obstacle(int size, int y)
{
    setPixmap(QPixmap("./img/leafs.png"));
    setPos(-50, y);
    setZValue(1);

}

void Obstacle::move(int speed)
{
    setPos(x(), y()+speed);
}
