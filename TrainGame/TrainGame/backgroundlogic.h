#ifndef BACKGROUNDLOGIC_H
#define BACKGROUNDLOGIC_H

#include "background.h"

#include <QObject>
#include <QGraphicsScene>
#include <memory>
#include <vector>

/**
 * @brief The BackgroundLogic class handles logic related to moving background
 */
class BackgroundLogic : public QObject
{
public:
    BackgroundLogic(std::shared_ptr<QGraphicsScene> scene);
    ~BackgroundLogic();

    /**
     * @brief Handles moving the background
     * @param double multiplier: speed multiplier unique of the
     * train being used by the player
     * @pre scene has been set to a qgraphicsview widget
     * @post the background has been moved the amount of speed*multiplier,
     *  new image has been added if necessary
     */
    void move(double multiplier);
    /**
     * @brief Sets the speed of the movement for the background
     * @param int newSpeed: New speed for the background
     * @pre -
     * @post new goalspeed has been set
     */
    void setSpeed(int newSpeed);
    /**
     * @brief Changes the direction the background is moved
     * @pre -
     * @post Direction is the opposite of previous state
     */
    void changeDirection();

private:

    float speed_ = 0;
    float goalSpeed_;
    bool forward_ = true;
    bool firstTime_ = true;
    float previousSpeed_;
    float accel_ = 0.1;
    int movementOverall_;
    int movementAtLastBgCreation_;
    int movementSinceLastBgDeletion_;

     std::shared_ptr<QGraphicsScene> scene_;
     std::vector<std::shared_ptr<Background>> bg;
};

#endif // BACKGROUNDLOGIC_H
