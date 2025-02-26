#include <stdio.h>

void insertionSort(int arr[], int indices[], int N);
int binarySearch(int arr[], int indices[], int N, int key);

int main()
{
    int size = 0;
    int key = -1;
    int keyIndex = -1;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int nums[size];
    int indices[size];
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &nums[i]);
        indices[i] = i;
    }
    
    insertionSort(nums, indices, size);
    
    printf("Enter the key to search: ");
    scanf("%d", &key);
    
    keyIndex = binarySearch(nums, indices, size, key);
    
    for (int i = 0; i < size; ++i)
    {
        printf("%d\n", nums[i]);
    }
    
    if (keyIndex == -1) 
    {
        printf("Key not found\n");
    }
    else
    {
        printf("Key found at position %d\n", keyIndex);
    }
}

int binarySearch(int arr[], int indices[], int N, int key)
{
    int left = 0;
    int mid;
    int right = N - 1;
    int output = -1;
    
    
    while (left <= right) {
        mid = left + (right - left) / 2;


        if (arr[indices[mid]] < key)
        {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
            output = indices[mid];
        }
    }

    return (arr[indices[output]] == key) ? output + 1 : -1;
}

void insertionSort(int arr[], int indices[], const int N) {

    for (int i = 1; i < N; i++) {
        int key = indices[i];
        int j = i - 1;


        while (j >= 0 && arr[indices[j]] > arr[key]) {
            indices[j + 1] = indices[j];
            j = j - 1;
        }

        indices[j + 1] = key;
    }
}

