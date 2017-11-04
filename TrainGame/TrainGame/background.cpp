#include "background.h"

Background::Background() {

    QImage kuva(":/kuvat/bg.png");
    //QImage kuvaScaled = kuva.scaled(300, 300, Qt::KeepAspectRatio);
    setPixmap(QPixmap::fromImage(kuva));
    setPos(500,0);
    setZValue(0);

}

void Background::move(int speed) {
    setPos(0, y()+speed);
}
