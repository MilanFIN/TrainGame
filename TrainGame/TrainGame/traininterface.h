#ifndef TRAININTERFACE_H
#define TRAININTERFACE_H

#include <QGraphicsPixmapItem>
#include <QObject>

/**
 * @brief The TrainInterface class defines
 *  an interface for handling player's trains
 */
class TrainInterface : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    TrainInterface() = default;
    virtual ~TrainInterface() = default;
};

#endif // TRAININTERFACE_H
