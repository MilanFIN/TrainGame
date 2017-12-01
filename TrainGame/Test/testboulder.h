#ifndef TESTBOULDER_H
#define TESTBOULDER_H

#include "boulder.h"
#include <QObject>
#include <QtTest/QtTest>
#include <QTest>

#include <memory>

class TestBoulder : public QObject
{
    Q_OBJECT
private slots:

    void testBoulder();
    void testMove();
};


#endif // TESTBOULDER_H
