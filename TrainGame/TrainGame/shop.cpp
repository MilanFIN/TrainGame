#include "shop.h"
#include "datareader.h"
#include <iostream>

Shop::Shop()
{
}

Shop::~Shop()
{
}

std::shared_ptr<PlayerTrain> Shop::buyTrain(int index)
{
    std::shared_ptr<PlayerTrain> buyed = availableTrains_.at(index);
    availableTrains_.erase(availableTrains_.begin() + index);

    return buyed;
}

void Shop::addTrain(std::shared_ptr<PlayerTrain> train)
{
    try {
        availableTrains_.push_back(train);
    } catch (std::bad_alloc& ba) {
        std::cerr << "Shop caugth std::bad_alloc: " << ba.what();
    }


}

std::shared_ptr<PlayerTrain> Shop::getTrainInfo(QString trainName) const
{
    foreach (std::shared_ptr<PlayerTrain> train, availableTrains_) {
        if (trainName == train->getName()) {
            return train;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<PlayerTrain> > Shop::buyableTrains() const
{
    return availableTrains_;
}
