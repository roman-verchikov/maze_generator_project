#ifndef WALL_POSITION_TEST_H
#define WALL_POSITION_TEST_H

class wall_position_test : public QObject
{
public:
    void equaltyTest_data();
    void equaltyTest();
    void addingWallPositionToSetTest();
    void addingLocationsToSetTest();
    void addingLocationsToMultisetTest();
};

#endif // WALL_POSITION_TEST_H
