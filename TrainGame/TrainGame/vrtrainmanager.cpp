#include "vrtrainmanager.h"
#include "datareader.h"
#include "ioexception.h"
#include <exception>
#include <iostream>
#include <sstream>
#include <QTime>
#include <regex>
#include <algorithm>
#include <iostream>



VrTrainManager::VrTrainManager(std::shared_ptr<QGraphicsScene> scene):
    scene_(scene)
{
    engine_ = std::make_shared<HttpEngine>();
    readTrainsFromAPI();

    timeSinceLastMsg = QTime::currentTime().second();

}

void VrTrainManager::addAiTrain(QString id, std::shared_ptr<VrTrain> aiTrain)
{
    try {
       aiTrains_.insert(id, aiTrain);
    }catch (std::bad_alloc& ba) {
        // out of memory
        Q_ASSERT("bad_alloc caught");

    }

}


bool VrTrainManager::checkCollisions(QString prev, QString next, bool harmful)
{
    if (!harmful){
        return false;
    }

    std::regex re{"([^T|Z|.]+)"}; //to get rid of all but time

    foreach(std::shared_ptr<VrTrain> train,aiTrains_){
        if (train.get()->blackListed() == false){
            QVector<QPair<QString, QString>> timeTable = train->getTimeTable();
            for (auto pair =timeTable.begin()+1; pair != timeTable.end() ; ++pair){
                if (((*pair).first == next && (*(pair-1)).first == prev) ||
                    ((*pair).first == prev && (*(pair-1)).first == next)) {


                    std::regex_token_iterator<std::string::iterator> i{(*pair).second.toStdString().begin(), (*pair).second.toStdString().end(), re, 1};
                    i++;
                    std::string time = *i;
                    std::string part;
                    std::stringstream stream(time);
                    QVector<int> timeFractures;
                    while( std::getline(stream, part, ':') ){
                       timeFractures.append(std::stoi(part));

                    }

                    std::regex_token_iterator<std::string::iterator> j{(*(pair-1)).second.toStdString().begin(), (*(pair-1)).second.toStdString().end(), re, 1};
                    j++;
                    std::string nextTime = *j;
                    std::string nextPart;
                    std::stringstream nextstream(nextTime);
                    QVector<int> nextTimeFractures;
                    while( std::getline(nextstream, nextPart, ':') ){
                       nextTimeFractures.append(std::stoi(nextPart));

                    }
                    int hour = QTime::currentTime().hour();
                    int minute = QTime::currentTime().minute();
                    int second = QTime::currentTime().second();


                    int prevSec = timeFractures.at(0) * 3600 + timeFractures.at(1)*60 + timeFractures.at(2);
                    int nextSec = nextTimeFractures.at(0) * 3600 + nextTimeFractures.at(1)*60 + nextTimeFractures.at(2);
                    int currentSec = hour*3600 + minute * 60 + second;

                    if ((prevSec <= currentSec && nextSec >= currentSec) || (prevSec >= currentSec && nextSec <= currentSec)){
                        //collision happened, so blacklist the train and inform controller
                        train.get()->blackList();

                        timeSinceLastMsg = QTime::currentTime().second();
                        emit message("Juna törmäsi esteeseen, uuden esteen sijainti kerrottu");



                        return true;
                    }

                }

            }

        }
    }
    return false;

}

int VrTrainManager::checkPlayerCollision(std::shared_ptr<PlayerTrain> player)
{
    foreach(std::shared_ptr<VrTrain> train,aiTrains_){
        if (train->collidesWithItem(player.get())){
            train->blackList();
            train->setInScene(false);
            scene_->removeItem(train.get());
            //collision happened, so return damage done to the player
            return 50;
        }
    }
    return 0;
}

QHash<QString, std::shared_ptr<VrTrain> > VrTrainManager::getAllAiTrains() const
{
    return aiTrains_;
}

