#include "pathfinder.h"
#include <iostream>


PathFinder PathFinder::PATHFINDER;

bool PathFinder::nextStationCode(QString &result, QMap<QString, QList<QString> > &trackData, QList<QString> &destinations, QString prev, QString next)
{
    QList<int> intResults;
    foreach(QString dest, destinations){
        intResults.append(generateDistance(dest, trackData, prev, next, 0));
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
        return false; //ei löytynyt lainkaan reittiä
    }
    else{
        result = destinations.at(resultIndex);
        return true;
    }

}

int PathFinder::generateDistance(QString startPoint, QMap<QString, QList<QString> > &trackData, QString &prev, QString &next, int covered)
{
    if (startPoint == prev || startPoint == next){
        return covered;
    }
    else if (covered >= 5){
        return 99; //ei löytynyt tältä reitiltä
    }
    else{
        QList<int> distances;
        foreach(QList<QString> i, trackData){
            for (QList<QString>::iterator j = i.begin(); j != i.end()-1;++j){
                if (*j == startPoint){
                    //löytyi asemalta lähtevä raide
                    distances.append(generateDistance((*(j+1)), trackData, prev, next, covered +1));


                }
            }
            for (QList<QString>::iterator j = i.begin()+1; j != i.end();++j){
                if (*j == startPoint){
                    //löytyi asemalta lähtevä raide toiseen suuntaan
                    distances.append(generateDistance((*(j-1)), trackData, prev, next, covered +1));
                }
            }
        }
        //etsitään pienin löytynyt etäisyys
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

