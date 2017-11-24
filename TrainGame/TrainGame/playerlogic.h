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
    PlayerLogic();
    /**
     * @brief PlayerLogic pelaajan rakentaja
     * @param scene
     */
    PlayerLogic(std::shared_ptr<QGraphicsScene> scene);

    /**
     * @brief location palauttaa pelaajan pelaaman junan y sijainnin.
     * @return int sijainti
     */
    int location();

    /**
     * @brief activeTrain palauttaa aktiivisen junan
     * @return jaettuosoitin aktiiviseen junaan
     */
    std::shared_ptr<PlayerTrain> activeTrain();

    /**
     * @brief addNewTrain
     * @param newTrain
     */
    void addNewTrain(std::shared_ptr<PlayerTrain> newTrain);

    /**
     * @brief deleteTrain poistaa junan pelaajalta
     * @param index jossa juna on pelaajalla.
     */
    void deleteTrain(int index);

    /**
     * @brief getCurrentMoney palauttaa tämänhetkisen rahamäärän
     * @return pelaajan rahamäärän
     */
    int getCurrentMoney();


    /**
     * @brief addFame lisää pelaajan karmaa asukkaisuun
     * @param amount famen määrä
     */
    void addFame(int amount);

    /**
     * @brief getOwnedTrainInfo palauttaa omistetun junan speksit
     * @param trainName junannimi josta tiedot halutaan
     */
    void getOwnedTrainInfo(QString trainName);

    /**
     * @brief getTrainInfo kysyy kaupasta junan tiedot.
     * @param trainName halutun junan nimi
     */
    void getTrainInfo(QString trainName);

    /**
     * @brief getInfoToGarage antaa omistetun/rikkinäisen junan tietoja varikolle.
     * @param trainName
     */
    void getInfoToGarage(QString trainName);

    /**
     * @brief getAvailableTrainsFromShop kysyy kaupasta ostettavat junat
     */
    void getAvailableTrainsFromShop();

    /**
     * @brief getOwnedTrains palauttaa pelaajan junat vectorissa signaalin avulla.
     */
    void getOwnedTrains();

    /**
     * @brief buyTrain ostaa junan pelaajalle
     * @param trainName ostettavan junan nimi
     * @param index, jossa juna on kaupassa
     */
    void buyTrain(QString trainName, int index);

    /**
     * @brief sellTrain myy junan kauppaan
     * @param index, jossa juna on pelaajalla
     */
    void sellTrain(int index);

    /**
     * @brief setActiveTrain asettaa pelaajalle aktiivisen junan
     * @param rowIndex, jossa juna on pelaajalla.
     */
    void setActiveTrain(int rowIndex);

    /**
     * @brief removeTrainPixmap poistaa vanhan aktiivisen junan raiteilta
     * @param trainToRemove heikko-osoitin junaan
     */
    void removeTrainPixmap(std::weak_ptr<PlayerTrain> trainToRemove);

    /**
     * @brief setTrainPixmap asettaa aktiiviseksi asetetun junan raiteille.
     */
    void setTrainPixmap();

    /**
     * @brief getTrainsToBeRepaired
     */
    void getTrainsToBeRepaired();

    /**
     * @brief repairTrain
     * @param rowIndex
     */
    void repairTrain(int rowIndex);

    /**
     * @brief takeDamage aktiivinen juna ottaa damagea
     * @param int dmg damagen määrä
     */
    void takeDamage(int dmg);

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
