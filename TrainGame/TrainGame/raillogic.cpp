#include "raillogic.h"
#include "datareader.h"
#include "pathfinder.h"
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QDateTime>
#include <math.h>


RailLogic::RailLogic(std::shared_ptr<QGraphicsScene> scene,
                     std::shared_ptr<QGraphicsScene> miniMapScene):
    scene_(scene),
    miniMapScene_(miniMapScene)
{
    // seed setup
    qsrand(QDateTime::currentDateTime().toTime_t());

    for (int i = -275; i < 280; i +=30){
        railTiles.push_back(std::make_shared<OneSideRailTile>(0,i));

        scene_->addItem(railTiles.back().get());
    }

    dataReader::READER.loadTracksFromFile(QString(":/data/ratadata.json"), *this);
    dataReader::READER.loadStationsFromFile(QString(":/data/asemadata.json"), *this);

    goalSpeed_ = 0;
    previousSpeed_ = 0;
    movementSinceLastRailSpawn_ = 0;

    //predefined start tracks
    QList<QString> startTracks = {"008",
                                  "009",
                                  "066",
                                  "142",
                                  "441",
                                  "521",
                                  "531",
                                  "731",};

    int index = qrand() % startTracks.size();
    QString trackCode = startTracks.at(index);

    if (tracks_.value(trackCode).size() >= 2){
        startStationCode_ = tracks_.value(trackCode).at(0);
        destinationStationCode_ = tracks_.value(trackCode).at(1);

    }

    else {
        //failsafe mode if messed up above
        startStationCode_ = "HKI";
        currentTrackCode_ = "001";
        destinationStationCode_ = "PSL";
    }

    //figure out where can go from pasila
    destinationStationCandidates_.clear();
    destinationTrackCandidates_.clear();
    foreach(QList<QString> i, tracks_){
        for (QList<QString>::iterator j = i.begin(); j != i.end()-1;++j){
            if (*j == destinationStationCode_){
                //found a rail that stops at our destination,
                //add possible next destination as the next stop on that track
                destinationTrackCandidates_.append(tracks_.key(i));
                destinationStationCandidates_.append(*(j+1));
            }
        }
        for (QList<QString>::iterator j = i.begin()+1; j != i.end();++j){
            if (*j == destinationStationCode_){
                //also add the previous stop on that track.
                destinationTrackCandidates_.append(tracks_.key(i));
                destinationStationCandidates_.append(*(j-1));
            }
        }
    }

    //figure out where we can go if we reversed back to helsinki
    backtrackStationCandidates_.clear();
    backtrackTrackCandidates_.clear();
    foreach(QList<QString> i, tracks_){
        for (QList<QString>::iterator j = i.begin(); j != i.end()-1;++j){
            if (*j == startStationCode_){
                //found a rail that stops at our start station,
                //add possible next backtrack point as the next stop on that track
                backtrackTrackCandidates_.append(tracks_.key(i));
                backtrackStationCandidates_.append(*(j+1));
            }
        }
        for (QList<QString>::iterator j = i.begin()+1; j != i.end();++j){
            if (*j == startStationCode_){
                //also add the previous stop on that track.
                backtrackTrackCandidates_.append(tracks_.key(i));
                backtrackStationCandidates_.append(*(j-1));
            }
        }
    }

    int distance = getNextDistance();
    //spawn the next station to the game scene
    nextStation_ = std::make_shared<Station>(-distance);
    scene->addItem(nextStation_.get());

    //spawn the previous station closer by as we just started there
    previousStation_ = std::make_shared<Station>(150);
    scene->addItem(previousStation_.get());
    destinationIndex_ = 0;
    backtrackIndex_ = 0;

    //populate minimap with stations
    foreach (auto i , stations_){
        double x = (i.lng-lngCenter_)*xConversionRate_;
        double y = (i.lat-latCenter_)*yConversionRate_;
        miniMapScene_->addEllipse(x-2, y-2, 3, 3,
                                  QPen(), QBrush(Qt::SolidPattern));
    }

    //populate minimap with railway connections between stations
    for (auto i = tracks_.begin(); i != tracks_.end(); ++i){
        for (auto j = (*i).begin(); j != (*i).end()-1; ++j){
            int x1 = (stations_.value(*j).lng-lngCenter_)*xConversionRate_;
            int y1 = (stations_.value(*j).lat-latCenter_)*yConversionRate_;
            int x2 = (stations_.value(*(j+1)).lng-lngCenter_)*xConversionRate_;
            int y2 = (stations_.value(*(j+1)).lat-latCenter_)*yConversionRate_;
            miniMapScene_->addLine(x1,y1, x2, y2, QPen(QColor(Qt::blue)));
        }
    }

    currentLocationMapPoint.
            setPixmap(QPixmap::fromImage(QImage(":/kuvat/redDot.png")));
    obstacleMapPoint_.
            setPixmap(QPixmap::fromImage(QImage(":/kuvat/greenDot.png")));
    updateDestinationOnMiniMap();
}

