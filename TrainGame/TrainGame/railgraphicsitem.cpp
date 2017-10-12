#include "railgraphicsitem.h"

RailGraphicsItem::RailGraphicsItem(int x, int y)
{
    QImage kuva(":/kuvat/rail.png");
    setPixmap(QPixmap::fromImage(kuva));
    setPos(x-15,y);
}

void RailGraphicsItem::move(int speed)
{
    setPos(x(), y()+speed);
}
