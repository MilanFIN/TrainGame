#ifndef PLAYERLOGIC_H
#define PLAYERLOGIC_H

#include <memory>
#include <QGraphicsScene>
#include <vector>
#include <QObject>

#include "playertrain.h"
#include "traininterface.h"
#include "shop.h"

/**
 * @brief The PlayerLogic class defines player related logic
 */
class PlayerLogic: public QObject
{
    Q_OBJECT
public:
    PlayerLogic();

    /**
     * @brief PlayerLogic constructor
     * @param scene is the qgraphcisscene the logic interacts with
     */
    PlayerLogic(std::shared_ptr<QGraphicsScene> scene);

    /**
     * @brief location returns player's location.
     * @return int location in y axis
     */
    int location();

    /**
     * @brief activeTrain returns a smart pointer to the active train
     * @return shared_ptr to the active train
     */
    std::shared_ptr<PlayerTrain> activeTrain();

    /**
     * @brief addNewTrain adds a new train to the player's use
     * @param newTrain pointer to the new train
     * @post the train has been added
     */
    void addNewTrain(std::shared_ptr<PlayerTrain> newTrain);

    /**
     * @brief deleteTrain removes a train from the player
     * @pre index is in range of the possible choises of trains
     * @param index that the train is on
     * @post the train has been removed
     */
    void deleteTrain(int index);

    /**
     * @brief getCurrentMoney returns the amount of money the player has
     * @return the player's money amount in int
     */
    int getCurrentMoney();

    /**
     * @brief addFame adds karma that the player has
     * @param amount amount of karma/fame to be added
     * @post amount of fame has been changed
     */
    void addFame(int amount);

    /**
     * @brief getFame returns fame
     * @return fame_
     */
    int getFame() const;

    /**
     * @brief getOwnedTrainInfo returns info on an owned train
     * @param trainName train that the info is wanted on
     */
    void getOwnedTrainInfo(QString trainName);

    /**
     * @brief getTrainInfo asks the shop for the train's specs.
     * @param trainName name of the train to be asked on
     */
    void getTrainInfo(QString trainName);

    /**
     * @brief getInfoToGarage gives info on a train to the depot.
     * @param trainName name of the train
     */
    void getInfoToGarage(QString trainName);

    /**
     * @brief getAvailableTrainsFromShop asks shop for buyable trains
     * @pre ui has been initialized
     * @post ui has been notified on buyable trains
     */
    void getAvailableTrainsFromShop();

    /**
     * @brief getOwnedTrains returns owned trains via a signal.
     * @pre signal-slot pair has been connected
     * @post signal sent
     */
    void getOwnedTrains();

    /**
     * @brief buyTrain buys a train to the player
     * @param trainName name of the train to be bought
     * @param index that the train has in the shop
     * @pre index and trainName exist
     * @post a new train has been moved to the player's inventory
     */
    void buyTrain(QString trainName, int index);

    /**
     * @brief sellTrain sells a train to the shop
     * @param index, index of the train on the player
     * @pre index is in range of trains that can be sold
     * @post the train chosen has been sold
     */
    void sellTrain(int index);

    /**
     * @brief setActiveTrain sets the active train for the player
     * @param rowIndex that the train has on player's inventory
     * @pre rowIndex is in range of owned trains
     * @post previous train removed from the scene, new one added
     */
    void setActiveTrain(int rowIndex);

    /**
     * @brief removeTrainPixmap removes the old train from the scene
     * @param trainToRemove weak pointer to the train
     * @post the train has been removed from scene
     */
    void removeTrainPixmap(std::weak_ptr<PlayerTrain> trainToRemove);

    /**
     * @brief setTrainPixmap adds the active train to the scene.
     * @post train updated to the scene
     */
    void setTrainPixmap();

    /**
     * @brief getTrainsToBeRepaired returns all
     *  trains in need of repair as a signal
     * @pre a slot for the signal has been connected
     * @post repairable trains signaled
     */
    void getTrainsToBeRepaired();

    /**
     * @brief repairTrain repairs a specific train
     * @param rowIndex index of the train in the player's inventory
     * @pre index is in range of possible choises in player's inventory
     * @post the chosen train has been repaired to full shape
     */
    void repairTrain(int rowIndex);

    /**
     * @brief takeDamage causes the active train to recieve damage
     * @param int dmg amount of damage
     * @pre an active train has been set
     * @post damage taken
     */
    void takeDamage(int dmg);
    /**
     * @brief increaseMoney increases the money plaeyr has
     * @param amount amount of addition (+ or - allowed)
     */
    void increaseMoney(int amount);

signals:
    int playerCashChanged(int amount);
    void playerFameChanged(int amount);
    void ownedTrainInfo(std::shared_ptr<PlayerTrain> train);
    void trainInfo(std::shared_ptr<PlayerTrain> train);
    void ownedTrains(std::vector<std::shared_ptr<PlayerTrain>> ownedTrains);
    void availableTrains(std::vector<std::shared_ptr<PlayerTrain>> buyableTrains);
    void activeTrainChanged(QString trainName);
    void showBrokenTrains(std::vector<std::shared_ptr<PlayerTrain>> brTrains);
    void trainRepaired();
    void brokenTrain(std::shared_ptr<PlayerTrain> brokenTrain);
    void notEnoughMoney(QString msg);
    void shopActionFailed(QString msg);
    void notAbleToPlay();

private:
    std::shared_ptr<QGraphicsScene> scene_;
    std::vector<std::shared_ptr<PlayerTrain>> playableTrains_;
    std::shared_ptr<PlayerTrain> activeTrain_;

    // player owns the shop and manages it trough this pointer
    std::shared_ptr<Shop> shop_;

    int currentMoney_;
    int fame_;
    void decreaseMoney(int amount);
    void playerToShopTransaction(int index, std::shared_ptr<PlayerTrain> train);
    void shopToPlayerTransaction(int index);
    void updateUI();
    void invariant();
};

#endif // PLAYERLOGIC_H
