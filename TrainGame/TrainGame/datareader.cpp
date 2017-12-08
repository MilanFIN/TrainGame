#include "datareader.h"
#include "shop.h"
#include "playertrain.h"
#include "httpengine.h"
#include "vrtrain.h"
#include "ioexception.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMap>
#include <QList>



dataReader dataReader::READER;

void dataReader::loadTracksFromFile(const QString &filepath, RailLogic &locig)
{
    QFile file(filepath);
    if (!file.open(QFile::ReadOnly)) {
        throw std::runtime_error("Can't open file " + filepath.toStdString() + ". Check filepath");
    }

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &error);

    if (doc.isNull()) {
        throw std::runtime_error("Failed to parse json" + error.errorString().toStdString());
    }
    if (!doc.isObject()) {
        throw std::runtime_error("ratadata to contain json object");
    }


    QJsonObject obj = doc.object();
    QJsonArray tracks = obj["tracks"].toArray();

    foreach (QJsonValue track, tracks) {
        // trackCode
        QJsonObject trackObj = track.toObject();
        QString trackCode = trackObj["trackCode"].toString();

        // stations on current track
        QJsonArray stations = trackObj["stations"].toArray();
        QList<QString> stationList = {};

        for (QJsonValue station : stations) {
            QJsonObject stationObj = station.toObject();
            QString stationName = stationObj["name"].toString();
            stationList.push_back(stationName);
        }
        locig.addTrack(trackCode, stationList);

    }
    file.close();
}

void dataReader::loadStationsFromFile(const QString &filepath, RailLogic& logic)
{
    QFile f(filepath);

    if (!f.open(QFile::ReadOnly)) {
        throw std::runtime_error("Can't open file" + filepath.toStdString());
    }

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(f.readAll(), &error);

    if (doc.isNull()) {
        throw std::runtime_error("Failed to parse json" + error.errorString().toStdString());
    }
    if (!doc.isArray()) {
        throw std::runtime_error("Document does not contain array of stations");
    }


    QJsonArray arr = doc.array();

    foreach (QJsonValue val, arr) {
        QJsonObject obj = val.toObject();

        // shortname of station
        QString shortCode = obj["stationShortCode"].toString();

        // other station info
        QString name = obj["stationName"].toString();
        QString type = obj["type"].toString();
        bool passengerTrafic = obj["passengerTraffic"].toBool();
        double lat = obj["latitude"].toDouble();
        double lng = obj["longitude"].toDouble();


        logic.addStations(shortCode, name, type, lat, lng, passengerTrafic);

    }
    f.close();
}

void dataReader::loadTrains(const QString &filepath, std::shared_ptr<Shop> shop, PlayerLogic &logic)
{
    QFile f(filepath);

    if (!f.open(QFile::ReadOnly)) {
        throw std::runtime_error("Can't open file" + filepath.toStdString());
    }

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(f.readAll(), &error);

    if (doc.isNull()) {
        throw std::runtime_error("Failed to parse json" + error.errorString().toStdString());
    }
    if (!doc.isArray()) {
        throw std::runtime_error("Document does not contain array of trainobjects");
    }

    QJsonArray arr = doc.array();

    bool first = true;
    foreach (QJsonValue val, arr) {
        QJsonObject obj = val.toObject();

        QString trainName = obj["name"].toString();

        double speed = obj["speed"].toDouble();
        unsigned short price = short(obj["price"].toInt());
        unsigned short repairCost = short(obj["repairCost"].toInt());
        unsigned short shape = short(obj["shape"].toInt());
        QString imagePath = obj["image"].toString();

        std::shared_ptr<PlayerTrain> train = std::make_shared<PlayerTrain>(trainName, shape, price, speed, repairCost, imagePath);

        if (first){
            logic.addNewTrain(train);
            logic.setActiveTrain(0);
            first = false;
        } else {
            shop->addTrain(train);
        }

    }

}

void dataReader::readHTTPData(std::weak_ptr<HttpEngine> engine, VrTrainManager& manager)
{

    QIODevice *ret = engine.lock()->httpData();
    // Whole game depends on API-info, throw exception, controlled closing
    if (ret == NULL) {
        throw IoException("NetworkRequest returned NULL");
    }

    QByteArray res = ret->readAll();

    parseHttpData(res, manager);


}

void dataReader::parseHttpData(QByteArray data, VrTrainManager& manager)
{
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);

    if (doc.isNull()) {
        throw std::runtime_error("Failed to parse json " + error.errorString().toStdString());
    }
    if (!doc.isArray()) {
        throw std::runtime_error("Document does not contain array of trainobjects");
    }

    QJsonArray arr = doc.array();

    foreach (QJsonValue val, arr) {
        QJsonObject obj = val.toObject();

        //if ( (obj["trainCategory"].toString() == QString("Long-distance") )
        //     || ( obj["trainsCategory"].toString() == QString("Cargo")) ) {
        if (true){
            QVector<QPair<QString, QString>> timeTable;
            QString trainNumberID = QString::number(obj["trainNumber"].toInt());


            QJsonArray timeTableArr = obj["timeTableRows"].toArray();
            foreach (QJsonValue value, timeTableArr) {

                QJsonObject objs = value.toObject();

                QString shortCode = objs["stationShortCode"].toString();
                QString actualTime = objs["scheduledTime"].toString();

                // APIdata also contains empty schedules. Get rid of them
                if (actualTime != ""){
                    timeTable.push_back(qMakePair(shortCode, actualTime));
                }
            }
            if (timeTable.size() != 0){
                std::shared_ptr<VrTrain> aiTrain = std::make_shared<VrTrain>(trainNumberID, timeTable);
                manager.addAiTrain(trainNumberID, aiTrain);
            }

        }

    }

}

dataReader::dataReader(){}
