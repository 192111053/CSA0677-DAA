#include <stdio.h>

typedef struct {
    int value;
    int weight;
} Item;

void knapsack(Item items[], int n, int capacity) {
    // Calculate value-to-weight ratios
    double ratios[n];
    for (int i = 0; i < n; i++) {
        ratios[i] = (double)items[i].value / items[i].weight;
    }

    // Sort items based on value-to-weight ratios in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratios[j] < ratios[j + 1]) {
                double tempRatio = ratios[j];
                ratios[j] = ratios[j + 1];
                ratios[j + 1] = tempRatio;

                Item tempItem = items[j];
                items[j] = items[j + 1];
                items[j + 1] = tempItem;
            }
        }
    }

    int selectedItems[n];
    for (int i = 0; i < n; i++) {
        selectedItems[i] = 0;
    }

    int currentWeight = 0;
    double totalValue = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            selectedItems[i] = 1;
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            double remainingCapacity = capacity - currentWeight;
            double fraction = remainingCapacity / items[i].weight;
            selectedItems[i] = fraction;
            currentWeight += (int)(fraction * items[i].weight);
            totalValue += (fraction * items[i].value);
            break;
        }
    }

    printf("Selected Items:\n");
    for (int i = 0; i < n; i++) {
        if (selectedItems[i]) {
            printf("Item %d: Fraction %.2f\n", i + 1, selectedItems[i]);
        }
    }

    printf("Total Value: %.2f\n", totalValue);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];

    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d:\n", i + 1);
        printf("Value: ");
        scanf("%d", &items[i].value);
        printf("Weight: ");
        scanf("%d", &items[i].weight);
    }

    int capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    knapsack(items, n, capacity);

    return 0;
}
