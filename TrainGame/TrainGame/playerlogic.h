#ifndef PLAYERLOGIC_H
#define PLAYERLOGIC_H


#include <memory>
#include <QGraphicsScene>
#include <vector>
#include <QObject>

#include "playertrain.h"
#include "traininterface.h"
#include "shop.h"

class PlayerLogic: public QObject
{
    Q_OBJECT
public:
    PlayerLogic(std::shared_ptr<QGraphicsScene> scene);
    int location();
    std::shared_ptr<PlayerTrain> activeTrain();

    void addNewTrain(std::shared_ptr<PlayerTrain> newTrain);
    void deleteTrain(int index);

    /**
     * @brief getCurrentMoney
     * @return pelaajan rahamäärän
     */
    int getCurrentMoney();

    /**
     * @brief increaseMoney
     * @param amount joka lisätään pelaajan rahamäärään.
     */
    void increaseMoney(int amount);

    /**
     * @brief decreaseMoney
     * @pre Pelaajalla on enemmän rahaa kuin mitä juna maksaa. pelaajan raha ei voi mennä alle 0
     * @param amount määrä, jonka ostettava juna maskaa.
     */
    void decreaseMoney(int amount);

    void addFame(int amount);
    void getOwnedTrainInfo(QString trainName);
    void getTrainInfo(QString trainName);
    void getInfoToGarage(QString trainName);

    void getAvailableTrainsFromShop();
    void getOwnedTrains();

    bool buyTrain(QString trainName, int index);
    bool sellTrain(QString trainName, int index);

    void setActiveTrain(int rowIndex);

    void removeTrainPixmap(std::shared_ptr<PlayerTrain> trainToRemove);
    void setTrainPixmap();

    void getTrainsToBeRepaired();
    void repairTrain(int rowIndex);

    void takeDamage(int dmg);

signals:
    int playerCashChanged(int amount);
    void playerFameChanged(int amount);
    void ownedTrainInfo(std::shared_ptr<PlayerTrain> train);
    void trainInfo(std::shared_ptr<PlayerTrain> train);
    void ownedTrains(std::vector<std::shared_ptr<PlayerTrain>> ownedTrains);
    void availableTrains(std::vector<std::shared_ptr<PlayerTrain>> buyableTrains);
    void activeTrainChanged(QString trainName);
    void showBrokenTrains(std::vector<std::shared_ptr<PlayerTrain>> brTrains);
    void notEnoughMoney();
    void trainRepaired();
    void brokenTrain(std::shared_ptr<PlayerTrain> brokenTrain);

private:
    std::shared_ptr<QGraphicsScene> scene_;
    std::vector<std::shared_ptr<PlayerTrain>> playableTrains_;
    std::shared_ptr<PlayerTrain> activeTrain_;

    // player owns the shop and manages it trough this pointer
    std::shared_ptr<Shop> shop_;

    int currentMoney_;
    int fame_;


    void invariant();
};

#endif // PLAYERLOGIC_H
