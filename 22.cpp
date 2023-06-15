#include <stdio.h>
#include <stdlib.h>

void backtrack(int* nums, int numsSize, int start, int* subset, int subsetSize, int** subsets, int* returnSize, int** returnColumnSizes)
{
    subsets[*returnSize] = (int*)malloc(subsetSize * sizeof(int));
    for (int i = 0; i < subsetSize; i++)
    {
        subsets[*returnSize][i] = subset[i];
    }
    (*returnColumnSizes)[*returnSize] = subsetSize;
    (*returnSize)++;

    for (int i = start; i < numsSize; i++)
    {
        subset[subsetSize] = nums[i];
        backtrack(nums, numsSize, i + 1, subset, subsetSize + 1, subsets, returnSize, returnColumnSizes);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int subsetSize = 0;
    int** subsets = (int**)malloc((1 << numsSize) * sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc((1 << numsSize) * sizeof(int));
    int* subset = (int*)malloc(numsSize * sizeof(int));

    backtrack(nums, numsSize, 0, subset, subsetSize, subsets, returnSize, returnColumnSizes);

    return subsets;
}

int main()
{
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* returnColumnSizes;

    int** result = subsets(nums, numsSize, &returnSize, &returnColumnSizes);

    printf("[");
    for (int i = 0; i < returnSize; i++)
    {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1)
                printf(",");
        }
        printf("]");
        if (i < returnSize - 1)
            printf(",");
    }
    printf("]\n");

    return 0;
}
