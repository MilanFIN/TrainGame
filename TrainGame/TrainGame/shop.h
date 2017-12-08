#ifndef SHOP_H
#define SHOP_H
#include <vector>
#include <memory>
#include "playertrain.h"

/**
 * @brief Shop class consists of buyable trains
 */

class Shop
{
public:
    Shop();
    ~Shop();
    /**
     * @brief buyTrain buys a train from the shop
     * @param index of the train in the shop
     * @pre player has money for the train and the index is in range of buyable trains
     * @post the train that was bought has been removed from the shop
     * @return shared_ptr to the bought train
     */
    std::shared_ptr<PlayerTrain> buyTrain(int index);

    /**
     * @brief addTrain adds a train to the buyable trains.
     * @pre the train to be added does not exist in buyable trains already.
     * @param train the train to be added to the shop
     */
    void addTrain(std::shared_ptr<PlayerTrain> train);

    /**
     * @brief getTrainInfo returns a smart pointer to a train.
     * @param trainName name of the train that the info is wanted on.
     * @pre the train exists in the shop
     * @return std::shared_ptr<PlayerTrain> train the requested train
     */
    std::shared_ptr<PlayerTrain> getTrainInfo(QString trainName) const;

    /**
     * @brief buyableTrains returns a vector of buyable trains
     * @return std::vector<std::shared_ptr<PlayerTrain>> trains
     */
    std::vector<std::shared_ptr<PlayerTrain>> buyableTrains() const;

private:

    std::vector<std::shared_ptr<PlayerTrain>> availableTrains_;
};

#endif // SHOP_H
