#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5 // Number of vertices in the graph

// Function to find the vertex with the minimum key value
int findMinKey(int key[], bool mstSet[]) {
    int minKey = INT_MAX;
    int minIndex;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to print the MST
void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[V][V]) {
    int parent[V]; // Array to store the constructed MST
    int key[V]; // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices not yet included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int v = 0; v < V; v++) {
        key[v] = INT_MAX;
        mstSet[v] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0; // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1; // First node is always the root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        int u = findMinKey(key, mstSet); // Pick the minimum key vertex from the set of vertices not yet included in MST
        mstSet[u] = true; // Add the picked vertex to the MST set

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

// Example usage
int main() {
    // Example graph represented using an adjacency matrix
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
