#include "raillogic.h"
#include "datareader.h"
#include <iostream>

RailLogic::RailLogic(std::shared_ptr<QGraphicsScene> scene):
    scene_(scene)
{
    railTiles.push_back(std::make_shared<OneSideRailTile>(0,-275)); //-275
    scene_->addItem(railTiles.at(0).get());
    std::shared_ptr<RailLogic> logic = std::make_shared<RailLogic>(*this);


    dataReader::READER.loadTracksFromFile(QString(":/data/ratadata.json"), logic);
    dataReader::READER.loadStationsFromFile(QString(":/data/asemadata.json"),  logic);

    goalSpeed_ = 0;
    previousSpeed_ = 0;
    movementSinceLastSpawn = 0;

}

void RailLogic::move()
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
    //siirretään raiteenpätkiä
    for (auto i = railTiles.begin(); i != railTiles.end(); ++i){
        (*i).get()->move((int)speed_);
    }



    //tarkistetaan, onko kulkusuunta ehtinyt vaihtua edellisen päiviyksen jälkeen

    if ((previousSpeed_ > 0 && speed_ < 0) || (previousSpeed_ < 0 && speed_ > 0)){
        movementSinceLastSpawn = 0;
    }

    movementSinceLastSpawn += speed_;
    previousSpeed_ = speed_;




    //luodaan uusi pätkä, jos on liikuttu tarpeeksi
    if (movementSinceLastSpawn >= 30){
        std::shared_ptr<OneSideRailTile> railTile = std::make_shared<OneSideRailTile>(0,-275);
        scene_->addItem(railTile.get());
        railTiles.push_back(railTile);
        movementSinceLastSpawn -= 30;
    }

    else if (movementSinceLastSpawn <= -30){
        std::shared_ptr<OneSideRailTile> railTile = std::make_shared<OneSideRailTile>(0,240);
        scene_->addItem(railTile.get());
        railTiles.push_back(railTile);
        movementSinceLastSpawn += 30;
    }



    //poistetaan näkyvistä hävinneet raiteenpätkät
    for (auto i = railTiles.begin(); i != railTiles.end();){
        if ((*i).get()->y() > 241){
            scene_->removeItem((*i).get());
            i = railTiles.erase(i);
        }
        else if ((*i).get()->y() < -276){
            scene_->removeItem((*i).get());
            i = railTiles.erase(i);
        }
        else{
            ++i;
        }
    }


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

