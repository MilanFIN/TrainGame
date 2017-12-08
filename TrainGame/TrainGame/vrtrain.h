#ifndef VRTRAIN_H
#define VRTRAIN_H

#include <QGraphicsPixmapItem>

/**
 * @brief The VrTrain class defines a single aitrain
 */
class VrTrain : public QGraphicsPixmapItem
{
public:
    /**
     * @brief VrTrain constructor
     * @param tNumber id of the train
     * @param timeTable vector of pairs of stations and departure times in a speficic form
     */
    VrTrain(QString tNumber, QVector<QPair<QString, QString> > timeTable);

    /**
     * @brief getTraiNumber gets the id of the train
     * @return trainId in qstring
     */
    QString getTraiNumber() const;
    /**
     * @brief getTimeTable gets the timetable
     * @return QVector<QPair<QString, QString>> first qstring is a stationcode, second the departure time in some weird format
     */
    QVector<QPair<QString, QString>> getTimeTable() const;
    /**
     * @brief inScene tells if the train is in scene
     * @return boolean
     */
    bool inScene();
    /**
     * @brief setInScene sets the inScene return value
     * @param i boolean of if the train is in scene
     */
    void setInScene(bool i);
    /**
     * @brief blackListed tells if the train has been blacklisted due to a collision
     * @return boolean true if blacklisted
     */
    bool blackListed();
    /**
     * @brief blackList blacklists the train
     * @post the blacklisted method now returns true
     */
    void blackList();
private:
    QString trainNumber_;
    // stationshortCode, actualTime
    QVector<QPair<QString, QString>> scheduledTime_;
    bool inverted_;
    bool inScene_;
    bool blacklisted_;
};

#endif // VRTRAIN_H
