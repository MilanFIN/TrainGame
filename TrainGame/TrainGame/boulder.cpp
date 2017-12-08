#include "boulder.h"

Boulder::Boulder(int y)
{
    QImage kuva(":/kuvat/brick.png");
    QImage kuvaScaled = kuva.scaled(100,100,Qt::KeepAspectRatio);
    setPixmap(QPixmap::fromImage(kuvaScaled));
    setPos(-50, y);
    setZValue(1);
}

void Boulder::move(int speed)
{
    setPos(x(), y()+speed);
}

int Boulder::getDamage()
{
    return damage_;
}
