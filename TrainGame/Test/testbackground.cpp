#include "testbackground.h"

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

    bg->move(10);
    Q_ASSERT(bg->x() == -250);
    Q_ASSERT(bg->y() == 60);

    bg->move(-20);
    Q_ASSERT(bg->x() == -250);
    Q_ASSERT(bg->y() == 40);

}
