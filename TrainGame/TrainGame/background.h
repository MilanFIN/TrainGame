#ifndef BG_H
#define BG_H

#include <QGraphicsPixmapItem>

class Background : public QGraphicsPixmapItem
{
public:
    Background(int y);

    void move(int speed);
};

#endif // BACKGROUND_H