void VrTrainManager::move(QString prev, QString next, int prevY, int nextY, bool mainRail)
{
    std::regex re{"([^T|Z|.]+)"}; //to get rid of all but time

    foreach(std::shared_ptr<VrTrain> train,aiTrains_){

        QVector<QPair<QString, QString>> timeTable = train->getTimeTable();
        for (auto pair =timeTable.begin()+1; pair != timeTable.end() ; ++pair){
            if (train->blackListed()){
                break;
            }
            if (!mainRail){
                if (train->inScene()){
                    scene_->removeItem(train.get());
                    train->setInScene(false);
                }
            }

            else if (((*pair).first == next && (*(pair-1)).first == prev) ||
                ((*pair).first == prev && (*(pair-1)).first == next)) {



                std::regex_token_iterator<std::string::iterator> i{(*pair).second.toStdString().begin(), (*pair).second.toStdString().end(), re, 1};
                i++;
                std::string time = *i;

                std::string part;
                std::stringstream stream(time);


                QVector<int> timeFractures;
                while( std::getline(stream, part, ':') ){
                   timeFractures.append(std::stoi(part));

                }




                std::regex_token_iterator<std::string::iterator> j{(*(pair-1)).second.toStdString().begin(), (*(pair-1)).second.toStdString().end(), re, 1};
                j++;
                std::string nextTime = *j;
                std::string nextPart;
                std::stringstream nextstream(nextTime);
                QVector<int> nextTimeFractures;
                while( std::getline(nextstream, nextPart, ':') ){
                   nextTimeFractures.append(std::stoi(nextPart));

                }


                int hour = QTime::currentTime().hour();
                int minute = QTime::currentTime().minute();
                int second = QTime::currentTime().second();

                int prevSec = timeFractures.at(0) * 3600 + timeFractures.at(1)*60 + timeFractures.at(2);
                int nextSec = nextTimeFractures.at(0) * 3600 + nextTimeFractures.at(1)*60 + nextTimeFractures.at(2);
                int currentSec = hour*3600 + minute * 60 + second;

                if ((prevSec <= currentSec && nextSec >= currentSec) || (prevSec >= currentSec && nextSec <= currentSec)){



                    if (!train->inScene()){
                        train->setInScene(true);
                        scene_->addItem(train.get());
                    }

                    int totalHours = nextTimeFractures.at(0) - timeFractures.at(0);
                    int totalMinutes = nextTimeFractures.at(1) - timeFractures.at(1);
                    int totalSeconds = 3600* totalHours + 60*totalMinutes + nextTimeFractures.at(2) - timeFractures.at(2);

                    int realHours = hour - timeFractures.at(0);
                    int realMinutes = minute - timeFractures.at(1);
                    int realSeconds = 3600 * realHours + 60*realMinutes + second - timeFractures.at(2);


                    double distance = 0;
                    if (totalSeconds != 0){
                         distance = double(realSeconds)/double(totalSeconds);
                    }
                    int y;


                    if ((*pair).first == next && (*(pair-1)).first == prev){
                        y = double(prevY) + (distance*(double(nextY-prevY)));
                    }
                    else {
                        y = double(nextY) - (distance*(double(nextY-prevY)));
                    }




                    train->setPos(train->x(), y);

                    std::cout << time << " " << y << std::endl;

                    if (abs(timeSinceLastMsg - QTime::currentTime().second()) >= 5){
                        emit message("Raiteellasi on toinen juna");
                    }

                }




            }
            else if (train->inScene()){
                scene_->removeItem(train.get());
                train->setInScene(false);

            }

        }

    }
}

std::weak_ptr<HttpEngine> VrTrainManager::getHttpEngine() const
{
    std::weak_ptr<HttpEngine> engine = engine_;
    return engine;

}

void VrTrainManager::readTrainsFromAPI()
{

    dataReader::dataReader::READER.readHTTPData(getHttpEngine(), *this);


}
