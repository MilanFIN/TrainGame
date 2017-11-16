#ifndef VRTRAINMANAGER_H
#define VRTRAINMANAGER_H

#include <QObject>
#include <QGraphicsScene>
#include <memory>

/**
 * @brief Hallitsee VrTrain-olioita
 */
class VrTrainManager
{
public:
    VrTrainManager(std::shared_ptr<QGraphicsScene> scene);
    void move();
};

#endif // VRTRAINMANAGER_H
