#ifndef PLAYERTRAIN_H
#define PLAYERTRAIN_H

#include <QGraphicsPixmapItem>
#include "traininterface.h"

/**
 * @brief The PlayerTrain class defines a playertrain graphics item
 */
class PlayerTrain: public TrainInterface
{
    Q_OBJECT
public:
    /**
     * @brief PlayerTrain constructor
     * @param name name of the train
     * @param shape maximum health of the train
     * @param price price of the train
     * @param speed speed multiplier for the train
     * @param repairCost cost of repairing the train to full health
     * @param imagePath path to the image of the train
     */
    PlayerTrain(QString name, short shape, unsigned short price, double speed, unsigned short repairCost, QString imagePath);

    /**
     * @brief getName returns the name of the train
     * @return name as QString
     */
    QString getName();

    /**
     * @brief getSpeed returns the speed multiplier
     * @return speed multiplier
     */
    double getSpeed() const;
    /**
     * @brief getPrice returns the price
     * @return price of the train
     */
    unsigned short getPrice() const;
    /**
     * @brief getShape returns the shape of the train
     * @return current shape
     */
    short getShape() const;
    /**
     * @brief getRepairCost cost of repairing the train
     * @return cost of repairing
     */
    unsigned short getRepairCost() const;

    /**
     * @brief isAbleToPlay gives info if the train is allowed to play
     * @return true/false statement on playability
     */
    bool isAbleToPlay() const;
    /**
     * @brief isOwned tells if player own's the train
     * @return status of player owning the train
     */
    bool isOwned() const;
    /**
     * @brief getAbsoluteShape returns maximum health of the train
     * @return max health
     */
    short getAbsoluteShape() const;
    /**
     * @brief repairTrain repairs the train
     * @post train healt = max health
     */
    void repairTrain();

    /**
     * @brief takeDamage reduces the amount of health the train has
     * @param dmgAmount damage taken
     * @return new shape after taken damage
     * @post shape has changed
     */
    unsigned short takeDamage(int dmgAmount);
    /**
     * @brief setPlayable set's the train as playable
     * @post train is playable
     */
    void setPlayable();
    /**
     * @brief setOwned sets if the train is owned by the player
     * @post owning status is changed to the opposite as before
     */
    void setOwned();

    /**
     * @brief setPixmapToShow sets the pixmap for the train
     * @pre the image specified in the constructor exists
     * @post pixmap has been set
     */
    void setPixmapToShow();
    /**
     * @brief getSpeed gets the speed multiplier of the train
     * @return double speed multiplier
     */
    double getSpeed();

signals:
    void message(QString msg);

private:


    QString name_;
    short shape_;
    unsigned short const price_;
    double const speed_;
    unsigned short repairCost_;
    QImage trainImage_;
    short const absoluteShape_;

    bool isPlayable_;
    bool isOwned_;

    void invariant();

};

#endif // PLAYERTRAIN_H
