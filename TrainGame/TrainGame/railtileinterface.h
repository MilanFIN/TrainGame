#ifndef RAILTILEINTERFACE_H
#define RAILTILEINTERFACE_H

#include <QGraphicsItem>


/**
 * @brief The RailTileInterface class defines an interface for railtiles
 */
class RailTileInterface : public QGraphicsPixmapItem
{
public:
    RailTileInterface() = default;
    virtual ~RailTileInterface() = default;
    /**
     * @brief move an abstract method for moving the object in a scene
     * @param speed amount of movement on y axis
     */
    virtual void move(int speed) = 0;

};

#endif // RAILTILEINTERFACE_H
