#include "station.h"

Station::Station(int y)
{
    QImage kuva(":/kuvat/station.png");
    QImage kuvaScaled = kuva.scaled(300,300,Qt::KeepAspectRatio);
    setPixmap(QPixmap::fromImage(kuvaScaled));
    setPos(0, y);
    setZValue(10);
}

void Station::move(int speed){
    setPos(45, y()+speed);
}
