#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "time_list.h"

bool isPrime(int num);
bool doubleCapacity(ArrayList *list);
bool isPrimeFactor(int test, int num);

ArrayList newList(uInt capacity)
{
    ArrayList list;
    list.arr = calloc(capacity, sizeof(int)); // TODO: need to check for failure
    list.capacity = capacity;
    list.size = 0;
    return list;
}

void displayList(const ArrayList list)
{
    printf("{\n");
    for (int i = 0; i < list.size; ++i) 
    {
        printf("\t");
        displayTime(list.arr[i]);
    }
    printf("}\n");
}


bool addElement(ArrayList *list, Time time)
{
    if (isFull(*list) && !doubleCapacity(list)) 
    {
        return false;
    }

    list->arr[list->size++] = time;
    return true;
}

bool isEmpty(const ArrayList list)
{
    return list.size == 0;
}

bool isFull(const ArrayList list)
{
    return list.size == list.capacity;
}

bool isPrimeFactor(int test, int num)
{
    return isPrime(test) && (num % test) == 0;
}

bool isPrime(int num) {
    if (num <= 1) {
        return false; 
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; 
        }
    }
    
    return true; 
}

bool doubleCapacity(ArrayList *list)
{
    Time *temp = realloc
    (
        list->arr, 
        (list->capacity << 1) * sizeof(Time)
    );

    if (temp == NULL) 
    {
        return false;
    }

    list->arr = temp;
    list->capacity = list->capacity << 1;
    return true;
}

/**
 * index, timeDiff, timePtr 
 */
void sortToNearestTime(Time time, ArrayList *list)
{
    Time temp[list->size];
    uInt timeDiffNdx[list->size];
    uInt timeDiffs[list->size];
    bool isChanged;

    for (int i = 0; i < list->size; ++i)
    {
        timeDiffs[i] = timeDiffInMinutes(time, list->arr[i]);
        timeDiffNdx[i] = i;
        temp[i] = list->arr[i];
    }

    do 
    {
        isChanged = false;
        for (int i = 1, temp; i < list->size; ++i)
        {
            if (timeDiffs[timeDiffNdx[i-1]] > timeDiffs[timeDiffNdx[i]])
            {
                temp = timeDiffNdx[i-1];
                timeDiffNdx[i-1] = timeDiffNdx[i];
                timeDiffNdx[i] = temp;
                isChanged = true;
            }
        }
    }
    while (isChanged);
    
    for (int i = 0; i < list->size; ++i)
    {
        list->arr[i] = temp[timeDiffNdx[i]];
    }
}
