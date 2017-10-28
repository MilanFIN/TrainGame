#include "station.h"

Station::Station(int y)
{
    QImage kuva(":/kuvat/station.png");
    setPixmap(QPixmap::fromImage(kuva));
    setPos(-100, y);
    setZValue(10);
}

void Station::move(int speed){
    setPos(-100, y()+speed);
}
