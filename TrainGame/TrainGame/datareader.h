#ifndef DATAREADER_H
#define DATAREADER_H
#include <QString>
#include <QJsonObject>
#include <memory>

#include "raillogic.h"
#include "shop.h"
#include "playerlogic.h"
#include "httpengine.h"
#include "vrtrainmanager.h"

class dataReader
{

public:
    /**
     * @brief READER singleton
     */
    static dataReader READER;

    ~dataReader() = default;

    /**
     * @brief loadTracksFromFile reads trackdata from file
     * @param filepath path to the file.
     */
    void loadTracksFromFile(const QString &filepath, RailLogic &logic);
    /**
     * @brief loadStationsFromFile reads stationdata from file
     * @param filepath path to stationdata.
     */
    void loadStationsFromFile(const QString &filepath, RailLogic &logic);

    /**
     * @brief Reads data on playable trains from file
     * @param filepath path to traindata. shop is the shop trains will be added to
     */
    void loadTrains(const QString &filepath, std::shared_ptr<Shop> shop, PlayerLogic &logic);

    /**
     * @brief Reads VR's traindata via http.
     * @param engine http:engine, manager: manager of aitrains
     */
    void readHTTPData(std::weak_ptr<HttpEngine> engine, VrTrainManager &manager);


private:
    dataReader();

    dataReader(dataReader const&) = delete;
    dataReader& operator=(dataReader const&) = delete;

    void parseHttpData(QByteArray data, VrTrainManager &manager);

};

#endif // DATAREADER_H
