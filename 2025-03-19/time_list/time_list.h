#include <stdio.h>
#include <stdbool.h>

#include "../time/time.h"

typedef struct
{
    Time *arr;
    uInt size;
    uInt capacity;
} ArrayList;

ArrayList newList(uInt capacity);

void displayList(const ArrayList list);

bool addElement(ArrayList *list, Time time);

bool isEmpty(const ArrayList list);

bool isFull(const ArrayList list);

void sortToNearestTime(Time time, ArrayList *list);
