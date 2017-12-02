#ifndef TESTPLAYERLOGIC_H
#define TESTPLAYERLOGIC_H


#include "playerlogic.h"
#include <QObject>

class TestPlayerLogic : public QObject
{
    Q_OBJECT
public:
    explicit TestPlayerLogic();

private Q_SLOTS:
    void defaultConstrcutor();
    void testVariant(PlayerLogic *player);

    void buyTrain();
signals:

public slots:
};

#endif // TESTPLAYERLOGIC_H
