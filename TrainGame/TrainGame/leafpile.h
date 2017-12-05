#ifndef LEAFPILE_H
#define LEAFPILE_H

#include "obstacleinterface.h"
/**
 * @brief leafpile describes a graphics object for a leafpile
 */
class LeafPile : public ObstacleInterface
{
public:
    /**
     * @brief constructor
     * @param int y: location on y axis
     */

    LeafPile(int y);
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
    int damage_ = 20;
};

#endif // LEAFPILE_H
