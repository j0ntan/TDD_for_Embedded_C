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
    Day day;
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
    scheduledEvent.day = day;
}

void LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay)
{
    scheduleEvent(id, day, minuteOfDay, TURN_ON);
}

void LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay)
{
    scheduleEvent(id, day, minuteOfDay, TURN_OFF);
}

static void operateLight(ScheduledLightEvent * lightEvent)
{
    if (lightEvent->event == TURN_ON)
        LightController_On(lightEvent->id);
    else if (lightEvent->event == TURN_OFF)
        LightController_Off(lightEvent->id);
}

static void processEventDueNow(Time * time, ScheduledLightEvent * lightEvent)
{
    int reactionDay = lightEvent->day;
    int today = time->dayOfWeek;

    if (lightEvent->id == UNUSED)
        return;
    if (reactionDay != EVERYDAY && reactionDay != today &&
       !(reactionDay == WEEKEND && (today == SATURDAY || today == SUNDAY)))
        return;
    if (lightEvent->minuteOfDay != time->minuteOfDay)
        return;

    operateLight(lightEvent);
}

void LightScheduler_Wakeup(void)
{
    Time time;
    TimeService_GetTime(&time);

    processEventDueNow(&time, &scheduledEvent);
}
