#include <QtCore/QString>
#include <QtTest/QtTest>

#include "random_maze_generator.h"
#include "location_t.h"

#include <limits>

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
    QTest::addColumn<int>("width");
    QTest::addColumn<int>("height");

    QTest::newRow("square 10x10") << 10 << 10;
    QTest::newRow("rect 20x10") << 20 << 10;
    QTest::newRow("rect 10x20") << 10 << 20;
    QTest::newRow("invalid rect negative width") << -1 << 20;
    QTest::newRow("invalid rect negative height") << 20 << -1;
    QTest::newRow("invalid zero size") << 0 << 0;
    QTest::newRow("invalid very big size") << std::numeric_limits<int>::max() <<
                                              std::numeric_limits<int>::max();
}

void maze_generator_test::generatorTest()
{
    location_t entrance;
    location_t exit;

    QFETCH(int, width);
    QFETCH(int, height);

    try
    {
        maze *m = random_maze_generator().generate(width, height, entrance, exit);
        QVERIFY(m != 0);
    }
    catch (const std::bad_alloc &ex)
    {
        QFAIL("Caught bad_alloc exception");
    }
    catch (...)
    {
        QFAIL("Caught unknown exception");
    }
}

QTEST_APPLESS_MAIN(maze_generator_test);

#include "maze_generator_test.moc"
