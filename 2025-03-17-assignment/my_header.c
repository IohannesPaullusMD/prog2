#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_header.h"

bool isPrime(int num);
bool doubleCapacity(ArrayList *list);
bool isPrimeFactor(int test, int num);

void initList(ArrayList *list, uInt capacity) 
{
    list->arr = calloc(capacity, sizeof(int));
    list->size = 0;
    if (list->arr != NULL)
    {
        list->capacity = (capacity < 1 ? 1 : capacity);
    }
}

ArrayList createList(uInt capacity)
{
    ArrayList list;
    initList(&list, capacity);
    return list;
}



void displayList(const ArrayList list)
{
    printf("{");
    for (int i = 0; i < list.size; ++i) 
    {
        printf
        (
            "%d%s",
            list.arr[i],
            (i+1) < list.size ? ", " : ""
        );
    }
    printf("}\n");
}

/**
 * insert front, if full, 
 * realloc array by doubling the capacity
 */
bool addElement(ArrayList *list, int item)
{
    if (isFull(*list) && !doubleCapacity(list)) 
    {
        return false;
    }

    for (int i = list->size; i > 0; --i)
    {
	    list->arr[i] = list->arr[i-1];
    }

    list->arr[0] = item;
    ++list->size;
    return true;
}

// {} -> 0
// {1} -> 1
// {1,2} -> 1
// {1,2,3} -> 2
bool removeElement(ArrayList *list, int item)
{   
    int i;
    for (i = 0; i < list->size && list->arr[i] != item; ++i);

    if (i < list->size && list->arr[i] != item)
    {
        return false;
    }

    for (++i; i < list->size; ++i)
    {
        list->arr[i-1] = list->arr[i];
    }
    --list->size;
    
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

/**
 * remove all prime factors of value in list.
 * return all removed values.
 */
ArrayList getAllPrimeFactors(ArrayList *list, int value)
{
    ArrayList primeFactors = createList(list->size);
    int newSize = 0;

    for (int i = 0; i < list->size; ++i)
    {
        if (isPrimeFactor(list->arr[i], value))
        {
            primeFactors.arr[primeFactors.size++] = list->arr[i];
        }
        else
        {
            list->arr[newSize++] = list->arr[i];
        }
    }

    list->size = newSize;
    return primeFactors;
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
    int *temp = realloc
    (
        list->arr, 
        (list->capacity << 1) * sizeof(int)
    );

    if (temp == NULL) 
    {
        return false;
    }

    list->arr = temp;
    list->capacity = list->capacity << 1;
    return true;
}
