#include <stdio.h>
#include "date.h"
#include "../string/myString.h"
#include "../error/error.h"


_Date createDate
(
    uShort day, 
    uShort month, 
    uShort year
)
{   
    if (year == 0 || year > 9999)
    {
        throwError("invalid year");
    } 
    else if (month == 0 || month > 12)
    {
        throwError("invalid month");
    }
    else if (day == 0 || day > daysInMonth(month, year))
    {
        throwError("invalid day");
    } 

    return (_Date) {day, month, year};
}

void displayDate(_Date date)
{   
    static String months[] = 
    {
        "Jan", "Feb", "Mar", "Apr",
        "May", "Jun", "Jul", "Aug",
        "Sep", "Oct", "Nov", "Dec"
    };

    printf(
        "%s-%s%hu-%hu\n", 
        months[date.month -1],
        (date.day > 9 ? "" : "0"),
        date.day,
        date.year
    );
}

uShort daysInMonth(uShort month, uShort year) 
{
    switch (month) {
        case 1: return 31;
        case 2: return isLeapYear(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0; 
    }
}

uInt daysSinceYearStart(_Date date) {
    uInt days = 0;
    for (uShort month = 1; month < date.month; month++) {
        days += daysInMonth(month, date.year);
    }
    days += date.day;
    return days;
}

uInt totalDays(_Date date) {
    uInt days = (date.year * 365) + (date.year / 4) - (date.year / 100) + (date.year / 400);
    days += daysSinceYearStart(date);
    return days;
}

_Date getDiffInDays(_Date d1, _Date d2)
{
    int days1 = totalDays(d1);
    int days2 = totalDays(d2);

    int diff = days2 - days1;
    if (diff < 0) {
        diff = -diff;
    }

    return (_Date) {diff, 0, 0};
}
