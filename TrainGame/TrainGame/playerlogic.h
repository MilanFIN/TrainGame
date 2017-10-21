#ifndef PLAYERLOGIC_H
#define PLAYERLOGIC_H


#include <memory>
#include <QGraphicsScene>
#include <vector>
#include "playertrain.h"

class PlayerLogic
{
public:
    PlayerLogic(std::shared_ptr<QGraphicsScene> scene);
private:
    std::shared_ptr<QGraphicsScene> scene_;
    std::vector<std::shared_ptr<PlayerTrain>> playableTrains;
    std::shared_ptr<PlayerTrain> activeTrain;
};

#endif // PLAYERLOGIC_H
