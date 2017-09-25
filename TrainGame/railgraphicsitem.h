#ifndef RAILGRAPHICSITEM_H
#define RAILGRAPHICSITEM_H

#include <QGraphicsPixmapItem>

//määrittelee raiteenpätkän
class RailGraphicsItem : public QGraphicsPixmapItem
{
public:
    RailGraphicsItem();
    //siirtää raidetta näytöllä
    void move();
};

#endif // RAILGRAPHICSITEM_H
