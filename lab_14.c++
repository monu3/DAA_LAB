#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item
{
    float weight;
    float value;
};

// Comparator function to sort items according to value/weight ratio
bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to calculate the maximum value that can be put in a knapsack of capacity W
double fractionalKnapsack(int W, struct Item arr[], int n)
{
    // Sort items according to value/weight ratio
    sort(arr, arr + n, cmp);

    double totalValue = 0.0;

    // Loop through the items
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        }
        else
        {
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }

    return totalValue;
}

int main()
{
    int n = 3;  // Number of items
    int W = 50; // Capacity of knapsack
    Item arr[] = {{20.0, 60.0}, {10.0, 40.0}, {30.0, 100.0}};

    double maxValue = fractionalKnapsack(W, arr, n);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
