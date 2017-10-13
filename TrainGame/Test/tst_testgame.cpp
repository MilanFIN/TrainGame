#include <QString>
#include <QtTest>



class TestGame : public QObject
{
    Q_OBJECT

public:
    TestGame();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testGame();
};

TestGame::TestGame()
{
}

void TestGame::initTestCase()
{
}

void TestGame::cleanupTestCase()
{
}

void TestGame::testGame()
{
    //Game* game;
    //QVERIFY(game != NULL);
}

QTEST_APPLESS_MAIN(TestGame)

#include "tst_testgame.moc"
