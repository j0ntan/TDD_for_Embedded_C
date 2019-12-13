#ifndef TimeService_H
#define TimeService_H

typedef struct Time
{
    int minuteOfDay;
    int dayOfWeek;
} Time;

void TimeService_Create(void);
void TimeService_Destroy(void);
void TimeService_GetTime(Time *);

#endif /* TimeService_H */
