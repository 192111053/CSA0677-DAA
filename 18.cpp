#include <stdio.h>
#include <limits.h>

// Function to calculate the sum of probabilities from i to j
double sumOfProbabilities(double probabilities[], int i, int j) {
    double sum = 0;
    for (int k = i; k <= j; k++)
        sum += probabilities[k];
    return sum;
}

// Function to find the optimal binary search tree using dynamic programming
double optimalBST(double probabilities[], int n) {
    double cost[n + 1][n + 1]; // Cost matrix
    double prefixSum[n + 1]; // Prefix sum array

    // Initialize the cost matrix and prefix sum array
    for (int i = 1; i <= n; i++) {
        cost[i][i] = probabilities[i];
        prefixSum[i] = prefixSum[i - 1] + probabilities[i];
    }

    for (int length = 2; length <= n; length++) {
        for (int i = 1; i <= n - length + 1; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;

            for (int k = i; k <= j; k++) {
                double temp = cost[i][k - 1] + cost[k + 1][j] + sumOfProbabilities(probabilities, i, j);
                if (temp < cost[i][j])
                    cost[i][j] = temp;
            }
        }
    }

    return cost[1][n];
}

// Example usage
int main() {
    double probabilities[] = {0, 0.15, 0.10, 0.05, 0.10, 0.20};
    int n = sizeof(probabilities) / sizeof(probabilities[0]) - 1;

    double optimalCost = optimalBST(probabilities, n);
    printf("Optimal Cost of Binary Search Tree: %.2f\n", optimalCost);

    return 0;
}
