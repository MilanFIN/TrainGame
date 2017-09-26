#include "railgraphicsitem.h"

RailGraphicsItem::RailGraphicsItem(int x, int y)
{
    setPixmap(QPixmap("./img/rail.png"));
    setPos(x-15,y);
}

void RailGraphicsItem::move(int speed)
{
    setPos(x(), y()+speed);
}
