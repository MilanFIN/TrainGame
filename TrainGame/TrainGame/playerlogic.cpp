#include "playerlogic.h"
#include "shop.h"
#include "datareader.h"

PlayerLogic::PlayerLogic(std::shared_ptr<QGraphicsScene> scene):
    scene_(scene)
{
    shop_ = std::make_shared<Shop>();

    dataReader::READER.loadTrains(":/data/junat.json", shop_, *this);

    //playableTrains_.push_back(std::make_shared<PlayerTrain>());

    activeTrain_ = playableTrains_.at(0);
    scene_->addItem(activeTrain_.get());




}

int PlayerLogic::location()
{
    return activeTrain_.get()->y();
}

std::shared_ptr<PlayerTrain> PlayerLogic::activeTrain()
{
    return activeTrain_;
}

void PlayerLogic::addNewTrain(std::shared_ptr<PlayerTrain> newTrain)
{
    playableTrains_.push_back(newTrain);
}
