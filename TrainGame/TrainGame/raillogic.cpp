#include "raillogic.h"
#include "datareader.h"
#include <iostream>

RailLogic::RailLogic(std::shared_ptr<QGraphicsScene> scene):
    scene_(scene)
{
    railTiles.push_back(std::make_shared<OneSideRailTile>(0,-275));
    scene_->addItem(railTiles.at(0).get());



    dataReader::READER.loadTracksFromFile(QString(":/data/ratadata.json"), *this);
    dataReader::READER.loadStationsFromFile(QString(":/data/asemadata.json"), *this);

    goalSpeed_ = 0;
    previousSpeed_ = 0;
    movementSinceLastSpawn = 0;


    //start from helsinki on track 001 towards pasila
    startStationCode_ = "HKI";
    currentTrackCode_ = "001";
    destinationStationCode_ = "PSL";


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




    //spawn the next station to the game scene
    nextStation_ = std::make_shared<Station>(-1000);
    scene->addItem(nextStation_.get());

    //spawn the previous station closer by as we just started there
    previousStation_ = std::make_shared<Station>(300);
    scene->addItem(previousStation_.get());


    destinationIndex_ = 0;
    backtrackIndex_ = 0;

}

RailLogic::~RailLogic()
{

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


    //siirretään seuraavaa asemaa
    nextStation_->move((int)speed_);
    previousStation_->move((int)speed_);

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

        std::cout << "passed " << startStationCode_.toStdString() << " on track " << currentTrackCode_.toStdString() << std::endl;

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
    }

    if (train.get()->collidesWithItem(previousStation_.get())){

        destinationStationCode_ = backtrackStationCandidates_.at(backtrackIndex_);
        currentTrackCode_ = backtrackTrackCandidates_.at(backtrackIndex_);


        std::cout << "asdf:" << backtrackIndex_ << std::endl;
        std::cout << "passed " << startStationCode_.toStdString() << " on track " << currentTrackCode_.toStdString() << std::endl;

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

    }

}

QList<QString> RailLogic::CombineStationTrackInfo(QList<QString> &stationCodes, QList<QString> &trackCodes)
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
    emit destinationCandidatesChanged(CombineStationTrackInfo( destinationStationCandidates_, destinationTrackCandidates_));
    emit backttrackCandidatesChanged(CombineStationTrackInfo(backtrackStationCandidates_, backtrackTrackCandidates_));
}

void RailLogic::changeDestinationCandidateIndex(int index)
{
    destinationIndex_ = index;
}

