#include "pathfinder.h"


PathFinder PathFinder::PATHFINDER;

bool PathFinder::nextStationCode(QString &result, QMap<QString,
                                 QList<QString> > &trackData,
                                 QList<QString> &destinations,
                                 QString prev, QString next)
{
    QList<int> intResults;
    foreach(QString dest, destinations){
        intResults.append(generateDistance(dest, trackData, prev, next, 0, ""));
    }
    int minResult = 99;
    int resultIndex;
    for(int i = 0; i < intResults.size(); ++i){
        if (intResults.at(i) < minResult){
            resultIndex = i;
            minResult = intResults.at(i);
        }
    }
    if (minResult == 99){
        return false;
    }
    else{
        result = destinations.at(resultIndex);
        return true;
    }

}

int PathFinder::generateDistance(QString startPoint,
                                 QMap<QString, QList<QString> > &trackData,
                                 QString &prev, QString &next, int covered,
                                 QString previousStation)
{
    if (startPoint == prev || startPoint == next){
        return covered;
    }
    else if (covered >= 6){
        return 99;
    }
    else{
        QList<int> distances;
        foreach(QList<QString> i, trackData){
            for (QList<QString>::iterator j = i.begin(); j != i.end()-1;++j){
                if (*j == startPoint && *j != previousStation){
                    distances.append(generateDistance((*(j+1)),
                                                      trackData, prev,
                                                      next, covered +1, *j));
                }
            }
            for (QList<QString>::iterator j = i.begin()+1; j != i.end();++j){
                if (*j == startPoint && *j != previousStation){
                    distances.append(generateDistance((*(j-1)), trackData,
                                                      prev, next, covered +1, *j));
                }
            }
        }
        // find smallest found distance
        int result = 99;
        foreach (int distance, distances) {
            if (distance < result){
                result = distance;
            }
        }
        return result;
    }
}

PathFinder::PathFinder(){}

