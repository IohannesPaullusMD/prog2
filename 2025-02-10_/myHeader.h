#ifndef MY_HEADER
#define MY_HEADER

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 32

void display(int arr[], int count);
bool insertFront(int arr[], int *count, int item);
bool insertRear(int arr[], int *count, int item);
bool insertAt(int arr[], int *count, int item, int position);
bool insertSorted(int arr[], int *count, int item);
bool deleteFront(int arr[], int *count);
bool deleteRear(int arr[], int *count);
bool deleteItem(int arr[], int *count, int item);
bool deleteAllItem(int arr[], int *count, int item);

int getAverageOfEvenInArr(int arr[], int count);
int getFirstOccurrencePosition(int arr[], int count, int item);
int* getFactors(int arr[], int count, int num, int *returnSize);
int getNumOfPrimes(int arr[], int count);
bool isPrime(int num);
int* getReversed(int arr[], int count, int *returnSize);
int getAverage(int arr[], int count);
int* getAboveAverageNums(int arr[], int count, int *returnSize);

#endif
