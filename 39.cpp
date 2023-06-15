#include <stdio.h>

// Function to find the sum of even Fibonacci numbers up to N
int evenFibonacciSum(int n) {
    int sum = 0;
    int fib1 = 0;
    int fib2 = 2;

    while (fib2 <= n) {
        sum += fib2;

        // Calculate the next even Fibonacci number
        int fib3 = 4 * fib2 + fib1;
        fib1 = fib2;
        fib2 = fib3;
    }

    return sum;
}

// Example usage
int main() {
    int n;
    printf("Enter the number (N): ");
    scanf("%d", &n);

    int result = evenFibonacciSum(n);
    printf("Sum of even Fibonacci numbers up to %d: %d\n", n, result);

    return 0;
}
