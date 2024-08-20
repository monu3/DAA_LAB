#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array using a randomized pivot
int partition(int arr[], int low, int high)
{
    int pivotIndex = low + rand() % (high - low + 1);
    swap(&arr[pivotIndex], &arr[high]); // Move pivot to end
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Move pivot to its correct position
    return i + 1;
}

// Function to implement the randomized quick sort
void randomizedQuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        randomizedQuickSort(arr, low, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    // Initializing random seed
    srand(time(NULL));

    // Initializing the array
    int arr[] = {5, 7, 3, 4, 9, 12, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Printing the original array
    printf("Original array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Performing the randomized quick sort
    randomizedQuickSort(arr, 0, size - 1);

    // Printing the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
