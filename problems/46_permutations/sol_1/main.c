/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void cal_permute(int level, int *cur_level, int *nums, int numsSize, int **table)
{
    if(level == numsSize - 1)
    {
        for(int i = 0; i < numsSize; ++i)
            table[*cur_level][i] = nums[i];

        (*cur_level)++;
        return;
    }

    for(int i = level; i < numsSize; ++i)
    {
        swap(&nums[i], &nums[level]);
        cal_permute(level + 1, cur_level, nums, numsSize, table);
        swap(&nums[i], &nums[level]);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int n = numsSize;
    int factorial = 1;
    while(n != 0)
    {
        factorial *= n;
        --n;
    }

    *returnSize = factorial;
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for(int i = 0; i < *returnSize; ++i)
        (*returnColumnSizes)[i] = numsSize;

    int **table = (int**)malloc(*returnSize * sizeof(int*));
    for(int i = 0; i < *returnSize; ++i)
        table[i] = (int*)malloc(numsSize * sizeof(int));

    int cur_level = 0;
    cal_permute(0, &cur_level, nums, numsSize, table);

    return table;
}