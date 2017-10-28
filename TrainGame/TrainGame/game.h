#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsScene>
#include <memory>
#include <vector>
#include <QTimer>
#include "raillogic.h"
#include "playerlogic.h"
#include "obstaclelogic.h"



//sisältää kontrollerin
class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(std::shared_ptr<QGraphicsScene> scene, QObject *parent = nullptr);
    void setSpeed(int newSpeed);
    void changeDirection();
    void removeBlockage();

signals:

public slots:
    void move();
    void spawn();
    void checkCollisions();
private:

    RailLogic* railLogic_;
    PlayerLogic* playerLogic_;
    ObstacleLogic* obstacleLogic_;

    float speed_;
    float goalSpeed_;
    bool forward_ = true;
    float previousSpeed_;
    std::shared_ptr<QGraphicsScene> scene_;
    int movementSinceLastSpawn;
    float accel_ = 0.1;
};

#endif // GAME_H
