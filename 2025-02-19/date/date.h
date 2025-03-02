#ifndef DATE_H
#define DATE_H

#define isLeapYear(year) ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))

typedef unsigned short uShort;
typedef unsigned int uInt;

/** {day, month, year} */
typedef struct
{
    uShort day;
    uShort month;
    uShort year;
} _Date, *Date;

_Date createDate
(
    uShort day,
    uShort month,
    uShort year
);

/** MMM-DD-YYYY */
void displayDate(_Date date);

_Date getDiffInDays(_Date d1, _Date d2);

uShort daysInMonth
(
    uShort month, 
    uShort year
);

uShort daysInMonth(uShort month, uShort year);
uInt daysSinceYearStart(_Date date);
uInt totalDays(_Date date);

#endif
