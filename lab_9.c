#include <stdio.h>
#include <stdlib.h>

// Function to merge two subarrays of arr[].
// The first subarray is arr[l..m]
// The second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1; // Size of the first subarray
    int n2 = r - m;     // Size of the second subarray

    // Create temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l; // Initial indexes of subarrays and merged array
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of L[], if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of R[], if any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free allocated memory
    free(L);
    free(R);
}

// Function to implement merge sort using divide and conquer
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Find the middle point
        int m = l + (r - l) / 2;

        // Divide the array into two halves and sort them
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Conquer by merging the two halves
        merge(arr, l, m, r);
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

    // Perform merge sort
    mergeSort(arr, 0, size - 1);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}
