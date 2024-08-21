#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int u, v, weight;
} Edge;

int parent[MAX];

// Function to find the parent of a node
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Function to unite two sets
void unionSets(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Function to implement Kruskal's algorithm
void kruskal(Edge edges[], int n, int e)
{
    Edge result[MAX]; // Array to store the resultant MST
    int k = 0;        // Index for result[]

    for (int i = 0; i < e; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        int set_u = find(u);
        int set_v = find(v);

        // If including this edge doesn't cause a cycle
        if (set_u != set_v)
        {
            result[k++] = edges[i];
            unionSets(set_u, set_v);
        }
    }

    // Print the resultant MST
    printf("Following are the edges in the constructed MST:\n");
    for (int i = 0; i < k; i++)
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].weight);
}

int main()
{
    int n = 4; // Number of vertices
    int e = 5; // Number of edges

    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4},
    };

    // Sort the edges by weight (using Bubble Sort for simplicity)
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initialize the parent array for union-find
    for (int i = 0; i < n; i++)
        parent[i] = i;

    kruskal(edges, n, e);

    return 0;
}
