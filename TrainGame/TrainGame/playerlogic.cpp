#include "playerlogic.h"
#include "shop.h"
#include "datareader.h"
#include <iostream>



PlayerLogic::PlayerLogic(std::shared_ptr<QGraphicsScene> scene):
    scene_(scene),
    fame_(100)
{
    shop_ = std::make_shared<Shop>();

    dataReader::READER.loadTrains(":/data/junat.json", shop_, *this);

    //playableTrains_.push_back(std::make_shared<PlayerTrain>());

    // Todo: kun peli aukeaa haetaan pelaajan aktiivinen juna
    //
//    activeTrain_ = playableTrains_.at(0);
//    scene_->addItem(activeTrain_.get());

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
    newTrain->setOwned();
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
    train->setOwned();

    // emit changes to window
    getAvailableTrainsFromShop();
    getOwnedTrains();

    return true;



}

void PlayerLogic::setActiveTrain(int rowIndex)
{
    // haetaan juna joka aktiiviseksi
    std::shared_ptr<PlayerTrain> trainActive = playableTrains_.at(rowIndex);
    removeTrainPixmap(activeTrain_);


    // asetetaan juna uusi aktiiviseksi
    activeTrain_ = trainActive;

    trainActive->setPixmapToShow();
    setTrainPixmap(activeTrain_);
    // pelaajajunaan ja asettaa kuvasta pixmap sceneen
    emit activeTrainChanged(activeTrain_->getName());


}

void PlayerLogic::removeTrainPixmap(std::shared_ptr<PlayerTrain> trainToRemove)
{
    scene_->removeItem(trainToRemove.get());
}

void PlayerLogic::setTrainPixmap(std::shared_ptr<PlayerTrain> traintoSet)
{
    scene_->addItem(activeTrain_.get());
}

void PlayerLogic::getTrainsToBeRepaired()
{
    std::vector<std::shared_ptr<PlayerTrain>> brokenTrains;
    for (std::shared_ptr<PlayerTrain> train : playableTrains_) {
        if (train->getShape() < train->getAbsoluteShape()) {
            brokenTrains.push_back(train);
        }
    }
    emit showBrokenTrains(brokenTrains);
}

void PlayerLogic::repairTrain(int rowIndex)
{
    std::vector<std::shared_ptr<PlayerTrain>> brokenTrains;
    for (std::shared_ptr<PlayerTrain> train : playableTrains_) {
        if (train->getShape() < train->getAbsoluteShape()) {
            brokenTrains.push_back(train);
        }
    }

    std::shared_ptr<PlayerTrain> brokeTrain = brokenTrains.at(rowIndex);


    if (brokeTrain->getRepairCost() > currentMoney_)
    {
        emit notEnoughMoney();
    }
    else
    {
        decreaseMoney(brokeTrain->getRepairCost());
        brokeTrain->repairTrain();
        emit trainRepaired();
    }


}

void PlayerLogic::invariant()
{
    Q_ASSERT(currentMoney_ > 0);
}
