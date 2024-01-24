/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int abs(int num)
{
    return num >= 0 ? num : -num;
}

int* leftRightDifference(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;

    int left_sum = 0;
    int right_sum = 0;

    for(int i = 0; i < numsSize; ++i)
        right_sum += nums[i];
    
    int *ans = (int*)malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; ++i)
    {
        right_sum -= nums[i];
        ans[i] = abs(left_sum - right_sum);
        left_sum += nums[i];
    }

    return ans;
}