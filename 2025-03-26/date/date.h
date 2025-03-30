#ifndef DATE_H
#define DATE_H

typedef struct
{
    int date;
    int month;
    int year;
}
_Date, *Date;

Date newDate(int date, int month, int year);

/**
 * dd Mmm yyyy
 */
void displayDate(Date date);


int compareDates(Date date1, Date date2);

#endif
