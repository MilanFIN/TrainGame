#ifndef RAILLOGIC_H
#define RAILLOGIC_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QList>
#include <QString>
#include <QMap>
#include <QHash>

#include <memory>
#include <vector>

#include "railtileinterface.h"
#include "onesiderailtile.h"
#include "station.h"
#include "traininterface.h"
#include "playertrain.h"
#include "background.h"

/**
 * @brief The RailLogic class defines the object that handles most railway network related stuff
 */

class RailLogic : public QObject
{
    Q_OBJECT
public:
    explicit RailLogic(std::shared_ptr<QGraphicsScene> scene,
                       std::shared_ptr<QGraphicsScene> miniMapScene);
    ~RailLogic();
    /**
     * @brief move moves items handled by this class
     * @param multiplier multiplier for the speed
     * @post items moved
     */
    void move(double multiplier);
    /**
     * @brief setSpeed sets a new goalspeed
     * @param newSpeed the goalspeed
     * @post the goalspeed has changed
     */
    void setSpeed(int newSpeed);
    /**
     * @brief changeDirection changes the goal direction
     * @post the goal direction is different than previously
     */
    void changeDirection();
    /**
     * @brief addTrack adds a new track to the object
     * @param trackCode code of the track
     * @param stations all stations along the track
     */
    void addTrack(QString trackCode, QList<QString> stations);
    /**
     * @brief addStations adds a new station to the object
     * @param shortCode stationcode
     * @param fullName name of the station
     * @param type type of the station
     * @param lat latitude as in the geographic coordinate
     * @param lng longitude as in the geographic coordinate
     * @param passengerStation info if the station handles passenger traffic(not really relevant for this)
     */
    void addStations(QString shortCode, QString fullName, QString type,
                     double lat, double lng, bool passengerStation);

    /**
     * @brief checkCollisionWithStations checks if the train collides with stations
     * @param train player's active train
     * @post if collided, then the track has been updated
     */
    void checkCollisionWithStations(std::shared_ptr<PlayerTrain> train);
    /**
     * @brief CombineStationTrackInfo makes a neat format of the station information
     * @param stationCodes list of stations
     * @param trackCodes list of tracks
     * @return list of the neatly combined infos made from the parameters
     */
    QList<QString> CombineStationTrackInfo(QList<QString> &stationCodes, QList<QString> &trackCodes);

    /**
     * @brief changeDestinationCandidateIndex changes the next destination
     * @param index index of the destination station
     * @pre the index must be in range of the possible choises
     * @post the new destination has been set
     */
    void changeDestinationCandidateIndex(int index);
    /**
     * @brief changeBackTrackCandidateIndex sets the new destination if we reversed back to the previous station
     * @param index index of the destination
     * @pre destination index is in the possible choises of destinations
     * @post the backtracking destination has been changed
     */
    void changeBackTrackCandidateIndex(int index);
    /**
     * @brief signalStationInfoToUi signals previous and next station's info to the ui
     * @pre the necessary slots to handle the upcoming signals have been defined and connected
     */
    void signalStationInfoToUi();
    /**
     * @brief updateDestinationOnMiniMap updates the last station to the minimap
     * @post red dot on the minimap has changed it's location
     */
    void updateDestinationOnMiniMap();
    /**
     * @brief updateObstacleOnMiniMap updates the obstacle's location on the minimap
     * @param prev prevous station to the obstacle (stationcode)
     * @param next next station from the obstacle (stationcode)
     * @post the green dot has been placed in between prev and next
     */
    void updateObstacleOnMiniMap(QString prev, QString next);
    /**
     * @brief getRandomStationAndTrack gets a random station pair at a maximum distance
     * @param distance max distance in amount of stations
     * @param Stations list of 2 elements, the two stations that were chosen
     * @param trackCode the trackcode of the chosen track
     * @param stationNames list of 2, names of the stations chosen
     * @param harmful boolean value if the location is in danger of collision from aitrains
     */
    void getRandomStationAndTrack(int distance, QList<QString>& Stations, QString& trackCode, QList<QString>& stationNames, bool &harmful);

    /**
     * @brief getCurrentTrack returns current track
     * @return current track's trackcode
     */
    QString getCurrentTrack();
    /**
     * @brief getLastStation gets the previous station
     * @return previous station's stationcode
     */
    QString getLastStation();
    /**
     * @brief getNextStation gets the next station
     * @return next stations stationcode
     */
    QString getNextStation();

    /**
     * @brief getCurrentLocation sets the current location into the parameters
     * @param prev previous stationcode
     * @param next next stationcode
     * @param prevY previous station's location in y axis
     * @param nextY next stations location in y axis
     * @param mainRail info if the train is in a track that has aitrain traffic
     */
    void getCurrentLocation(QString &prev, QString &next, int &prevY, int &nextY, bool &mainRail);
    /**
     * @brief getNextDistance gets the distance of the next station in y axis based on coordinate data
     * @return int y distance
     */
    int getNextDistance();
    /**
     * @brief updateNavi updates ui with the best route towards the obstacle
     * @param next 1st station near the obstacle (stationcode)
     * @param prev 2nd station near the obstacle (stationcode)
     */
    void updateNavi(QString next, QString prev);
signals:
    void destinationCandidatesChanged(QList<QString> stations);
    void backttrackCandidatesChanged(QList<QString> stations);
    void signalDestAndPrevious(QString previous, QString next);
    void naviInfoUpdate(QString info);


private:

    //movement related
    float speed_ = 0;
    float goalSpeed_;
    bool forward_ = true;
    float previousSpeed_;
    int movementSinceLastRailSpawn_;
    float accel_ = 0.1;


    //other
    std::shared_ptr<QGraphicsScene> scene_;
    std::shared_ptr<QGraphicsScene> miniMapScene_;
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

    double lngCenter_ = 27.21985;
    double xConversionRate_ = 22.0;//max 22.86;

    double latCenter_ = 63.4086;
    double yConversionRate_ = -50.0;//max 51.99;

    double distanceConversionRate_ = 20000.0;


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

    int destinationIndex_;
    int backtrackIndex_;

    //point in the minimap for next station
    QGraphicsPixmapItem currentLocationMapPoint;
    //point in the minimap for the obstacle
    QGraphicsPixmapItem obstacleMapPoint_;
    bool locMapPoint_ = false;
    bool obsMapPoint_ = false;

};

#endif // RAILLOGIC_H
