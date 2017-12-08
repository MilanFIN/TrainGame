#ifndef OBSTACLELOGIC_H
#define OBSTACLELOGIC_H

#include <QGraphicsScene>
#include <QObject>
#include <memory>
#include <vector>

#include "obstacleinterface.h"
#include "boulder.h"
#include "traininterface.h"
#include "playertrain.h"

/**
 * @brief The ObstacleLogic is responsible for handling obstacles
 */
class ObstacleLogic: public QObject
{
    Q_OBJECT
public:
    /**
     * @brief constructor
     * @param qgraphicsscene that obstacles are added into
     */
    ObstacleLogic(std::shared_ptr<QGraphicsScene> scene);
    /**
     * @brief moves obstacles
     * @param double multiplier: train specific speed multiplier
     * @pre -
     * @post obstacle has been moved
     */
    void move(double multiplier);
    /**
     * @brief sets the new goalspeed for moving obstacles
     * @param int newSpeed: new goalspeed
     * @pre -
     * @post goalspeed has been changed
     */
    void setSpeed(int newSpeed);
    /**
     * @brief changes the direction that obstacles are moved
     * @pre -
     * @post goaldirection is the opposite of the previous state
     */
    void changeDirection();
    /**
     * @brief creates a new obstacle with obstaclefactory
     * @param stations: the two stations the obstacle will
     * appear between, trackcode: track obstacle will appear on,
     *  stationNames: names of the two stations, bool harmful:
     * information on if the obstacle is in danger of aitraincollision
     * @pre -
     * @post new obstacle has been created
     */
    void spawnObstacle(QList<QString> stations, QString trackCode,
                       QList<QString> stationNames, bool harmful);
    /**
     * @brief removes obstacles nearby the player
     * @param location: player's location in y axis
     * @pre -
     * @post nearby obstacles have been removed
     */
    void removeNearbyObjects(int location);
    /**
     * @brief checks collision between player's train and the obstacle
     * @param player's active train as a shared_ptr
     * @pre player's train is in the scene
     * @post colliding obstacles have been removed
     * @return damage dealt to the player
     */
    int checkCollision(std::shared_ptr<PlayerTrain> train); //returns amount of damage
    /**
     * @brief defines the maximum amount of distance in
     * stations that the next obstacle should be created on
     * @post maximum distance has been grown by 0.1 for the next call
     * @return goal distance for the new obstacle
     */
    int getNextDistance();
    /**
     * @brief adds the obstacle to the scene, if it should be visible
     * @post next, previous: location of the player, track: track the player is on
     */
    void addObstacleToScene(QString next, QString previous, QString track);
    /**
     * @brief returns obstacle's location and danger level as new
     * values to the parameters
     * @post info returned
     * @param prev, next: stations the obstacle is between, harmful: danger
     * level of the obstacle
     */
    void getObstacleLocation(QString &prev, QString &next, bool &harmful);
    /**
     * @brief deals with the situation, where player has collided with an obstacle
     * @pre ui has to be initialized
     * @post ui informed on an update
     */
    void crash();

signals:
    void obstacleRemoved(int fameReward, int moneyReward);
    void obstacleCreated(QString stations, QString track, QString threatLevel);
private:

    //movement related
    float speed_ = 0;
    float goalSpeed_;
    bool forward_ = true;
    float previousSpeed_;
    float accel_ = 0.1;

    //other
    std::shared_ptr<QGraphicsScene> scene_;
    std::shared_ptr<ObstacleInterface> obstacle_;

    bool inScene_ = false;
    //stationcode
    QString obstacleStartStation_;
    QString obstacleEndStation_;
    QString ObstacleTrackCode_;
    int nextObstacleDistance_ = 20;
    bool harmful_ = false;
};

#endif // OBSTACLELOGIC_H
