#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsScene>
#include <memory>
#include <vector>
#include <QTimer>
#include "railgraphicsitem.h"
#include "traingraphicsitem.h"
#include "obstacle.h"



//sisältää pelilogiikan
class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(std::shared_ptr<QGraphicsScene> scene, QObject *parent = nullptr);
    void setSpeed(int newSpeed);
    void removeBlockage();

signals:

public slots:
    void move();
    void spawnObstacle();
private:
    int speed_;
    std::shared_ptr<QGraphicsScene> scene_;
    std::vector<std::shared_ptr<RailGraphicsItem>> railTiles;
    std::vector<std::shared_ptr<Obstacle>> obstacles;
    int movementSinceLastSpawn;
    TrainGraphicsItem train;
};

#endif // GAME_H
