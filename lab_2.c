#include <stdio.h>

void insertionSort(int arr[], int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key, // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// Function to print an array
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
    // Given array
    int arr[] = {25, 57, 48, 37, 12, 92, 86, 33};
    int size = sizeof(arr) / sizeof(arr[0]); // Size of the array
    printf("Original array: ");
    printArray(arr, size);

    // Perform insertion sort
    insertionSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);
    return 0;
}