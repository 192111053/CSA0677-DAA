#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the Knapsack problem
int knapsack(int W, int weights[], int profits[], int n) {
    // Create a table to store the maximum profit for each weight and item
    int table[n + 1][W + 1];

    // Fill the table in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                table[i][w] = 0;
            else if (weights[i - 1] <= w)
                table[i][w] = max(profits[i - 1] + table[i - 1][w - weights[i - 1]], table[i - 1][w]);
            else
                table[i][w] = table[i - 1][w];
        }
    }

    // Return the maximum profit
    return table[n][W];
}

// Example usage
int main() {
    int weights[] = {40, 30, 20, 30};
    int profits[] = {80, 70, 50, 80};
    int knapsackWeight = 100;
    int numItems = sizeof(weights) / sizeof(weights[0]);

    int maxProfit = knapsack(knapsackWeight, weights, profits, numItems);
    printf("Maximum profit: %d\n", maxProfit);

    return 0;
}
