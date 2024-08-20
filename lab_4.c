#include <stdio.h>

// Function to find the minimum and maximum values in an array
void findMinMax(int arr[], int size, int *min, int *max)
{
    // Initialize min and max with the first element of the array
    *min = arr[0];
    *max = arr[0];

    // Traverse the array to find min and max
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < *min)
        {
            *min = arr[i];
        }
        if (arr[i] > *max)
        {
            *max = arr[i];
        }
    }
}

int main()
{
    // Initialize the array
    int arr[] = {5, 7, 3, 4, 9, 12, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Variables to store the minimum and maximum values
    int min, max;

    // Find the minimum and maximum values
    findMinMax(arr, size, &min, &max);

    // Print the results
    printf("The minimum value in the array is: %d\n", min);
    printf("The maximum value in the array is: %d\n", max);

    return 0;
}