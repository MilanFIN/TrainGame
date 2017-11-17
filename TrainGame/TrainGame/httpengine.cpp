#include "httpengine.h"
#include <QDate>
#include <QEventLoop>

QString currdate = QDate::currentDate().toString("yyyy-MM-dd");
QString baseUrl = "https://rata.digitraffic.fi/api/v1/trains/" + currdate;

HttpEngine::HttpEngine(){}

QIODevice *HttpEngine::httpData()
{
    QEventLoop eLoop;
    QObject::connect(&nam_, SIGNAL(finished(QNetworkReply*)), &eLoop, SLOT(quit()));

    QUrl apiUrl(baseUrl);
    QNetworkRequest req(apiUrl);
    QNetworkReply *reply = nam_.get(req);

    int code = eLoop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        return reply;
    } else {
        return NULL;
    }
}

