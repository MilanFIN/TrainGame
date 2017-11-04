#include "background.h"

Background::Background() {

    QImage kuva(":/kuvat/bg.png");
    //QImage kuvaScaled = kuva.scaled(300, 300, Qt::KeepAspectRatio);
    setPixmap(QPixmap::fromImage(kuva));
    setPos(500,0);

    setZValue(0);

}

void Background::move(int speed) {
<<<<<<< HEAD
    setPos(0, y()+speed);
=======
    setPos(x(), y()+speed);
>>>>>>> d23fc6f108ea175c63bae3223fde2073715f4a5c
}
