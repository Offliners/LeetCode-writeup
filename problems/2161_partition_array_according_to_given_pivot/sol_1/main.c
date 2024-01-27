/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    int *left = (int*)malloc(numsSize * sizeof(int));
    int *right = (int*)malloc(numsSize * sizeof(int));

    int pivot_count = 0;
    *returnSize = numsSize;
    int left_index = 0;
    int right_index = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] == pivot)
            ++pivot_count;
        else if(nums[i] < pivot)
        {
            left[left_index] = nums[i];
            ++left_index;
        }
        else
        {
            right[right_index] = nums[i];
            ++right_index;
        }
    }

    for(int i = 0; i < pivot_count; ++i)
    {
        left[left_index] = pivot;
        ++left_index;
    }

    for(int i = 0; i < right_index; ++i)
    {
        left[left_index] = right[i];
        ++left_index;
    }

    free(right);
    return left;
}