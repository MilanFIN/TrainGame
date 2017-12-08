#include "leafpile.h"

LeafPile::LeafPile(int y)
{
    QImage kuva(":/kuvat/leafs.png");
    QImage kuvaScaled = kuva.scaled(100,100,Qt::KeepAspectRatio);
    setPixmap(QPixmap::fromImage(kuvaScaled));
    setPos(-50, y);
    setZValue(1);
}

void LeafPile::move(int speed)
{
    setPos(x(), y()+speed);
}

int LeafPile::getDamage()
{
    return damage_;
}
