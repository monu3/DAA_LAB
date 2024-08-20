#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return mid; // Target found at index mid
        }
        else if (arr[mid] < target)
        {
            low = mid + 1; // Search in the right half
        }
        else
        {
            high = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

int main()
{
    // Given array
    int arr[] = {10, 14, 19, 26, 31, 42, 44};
    int size = sizeof(arr) / sizeof(arr[0]); // Size of the array
    int target = 31;                         // Target to search for

    // Perform binary search
    int result = binarySearch(arr, size, target);

    if (result != -1)
    {
        printf("Position of %d: index(%d)\n", target, result);
    }
    else
    {
        printf("%d not found in the array.\n", target);
    }

    return 0;
}
