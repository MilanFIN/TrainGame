#ifndef HTTPENGINE_H
#define HTTPENGINE_H

#include <QObject>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QIODevice>

/**
 * @brief HttpEngine-object executes a HTTP: query to VR's API.
 */
class HttpEngine: public QObject
{
    Q_OBJECT
public:
    /**
     * @brief HttpEngine construcotr
     */
    HttpEngine();

    /**
     * @brief httpData executes the query
     * @return QIODevice* pointer
     */
    QIODevice* httpData();

private:
    QNetworkAccessManager nam_;
};

#endif // HTTPENGINE_H
