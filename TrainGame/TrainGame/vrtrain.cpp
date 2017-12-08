#include "vrtrain.h"

VrTrain::VrTrain(QString tNumber, QVector<QPair<QString, QString> > timeTable):
    trainNumber_(tNumber),
    scheduledTime_(timeTable)
{
    inScene_ = false;
    inverted_ = false;
    blacklisted_ = false;
    QImage img(":/kuvat/train5.png");
    QImage imageScaled = img.scaled(150,150,Qt::KeepAspectRatio);
    setPixmap(QPixmap::fromImage(imageScaled));
    setPos(-38, -500);
}

QString VrTrain::getTraiNumber() const
{
    return trainNumber_;
}

QVector<QPair<QString, QString> > VrTrain::getTimeTable() const
{
    return scheduledTime_;
}

bool VrTrain::inScene()
{
    return inScene_;
}

void VrTrain::setInScene(bool i)
{
    inScene_ = i;
}

bool VrTrain::blackListed()
{
    return blacklisted_;
}

void VrTrain::blackList()
{
    blacklisted_ = true;
}
