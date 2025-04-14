#ifndef DATE_H
#define DATE_H

typedef struct
{
    int date;
    int month;
    int year;
}
Date;

Date createDate(int date, int month, int year);

/**
 * dd Mmm yyyy
 */
void displayDate(Date date);

/**
* returns 1 if date1 > date2
* returns -1 if date1 < date2
* returns 0 if date1 == date2
*/
int compareDates(Date date1, Date date2);

#endif
