#include "LightScheduler.h"
#include "TimeService.h"
#include "LightController.h"

enum
{
    UNUSED = -1, TURN_ON, TURN_OFF
};

typedef struct
{
    int id;
    int minuteOfDay;
    int event;
} ScheduledLightEvent;

static ScheduledLightEvent scheduledEvent;

void LightScheduler_Create(void)
{
    scheduledEvent.id = UNUSED;
}
void LightScheduler_Destroy(void)
{
}

static void scheduleEvent(int id, Day day, int minuteOfDay, int event)
{
    scheduledEvent.minuteOfDay = minuteOfDay;
    scheduledEvent.event = event;
    scheduledEvent.id = id;
}

void LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay)
{
    scheduleEvent(id, day, minuteOfDay, TURN_ON);
}

void LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay)
{
    scheduleEvent(id, day, minuteOfDay, TURN_OFF);
}

void LightScheduler_Wakeup(void)
{
    Time time;
    TimeService_GetTime(&time);

    if (scheduledEvent.id == UNUSED)
        return;

    if (time.minuteOfDay != scheduledEvent.minuteOfDay)
        return;

    if (scheduledEvent.event == TURN_ON)
        LightController_On(scheduledEvent.id);
    else if (scheduledEvent.event == TURN_OFF)
        LightController_Off(scheduledEvent.id);
}
