#include "vrtrainmanager.h"
#include "datareader.h"
#include <exception>
#include <iostream>
#include <QTime>
#include <regex>
#include <algorithm>


VrTrainManager::VrTrainManager(std::shared_ptr<QGraphicsScene> scene):
    scene_(scene)
{
    engine_ = std::make_shared<HttpEngine>();
    dataReader::dataReader::READER.readHTTPData(getHttpEngine(), *this);
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

void VrTrainManager::move()
{

}

bool VrTrainManager::checkCollisions(QString prev, QString next)
{
    std::regex re{"([^T|Z|.]+)"}; //to get rid of all but time

    foreach(std::shared_ptr<VrTrain> train,aiTrains_){
        if (train.get()->blackListed() == false){
            QVector<QPair<QString, QString>> timeTable = train->getTimeTable();
            for (auto pair =timeTable.begin()+1; pair != timeTable.end() ; ++pair){
                if ((*pair).first == next && (*(pair-1)).first == prev ||
                    (*pair).first == prev && (*(pair-1)).first == next) {


                    std::regex_token_iterator<std::string::iterator> i{(*pair).second.toStdString().begin(), (*pair).second.toStdString().end(), re, 1};
                    i++;
                    std::string time = *i;
                    std::string part;
                    std::stringstream stream(time);
                    QVector<int> timeFractures;
                    while( std::getline(stream, part, ':') ){
                       timeFractures.append(std::stoi(part));

                    }

                    std::regex_token_iterator<std::string::iterator> j{(*(pair+1)).second.toStdString().begin(), (*(pair+1)).second.toStdString().end(), re, 1};
                    j++;
                    std::string nextTtime = *j;
                    std::string nextPart;
                    std::stringstream stream(nextTime);
                    QVector<int> nextTimeFractures;
                    while( std::getline(stream, nextPart, ':') ){
                       nextTimeFractures.append(std::stoi(part));

                    }
                    int hour = QTime::currentTime().hour();
                    int minute = QTime::currentTime().minute();
                    int second = QTime::currentTime().second();



                    if (timeFractures.at(0) >= hour && timeFractures.at(1) >= minute && timeFractures.at(2) >= second
                            && nextTimeFractures.at(0) <=  hour && nextTimeFractures.at(1) <= minute && nextTimeFractures.at(2) <= second){
                        //collision happened, so blacklist the train and inform controller
                        train.get()->blackList();
                        return true;
                    }

                }

            }

        }
    }
    return false;

}

QHash<QString, std::shared_ptr<VrTrain> > VrTrainManager::getAllAiTrains() const
{
    return aiTrains_;
}

std::weak_ptr<HttpEngine> VrTrainManager::getHttpEngine() const
{
    std::weak_ptr<HttpEngine> engine = engine_;
    return engine;

}
