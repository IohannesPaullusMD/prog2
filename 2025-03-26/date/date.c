#include <stdio.h>
#include <stdlib.h>

#include "date.h"
#include "../string/string.h"

String monthStr[12] = 
{
    "Jan", "Feb", "Mar", 
    "Apr", "May", "Jun",
    "Jul", "Aug", "Sep",
    "Oct", "Nov", "Dec"
};

Date newName(int date, int month, int year)
{
    Date instance = calloc(1, sizeof(_Date));
    if (instance == NULL) { return NULL; }

    instance->date = date;
    instance->month = month;
    instance->year = year;

    return instance;
}

void displayName(Date date) 
{
    printf
    (
        "%02d %s %04d",
        date->date,
        monthStr[date->month - 1],
        date->year
    );
}

int compareDates(Date date1, Date date2)
{
    if (date1->year < date2->year) { return -1; }
    if (date1->year > date2->year) { return 1; }
    if (date1->month < date2->month) { return -1; }
    if (date1->month > date2->month) { return 1; }
    if (date1->date < date2->date) { return -1; }
    if (date1->date > date2->date) { return 1; }
    // else
    return 0;
}
