#include "playerlogic.h"

PlayerLogic::PlayerLogic(std::shared_ptr<QGraphicsScene> scene):
    scene_(scene)
{
    playableTrains.push_back(std::make_shared<PlayerTrain>());

    activeTrain = playableTrains.at(0);
    scene_->addItem(activeTrain.get());
}
