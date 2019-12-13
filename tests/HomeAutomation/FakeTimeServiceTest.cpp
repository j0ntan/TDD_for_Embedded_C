#include "CppUTest/TestHarness.h"

extern "C"
{
}

TEST_GROUP(FakeTimeService)
{
    void setup()
    {
    }
    void destroy()
    {
    }
};

TEST(FakeTimeService, Create)
{
    Time time;
    TimeService_GetTime(&time);

    LONGS_EQUAL(TIME_UNKNOWN, time.minuteOfDay);
    LONGS_EQUAL(TIME_UNKNOWN, time.dayOfWeek);
}
