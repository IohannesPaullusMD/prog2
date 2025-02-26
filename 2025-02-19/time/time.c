#include <assert.h>
#include <stdlib.h>
#include "time.h"
#include "../error/error.h"

Time createTime(uInt hours, uInt minutes)
{
    assert(hours < 24 || minutes < 60);
    Time time = malloc(sizeof(_Time));

    if (time != NULL)
    {
        time->hours = hours;
        time->minutes = minutes;
    }
    return time;
}

void displayTime(_Time time)
{
    // printf(
    //     "%s%u:%s%u\n",
    //     (time.hours > 9) ? "" : "0",
    //     time.hours,
    //     (time.minutes > 9) ? "" : "0",
    //     time.minutes
    // );
    printf("%02d:%02d\n",time.hours, time.minutes);
}

void displayStandardTime(_Time time)
{
    
    printf
    (
        "%s%u:%s%u %s\n",
        (time.hours > 9) ? "" : "0",
        (time.hours > 12) ? (time.hours % 12) : time.hours,
        (time.minutes > 9) ? "" : "0",
        time.minutes,
        ((time.hours == 12) ? "NN" :
            (time.hours > 12) ? "PM" : "AM")
    );
    printf("%02d:%02d %s\n", 
        (time.hours > 12) ? (time.hours % 12) : time.hours, 
        time.minutes,
        );
}

long64 convertToMinutes(_Time time)
{
    long64 minutes = time.minutes;
    minutes += (time.hours * 60);
    return minutes;
}

long64 getTimeDiffInMinutes(_Time t1, _Time t2)
{
    long64 mins1, mins2, diff;
    mins1 = convertToMinutes(t1);
    mins2 = convertToMinutes(t2);
    diff = mins2 - mins1;

    return (diff < 0) ? -diff : diff;
}

Time getTimeDiffInHoursAndMinutes(_Time t1, _Time t2)
{
    long64 minsDiff = getTimeDiffInMinutes(t1, t2);
    return createTime
    (
        (minsDiff / 60), 
        (minsDiff % 60)
    );
}

