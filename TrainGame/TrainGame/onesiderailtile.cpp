#include "onesiderailtile.h"

OneSideRailTile::OneSideRailTile(int x, int y)
{
    QImage kuva(":/kuvat/rail.png");
    setPixmap(QPixmap::fromImage(kuva));
    setPos(x-15,y);
    setZValue(-1);
}

void OneSideRailTile::move(int speed)
{
    setPos(x(), y()+speed);
}
