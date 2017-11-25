#include "background.h"
#include <QObject>
#include <QtTest/QtTest>
#include <QTest>

#include <memory>

class TestBackground : public QObject
{
    Q_OBJECT

private Q_SLOTS:

    void testBackground();
    void testMove();
};

void TestBackground::testBackground()
{
    std::shared_ptr<Background> bg = std::make_shared<Background>(50);
    QVERIFY(bg != NULL);
    Q_ASSERT(bg->x() == -250);
    Q_ASSERT(bg->y() == 50);
}

void TestBackground::testMove()
{

    std::shared_ptr<Background> bg = std::make_shared<Background>(50);

    Q_ASSERT(bg->x() == -250);
    Q_ASSERT(bg->y() == 50);

    bg->move(10);
    Q_ASSERT(bg->x() == -250);
    Q_ASSERT(bg->y() == 60);

}

#include "testbackground.moc"
