#ifndef DATAREADER_H
#define DATAREADER_H
#include <QString>
#include <QJsonObject>
#include <memory>
#include "raillogic.h"
#include "shop.h"
#include "playerlogic.h"


class dataReader
{
public:
    /**
     * @brief READER singleton-olio
     */
    static dataReader READER;

    ~dataReader() = default;

    /**
     * @brief loadTracksFromFile lukee junaverkkodatan tiedostosta
     * @param filepath polku ratadata tiedostoon.
     */
    void loadTracksFromFile(const QString &filepath, RailLogic &logic);
    void loadStationsFromFile(const QString &filepath, RailLogic &logic);
    // Todo: return vectori, jossa junat valmiina.
    void loadTrains(const QString &filepath, std::shared_ptr<Shop> shop, PlayerLogic &logic);




private:
    dataReader();

    dataReader(dataReader const&) = delete;
    dataReader& operator=(dataReader const&) = delete;
    static QJsonObject verifyIsObject(const QJsonValue &jsonValue);
};

#endif // DATAREADER_H
