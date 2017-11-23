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

void VrTrainManager::checkCollisions(QString prev, QString next)
{
    std::regex re{"([^T|Z|.]+)"}; //to get rid of all but time

    foreach(std::shared_ptr<VrTrain> train,aiTrains_){
        QVector<QPair<QString, QString>> timeTable = train->getTimeTable();
        for (auto pair =timeTable.begin(); pair != timeTable.end()-1 ; ++pair){
            if ((*pair).first == next && (*(pair+1)).first == prev ||
                (*pair).first == prev && (*(pair+1)).first == next) {


                std::regex_token_iterator<std::string::iterator> i{(*pair).second.toStdString().begin(), (*pair).second.toStdString().end(), re, 1};
                i++;
                std::string time = *i;
                std::string part;
                std::stringstream stream(time);
                QVector<int> timeFractures;
                while( std::getline(stream, part, ':') ){
                   timeFractures.append(std::stoi(part));

                }

                int hour = QTime::currentTime().hour();
                int minute = QTime::currentTime().minute();
                int second = QTime::currentTime().second();

                //define the first station, whose time is bigger than current
                if (timeFractures.at(0) >= hour && timeFractures.at(1) >= minute && timeFractures.at(2) >= hour){
                    std::cout << "collision" << std::endl;
                }

            }

        }

    }

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
