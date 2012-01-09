#include <QtCore/QString>
#include <QtTest/QtTest>

#include <limits>

#include "location_t.h"
#include "maze.h"
#include "random_maze_generator.h"
#include "wall_position_test.h"

class maze_generator_test : public QObject
{
    Q_OBJECT

public:
    maze_generator_test();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void generatorTest_data();
    void generatorTest();

    void runWallPositionTests();
};

maze_generator_test::maze_generator_test()
{
}

void maze_generator_test::initTestCase()
{
}

void maze_generator_test::cleanupTestCase()
{
}

void maze_generator_test::generatorTest_data()
{
#if 0
    QTest::addColumn<int>("width");
    QTest::addColumn<int>("height");

    QTest::newRow("square 10x10") << 10 << 10;
    QTest::newRow("rect 20x10") << 20 << 10;
    QTest::newRow("rect 10x20") << 10 << 20;
    QTest::newRow("zero size maze 0x0") << 0 << 0;
    QTest::newRow("Invalid size -1x-1") << -1 << -1;
#endif
}

void maze_generator_test::generatorTest()
{
#if 0
    location_t entrance;
    location_t exit;

    QFETCH(int, width);
    QFETCH(int, height);

    try
    {
        std::auto_ptr<maze> m(random_maze_generator().
                              generate(width,
                                       height,
                                       entrance,
                                       exit));

        for (int i = 0; i < width*height; ++i)
        {
            m->next_step();
        }

        for (int i = 0; i < width*height; ++i)
        {
            m->prev_step();
        }

        QVERIFY(m.get() != 0);
    }
    catch (const std::bad_alloc &ex)
    {
        QFAIL("Caught bad_alloc exception");
    }
    catch (...)
    {
        QFAIL("Caught unknown exception");
    }
#endif
}

void maze_generator_test::runWallPositionTests()
{
    wall_position_test wpt;

    wpt.equaltyTest();
    wpt.addingWallPositionToSetTest();
    wpt.addingLocationsToMultisetTest();
}

QTEST_APPLESS_MAIN(maze_generator_test);

#include "maze_generator_test.moc"
