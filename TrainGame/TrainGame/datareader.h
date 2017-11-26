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
     * @brief loadTracksFromFile lukee junaverkkodatan tiedostosta
     * @param filepath polku ratadata tiedostoon.
     */
    void loadTracksFromFile(const QString &filepath, RailLogic &logic);
    void loadStationsFromFile(const QString &filepath, RailLogic &logic);

    void loadTrains(const QString &filepath, std::shared_ptr<Shop> shop, PlayerLogic &logic);


    void readHTTPData(std::weak_ptr<HttpEngine> engine, VrTrainManager &manager);


private:
    dataReader();

    dataReader(dataReader const&) = delete;
    dataReader& operator=(dataReader const&) = delete;

    void parseHttpData(QByteArray data, VrTrainManager &manager);

};

#endif // DATAREADER_H
