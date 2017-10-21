#ifndef RAILTILEINTERFACE_H
#define RAILTILEINTERFACE_H

#include <QGraphicsItem>

//radanpätkän kuvaava rajapintaluokka
class RailTileInterface : public QGraphicsPixmapItem
{
public:
    RailTileInterface() = default;
    virtual ~RailTileInterface() = default;
    virtual void move(int speed) = 0;

};

#endif // RAILTILEINTERFACE_H
