#include "vrtrainmanager.h"
#include "datareader.h"
#include <exception>
#include <iostream>

VrTrainManager::VrTrainManager(std::shared_ptr<QGraphicsScene> scene):
    scene_(scene)
{
    engine_ = std::make_shared<HttpEngine>();
    dataReader::dataReader::READER.readHTTPData(getHttpEngine(), *this);
}

void VrTrainManager::addAiTrain(QString id, std::shared_ptr<VrTrain> aiTrain)
{
    try {
       aiTrains_.insert(id, aiTrain);
    }catch (std::bad_alloc& ba) {
        // out of memory
        Q_ASSERT("bad_alloc caught");

    }

}

void VrTrainManager::move()
{

}

QHash<QString, std::shared_ptr<VrTrain> > VrTrainManager::getAllAiTrains() const
{
    return aiTrains_;
}

std::weak_ptr<HttpEngine> VrTrainManager::getHttpEngine() const
{
    std::weak_ptr<HttpEngine> engine = engine_;
    return engine;

}
