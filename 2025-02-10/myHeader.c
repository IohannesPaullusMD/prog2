#include "myHeader.h"

#define FN_NAMES_LEN 16

String functionNames[FN_NAMES_LEN] = {
    "exit",
    "display",
    "insertFront",
    "insertRear",
    "insertAt",
    "insertSorted",
    "deleteFront",
    "deleteRear",
    "deleteItem",
    "deleteAllItemOccurrence",
    "getAverageOfEvenInArr",
    "getFirstOccurrencePosition",
    "getFactors",
    "getNumOfPrimes",
    "getReversed",
    "getAboveAverageNums"
};

String fnName(int index)
{
    return functionNames[index];
}

int* createOccupiedIntArr(int *returnSize)
{
    int temp[] = {1,5,6,8,11,14,23,40};
    const int N = sizeof(temp) / sizeof(temp[0]);
    int *arr = malloc(sizeof(int) * MAX_LEN);
    *returnSize = 0;
    
    if (arr == NULL) 
    {
        return NULL;
    }

    memcpy(arr, temp, sizeof(int) * N);
    *returnSize = N;
    return arr;
}

void displayFnNames()
{
    printf("List of functions you can call:\n");
    for (int i = 0; i < FN_NAMES_LEN; ++i)
    {
        printf("[%d]: %s\n", i, functionNames[i]);
    }
}

void display(int arr[], int count)
{
    printf("{");
    for (int i = 0; i < count; ++i) 
    {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}

bool insertFront(int arr[], int *count, int item)
{
    if (*count >= MAX_LEN) 
    {
        return false;
    }

    for (int i = *count; i > 0; --i) 
    {
        arr[i] = arr[i-1];
    }

    arr[0] = item;
    ++(*count);
    return true;
}

bool insertRear(int arr[], int *count, int item)
{
    if (*count >= MAX_LEN) 
    {
        return false;
    }

    arr[(*count)++] = item;
    return true;
}

bool insertAt(int arr[], int *count, int item, int position)
{
    if (*count >= MAX_LEN || position < 0 || position >= MAX_LEN) 
    {
        return false;
    }

    for (int i = *count; i > position; --i) 
    {
        arr[i] = arr[i-1];
    }

    arr[position] = item;
    ++(*count);
    return true;
}

bool insertSorted(int arr[], int *count, int item)
{
    if (*count >= MAX_LEN) 
    {
        return false;
    }

    int i;
    for (i = *count; i > 0 && arr[i-1] > item; --i) 
    {
        arr[i] = arr[i-1];
    }

    arr[i] = item;
    ++(*count);
    return true;
}

bool deleteFront(int arr[], int *count)
{
    for (int i = 1; i < *count; ++i)
    {
        arr[i-1] = arr[i];
    }

    --(*count);
    return true;
}

bool deleteRear(int arr[], int *count)
{
    if (*count <= 0) 
    {
        return false;
    }

    --(*count);
    return true;
}

bool deleteItem(int arr[], int *count, int item)
{
    int i;
    for (i = 0; i < *count && arr[i] != item; ++i) {}
    for (const int LIMIT = *count - 1; i < LIMIT; ++i)
    {
        arr[i] = arr[i+1];
    }
    return true;
}

bool deleteAllItemOccurrence(int arr[], int *count, int item)
{
    int slow = 0;
    int fast = 0;

    while (fast < *count)
    {
        if (arr[fast] != item)
        {
            arr[slow++] = arr[fast];
        }

        ++fast;
    }

    return true;
}


int getAverageOfEvenNumsInArr(int arr[], int count)
{
    int evenCount = 0;
    int sum = 0;
    
    for (int i = 0; i < count; ++i)
    {
        if (arr[i] == 0)
        {
            sum += arr[i];
            ++evenCount;
        }
    }

    return (sum / evenCount);
}

int getFirstOccurrencePosition(int arr[], int count, int item)
{
    for (int i = 0; i < count; ++i)
    {
        if (arr[i] == item)
        {
            return i;
        }
    }

    return -1;
}

int* getFactors(int arr[], int count, int num, int *returnSize)
{
    int *factors;
    int temp[MAX_LEN];
    int tempCount = 0;
    *returnSize = 0;

    for (int i = 0; i < count; ++i)
    {
        if ((num % arr[i]) == 0)
        {
            temp[tempCount++] = arr[i];
        }
    }

    factors = malloc(sizeof(int) * tempCount);

    if (factors != NULL) 
    {
        memcpy(factors, temp, sizeof(int) * tempCount);
        *returnSize = tempCount;
    }

    return factors;
}

bool isPrime(int num)
{
    int count = 0;

    if (num <= 1)
    {
        return false;
    }

    for (int i = 1; i <= num; ++i)
    {
        if ((num % i) == 0)
        {
            ++count;
        }
    }

    return (count == 2);
}

int getNumOfPrimes(int arr[], int count)
{
    int numOfPrimes = 0;
    for (int i = 0; i < count; ++i)
    {
        if (isPrime(arr[i]))
        {
            ++numOfPrimes;
        }
    }

    return numOfPrimes;
}

int* getReversed(int arr[], int count, int *returnSize)
{
    int *reversed = malloc(sizeof(int) * count);
    *returnSize = 0;

    if (reversed != NULL)
    {
        for (int i = count - 1, j = 0; i > -1; --i)
        {
            reversed[j++] = arr[i];
        }
        *returnSize = count;
    }

    return reversed;
}

int getAverage(int arr[], int count)
{
    int sum = 0;
    for (int i = 0; i < count; ++i)
    {
        sum += arr[i];
    }

    return (sum / count);
}

int* getAboveAverageNums(int arr[], int count, int *returnSize)
{
    int *output;
    int temp[MAX_LEN];
    int tempCount = 0;
    int average = getAverage(arr, count);
    *returnSize = 0;

    for (int i = 0; i < count; ++i)
    {
        if (arr[i] > average)
        {
            temp[tempCount++] = arr[i];
        }
    }

    output = malloc(sizeof(int) * tempCount);

    if (output != NULL)
    {
        memcpy(output, temp, sizeof(int) * tempCount);
        *returnSize = tempCount;
    }

    return output;
}

int getIntFromUser(String prompt)
{
    int input = -1;
    printf("%s", prompt);
    scanf("%d", &input);
    return input;
}
