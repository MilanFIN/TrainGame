#ifndef VRTRAINMANAGER_H
#define VRTRAINMANAGER_H

#include <QObject>
#include <QGraphicsScene>
#include <QVector>
#include <memory>
#include "httpengine.h"
#include "vrtrain.h"
#include "playertrain.h"

/**
 * @brief The VrTrainManager class manages vrtrain objects
 */
class VrTrainManager : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief VrTrainManager constructor
     * @param scene scene that the vrtrain objecs are to be added into
     */
    VrTrainManager(std::shared_ptr<QGraphicsScene> scene);
    /**
     * @brief addAiTrain adds a vrtrain object to be managed
     * @param id id of the train
     * @param aiTrain smart pointer to the vrtrain
     * @post the aiTrain object has been added to the ones being handled by this class
     */
    void addAiTrain(QString id, std::shared_ptr<VrTrain> aiTrain);
    /**
     * @brief checkCollisions checks collisions between an obstacle and the vrtrains
     * @param prev a station next to the obstacle (stationcode)
     * @param next another station next to the obstacle (stationcode)
     * @param harmful info if the obstacle is a danger to the vrtrain objects
     * @return true if a collision has happened
     * @post the collided vrtrain has been blacklisted
     */
    bool checkCollisions(QString prev, QString next, bool harmful);
    /**
     * @brief checkPlayerCollision checks collisions between vrtrains and the player's train
     * @param player player's active train
     * @return int damage taken, 0 if no collision has happened
     * @post the collided vrtrain has been blacklisted
     */
    int checkPlayerCollision(std::shared_ptr<PlayerTrain> player);

    /**
     * @brief getAllAiTrains returns all vrtrains
     * @return all vrtrains
     */
    QHash<QString, std::shared_ptr<VrTrain>> getAllAiTrains() const;
    /**
     * @brief move moves the vrtrain objects in regard to their timetables
     * @param prev last station the player passed (stationcode)
     * @param next players destination (stationcode)
     * @param prevY previous stations y coordinate
     * @param nextY next stations y coordinate
     * @param mainRail info if the player is on a railway used by aitrains
     * @pre prev and next are stations connected by a track
     * @post those trains that are on the same rail as the player are in the correct positions in the scene
     */
    void move(QString prev, QString next, int prevY, int nextY, bool mainRail);

signals:
    void message(QString msg);
private:
    std::weak_ptr<HttpEngine> getHttpEngine() const;
    void readTrainsFromAPI();

    // trainNumber, VrTrain-Object
    QHash<QString, std::shared_ptr<VrTrain>> aiTrains_;
    std::shared_ptr<HttpEngine> engine_;

    std::shared_ptr<QGraphicsScene> scene_;

    int timeSinceLastMsg;



};

#endif // VRTRAINMANAGER_H
