#ifndef BG_H
#define BG_H

#include <QGraphicsPixmapItem>

/**
 * @brief Background describes an object for an background image.
 */
class Background : public QGraphicsPixmapItem
{
public:

    Background(int y);
    /**
     * @brief moves the background
     * @param amount of movement
     * @pre -
     * @post background has been moved the amount of speed
     */
    void move(int speed);
};

#endif // BACKGROUND_H
