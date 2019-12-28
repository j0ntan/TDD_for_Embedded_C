#include "LightScheduler.h"
#include "TimeService.h"
#include "LightController.h"
#include "BOOL.h"

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

#define MAX_EVENTS 128
static ScheduledLightEvent scheduledEvent;
static ScheduledLightEvent scheduledEvents[MAX_EVENTS];

void LightScheduler_Create(void)
{
    for (int i = 0; i < MAX_EVENTS; i++)
        scheduledEvents[i].id = UNUSED;

    TimeService_SetPeriodicAlarmInSeconds(60,
            LightScheduler_Wakeup);
}
void LightScheduler_Destroy(void)
{
    TimeService_CancelPeriodicAlarmInSeconds(60,
            LightScheduler_Wakeup);
}

static int scheduleEvent(int id, Day day, int minuteOfDay, int event)
{
    if (id < 0 || id >= MAX_LIGHTS)
        return LS_ID_IS_OUT_OF_BOUNDS;

    for (int i = 0; i < MAX_EVENTS; i++)
    {
        if (scheduledEvents[i].id == UNUSED)
        {
            scheduledEvents[i].minuteOfDay = minuteOfDay;
            scheduledEvents[i].event = event;
            scheduledEvents[i].id = id;
            scheduledEvents[i].day = day;
            return LS_OK;
        }
    }
    return LS_TOO_MANY_EVENTS;
}

int LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay)
{
    return scheduleEvent(id, day, minuteOfDay, TURN_ON);
}

int LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay)
{
    return scheduleEvent(id, day, minuteOfDay, TURN_OFF);
}

void LightScheduler_ScheduleRemove(int id, Day day, int minuteOfDay)
{
    for (int i = 0; i < MAX_EVENTS; i++)
    {
        if (scheduledEvents[i].id == id
         && scheduledEvents[i].day == day
         && scheduledEvents[i].minuteOfDay == minuteOfDay)
         {
             scheduledEvents[i].id = UNUSED;
         }
    }
}

static void operateLight(ScheduledLightEvent * lightEvent)
{
    if (lightEvent->event == TURN_ON)
        LightController_On(lightEvent->id);
    else if (lightEvent->event == TURN_OFF)
        LightController_Off(lightEvent->id);
}

static BOOL DoesLightRespondToday(Time * time, int reactionDay)
{
    int today = time->dayOfWeek;

    if (reactionDay == EVERYDAY)
        return TRUE;
    if (reactionDay == today)
        return TRUE;
    if (reactionDay == WEEKEND && (today == SATURDAY || today == SUNDAY))
        return TRUE;
    if (reactionDay == WEEKDAY && today >= MONDAY && today <= FRIDAY)
        return TRUE;
    return FALSE;
}

static void processEventDueNow(Time * time, ScheduledLightEvent * lightEvent)
{
    int reactionDay = lightEvent->day;

    if (lightEvent->id == UNUSED)
        return;
    if (!DoesLightRespondToday(time, reactionDay))
        return;
    if (lightEvent->minuteOfDay != time->minuteOfDay)
        return;

    operateLight(lightEvent);
}

void LightScheduler_Wakeup(void)
{
    Time time;
    TimeService_GetTime(&time);

    for (int i = 0; i < MAX_EVENTS; i++)
    {
        processEventDueNow(&time, &scheduledEvents[i]);
    }
}
