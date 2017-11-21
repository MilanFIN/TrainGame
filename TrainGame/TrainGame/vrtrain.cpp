#include "vrtrain.h"

VrTrain::VrTrain(QString tNumber, QVector<QPair<QString, QString> > timeTable):
    trainNumber_(tNumber),
    scheduledTime_(timeTable)
{

}

void VrTrain::move()
{

}

QString VrTrain::getTraiNumber() const
{
    return trainNumber_;
}

QVector<QPair<QString, QString> > VrTrain::getTimeTable() const
{
    return scheduledTime_;
}
