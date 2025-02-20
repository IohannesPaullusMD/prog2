
#include "time.h"
#include "../error/error.h"

_Time createTime(uInt hours, uInt minutes)
{
    if (hours >= 24 || minutes >= 60)
    {
        throwError("invalid arguments");
    }

    return (_Time) {hours, minutes};
}

void displayTime(_Time time)
{
    printf(
        "%s%u:%s%u\n",
        (time.hours > 9) ? "" : "0",
        time.hours,
        (time.minutes > 9) ? "" : "0",
        time.minutes
    );
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

    if (diff < 0)
    {
        diff = -diff;
    }

    return diff;
}

_Time getTimeDiffInHoursAndMinutes(_Time t1, _Time t2)
{
    long64 minsDiff = getTimeDiffInMinutes(t1, t2);
    return (_Time) 
    {
        (minsDiff / MINS_IN_DAY), 
        (minsDiff % MINS_IN_DAY)
    };
}

