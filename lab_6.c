#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int size)
{
    int i, j, minIndex, temp;
    for (i = 0; i < size - 1; i++)
    {
        // Find the index of the minimum element in the unsorted part
        minIndex = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i)
        {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // Initialize the array
    int arr[] = {7, 4, 10, 8, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    // Print the original array
    printf("Original array:\n");
    printArray(arr, size);

    // Perform selection sort
    selectionSort(arr, size);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}