RailLogic::~RailLogic()
{ }

void RailLogic::move(double multiplier)
{
    if (forward_){
        if (speed_ > goalSpeed_){
            speed_ -= accel_;
        }
        else if (speed_ < goalSpeed_){
            speed_ += accel_;
        }
    }
    if (!forward_){
        if (speed_ < goalSpeed_){
            speed_ += accel_;
        }
        else if (speed_ > goalSpeed_){
            speed_ -= accel_;
        }
    }

    // move railtiles
    for (auto i = railTiles.begin(); i != railTiles.end(); ++i){
        (*i).get()->move((int)(multiplier*speed_));
    }

    // check if moving direction has changed since last frame update
    if ((previousSpeed_ > 0 && speed_ < 0) || (previousSpeed_ < 0 && speed_ > 0)){
        movementSinceLastRailSpawn_ = 0;
    }

    movementSinceLastRailSpawn_ += multiplier*speed_;
    previousSpeed_ = multiplier*speed_;

    // create new tiles if train has moved enough
    if (movementSinceLastRailSpawn_ >= 30){
        std::shared_ptr<OneSideRailTile> railTile =
                std::make_shared<OneSideRailTile>(0,-275);
        scene_->addItem(railTile.get());
        railTiles.push_back(railTile);
        movementSinceLastRailSpawn_ -= 30;
    }

    else if (movementSinceLastRailSpawn_ <= -30){
        std::shared_ptr<OneSideRailTile> railTile =
                std::make_shared<OneSideRailTile>(0,240);
        scene_->addItem(railTile.get());
        railTiles.push_back(railTile);
        movementSinceLastRailSpawn_ += 30;
    }

    // delete disappeared railtiles
    for (auto i = railTiles.begin(); i != railTiles.end();){
        if ((*i).get()->y() > 241){

            scene_->removeItem((*i).get());
            i = railTiles.erase(i);
        }
        else if ((*i).get()->y() < -276){
            scene_->removeItem((*i).get());
            i = railTiles.erase(i);
        }
        else {
            ++i;
        }
    }

    // move next station
    nextStation_->move((int)(multiplier*speed_));
    previousStation_->move((int)(multiplier*speed_));
}

void RailLogic::setSpeed(int newSpeed)
{
    if (forward_){
        goalSpeed_ = newSpeed;
    }
    else{
        goalSpeed_ = -newSpeed;
    }
}

void RailLogic::changeDirection()
{
    forward_ = !forward_;
    goalSpeed_ = -goalSpeed_;
}

void RailLogic::addTrack(QString trackCode, QList<QString> stations)
{
    tracks_.insert(trackCode, stations);
}

void RailLogic::addStations(QString shortCode, QString fullName, QString type,
                            double lat, double lng, bool passengerStation)
{
    StationInfo stationInfo = {};
    stationInfo.fullName = fullName;
    stationInfo.type = type;
    stationInfo.lat = lat;
    stationInfo.lng = lng;
    stationInfo.passengerTrafic = passengerStation;
    stations_.insert(shortCode, stationInfo);
}

