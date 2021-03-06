#include "obstaclefactory.h"
#include "boulder.h"
#include "leafpile.h"
#include <memory>
#include <QDateTime>

std::shared_ptr<ObstacleFactory> ObstacleFactory::_instance = nullptr;

ObstacleFactory::ObstacleFactory()
{
    // seed setup
    qsrand(QDateTime::currentDateTime().toTime_t());
}

ObstacleFactory::~ObstacleFactory(){}

std::shared_ptr<ObstacleFactory> ObstacleFactory::GetInstance()
{
    if (_instance == 0) {
        _instance = std::shared_ptr<ObstacleFactory>();
    }
    return _instance;
}

std::shared_ptr<ObstacleInterface> ObstacleFactory::createObject()
{

    if (qrand() % 2 == 0) {
        std::shared_ptr<Boulder> a = std::make_shared<Boulder>(0);
        return a;
    } else {
        std::shared_ptr<LeafPile> a = std::make_shared<LeafPile>(0);
        return a;
    }
}
