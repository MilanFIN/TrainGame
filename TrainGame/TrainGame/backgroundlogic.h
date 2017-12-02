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

    void move(double multiplier);
    void setSpeed(int newSpeed);
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
