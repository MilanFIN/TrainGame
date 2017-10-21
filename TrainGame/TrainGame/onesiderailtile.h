#ifndef ONESIDERAILTILE_H
#define ONESIDERAILTILE_H

#include "railtileinterface.h"

class OneSideRailTile : public RailTileInterface
{
public:
    OneSideRailTile(int x, int y);
    void move(int speed);
};

#endif // ONESIDERAILTILE_H
