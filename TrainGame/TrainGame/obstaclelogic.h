#ifndef OBSTACLELOGIC_H
#define OBSTACLELOGIC_H

#include <QGraphicsScene>
#include <memory>
#include <vector>
#include <QObject>

#include "obstacleinterface.h"
#include "boulder.h"
#include "traininterface.h"
#include "playertrain.h"

class ObstacleLogic: public QObject
{
    Q_OBJECT
public:
    /**
     * @brief vastaa esteiden hallinnasta
     * @param qgraphicsscene johon esteet lisätään
     */
    ObstacleLogic(std::shared_ptr<QGraphicsScene> scene);
    /**
     * @brief siirtää esteitä
     * @param esteiden siirtonopeus
     * @pre -
     * @post esteet on siirrettty
     */
    void move();
    /**
     * @brief asettaa esteiden tavoitesiirtonopeuden
     * @param uusi tavoitenopeus
     * @pre -
     * @post tavoitenopeus on muuttunut
     */
    void setSpeed(int newSpeed);
    /**
     * @brief vaihtaa esteiden siirtosuuntaa
     * @pre -
     * @post tavoitesuunta on muuttunut
     */
    void changeDirection();
    /**
     * @brief luo obstaclefactoryn avulla esteen
     * @pre -
     * @post uusi este lisätty sceneen
     */
    void spawnObstacle(QList<QString> stations, QString trackCode, QList<QString> stationNames, bool harmful);
    /**
     * @brief poistaa sijainnin lähellä olevat esteet
     * @param sijainti y-akselilla
     * @pre -
     * @post läheiset esteet poistettu scenestä ja unohdettu logiikasta
     */
    void removeNearbyObjects(int location);
    /**
     * @brief tarkistaa junan ja esteiden törmäyksen
     * @param juna, jonka suhteen törmäyksiä tarkistetaan
     * @pre juna on lisätty pelialueelle
     * @post törmänneet esteet poistettu
     * @return vastaanotetun vahingon määrä
     */
    int checkCollision(std::shared_ptr<PlayerTrain> train); //returns amount of damage
    /**
     * @brief kertoo seuraavan esteen tavoite-etäisyyden
     * @post tavoite-etäisyys on kasvanut yhdellä
     * @return tavoite-etäisyys
     */
    int getNextDistance();

    void addObstacleToScene(QString next, QString previous, QString track);

    void getObstacleLocation(QString &prev, QString &next, bool &harmful);
    void crash();

signals:
    void obstacleRemoved(int fameReward, int moneyReward);
    void obstacleCreated(QString stations, QString track, QString threatLevel);
private:

    //movement related
    float speed_ = 0;
    float goalSpeed_;
    bool forward_ = true;
    float previousSpeed_;
    float accel_ = 1;

    //other
    std::shared_ptr<QGraphicsScene> scene_;
    std::shared_ptr<ObstacleInterface> obstacle_;

    bool inScene_ = false;
    QString obstacleStartStation_;//stationcode
    QString obstacleEndStation_;
    QString ObstacleTrackCode_;
    int nextObstacleDistance_ = 20;
    bool harmful_ = false;

};

#endif // OBSTACLELOGIC_H
