#ifndef TESTPLAYERLOGIC_H
#define TESTPLAYERLOGIC_H

#include "playerlogic.h"
#include <QObject>

class TestPlayerLogic : public QObject
{
    Q_OBJECT
public:
    explicit TestPlayerLogic(std::shared_ptr<QGraphicsScene> scene);

private Q_SLOTS:
    void defaultConstrcutor();
    void testVariant(PlayerLogic *player);
    void buyTrain();


private:
    std::shared_ptr<QGraphicsScene> scene_;

};

#endif // TESTPLAYERLOGIC_H
