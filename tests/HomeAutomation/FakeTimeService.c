#include "FakeTimeService.h"

static Time fakeTime;

void TimeService_Create(void)
{
    fakeTime.minuteOfDay = -1;
    fakeTime.dayOfWeek = -1;
}

void TimeService_Destroy(void)
{
}

void TimeService_GetTime(Time * time)
{
    time->minuteOfDay = fakeTime.minuteOfDay;
    time->dayOfWeek = fakeTime.dayOfWeek;
}
