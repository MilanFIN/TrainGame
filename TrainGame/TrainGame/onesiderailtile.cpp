#include "onesiderailtile.h"

OneSideRailTile::OneSideRailTile(int x, int y)
{
    QImage pic(":/kuvat/rail.png");
    QImage picScaled = pic.scaled(50,80, Qt::KeepAspectRatio);
    setPixmap(QPixmap::fromImage(picScaled));
    setPos(x-26,y);
    setZValue(-1);
}

void OneSideRailTile::move(int speed)
{
    setPos(x(), y()+speed);
}
