#include "boulder.h"

Boulder::Boulder(int y)
{
    QImage kuva(":/kuvat/leafs.png");
    setPixmap(QPixmap::fromImage(kuva));
    setPos(-50, y);
    setZValue(1);
}

void Boulder::move(int speed)
{
    setPos(x(), y()+speed);
}
