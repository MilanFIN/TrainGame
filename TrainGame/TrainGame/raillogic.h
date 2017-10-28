#ifndef RAILLOGIC_H
#define RAILLOGIC_H

#include <QObject>
#include <QGraphicsScene>
#include <memory>
#include <vector>
#include "railtileinterface.h"
#include "onesiderailtile.h"



#include "QList"
#include "QString"
#include "QMap"
#include "QHash"


class RailLogic
{

public:
    RailLogic(std::shared_ptr<QGraphicsScene> scene);
    void move();
    void setSpeed(int newSpeed);
    void changeDirection();

    void addTrack(QString trackCode, QList<QString> stations);
    void addStations(QString shortCode, QString fullName, QString type,
                     double lat, double lng, bool passengerStation);

private:
    //movement related
    float speed_ = 0;
    float goalSpeed_;
    bool forward_ = true;
    float previousSpeed_;
    int movementSinceLastSpawn;
    float accel_ = 0.1;


    //other
    std::shared_ptr<QGraphicsScene> scene_;
    std::vector<std::shared_ptr<RailTileInterface>> railTiles;


    // station info
    struct StationInfo {
        QString fullName;
        QString type;
        double lat;
        double lng;
        bool passengerTrafic = false;
    };


    // key : shortcode , value: particular station
    QHash<QString, StationInfo> stations_;

    // key: trackcode , value: Qlist of tracks(shortcodes) under current trackcode
    QMap<QString, QList<QString>> tracks_;

    //variables to store location in the railway system during gameplay
    QString startStationCode_; //previous station
    QString destinationStationCode_; //next station on the track
    QString currentTrackCode_; //current track
    QList<QString> destinationCandidates_; //stationcodes for possible destinations after the current one is reached
    QList<QString> backtrackCandidates; //stationcodes for possible destinations after

};

#endif // RAILLOGIC_H
