#ifndef BOULDER_H
#define BOULDER_H

#include "obstacleinterface.h"

class Boulder : public ObstacleInterface
{
public:
    Boulder(int y);

    void move(int speed);

};

#endif // BOULDER_H
