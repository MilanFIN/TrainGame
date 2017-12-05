#ifndef BOULDER_H
#define BOULDER_H

#include "obstacleinterface.h"

/**
 * @brief Boulder describes a graphics object for a boulder
 */
class Boulder : public ObstacleInterface
{
public:
    /**
     * @brief Constructor
     * @param int y: location on y axis
     */
    Boulder(int y);

    /**
     * @brief Moves the object on y axis
     * @param int speed the amount of movement
     * @pre -
     * @post object has been moved the specified amount
     */
    void move(int speed);
    /**
     * @brief Returns the amount of damage the object does to the player
     * @pre -
     * @post Amount of damage has been returned
     * @return int amount of damage to be done to the player
     */
    int getDamage();
private:
    int damage_ = 50;
};

#endif // BOULDER_H
