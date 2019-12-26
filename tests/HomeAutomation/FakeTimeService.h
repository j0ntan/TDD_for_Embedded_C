#ifndef FakeTimeService_H
#define FakeTimeService_H

#include "TimeService.h"

enum {TIME_UNKNOWN = -1};

void FakeTimeService_SetMinute(int);
void FakeTimeService_SetDay(int);

WakeupCallback FakeTimeService_GetAlarmCallback(void);
int FakeTimeService_GetAlarmPeriod(void);

#endif /* FakeTimeService_H */
