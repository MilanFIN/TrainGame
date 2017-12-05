#ifndef OBSTACLEFACTORY_H
#define OBSTACLEFACTORY_H
#include <memory>
#include <obstacleinterface.h>


/**
 * @brief ObstacleFactory is used for creating random obstacles
 */
class ObstacleFactory: public std::enable_shared_from_this<ObstacleFactory>
{
public:

    ~ObstacleFactory();

    /**
     * @brief GetInstance
     * @return std::shared_ptr<ObstacleFactory> same instance all the time
     */
    static std::shared_ptr<ObstacleFactory> GetInstance();

    /**
     * @brief createObject creates new object
     * @return std::shared_ptr<ObstacleInterface> randomly chosen obstacle
     */
    std::shared_ptr<ObstacleInterface> createObject();

private:

    static std::shared_ptr<ObstacleFactory> _instance;
    ObstacleFactory();

};



#endif // OBSTACLEFACTORY_H
