#include <stdio.h>
#include <stdbool.h>
int count=0;
bool isPrime(int n) {
	count++;
    if (n < 2){
	    count++;
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
    	count++;
        if (n % i == 0){
		    count++;
            return false;
        }
    }
    return true;
}
int reverse(int n) {
	count++;
    int rev = 0;
    count++;
    while (n != 0) {
    	count++;
        rev = rev * 10 + n % 10;
        count++;
        n /= 10;
        count++;
    }
    return rev;
}
int main() {
    int N;
    count++;
    printf("Enter the limit N: ");
    count++;
    scanf("%d", &N);
    count++;
    printf("Prime numbers whose reverse is also prime up to %d:\n", N);
    count++;
    for (int i = 2; i <= N; i++) {
    	count++;
        if (isPrime(i) && isPrime(reverse(i))) {
        	count++;
            printf("%d ", i);
            count++;
        }
    }
    printf("time complexity is %d",count);
}
