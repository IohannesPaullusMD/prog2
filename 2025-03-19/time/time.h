#ifndef TIME
#define TIME

typedef unsigned int uInt; 

typedef struct 
{
    uInt hour;
    uInt minute;
}
Time;

Time newTime(uInt hour, uInt minute);
void displayTime(const Time time);
uInt timeDiffInMinutes(Time t1, Time t2);
uInt convertToMinutes(Time time);
Time convertToTime(uInt minutes);

#endif 