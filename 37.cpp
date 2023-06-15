#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1)
        return false;

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }

    return true;
}

// Function to reverse a given number
int reverseNumber(int num) {
    int reversedNum = 0;

    while (num != 0) {
        int remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }

    return reversedNum;
}

// Function to generate primes and check if the reverse is also prime
void generatePrimesWithReversedPrime(int N) {
    printf("Primes with Reversed Prime:\n");

    for (int num = 2; num <= N; num++) {
        if (isPrime(num)) {
            int reversedNum = reverseNumber(num);

            if (isPrime(reversedNum))
                printf("%d ", num);
        }
    }

    printf("\n");
}

// Example usage
int main() {
    int N;
    printf("Enter the limit (N): ");
    scanf("%d", &N);

    generatePrimesWithReversedPrime(N);

    return 0;
}
