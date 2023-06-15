#include <stdio.h>

// Function to perform Counting Sort without swapping
void countingSort(int arr[], int n, int max) {
    int count[max + 1] = {0};

    // Count the frequency of each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    int index = 0;

    // Reconstruct the sorted array
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Example usage
int main() {
    int arr[] = {7, 2, 4, 1, 3, 7, 9, 5, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = 9; // Maximum element in the array

    printf("Original array: ");
    printArray(arr, n);

    countingSort(arr, n, max);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
