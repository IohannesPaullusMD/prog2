#ifndef ARRAY_LIST
#define ARRAY_LIST

#include <stdbool.h>

#define LEN 20

typedef struct
{
    int arr[LEN];
    int count;
} List;

void initList(List *list);
List createList();
bool insertSorted(List *list, int item);
void displayList(const List list);
List getPrimeNumbers(List *list);

#endif
