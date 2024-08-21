#include <stdio.h>
#include <stdbool.h>

#define V 4 // Number of vertices in the graph

// Function to print the vertex cover
void printVertexCover(bool cover[V])
{
    printf("Vertex Cover: ");
    for (int i = 0; i < V; i++)
    {
        if (cover[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to find a vertex cover of the given graph
void vertexCover(int graph[V][V])
{
    bool cover[V] = {false}; // To keep track of the vertex cover

    // Traverse all edges
    for (int u = 0; u < V; u++)
    {
        for (int v = u + 1; v < V; v++)
        {
            // If there is an edge between u and v
            if (graph[u][v])
            {
                // If neither u nor v is in the cover, add both to cover
                if (!cover[u] && !cover[v])
                {
                    cover[u] = true;
                    cover[v] = true;
                }
            }
        }
    }

    // Print the result
    printVertexCover(cover);
}

int main()
{
    // Example graph
    int graph[V][V] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}};

    vertexCover(graph);
    return 0;
}
