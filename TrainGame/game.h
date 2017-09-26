#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsScene>
#include <memory>

//sisältää pelilogiikan
class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(std::shared_ptr<QGraphicsScene> scene, QObject *parent = nullptr);

signals:

public slots:
private:
    void setSpeed(int newSpeed);
};

#endif // GAME_H
