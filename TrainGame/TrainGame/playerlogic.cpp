#include "playerlogic.h"
#include "shop.h"
#include "datareader.h"

PlayerLogic::PlayerLogic():
    currentMoney_(300),
    fame_(0)
{
}

PlayerLogic::PlayerLogic(std::shared_ptr<QGraphicsScene> scene):
    scene_(scene),
    currentMoney_(300),
    fame_(0)
{
    shop_ = std::make_shared<Shop>();

    //read trains from JSON
    dataReader::READER.loadTrains(":/data/junat.json", shop_, *this);

    emit playerCashChanged(getCurrentMoney());
    emit playerFameChanged(fame_);
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

void PlayerLogic::addFame(int amount)
{
    fame_ += amount;
    emit playerFameChanged(fame_);
}

int PlayerLogic::getFame() const
{
    return fame_;
}

void PlayerLogic::getOwnedTrainInfo(QString trainName)
{
    foreach (std::shared_ptr<PlayerTrain> train, playableTrains_) {
        if (trainName == train->getName()) {
            emit ownedTrainInfo(train);
        }
    }
}

void PlayerLogic::getTrainInfo(QString trainName)
{
    emit trainInfo(shop_->getTrainInfo(trainName));
}

void PlayerLogic::getInfoToGarage(QString trainName)
{
    foreach (std::shared_ptr<PlayerTrain> train, playableTrains_) {
        if (trainName == train->getName()) {
            emit brokenTrain(train);
        }
    }
}

void PlayerLogic::getAvailableTrainsFromShop()
{
    emit availableTrains(shop_->buyableTrains());
}

void PlayerLogic::getOwnedTrains()
{
    emit ownedTrains(playableTrains_);
}

void PlayerLogic::buyTrain(QString trainName, int index)
{

    std::weak_ptr<PlayerTrain> newTrain = shop_->getTrainInfo(trainName);
    if (newTrain.lock() == NULL) {
        QString msg = QString("BuyTrain kutsuttiin virheellisesti!");
        emit shopActionFailed(msg);
        return;
    }

    if (newTrain.lock()->getPrice() > short(currentMoney_)) {
        QString msg = QString("Pelaajalla liian vähän rahaa ostaa juna.");
        emit shopActionFailed(msg);
        return;
    }

    shopToPlayerTransaction(index);

    updateUI();
}

void PlayerLogic::sellTrain(int index)
{
    std::weak_ptr<PlayerTrain> train = playableTrains_.at(index);
    if (train.lock()->getShape() < train.lock()->getAbsoluteShape()) {
        QString msg = QString("Juna on rikki, korjaa se ensin ennen myyntiä");
        emit shopActionFailed(msg);
        return;
    }
    playerToShopTransaction(index, train.lock());

    updateUI();
}

void PlayerLogic::setActiveTrain(int rowIndex)
{
    // finds train that will be set active
    std::weak_ptr<PlayerTrain> trainActive = playableTrains_.at(rowIndex);
    removeTrainPixmap(activeTrain_);

    // set train active and new pixmap
    activeTrain_ = trainActive.lock();
    trainActive.lock()->setPixmapToShow();
    setTrainPixmap();

    emit activeTrainChanged(activeTrain_->getName());
}

void PlayerLogic::removeTrainPixmap(std::weak_ptr<PlayerTrain> trainToRemove)
{
    if (trainToRemove.lock().get() != NULL) {
        scene_->removeItem(trainToRemove.lock().get());
    }
}

void PlayerLogic::setTrainPixmap()
{
    scene_->addItem(activeTrain_.get());
}

void PlayerLogic::getTrainsToBeRepaired()
{
    std::vector<std::shared_ptr<PlayerTrain>> brokenTrains;
    foreach (std::shared_ptr<PlayerTrain> train, playableTrains_) {
        if (train->getShape() < train->getAbsoluteShape()) {
            brokenTrains.push_back(train);
        }
    }
    emit showBrokenTrains(brokenTrains);
}

void PlayerLogic::repairTrain(int rowIndex)
{
    std::vector<std::shared_ptr<PlayerTrain>> brokenTrains;
    foreach (std::shared_ptr<PlayerTrain> train, playableTrains_) {
        if (train->getShape() < train->getAbsoluteShape()) {
            brokenTrains.push_back(train);
        }
    }

    std::weak_ptr<PlayerTrain> brokeTrain = brokenTrains.at(rowIndex);


    if (brokeTrain.lock()->getRepairCost() > currentMoney_)
    {
        QString msg = QString("Pelaajalla liian vähän rahaa korjata juna.");
        emit notEnoughMoney(msg);
    }
    else
    {
        decreaseMoney(brokeTrain.lock()->getRepairCost());
        brokeTrain.lock()->repairTrain();
        emit trainRepaired();
    }
}

void PlayerLogic::takeDamage(int dmg)
{
    activeTrain().get()->takeDamage(dmg);
}

void PlayerLogic::playerToShopTransaction(int index,
                                          std::shared_ptr<PlayerTrain> train)
{
    deleteTrain(index);

    // if player sells activeTrain, check if p has any
    // trains to set active if not notify mainW and disable pelaa button
    if (train == activeTrain()) {
        if (playableTrains_.size() != 0) {
            setActiveTrain(0);
        } else {
            removeTrainPixmap(activeTrain_);
            activeTrain_ = nullptr;
            emit notAbleToPlay();
        }
    }
    shop_->addTrain(train);
    increaseMoney(train->getPrice());
    train->setOwned();
}

void PlayerLogic::shopToPlayerTransaction(int index)
{
    std::shared_ptr<PlayerTrain> buyedTrain = shop_->buyTrain(index);
    decreaseMoney(buyedTrain->getPrice());
    buyedTrain->setOwned();
    addNewTrain(buyedTrain);
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

void PlayerLogic::updateUI()
{
    emit ownedTrains(playableTrains_);
    emit availableTrains(shop_->buyableTrains());
}

void PlayerLogic::invariant()
{
    Q_ASSERT(currentMoney_ >= 0);
}
