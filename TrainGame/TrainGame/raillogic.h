#ifndef RAILLOGIC_H
#define RAILLOGIC_H

#include <QObject>
#include <QGraphicsScene>
#include <memory>
#include <vector>


#include "QList"
#include "QString"
#include "QMap"
#include "QHash"


#include "railtileinterface.h"
#include "onesiderailtile.h"
#include "station.h"
#include "traininterface.h"
#include "playertrain.h"




class RailLogic : public QObject
{
    Q_OBJECT
public:
    explicit RailLogic(std::shared_ptr<QGraphicsScene> scene);
    ~RailLogic();
    void move();
    void setSpeed(int newSpeed);
    void changeDirection();

    void addTrack(QString trackCode, QList<QString> stations);
    void addStations(QString shortCode, QString fullName, QString type,
                     double lat, double lng, bool passengerStation);

    void checkCollisionWithStations(std::shared_ptr<PlayerTrain> train);
    QList<QString> CombineStationTrackInfo(QList<QString> &stationCodes, QList<QString> &trackCodes);

signals:
    void destinationCandidatesChanged(QList<QString> stations);
    void backttrackCandidatesChanged(QList<QString> stations);


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

    std::shared_ptr<Station> nextStation_;
    std::shared_ptr<Station> previousStation_;

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
    QList<QString> destinationStationCandidates_; //stationcodes for possible destinations after the current one is reached
    QList<QString> destinationTrackCandidates_; //trackcodes that correspond to the above destinations
    QList<QString> backtrackStationCandidates_; //stationcodes for possible destinations after reversing to previous station
    QList<QString> backtrackTrackCandidates_; //trackcodes for the above

};

#endif // RAILLOGIC_H
