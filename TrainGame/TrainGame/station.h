#ifndef STATION_H
#define STATION_H

#include "QGraphicsPixmapItem"

class Station : public QGraphicsPixmapItem
{
public:
    Station(int y);
    void move(int speed);
};

#endif // STATION_H
