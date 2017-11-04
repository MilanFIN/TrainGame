#include "background.h"

Background::Background(int y) {

    QImage kuva(":/kuvat/bg.png");
    //QImage kuvaScaled = kuva.scaled(550, 5000, Qt::KeepAspectRatio);
    setPixmap(QPixmap::fromImage(kuva));
    setPos(-250,y);

    setZValue(-20);

}

void Background::move(int speed) {

    setPos(x(), y()+speed);

}
