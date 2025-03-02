#ifndef TIME_H
#define TIME_H

#define MINS_IN_DAY 1440

typedef unsigned short uInt;
typedef long long long64;


/**
 * 0-23 (hours)
 * 0-59 (minutes)
 */
typedef struct
{
    uInt hours;
    uInt minutes;
} _Time, *Time;

Time createTime(uInt hours, uInt minutes);
void displayTime(_Time time);
void displayStandardTime(_Time time);
long64 getTimeDiffInMinutes(_Time t1, _Time t2);
Time getTimeDiffInHoursAndMinutes(_Time t1, _Time t2);
long64 convertToMinutes(_Time time);

#endif
