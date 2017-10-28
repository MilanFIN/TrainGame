#include "shop.h"
#include "datareader.h"

Shop::Shop()
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
    availableTrains_.push_back(train);
}

std::vector<std::shared_ptr<PlayerTrain> > Shop::buyableTrains() const
{
    return availableTrains_;
}
