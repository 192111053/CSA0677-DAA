#include <stdio.h>
#include <stdbool.h>

#define N 8

// Function to compute the Container Loading Problem
bool containerLoading(int weights[], int capacity) {
    bool dp[N + 1][capacity + 1];

    // Initialize the first column with true
    for (int i = 0; i <= N; i++)
        dp[i][0] = true;

    // Initialize the first row except for the first element with false
    for (int j = 1; j <= capacity; j++)
        dp[0][j] = false;

    // Fill the dynamic programming table
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= capacity; j++) {
            dp[i][j] = dp[i - 1][j]; // Exclude the current container

            if (j >= weights[i - 1])
                dp[i][j] = dp[i][j] || dp[i - 1][j - weights[i - 1]]; // Include the current container
        }
    }

    return dp[N][capacity];
}

// Example usage
int main() {
    int weights[N] = {50, 100, 30, 80, 90, 200, 150, 20};
    int capacity = 100;

    if (containerLoading(weights, capacity))
        printf("Containers can be loaded into the given capacity.\n");
    else
        printf("Containers cannot be loaded into the given capacity.\n");

    return 0;
}
