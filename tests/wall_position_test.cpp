#include <QtTest/QtTest>
#include <set>
#include <utility>

#include "wall_position_test.h"
#include "wall_position_t.h"

void wall_position_test::equaltyTest_data()
{
#if 0
    QTest::addColumn<wall_position_t>("lhs");
    QTest::addColumn<wall_position_t>("rhs");
    QTest::addColumn<bool>("result");

    QTest::newRow("(0,0) == (0,1)") << wall_position_t::wall_position_with(location_t(0,0), location_t(0,1)) <<
                                       wall_position_t::wall_position_with(location_t(0,0), location_t(0,1)) <<
                                       false;

    QTest::newRow("(1,0) == (0,1)") << wall_position_t::wall_position_with(location_t(1,0), location_t(0,1)) <<
                                       wall_position_t::wall_position_with(location_t(1,0), location_t(0,1)) <<
                                       false;

    QTest::newRow("(-1,0) == (0,-1)") << wall_position_t::wall_position_with(location_t(-1,0), location_t(0,-1)) <<
                                         wall_position_t::wall_position_with(location_t(-1,0), location_t(0,-1)) <<
                                         false;

    QTest::newRow("(-1,0) == (-1,0)") << wall_position_t::wall_position_with(location_t(-1,0), location_t(-1,0)) <<
                                         wall_position_t::wall_position_with(location_t(-1,0), location_t(-1,0)) <<
                                         true;
#endif
}

void wall_position_test::equaltyTest()
{
#if 0
    QFETCH(wall_position_t, lhs);
    QFETCH(wall_position_t, rhs);
    QFETCH(bool, expected_result);

    QVERIFY( (lhs == rhs) == expected_result );
#else
    const struct test_data_t {
        wall_position_t lhs;
        wall_position_t rhs;
        bool expected_result;
    } test_data[] = {
        {
            wall_position_t(location_t(1,0), location_t(0,1)),
            wall_position_t(location_t(1,0), location_t(0,1)),
            true
        },
        {
            wall_position_t(location_t(1,1), location_t(1,2)),
            wall_position_t(location_t(1,0), location_t(1,1)),
            false
        },
        {
            wall_position_t(location_t(-1,0), location_t(-1,1)),
            wall_position_t(location_t(0,-1), location_t(1,-1)),
            false
        },
        {
            wall_position_t(location_t(10,10), location_t(10,11)),
            wall_position_t(location_t(10,11), location_t(10,10)),
            true
        }
    };

    const int num_locations = sizeof(test_data)/sizeof(*test_data);

    for(int i = 0; i < num_locations; ++i) {
        wall_position_t lhs = test_data[i].lhs;
        wall_position_t rhs = test_data[i].rhs;
        bool expected_res = test_data[i].expected_result;
        bool res = (rhs == lhs);

        qDebug("{(%d,%d);(%d,%d)} == {(%d,%d);(%d,%d)}",
               lhs.first.x(), lhs.first.y(), lhs.second.x(), lhs.second.y(),
               rhs.first.x(), rhs.first.y(), rhs.second.x(), rhs.second.y());
        QVERIFY( expected_res == res );
    }
#endif
}

void wall_position_test::addingWallPositionToSetTest()
{
    using std::set;
    using std::pair;

    typedef pair<set<wall_position_t>::iterator, bool> insert_ret_t;

    const int n = 5;
    std::set<wall_position_t> s;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            wall_position_t wp = wall_position_t(location_t(i,j), location_t(j,i));

            insert_ret_t insert_ret = s.insert(wp);

            qDebug("insert( (%d,%d); (%d,%d) ) == %s",
                   wp.first.x(), wp.first.y(),
                   wp.second.x(), wp.second.y(),
                   insert_ret.second ? "OK" : "FAILED");
        }
    }

    qDebug("%d == %d", s.size(), n*n);
    QVERIFY(s.size() == n*n);
}

void wall_position_test::addingLocationsToSetTest()
{
    using std::set;
    using std::pair;

    typedef set<location_t> location_set;
    typedef pair<location_set::iterator, bool> insert_ret_t;

    const int w = 4;
    const int h = 4;

    location_set s;

    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            location_t l(i,j);
            insert_ret_t ret = s.insert(l);

            qDebug("insert (%d,%d) == %s",
                   i,j,
                   ret.second ? "OK":"FAILED");
        }
    }

    QVERIFY(s.size() == w*h);
}

void wall_position_test::addingLocationsToMultisetTest()
{
    using std::multiset;
    using std::pair;

    typedef multiset<location_t> location_set;
    typedef pair<location_set::iterator, bool> insert_ret_t;

    const int w = 4;
    const int h = 4;

    location_set s;

    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            s.insert(location_t(i,j));
        }
    }

    QVERIFY(s.size() == w*h);

    const location_t bad_locations[] = {
        location_t(1,0), location_t(2,0), location_t(2,1)
    };
    const int num_bad_locations = sizeof(bad_locations)/sizeof(*bad_locations);

    for (int i = 0; i < num_bad_locations; ++i) {
        location_set::size_type n = s.erase(bad_locations[i]);

        qDebug("erase (%d,%d) = %d",
               bad_locations[i].x(),
               bad_locations[i].y(),
               n);
    }
}
