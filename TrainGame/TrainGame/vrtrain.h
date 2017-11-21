#ifndef VRTRAIN_H
#define VRTRAIN_H

#include <QGraphicsPixmapItem>

/**
 * @brief Yksittäisen Vr-junan kuvaava luokka
 */
class VrTrain : public QGraphicsPixmapItem
{
public:
    VrTrain(QString tNumber, QVector<QPair<QString, QString> > timeTable);
    void move();

    QString getTraiNumber() const;
    QVector<QPair<QString, QString>> getTimeTable() const;
private:
    QString trainNumber_;
    // stationshortCode, actualTime
    QVector<QPair<QString, QString>> scheduledTime_;


};

#endif // VRTRAIN_H
