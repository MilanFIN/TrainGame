#ifndef TESTBACKGROUND_H
#define TESTBACKGROUND_H

#include "background.h"
#include <QObject>
#include <QtTest/QtTest>
#include <QTest>

#include <memory>

class TestBackground : public QObject
{
    Q_OBJECT

private slots:

    void testBackground();
    void testMove();
};

#endif // TESTBACKGROUND_H
