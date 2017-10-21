#include "playerlogic.h"

PlayerLogic::PlayerLogic(std::shared_ptr<QGraphicsScene> scene):
    scene_(scene)
{
    playableTrains_.push_back(std::make_shared<PlayerTrain>());

    activeTrain_ = playableTrains_.at(0);
    scene_->addItem(activeTrain_.get());
}

int PlayerLogic::location()
{
    return activeTrain_.get()->y();
}

std::shared_ptr<TrainInterface> PlayerLogic::activeTrain()
{
    return activeTrain_;
}