void RailLogic::checkCollisionWithStations(std::shared_ptr<PlayerTrain> train)
{
    if (train.get()->collidesWithItem(nextStation_.get())){
        startStationCode_ = destinationStationCode_;
        //destination options are now the ones for backtracking
        backtrackStationCandidates_ = destinationStationCandidates_;
        backtrackTrackCandidates_ = destinationTrackCandidates_;

        destinationStationCode_ = destinationStationCandidates_.at(destinationIndex_);
        currentTrackCode_ = destinationTrackCandidates_.at(destinationIndex_);

        //figure out possible directions after reaching destination
        destinationStationCandidates_.clear();
        destinationTrackCandidates_.clear();
        foreach(QList<QString> i, tracks_){
            for (QList<QString>::iterator j = i.begin(); j != i.end()-1;++j){
                if (*j == destinationStationCode_){
                    //found a rail that stops at our destination,
                    //add possible next destination as the next stop on that track
                    destinationTrackCandidates_.append(tracks_.key(i));
                    destinationStationCandidates_.append(*(j+1));
                }
            }
            for (QList<QString>::iterator j = i.begin()+1; j != i.end();++j){
                if (*j == destinationStationCode_){
                    //also add the previous stop on that track.
                    destinationTrackCandidates_.append(tracks_.key(i));
                    destinationStationCandidates_.append(*(j-1));
                }
            }
        }

        //delete original destination
        scene_->removeItem(nextStation_.get());
        //add the next station to the scene
        int distance = getNextDistance();
        nextStation_ = std::make_shared<Station>(-distance);
        scene_->addItem(nextStation_.get());

        //delete the station we passed from the scene
        scene_->removeItem(previousStation_.get());
        //add the next station to the scene
        previousStation_ = std::make_shared<Station>(150);
        scene_->addItem(previousStation_.get());

        signalStationInfoToUi();
        destinationIndex_ = 0;
        backtrackIndex_ = 0;

        updateDestinationOnMiniMap();
    }

    if (train.get()->collidesWithItem(previousStation_.get())){

        destinationStationCode_ = backtrackStationCandidates_.at(backtrackIndex_);
        currentTrackCode_ = backtrackTrackCandidates_.at(backtrackIndex_);

        //figure out possible directions after reaching destination
        destinationStationCandidates_.clear();
        destinationTrackCandidates_.clear();
        foreach(QList<QString> i, tracks_){
            for (QList<QString>::iterator j = i.begin(); j != i.end()-1;++j){
                if (*j == destinationStationCode_){
                    //found a rail that stops at our destination,
                    //add possible next destination as the next stop on that track
                    destinationTrackCandidates_.append(tracks_.key(i));
                    destinationStationCandidates_.append(*(j+1));
                }
            }
            for (QList<QString>::iterator j = i.begin()+1; j != i.end();++j){
                if (*j == destinationStationCode_){
                    //also add the previous stop on that track.
                    destinationTrackCandidates_.append(tracks_.key(i));
                    destinationStationCandidates_.append(*(j-1));
                }
            }
        }

        //delete original destination
        scene_->removeItem(nextStation_.get());
        //add the next station to the scene
        nextStation_ = std::make_shared<Station>(-1000);
        scene_->addItem(nextStation_.get());

        //delete the station we passed from the scene
        scene_->removeItem(previousStation_.get());
        //add the next station to the scene
        previousStation_ = std::make_shared<Station>(300);
        scene_->addItem(previousStation_.get());

        signalStationInfoToUi();
        destinationIndex_ = 0;
        backtrackIndex_ = 0;

        updateDestinationOnMiniMap();
    }
}

QList<QString> RailLogic::CombineStationTrackInfo(QList<QString> &stationCodes,
                                                  QList<QString> &trackCodes)
{
    QList<QString> tempList;
    QList<QString> nameList;

    for (auto i = stationCodes.begin(); i != stationCodes.end(); ++i){
        tempList.append( stations_.value(*i).fullName);
    }

    for (int i = 0; i < trackCodes.size(); ++i){
        nameList.append(trackCodes.at(i) + ", " + tempList.at(i));
    }
    return nameList;
}

void RailLogic::changeBackTrackCandidateIndex(int index)
{
    backtrackIndex_ = index;
}

void RailLogic::signalStationInfoToUi()
{
    emit destinationCandidatesChanged(CombineStationTrackInfo(
                                          destinationStationCandidates_,
                                          destinationTrackCandidates_));
    emit backttrackCandidatesChanged(CombineStationTrackInfo(
                                         backtrackStationCandidates_,
                                         backtrackTrackCandidates_));
    emit signalDestAndPrevious(currentTrackCode_ + " "
                               +stations_.value(startStationCode_)
                               .fullName, currentTrackCode_ + " " +
                               stations_.value(destinationStationCode_).fullName);
}

void RailLogic::updateDestinationOnMiniMap()
{
    if (!locMapPoint_) {
        miniMapScene_->addItem(&currentLocationMapPoint);
        locMapPoint_ = true;
    }

    int x = (stations_.value(startStationCode_).lng-lngCenter_)*xConversionRate_;
    int y = (stations_.value(startStationCode_).lat-latCenter_)*yConversionRate_;

    currentLocationMapPoint.setPos(x-5, y-5);
}

void RailLogic::updateObstacleOnMiniMap(QString prev, QString next)
{
    if (!obsMapPoint_) {
        miniMapScene_->addItem(&obstacleMapPoint_);
        obsMapPoint_ = true;


    }
    int x = ((stations_.value(prev).lng-lngCenter_)
             + (stations_.value(next).lng-lngCenter_))/2 * xConversionRate_;
    int y = ((stations_.value(prev).lat-latCenter_)
             + (stations_.value(next).lat-latCenter_))/2 * yConversionRate_;


    obstacleMapPoint_.setPos(x-5, y-5);
}

