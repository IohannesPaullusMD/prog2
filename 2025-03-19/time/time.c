#include <stdio.h>
#include <stdlib.h>

#include "time.h"

Time newTime(uInt hour, uInt minute)
{
    Time time;
    time.hour = hour;
    time.minute = minute;
    return time;
}

void displayTime(const Time time)
{
    printf("[%02d:%02d]\n", time.hour, time.minute);
}

uInt timeDiffInMinutes(Time t1, Time t2)
{
    uInt t1Mins = convertToMinutes(t1);
    uInt t2Mins = convertToMinutes(t2);
    return abs(t1Mins - t2Mins);
}

uInt convertToMinutes(Time time)
{
    return time.minute + (time.hour * 60);
}

Time convertToTime(uInt minutes)
{
    return newTime(minutes / 60, minutes % 60);
}
