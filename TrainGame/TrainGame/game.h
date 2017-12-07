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



/**
 * @brief Game controller (in an mvc model)
 */
class Game : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor
     * @param scene: qgraphicsscene, miniMapScene -||- for the minimap
     */
    explicit Game(std::shared_ptr<QGraphicsScene> scene,
                  std::shared_ptr<QGraphicsScene> miniMapScene, QObject *parent = nullptr);
    /**
     * @brief sets a new goalspeed for the game
     * @param int newSpeed: new goalspeed
     * @pre -
     * @post new goalspeed has been sent to logic
     */
    void setSpeed(int newSpeed);
    /**
     * @brief changes direction of the game
     * @pre -
     * @post direction is the opposite of previous state
     */
    void changeDirection();
    /**
     * @brief tells obstaclelogic to remove nearby obstacles
     * @pre an obstacle exists
     * @post a method in obstaclelogic has been called
     */
    void removeBlockage();
    /**
     * @brief changes destination station to the index
     * @param index of the destination
     * @pre index is in the range of possible destinations
     * @post new destination has been chosen
     */
    void changeDestination(int index);
    /**
     * @brief changes previous stations options for destinations to the index
     * @param index for the station
     * @pre index is in range of possible stations choises
     * @post new choise has been set
     */
    void changeBacktrack(int index);
    /**
     * @brief sets gamestate to the one needed on game-tab
     * @pre -
     * @post gamestate updated
     */
    void gameTabChosen();
    /**
     * @brief sets gamestate to the one needed on shop-tab
     * @pre -
     * @post gamestate updated
     */
    void shopTabChosen();
    /**
     * @brief sets gamestate to the one needed on depot-tab
     * @pre -
     * @post gamestate updated
     */
    void depotTabChosen();

    void wantedOwnedTrainInfo(QString trainName);
    void wantedTrainInfo(QString trainName);
    void fixlistTrainInfo(QString trainName);
    /**
     * @brief returns amount of money the player has
     * @pre -
     * @return amount of money in int
     * @post returned amount of money on the player
     */
    int getPlayerMoney();
    /**
     * @brief tells playerlogic to repair the specified train
     * @param index for the train
     * @pre index is in range of possible train choises
     * @post chosen train has been repaired
     */
    void repairPlayerTrain(int rowIndex);
    /**
     * @brief tells playerlogic to change the active train
     * @param index for the train
     * @pre index is in range of possible train choises
     * @post chosen train has been set active, previous to inactive
     */
    void setActiveTrain(int rowIndex);
    /**
     * @brief tells playerlogic to buy a new train
     * @param index for the train
     * @pre index is in range of possible train choises
     * @post chosen train has been bought
     */
    void buyNewTrain(QString trainName, int index);
    /**
     * @brief tells playerlogic to sell the specified train
     * @param index for the train
     * @pre index is in range of possible train choises
     * @post chosen train has been sold
     */
    void sellTrain(int index);
    /**
     * @brief informs obstaclelogic that the current railway part has been changed
     * @pre railway network data has been read in raillogic
     * @post obstacle appears in scene if necessary
     */
    void railChanged();
    /**
     * @brief tells playerlogic to add money to the player
     * @param int amount: amount of money to be added
     * @post money amount updated
     */
    void addMoney(int amount);
    /**
     * @brief tells playerlogic to add fame to the player
     * @param int amount: amount of fame to be added
     * @post fame amount updated
     */
    void addFame(int amount);
    /**
     * @brief tells raillogic to update navigation data
     * @pre -
     * @post navigation data updated to ui
     */
    void updateNavi();
    /**
     * @brief returns a pointer to a logic object
     * @return pointer to raillogic
     */
    RailLogic* getRailModel();
    /**
     * @brief returns a pointer to a logic object
     * @return pointer to playerlogic
     */
    PlayerLogic* getPlayerModel();
    /**
     * @brief returns a pointer to a logic object
     * @return pointer to obstaclelogic
     */
    ObstacleLogic* getObstacleModel();
    /**
     * @brief returns a pointer to a logic object
     * @return pointer to vrtrainmanager
     */
    VrTrainManager* getAiTrainModel();
public slots:
    /**
     * @brief moves necessary gameobjects
     * @post objects have moved
     */
    void move();
    /**
     * @brief tells obstaclelogic to spawn a new obstacle
     * @post new obstacle has been spawned and previous removed if still present
     */
    void spawn();
    /**
     * @brief checks collision between ai and playertrains and obstacles
     * @post damage and penalties happened if necessary
     */
    void checkCollisions();
signals:
    void endGameSignal();

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
    //float accel_ = 0.03;
    QTimer *obstacleSpawner_ = new QTimer(this);
    QTimer *moveTimer = new QTimer(this);
    bool runGame_ = false;

};

#endif // GAME_H
