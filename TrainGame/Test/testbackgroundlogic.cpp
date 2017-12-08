#include "testbackgroundlogic.h"

TestBackgroundLogic::TestBackgroundLogic(std::shared_ptr<QGraphicsScene> scene)
{
    scene_ = scene;
}

void TestBackgroundLogic::initTestCase()
{
    bgLogic_ = std::make_shared<BackgroundLogic>(scene_);
}

void TestBackgroundLogic::testConstructor()
{
    QVERIFY(bgLogic_ != NULL);

    bool itemInScene = false;

    foreach(QGraphicsItem *item, scene_->items())
    {
        if( item->type() == Background::Type )
        {
            itemInScene = true;
        }
    }

    Q_ASSERT(itemInScene == true);
}
