#ifndef SHOP_H
#define SHOP_H
#include <vector>
#include <memory>
#include "playertrain.h"



class Shop
{
public:
    Shop();

    /**
     * @brief buyTrain
     * @param index jolla löytää junan vectorista
     * @pre pelaajalla riittävästi rahaa ostaa juna
     * @return shared_ptr ostettu juna
     */
    std::shared_ptr<PlayerTrain> buyTrain(int index);

    /**
     * @brief addTrain lisää junan ostettavien junien listaan.
     * @pre juna jota yritetään lisätä ei ole jo listassa.
     * @param train, joka halutaan lisätä listaan
     */
    void addTrain(std::shared_ptr<PlayerTrain> train);

    std::shared_ptr<PlayerTrain> getTrainInfo(QString trainName) const;

    /**
     * @brief buyableTrains palauttaa vectorin, joka sisältää ostettavat junat
     * @return vector
     */
    std::vector<std::shared_ptr<PlayerTrain>> buyableTrains() const;


private:

    std::vector<std::shared_ptr<PlayerTrain>> availableTrains_;
};

#endif // SHOP_H
