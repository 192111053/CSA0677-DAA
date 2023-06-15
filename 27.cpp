#include <stdio.h>

#define MAX_SIZE 100

// Function to print the subsets that sum up to the target
void printSubsets(int set[], int subset[], int n, int target, int sum, int k) {
    if (sum == target) {
        printf("Subset found: { ");
        for (int i = 0; i < k; i++) {
            printf("%d ", subset[i]);
        }
        printf("}\n");
        return;
    }

    if (n == 0 || sum > target)
        return;

    subset[k] = set[n - 1];
    printSubsets(set, subset, n - 1, target, sum + set[n - 1], k + 1);

    printSubsets(set, subset, n - 1, target, sum, k);
}

// Function to solve the subset sum problem using backtracking
void subsetSum(int set[], int n, int target) {
    int subset[MAX_SIZE];
    printSubsets(set, subset, n, target, 0, 0);
}

// Example usage
int main() {
    int set[] = {1, 3, 5, 7, 9};
    int n = sizeof(set) / sizeof(set[0]);
    int target = 12;

    subsetSum(set, n, target);

    return 0;
}
