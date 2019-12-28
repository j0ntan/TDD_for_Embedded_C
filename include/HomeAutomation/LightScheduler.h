#ifndef LightScheduler_H
#define LightScheduler_H

enum Day {
    NONE = -1, EVERYDAY = 10, WEEKDAY, WEEKEND,
    SUNDAY = 1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};

enum { LS_OK, LS_TOO_MANY_EVENTS };

typedef enum Day Day;

void LightScheduler_Create(void);
void LightScheduler_Destroy(void);
int LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay);
int LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay);
void LightScheduler_Wakeup(void);

#endif /* LightScheduler_H */
