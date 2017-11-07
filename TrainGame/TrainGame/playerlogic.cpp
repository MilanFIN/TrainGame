#include "playerlogic.h"
#include "shop.h"
#include "datareader.h"
#include <iostream>



PlayerLogic::PlayerLogic(std::shared_ptr<QGraphicsScene> scene):
    scene_(scene)
{
    shop_ = std::make_shared<Shop>();

    dataReader::READER.loadTrains(":/data/junat.json", shop_, *this);

    //playableTrains_.push_back(std::make_shared<PlayerTrain>());

    activeTrain_ = playableTrains_.at(0);
    scene_->addItem(activeTrain_.get());

    currentMoney_ = 500;
    emit playerCashChanged(getCurrentMoney());




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

void PlayerLogic::deleteTrain(int index)
{
    playableTrains_.erase(playableTrains_.begin() + index);
}

int PlayerLogic::getCurrentMoney()
{
    return currentMoney_;
}

void PlayerLogic::increaseMoney(int amount)
{
    currentMoney_ += amount;
    invariant();
    emit playerCashChanged(currentMoney_);
}

void PlayerLogic::decreaseMoney(int amount)
{
    currentMoney_ -= amount;
    invariant();
    emit playerCashChanged(currentMoney_);
}

void PlayerLogic::getOwnedTrainInfo(QString trainName)
{
    for (std::shared_ptr<PlayerTrain> train : playableTrains_) {
        if (trainName == train->getName()) {
            emit ownedTrainInfo(train);
        }
    }
}

void PlayerLogic::getTrainInfo(QString trainName)
{
    emit trainInfo(shop_->getTrainInfo(trainName));
}

void PlayerLogic::getAvailableTrainsFromShop()
{
    emit availableTrains(shop_->buyableTrains());
}

void PlayerLogic::getOwnedTrains()
{
    emit ownedTrains(playableTrains_);
}

bool PlayerLogic::buyTrain(QString trainName, int index)
{
    std::shared_ptr<PlayerTrain> newTrain = shop_->getTrainInfo(trainName);
    if (newTrain->getPrice() > short(currentMoney_)) {
        return false;
    }
    decreaseMoney(newTrain->getPrice());
    shop_->buyTrain(index);
    addNewTrain(newTrain);

    getAvailableTrainsFromShop();
    getOwnedTrains();


    return true;
}

bool PlayerLogic::sellTrain(QString trainName, int index)
{
    std::shared_ptr<PlayerTrain> train = playableTrains_.at(index);
    // jos juna rikki -> ei voi myydä tai jotain muuta
    deleteTrain(index);
    shop_->addTrain(train);
    increaseMoney(train->getPrice());

    // emit changes to window
    getAvailableTrainsFromShop();
    getOwnedTrains();

    return true;



}

void PlayerLogic::setActiveTrain(int rowIndex)
{
    try {
        activeTrain_ = playableTrains_.at(rowIndex);
        emit activeTrainChanged(activeTrain_->getName());
    }catch (...){
        throw std::runtime_error("Junan asettaminen aktiiviseksi epäonnistui.");
    }

}

void PlayerLogic::invariant()
{
    Q_ASSERT(currentMoney_ > 0);
}
