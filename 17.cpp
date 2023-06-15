#include <stdio.h>

int findMthMax(int arr[], int size, int m)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return arr[m - 1];
}

int findNthMin(int arr[], int size, int n)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return arr[n - 1];
}

int main()
{
    int arr[] = {10, 5, 7, 8, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int m = 3;  // M-th maximum number
    int n = 2;  // N-th minimum number

    int mthMax = findMthMax(arr, size, m);
    int nthMin = findNthMin(arr, size, n);

    int sum = mthMax + nthMin;
    int diff = mthMax - nthMin;

    printf("M-th maximum number: %d\n", mthMax);
    printf("N-th minimum number: %d\n", nthMin);
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);

    return 0;
}
