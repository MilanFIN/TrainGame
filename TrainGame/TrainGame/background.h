#ifndef BG_H
#define BG_H

#include <QGraphicsPixmapItem>

class Background : public QGraphicsPixmapItem
{
public:
    Background();

    void move(int speed);
};

#endif // BACKGROUND_H
