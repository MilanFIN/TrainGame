#ifndef VRTRAINMANAGER_H
#define VRTRAINMANAGER_H

#include <QObject>
#include <QGraphicsScene>
#include <QVector>
#include <memory>
#include "httpengine.h"
#include "vrtrain.h"

/**
 * @brief Hallitsee VrTrain-olioita
 */
class VrTrainManager
{
public:
    VrTrainManager(std::shared_ptr<QGraphicsScene> scene);
    void addAiTrain(QString id, std::shared_ptr<VrTrain> aiTrain);
    void move();
    bool checkCollisions(QString prev, QString next);

    QHash<QString, std::shared_ptr<VrTrain>> getAllAiTrains() const;
private:
    std::weak_ptr<HttpEngine> getHttpEngine() const;

    // trainNumber, VrTrain-Object
    QHash<QString, std::shared_ptr<VrTrain>> aiTrains_;
    std::shared_ptr<HttpEngine> engine_;

    std::shared_ptr<QGraphicsScene> scene_;



};

#endif // VRTRAINMANAGER_H
