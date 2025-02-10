#include "myHeader.h"

bool manipulateArray(int arr[], int *count);

int main()
{
    int count = 0;
    int *arr = createOccupiedIntArr(&count);

    while (manipulateArray(arr, &count));
    

    free(arr);
}

bool manipulateArray(int arr[], int *count)
{
    int choice = 0;
    int item = -1;
    int position = -1;
    int size = 0;
    int *output;
    
    system("cls");
    displayFnNames();
    printf("Enter the number of the function you want to call: ");
    scanf("%d", &choice);
    printf("choice: %s\n", fnName(choice));

    switch (choice)
    {
        case 0:
            return false;
        case 1:
            display(arr, *count);
            break;
        case 2:
            item = getIntFromUser("Enter element to insert: ");
            insertFront(arr, count, item);
            break;
        case 3:
            item = getIntFromUser("Enter element to insert: ");
            insertRear(arr, count, item);
            break;
        case 4:
            item = getIntFromUser("Enter element to insert: ");
            position = getIntFromUser("Enter position to insert at: ");
            insertAt(arr, count, item, position);
            break;
        case 5:
            item = getIntFromUser("Enter element to insert: ");
            insertSorted(arr, count, item);
            break;
        case 6:
            deleteFront(arr, count);
            break;
        case 7:
            deleteRear(arr, count);
            break;
        case 8:
            item = getIntFromUser("Enter element to delete: ");
            deleteItem(arr, count, item);
            break;
        case 9:
            item = getIntFromUser("Enter element to delete: ");
            deleteAllItemOccurrence(arr, count, item);
            break;
        case 10:
            printf("Average of even nums in array: %d\n", getAverageOfEvenNumsInArr(arr, *count));
            break;
        case 11:
            item = getIntFromUser("Enter element to find: ");
            position = getFirstOccurrencePosition(arr, *count, item);
            printf("First occurrence of %d is at index %d\n", item, position);
            break;
        case 12:
            item = getIntFromUser("Enter the element to find its factors: ");
            printf("Factors of %d: ", item);
            output = getFactors(arr, *count, item, &size);
            display(output, size);
            break;
        case 13:
            printf("Number of primes in arrays is %d\n", getNumOfPrimes(arr, *count));
            break;
        case 14:
            output = getReversed(arr, *count, &size);
            display(output, size);
            break;
        case 15:
            printf("Nums above average in array: ");
            output = getAboveAverageNums(arr, *count, &size);
            display(output, size);
            break;
        default:
            printf("Invalid Input");
            break;
    }

    system("pause");
    return true;
}
