#include "datareader.h"
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

    for (QJsonValue track : tracks) {
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

    for (QJsonValue val : arr) {
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

void dataReader::loadTrains(const QString &filepath)
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
        throw std::runtime_error("Document does not contain array of trains");
    }

    QJsonArray arr = doc.array();



}

dataReader::dataReader(){}
