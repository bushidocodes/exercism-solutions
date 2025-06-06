#include "clock.h"
#include <stdio.h>
#include <string.h>

static inline int calculate_hour(int hour, int minute)
{
    hour += (minute / 60);
    // We are rounding the negative minutes down, so decrement
    // if not exactly on the hour
    if (minute < 0 && minute % 60 != 0)
        hour -= 1;
    hour %= 24;
    if (hour < 0)
        hour += 24;
    return hour;
}

static inline int calculate_minute(int minute)
{
    minute %= 60;
    if (minute < 0)
        minute += 60;
    return minute;
}

clock_t clock_create(int hour, int minute)
{
    clock_t clock;
    sprintf(clock.text, "%02d:%02d", calculate_hour(hour, minute), calculate_minute(minute));
    return clock;
}

clock_t clock_add(clock_t clock, int minute_add)
{
    int hour, minute;
    sscanf(clock.text, "%2d:%2d", &hour, &minute);
    minute += minute_add;
    sprintf(clock.text, "%02d:%02d", calculate_hour(hour, minute), calculate_minute(minute));
    return clock;
}
clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    int hour, minute;
    sscanf(clock.text, "%2d:%2d", &hour, &minute);
    minute -= minute_subtract;
    sprintf(clock.text, "%02d:%02d", calculate_hour(hour, minute), calculate_minute(minute));
    return clock;
}
bool clock_is_equal(clock_t a, clock_t b)
{
    return strcmp(a.text, b.text) == 0;
}