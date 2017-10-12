#include "traingraphicsitem.h"

TrainGraphicsItem::TrainGraphicsItem()
{
    QImage kuva(":/kuvat/train.png");
    setPixmap(QPixmap::fromImage(kuva));
    setPos(-25, 0);
    //asetetaan raiteiden päälle
    setZValue(2);
}
