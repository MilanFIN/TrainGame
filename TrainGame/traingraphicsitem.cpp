#include "traingraphicsitem.h"

TrainGraphicsItem::TrainGraphicsItem()
{
    setPixmap(QPixmap("./img/train.png"));
    setPos(-25, 0);
    //asetetaan raiteiden päälle
    setZValue(2);
}
