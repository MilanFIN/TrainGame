#ifndef RAILGRAPHICSITEM_H
#define RAILGRAPHICSITEM_H

#include <QGraphicsPixmapItem>

//määrittelee raiteenpätkän
class RailGraphicsItem : public QGraphicsPixmapItem
{
public:
    RailGraphicsItem(int x, int y);
    //siirtää raidetta näytöllä
    void move(int speed);
};

#endif // RAILGRAPHICSITEM_H
