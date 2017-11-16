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
    void move();
private:
    QVector<std::shared_ptr<VrTrain>> aiTrains_;
    std::shared_ptr<HttpEngine> engine_;


};

#endif // VRTRAINMANAGER_H
