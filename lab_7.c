#include <stdio.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int size)
{
    int i, j, temp;
    // Traverse through all elements in the array
    for (i = 0; i < size - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < size - i - 1; j++)
        {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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

    // Perform bubble sort
    bubbleSort(arr, size);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}
