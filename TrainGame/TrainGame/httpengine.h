#ifndef HTTPENGINE_H
#define HTTPENGINE_H

#include <QObject>
#include <QUrl>
#include <QNetworkRequest> //wtf ei käänny?
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QIODevice>


/**
 * @brief HttpEngine-Luokka suorittaa kyselyn vr:n API:in.
 */
class HttpEngine: public QObject
{
    Q_OBJECT
public:
    /**
     * @brief HttpEngine rakentaja
     */
    HttpEngine();

    /**
     * @brief httpData suorittaa http kyselyn vr:n API:in
     * @return QIODevice* osoitin
     */
    QIODevice* httpData();


private:
    QNetworkAccessManager nam_;
};

#endif // HTTPENGINE_H
