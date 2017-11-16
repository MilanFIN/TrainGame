#include "vrtrainmanager.h"

VrTrainManager::VrTrainManager(std::shared_ptr<QGraphicsScene> scene)
{
    engine_ = std::make_shared<HttpEngine>();
}

void VrTrainManager::move()
{

}
