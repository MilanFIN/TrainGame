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
#include "backgroundlogic.h"



//sisältää kontrollerin
class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(std::shared_ptr<QGraphicsScene> scene,
                  std::shared_ptr<QGraphicsScene> miniMapScene, QObject *parent = nullptr);
    void setSpeed(int newSpeed);
    void changeDirection();
    void removeBlockage();
    //tells raillogic to change destination to index
    void changeDestination(int index);
    //tells raillogic to change backtrack destination to index
    void changeBacktrack(int index);
    void gameTabChosen();
    void shopTabChosen();
    void wantedOwnedTrainInfo(QString trainName);
    void wantedTrainInfo(QString trainName);
    int getPlayerCash();

    void setActiveTrain(int rowIndex);

    bool buyNewTrain(QString trainName, int index);
    bool sellTrain(QString trainName, int index);

    RailLogic* getRailModel();
    PlayerLogic* getPlayerModel();
signals:
    void shopChanged();
public slots:
    void move();
    void spawn();
    void checkCollisions();
    void updateShop();
private:

    std::shared_ptr<RailLogic>  railLogic_;
    std::shared_ptr<PlayerLogic>  playerLogic_ ;
    std::shared_ptr<ObstacleLogic>  obstacleLogic_ ;
    std::shared_ptr<BackgroundLogic> bgLogic_;


    float speed_;
    float goalSpeed_;
    bool forward_ = true;
    float previousSpeed_;
    std::shared_ptr<QGraphicsScene> scene_;
    int movementSinceLastSpawn;
    float accel_ = 0.1;
};

#endif // GAME_H
