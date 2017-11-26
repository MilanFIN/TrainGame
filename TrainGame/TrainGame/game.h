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
#include "vrtrainmanager.h"


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
    void depotTabChosen();
    void wantedOwnedTrainInfo(QString trainName);
    void wantedTrainInfo(QString trainName);
    void fixlistTrainInfo(QString trainName);
    int getPlayerCash();

    void repairPlayerTrain(int rowIndex);

    void setActiveTrain(int rowIndex);

    void buyNewTrain(QString trainName, int index);
    void sellTrain(int index);

    void railChanged();

    void addMoney(int amount);
    void addFame(int amount);

    RailLogic* getRailModel();
    PlayerLogic* getPlayerModel();
    ObstacleLogic* getObstacleModel();
    VrTrainManager* getAiTrainModel();
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
    std::shared_ptr<VrTrainManager> aiTrainManager_;


    float speed_;
    float goalSpeed_;
    bool forward_ = true;
    float previousSpeed_;
    std::shared_ptr<QGraphicsScene> scene_;
    int movementSinceLastSpawn;
    float accel_ = 0.1;



    QTimer *obstacleSpawner_ = new QTimer(this);


    bool runGame_ = false;

};

#endif // GAME_H
