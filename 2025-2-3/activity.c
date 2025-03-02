#include <stdio.h>

void insertionSort(int arr[], const int N);
int binarySearch(int arr[], const int N, int key);

int main()
{
    int size = 0;
    int key = -1;
    int keyIndex = -1;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int nums[size];
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &nums[i]);
    }
    
    insertionSort(nums, size);
    
    printf("Enter the key to search: ");
    scanf("%d", &key);
    
    keyIndex = binarySearch(nums, size, key);
    
    if (keyIndex == -1) 
    {
        printf("Key not found\n");
    }
    else
    {
        printf("Key found at position %d\n", keyIndex);
    }
}

int binarySearch(int arr[], int N, int key)
{
    int left = 0;
    int mid;
    int right = N - 1;
    int output = -1;
    
    
    while (left <= right) {
        mid = left + (right - left) / 2;


        if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
            output = mid;
        }
    }

    return (arr[output] == key) ? output + 1 : -1;
}

void insertionSort(int arr[], const int N) {

    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;


        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}


////////////////

