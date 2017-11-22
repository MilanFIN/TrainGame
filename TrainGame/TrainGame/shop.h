#ifndef SHOP_H
#define SHOP_H
#include <vector>
#include <memory>
#include "playertrain.h"

/**
 * @brief Shop class koostuu junista, jota pelaaja voi ostaa
 */

class Shop
{
public:
    Shop();
    ~Shop();
    /**
     * @brief buyTrain metodi ostaa junan kaupasta
     * @param index jolla löytää junan vectorista
     * @pre pelaajalla riittävästi rahaa ostaa juna
     * @post ostettu juna on poistunut kaupasta
     * @return shared_ptr ostettu juna
     */
    std::shared_ptr<PlayerTrain> buyTrain(int index);

    /**
     * @brief addTrain lisää junan ostettavien junien listaan.
     * @pre juna jota yritetään lisätä ei ole jo listassa.
     * @param train, joka halutaan lisätä listaan
     */
    void addTrain(std::shared_ptr<PlayerTrain> train);

    /**
     * @brief getTrainInfo palauttaa jaetun osoittimen junaan, josta halutaan tietoja.
     * @param trainName, junan nimi jonka tiedot halutaan.
     * @return std::shared_ptr<PlayerTrain> train
     */
    std::shared_ptr<PlayerTrain> getTrainInfo(QString trainName) const;

    /**
     * @brief buyableTrains palauttaa vectorin, joka sisältää ostettavat junat
     * @return std::vector<std::shared_ptr<PlayerTrain>> trains
     */
    std::vector<std::shared_ptr<PlayerTrain>> buyableTrains() const;


private:

    std::vector<std::shared_ptr<PlayerTrain>> availableTrains_;
};

#endif // SHOP_H
