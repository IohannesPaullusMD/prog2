#include <stdio.h>
#include "my_header.h"

bool isPrime(int num);

void initList(List *list) 
{
    list->count = 0;
    for (int i = 0; i < LEN; list->arr[i++] = 0);
}

List createList()
{
    List list;
    list.count = 0;
    return list;
}

bool insertSorted(List *list, int item)
{
    if (list->count == LEN) 
    {
        return false;
    }

    int i = 0;

    for 
    (
        i = list->count; 
        i > 0 && list->arr[i-1] > item; 
        --i
    )
    {
        list->arr[i] = list->arr[i-1];
    }

    list->arr[i] = item;
    ++list->count;
    return true;
}

void displayList(const List list)
{
    printf("{");
    for (int i = 0; i < list.count; ++i) 
    {
        printf
        (
            "%d%s",
            list.arr[i],
            (i+1) < list.count ? ", " : ""
        );
    }
    printf("}\n");
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
