#include <stdio.h>

long binomialCoeff(int n, int k)
{
    long res = 1;

    if (k > n - k)
        k = n - k;

    for (int i = 0; i < k; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

void printPascalTriangle(int numRows)
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            long coeff = binomialCoeff(i, j);
            printf("%ld ", coeff);
        }
        printf("\n");
    }
}

int main()
{
    int numRows;

    printf("Enter the number of rows for Pascal's triangle: ");
    scanf("%d", &numRows);

    printf("Pascal's triangle with %d rows:\n", numRows);
    printPascalTriangle(numRows);

    return 0;
}
