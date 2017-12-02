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
 * @brief Hallitsee VrTrain-olioita
 */
class VrTrainManager : public QObject
{
    Q_OBJECT
public:
    VrTrainManager(std::shared_ptr<QGraphicsScene> scene);
    void addAiTrain(QString id, std::shared_ptr<VrTrain> aiTrain);
    bool checkCollisions(QString prev, QString next, bool harmful);
    int checkPlayerCollision(std::shared_ptr<PlayerTrain> player);

    QHash<QString, std::shared_ptr<VrTrain>> getAllAiTrains() const;

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
