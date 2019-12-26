#ifndef TimeService_H
#define TimeService_H

typedef void (*WakeupCallback)(void);

typedef struct Time
{
    int minuteOfDay;
    int dayOfWeek;
} Time;

void TimeService_Create(void);
void TimeService_Destroy(void);
void TimeService_GetTime(Time *);

void TimeService_SetPeriodicAlarmInSeconds(
    int seconds, WakeupCallback);
void TimeService_CancelPeriodicAlarmInSeconds(
    int seconds, WakeupCallback);

#endif /* TimeService_H */
