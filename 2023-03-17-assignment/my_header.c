#include <stdio.h>
#include <stdlib.h>
#include "my_header.h"

bool isPrime(int num);

void initList(ArrayList *list, uInt capacity) 
{
    list->arr = calloc(capacity, sizeof(int));
    list->size = 0;
    if (list->arr != NULL)
    {
        list->capacity = capacity;
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
    if (list->size == list->capacity) 
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

        list->capacity = list->capacity << 1;
    }
    
}

// TODO: remove primes in list then return the removed items
List getPrimeNumbers(List *list)
{
    List notPrimes = createList();
    int newCount = 0;

    for (int i = 0; i < list->count; ++i)
    {
        if (isPrime(list->arr[i]))
        {
            list->arr[newCount++] = list->arr[i];
        }
        else
        {
            notPrimes.arr[notPrimes.count++] = list->arr[i];
        }
    }

    list->count = newCount;
    return notPrimes;
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
