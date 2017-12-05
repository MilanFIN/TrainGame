#ifndef STATION_H
#define STATION_H

#include "QGraphicsPixmapItem"

/**
 * @brief The Station class describes a station graphics item
 */
class Station : public QGraphicsPixmapItem
{
public:
    /**
     * @brief Station constructor
     * @param y location in y axis
     */
    Station(int y);
    /**
     * @brief move moves the station in a scene
     * @param speed amount of movement
     * @post the station has moved
     */
    void move(int speed);
};

#endif // STATION_H
