#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <QList>
#include <QMap>
#include <QString>

/**
 * @brief The PathFinder defines a singleton
 * for getting a route between two locations
 */
class PathFinder
{
public:
    static PathFinder PATHFINDER;

    ~PathFinder() = default;
    /**
     * @brief nextStationCode returns if a route has been found
     * and the route in parameters if so
     * @param result the next station to be chosen to follow the route
     * @param trackData trackdata to be used on the pathfinding
     * @param destinations possible directions of which one has to be picked
     * @param prev 1st station near the goal location
     * @param next 2nd station near the goal location
     * @pre trackdata includes useful data
     * @return info, if a route was found
     */
    bool nextStationCode(QString& result, QMap<QString,
                         QList<QString>>& trackData, QList<QString>& destinations,
                         QString prev, QString next);

private:
    PathFinder();

    PathFinder(PathFinder const&) = delete;
    PathFinder& operator=(PathFinder const&) = delete;

    int generateDistance(QString startPoint, QMap<QString, QList<QString>>&
                         trackData, QString& prev, QString& next, int covered);
};

#endif // PATHFINDER_H
