#include <stdio.h>

// Function to check if a number is a perfect number
int isPerfectNumber(int num) {
    int sum = 0;

    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0)
            sum += i;
    }

    if (sum == num)
        return 1; // The number is perfect
    else
        return 0; // The number is not perfect
}

// Example usage
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPerfectNumber(num))
        printf("%d is a perfect number.\n", num);
    else
        printf("%d is not a perfect number.\n", num);

    return 0;
}
