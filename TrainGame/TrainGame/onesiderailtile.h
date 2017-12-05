#ifndef ONESIDERAILTILE_H
#define ONESIDERAILTILE_H

#include "railtileinterface.h"

/**
 * @brief The OneSideRailTile defines a graphics object for a railtile
 */
class OneSideRailTile : public RailTileInterface
{
public:
    /**
     * @brief OneSideRailTile constructor
     * @param x location in x axis
     * @param y location in y axis
     */
    OneSideRailTile(int x, int y);
    /**
     * @brief move moves the tile
     * @param speed amount of movement
     */
    void move(int speed);
};

#endif // ONESIDERAILTILE_H
