#ifndef PLAYERLOGIC_H
#define PLAYERLOGIC_H


#include <memory>
#include <QGraphicsScene>
#include <vector>
#include "playertrain.h"
#include "traininterface.h"
#include "shop.h"

class PlayerLogic
{
public:
    PlayerLogic(std::shared_ptr<QGraphicsScene> scene);
    int location();
    std::shared_ptr<PlayerTrain> activeTrain();

    void addNewTrain(std::shared_ptr<PlayerTrain> newTrain);
private:
    std::shared_ptr<QGraphicsScene> scene_;
    std::vector<std::shared_ptr<PlayerTrain>> playableTrains_;
    std::shared_ptr<PlayerTrain> activeTrain_;

    // player owns the shop and manages it trough this pointer
    std::shared_ptr<Shop> shop_;
};

#endif // PLAYERLOGIC_H
