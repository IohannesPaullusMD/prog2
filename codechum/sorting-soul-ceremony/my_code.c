#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50
#define INT_MIN -2147483648
#define INT_MAX 214748364

void display(int arr[]);
int *sorting_souls(int arr[]);

int main() {
    int list[MAX_SIZE];
    int * sortedSouls;

    printf("Enter number of souls: ");
    scanf("%d", &list[0]);

    printf("Enter soul scores: ");
    for(int i = 1; i <= list[0]; ++i) {
        scanf("%d", &list[i]);
    }

    printf("Initial soul list: ");
    display(list);

    sortedSouls = sorting_souls(list);
    
    printf("Sorted soul list: ");
    display(sortedSouls);
    
    return 0;
}

void display(int arr[]) {
    printf("[");
    for(int i = 1; i <= arr[0]; ++i) {
        printf("%d", arr[i]);
        if(i < arr[0]) {
            printf("|");
        }
    }
    printf("], SOUL COUNT: %d\n", arr[0]);
}

int findSecondMax(int max[])
{
    int firstmax = INT_MIN;
    int secondMax = INT_MIN;

    for (int i = 1; i <= max[0]; ++i)
    {
        if (max[i] > firstmax) 
        {
            secondMax = firstmax;
            firstmax = max[i];
        }
        else if (max[i] > secondMax && max[i] < firstmax)
        {
            secondMax = max[i];
        }
    }
    
    return secondMax;
}

int *sorting_souls(int arr[]) {
    int * output;
    int temp[MAX_SIZE];
    int secondMax = findSecondMax(arr);
    int count = 0;
    int i;

    for (i = 1; i <= arr[0] && arr[i] != secondMax; ++i);
    
    if (arr[0] > 1) {
        for (; i <= arr[0]; ++i)
        {
            temp[count++] = arr[i];
        }   
    }
    output = malloc(sizeof(int) * (count + 1));
    
    if (output != NULL)
    {
        memcpy(output + 1, temp, sizeof(int) * count);
        
        output[0] = count;
    }
    
    return output;
}