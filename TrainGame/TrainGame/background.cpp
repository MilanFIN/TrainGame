#include "background.h"

Background::Background(int y) {

    QImage kuva(":/kuvat/bg.png");
    setPixmap(QPixmap::fromImage(kuva));
    setPos(-250,y);
    setZValue(-20);
}

void Background::move(int speed) {

    setPos(x(), y()+speed);
}
