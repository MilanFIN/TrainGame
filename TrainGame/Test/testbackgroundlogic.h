#ifndef TESTBACKGROUNDLOGIC_H
#define TESTBACKGROUNDLOGIC_H

#include "backgroundlogic.h"
#include "background.h"
#include <QObject>
#include <QGraphicsScene>
#include <QtTest/QtTest>
#include <QTest>

#include <memory>

class TestBackgroundLogic : public QObject
{
    Q_OBJECT
public:
    TestBackgroundLogic(std::shared_ptr<QGraphicsScene> scene);

private slots:
    void initTestCase();
    void testConstructor();

private:
    std::shared_ptr<QGraphicsScene> scene_;
    std::shared_ptr<BackgroundLogic> bgLogic_;
};

#endif // TESTBACKGROUNDLOGIC_H
