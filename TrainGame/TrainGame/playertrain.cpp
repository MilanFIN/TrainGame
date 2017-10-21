#include "playertrain.h"

PlayerTrain::PlayerTrain()
{
    QImage kuva(":/kuvat/train.png");
    setPixmap(QPixmap::fromImage(kuva));
    setPos(-25, 0);
    //asetetaan raiteiden päälle
    setZValue(2);
}

