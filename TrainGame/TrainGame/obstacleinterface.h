#ifndef OBSTACLEINTERFACE_H
#define OBSTACLEINTERFACE_H

#include <QGraphicsPixmapItem>

/**
 * @brief ObstacleInterface defines an abstract interface for using obstacles
 */
class ObstacleInterface : public QGraphicsPixmapItem
{
public:
    ObstacleInterface() = default;
    virtual ~ObstacleInterface() = default;
    /**
     * @brief abstract method to move the object
     * @param int speed: amount of movement
     */
    virtual void move(int speed) = 0;
    /**
     * @brief abstract method to get the damage
     *  to be done to the player by the obstacle
     * @return damage done to player
     */
    virtual int getDamage() = 0;
};

#endif // OBSTACLEINTERFACE_H
