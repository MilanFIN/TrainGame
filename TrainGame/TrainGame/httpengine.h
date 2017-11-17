#ifndef HTTPENGINE_H
#define HTTPENGINE_H

#include <QObject>
#include <QUrl>
#include <QNetworkRequest> //wtf ei käänny?
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QIODevice>

class HttpEngine: public QObject
{
    Q_OBJECT
public:
    HttpEngine();
    QIODevice* httpData();
private:
    QNetworkAccessManager nam_;
};

#endif // HTTPENGINE_H
