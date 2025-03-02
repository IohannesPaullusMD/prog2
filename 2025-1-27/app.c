#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DELIMETER 0
#define MAX 10

int * getPositives(int nums[]);
void displayNums(int nums[]);
int * getFactors(int nums[], int factorOf);
int * combineArrays(int nums1[], int nums2[]);

int main()
{
    int x = 16;
    int nums[MAX] = {2, -1, 7, 8, -3, DELIMETER};
    int * positiveList = NULL;
    int * factorsOfX = NULL;
    int * combinedArray = NULL;

    printf("Original List: ");
    displayNums(nums);


    positiveList = getPositives(nums);
    printf("Positive List: ");
    displayNums(positiveList);


    factorsOfX = getFactors(nums, x);
    printf("Factors of %d: ", x);
    displayNums(factorsOfX);

    
    combinedArray = combineArrays(positiveList, factorsOfX);
    printf("Combined Array: ");
    displayNums(combinedArray);

    free(positiveList);
    free(factorsOfX);
    free(combinedArray);

    return 0;
}


int * combineArrays(int nums1[], int nums2[])
{
    int * combinedArray = NULL;
    int temp[MAX];
    int count = 0;

    for (count = 0; nums1[count] != DELIMETER; ++count)
    {
        temp[count] = nums1[count];
    }

    for (int i = 0; nums2[i] != DELIMETER; ++i)
    {
        temp[count++] = nums2[i];
    }

    temp[count++] = DELIMETER;
    combinedArray = malloc(sizeof(int) * count);

    if (combinedArray != NULL) memcpy(combinedArray, temp, (sizeof(int) * count));

    return combinedArray;
}

void displayNums(int nums[])
{
    printf("{");

    for (int i = 0; nums[i] != DELIMETER; ++i)
    {
        printf("%d%s", nums[i], (nums[i+1] != DELIMETER ? ",": ""));
    }

    printf("}\n");
}

int * getFactors(int nums[], int factorOf)
{
    int * factors = NULL;
    int temp[MAX];
    int count = 0;

    for (int i = 0; nums[i] != DELIMETER; ++i)
    {
        if ((factorOf % nums[i]) == 0) temp[count++] = nums[i];
    }

    temp[count++] = DELIMETER;
    factors = malloc(sizeof(int) * count);

    if (factors != NULL) memcpy(factors, temp, (sizeof(int) * count));
    
    return factors;
}

int * getPositives(int nums[])
{
    int * positives = NULL; 
    int temp[MAX];
    int count = 0;

    for (int i = 0; nums[i] != DELIMETER; ++i)
    {
        if (nums[i] > 0) temp[count++] = nums[i]; 
    }

    temp[count++] = DELIMETER;
    positives = malloc(sizeof(int) * count);

    if (positives != NULL) memcpy(positives, temp, (sizeof(int) * count));

    return positives;
}
