#ifndef PLAYERLOGIC_H
#define PLAYERLOGIC_H


#include <memory>
#include <QGraphicsScene>
#include <vector>
#include "playertrain.h"
#include "traininterface.h"

class PlayerLogic
{
public:
    PlayerLogic(std::shared_ptr<QGraphicsScene> scene);
    int location();
    std::shared_ptr<TrainInterface> activeTrain();
private:
    std::shared_ptr<QGraphicsScene> scene_;
    std::vector<std::shared_ptr<PlayerTrain>> playableTrains_;
    std::shared_ptr<PlayerTrain> activeTrain_;
};

#endif // PLAYERLOGIC_H
