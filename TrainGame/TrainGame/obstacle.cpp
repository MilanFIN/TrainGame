#include "obstacle.h"
#include <QString>



Obstacle::Obstacle(int size, int y)
{
    QImage kuva(":/kuvat/leafs.png");
    setPixmap(QPixmap::fromImage(kuva));
    setPos(-50, y);
    setZValue(1);

}

void Obstacle::move(int speed)
{
    setPos(x(), y()+speed);
}
