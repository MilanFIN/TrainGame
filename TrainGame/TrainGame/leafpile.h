#ifndef LEAFPILE_H
#define LEAFPILE_H

#include "obstacleinterface.h"

class LeafPile : public ObstacleInterface
{
public:
    LeafPile(int y);

    void move(int speed);
    int getDamage();
private:
    int damage_ = 20;
};

#endif // LEAFPILE_H
