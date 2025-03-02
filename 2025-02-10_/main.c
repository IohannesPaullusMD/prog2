#include "myHeader.h"

int main()
{
    int arr[MAX_LEN] = {1,2,4,5};
    int count = 4;
    display(arr, count);
    insertSorted(arr, &count, 3);
    display(arr, count);
    deleteFront(arr, &count);
    display(arr, count);

    int choice = 0;
    do 
    {
        
    }
    while (choice != 0);
}
