#ifndef ARRAY_LIST
#define ARRAY_LIST

#include <stdbool.h>

typedef unsigned int uInt;

typedef struct
{
    int *arr;
    uInt size;
    uInt capacity;
} ArrayList;

void initList(ArrayList *list, uInt capacity);

ArrayList createList(uInt capacity);

void displayList(const ArrayList list);

/**
 * insert front, if full, 
 * realloc array by doubling the capacity
 */
bool addElement(ArrayList *list, int item);

bool removeElement(ArrayList *list, int item);

bool isEmpty(const ArrayList list);

bool isFull(const ArrayList list);

/**
 * remove all prime factors of value in list.
 * return all removed values.
 */
ArrayList getAllPrimeFactors(ArrayList *list, int value);

#endif
