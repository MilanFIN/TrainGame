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

void TestBoulder::testBoulder() {

    std::shared_ptr<Boulder> boulder = std::make_shared<Boulder>(50);
    QVERIFY(boulder != NULL);
    Q_ASSERT(boulder->x() == -50);
    Q_ASSERT(boulder->y() == 50);

}

void TestBoulder::testMove() {

    std::shared_ptr<Boulder> boulder = std::make_shared<Boulder>(50);
    boulder->move(50);
    Q_ASSERT(boulder->x() == -50);
    Q_ASSERT(boulder->y() == 100);
}

#include "testboulder.moc"
