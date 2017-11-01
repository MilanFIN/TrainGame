#include "boulder.h"

Boulder::Boulder(int y)
{
    QImage kuva(":/kuvat/leafs.png");
    QImage kuvaScaled = kuva.scaled(200,200,Qt::KeepAspectRatio);
    setPixmap(QPixmap::fromImage(kuvaScaled));
    setPos(-100, y);
    setZValue(1);
}

void Boulder::move(int speed)
{
    setPos(x(), y()+speed);
}
