#include "station.h"

Station::Station(int y)
{
    QImage kuva(":/kuvat/station.png");
    QImage kuvaScaled = kuva.scaled(200,200,Qt::KeepAspectRatio);
    setPixmap(QPixmap::fromImage(kuvaScaled));
    setPos(-70, y);
    setZValue(10);
}

void Station::move(int speed){
    setPos(x(), y()+speed);
}