void RailLogic::getRandomStationAndTrack(int distance, QList<QString> &stations,
                                         QString &trackCode,
                                         QList<QString> &stationNames, bool &harmful)
{
    int randomNumber = qrand() % destinationStationCandidates_.size();
    QString destinationStation = destinationStationCandidates_.at(randomNumber);
    QString startStation = destinationStationCode_;
    QString track = destinationTrackCandidates_.at(randomNumber);
    for (int k = 0; k < distance; ++k){
        startStation = destinationStation;

        QList<QString> destStat;
        QList<QString> destTrack;
        foreach(QList<QString> i, tracks_){
            for (QList<QString>::iterator j = i.begin(); j != i.end()-1;++j){
                if (*j == startStation){
                    //found a rail that stops at our station,
                    //add possible next destination as the next stop on that track
                    destTrack.append(tracks_.key(i));
                    destStat.append(*(j+1));
                }
            }

            for (QList<QString>::iterator j = i.begin()+1; j != i.end();++j){
                if (*j == startStation){
                    //also add the previous stop on that track.
                    destTrack.append(tracks_.key(i));
                    destStat.append(*(j-1));
                }
            }

        }
        randomNumber = qrand() % destStat.size();
        track = destTrack.at(randomNumber);
        destinationStation = destStat.at(randomNumber);

    }
    stations.append(startStation);
    stations.append(destinationStation);
    stationNames.append(stations_.value(stations.at(0)).fullName);
    stationNames.append(stations_.value(stations.at(1)).fullName);
    trackCode = track;

    //find out if there are multiple tracks between the two stations
    //if so, figure if the obstacle is on one that aitrains go through
    bool found = false;
    harmful = false;
    foreach(QList<QString> i, tracks_){
        for (QList<QString>::iterator j = i.begin(); j != i.end()-1;++j){
            if ((*j == stations.at(0) && *(j+1) == stations.at(1) )
                    || (*j == stations.at(1) && *(j+1) == stations.at(0))){
                //found a track between the stations,
                //figure out what the name of the track is
                if (tracks_.key(i).toStdString() == trackCode.toStdString()){
                    harmful = true;
                }
                found = true;
                break;
            }
        }
        if (found){
            break;
        }
    }
}

QString RailLogic::getCurrentTrack()
{
    return currentTrackCode_;
}

QString RailLogic::getLastStation()
{
    return startStationCode_;
}

QString RailLogic::getNextStation()
{
    return destinationStationCode_;
}

void RailLogic::getCurrentLocation(QString &prev, QString &next,
                                   int &prevY, int &nextY, bool &mainRail)
{
    prev = startStationCode_;
    next = destinationStationCode_;
    prevY = previousStation_->y();
    nextY = nextStation_->y();

    mainRail = false;
    bool found = false;
    foreach(QList<QString> i, tracks_){
        for (QList<QString>::iterator j = i.begin(); j != i.end()-1;++j){
            if ((*j == startStationCode_ && *(j+1) == destinationStationCode_ )
                    || (*j == destinationStationCode_
                        && *(j+1) == startStationCode_)){
                //found a track between the stations, figure out, if the track is
                if (tracks_.key(i).toStdString() == currentTrackCode_.toStdString()){
                    mainRail = true;
                }
                found = true;
                break;
            }
        }
        if (found){
            break;
        }
    }
}

int RailLogic::getNextDistance()
{
    double xdist = ((stations_.value(startStationCode_).lng) -
                    (stations_.value(destinationStationCode_).
                     lng))*distanceConversionRate_;
    double ydist = ((stations_.value(startStationCode_).lat) -
                    (stations_.value(destinationStationCode_).lat))*
                     distanceConversionRate_;
    double dist = sqrt(xdist*xdist + ydist*ydist);
    //rajoitteet etäisyydelle, jottei tule järjettömiä välimatkoja
    if (dist < 500.0){
        dist = 500.0;
    }
    else if (dist > 2500.0){
        dist = 2500.0;
    }
    return (int)dist;
}

void RailLogic::updateNavi(QString next, QString prev)
{
    QString result;
    bool found = PathFinder::PATHFINDER.nextStationCode(result,
                                                        tracks_,
                                                        destinationStationCandidates_,
                                                        prev, next);
    if (found) {
        emit naviInfoUpdate("Valitse seuraavaksi " + stations_.value(result).fullName);
    }
    else {
        emit naviInfoUpdate("Olet liian kaukana reittiarviota varten");
    }
}

void RailLogic::changeDestinationCandidateIndex(int index)
{
    destinationIndex_ = index;
}
