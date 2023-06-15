#include <stdio.h>
#include <limits.h>

#define N 4 // Number of cities

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the minimum cost of the TSP using dynamic programming
int tsp(int graph[][N], int start, int visited) {
    if (visited == (1 << N) - 1) // If all cities have been visited
        return graph[start][0]; // Return the cost from the last city to the starting city

    int minCost = INT_MAX;

    for (int i = 0; i < N; i++) {
        if (visited & (1 << i)) // If the city has already been visited
            continue;

        int newCost = graph[start][i] + tsp(graph, i, visited | (1 << i)); // Recursive call

        minCost = min(minCost, newCost);
    }

    return minCost;
}

// Example usage
int main() {
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int start = 0; // Starting city

    int minCost = tsp(graph, start, 1 << start);

    printf("Minimum cost of the TSP: %d\n", minCost);

    return 0;
}
