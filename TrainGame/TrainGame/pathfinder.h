#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <QList>
#include <QString>

class PathFinder
{
public:
    static PathFinder PATHFINDER;

    ~PathFinder() = default;

    bool nextStationCode(QString& result, QMap<QString, QList<QString>>& trackData, QList<QString>& destinations, QString prev, QString next);

private:


    PathFinder();

    PathFinder(PathFinder const&) = delete;
    PathFinder& operator=(PathFinder const&) = delete;


    int generateDistance(QString startPoint, QMap<QString, QList<QString>>& trackData, QString& prev, QString& next, int covered);

};

#endif // PATHFINDER_H
