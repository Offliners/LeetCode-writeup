/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int abs(int num)
{
    return num >= 0 ? num : -num; 
}

int* leftRightDifference(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;

    int *left = (int*)malloc(numsSize * sizeof(int));

    left[0] = 0;
    for(int i = 1; i < numsSize; ++i)
        left[i] = left[i - 1] + nums[i - 1];

    int *right = (int*)malloc(numsSize * sizeof(int));
    right[numsSize - 1] = 0;
    for(int i = numsSize - 2; i >= 0; --i)
        right[i] = right[i + 1] + nums[i + 1];

    for(int i = 0; i < numsSize; ++i)
        left[i] = abs(left[i] - right[i]);

    free(right);
    return left;
}