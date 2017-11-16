#ifndef VRTRAIN_H
#define VRTRAIN_H

#include <QGraphicsPixmapItem>

/**
 * @brief Yksittäisen Vr-junan kuvaava luokka
 */
class VrTrain : public QGraphicsPixmapItem
{
public:
    VrTrain(int y);
    void move();
};

#endif // VRTRAIN_H
