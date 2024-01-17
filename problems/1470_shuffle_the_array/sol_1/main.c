/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    *returnSize = numsSize;
    int *ans = (int*)malloc(*returnSize * sizeof(int));
    int index = 0;
    for(int i = 0; i < n; ++i)
    {
        ans[index] = nums[i];
        ++index;
        ans[index] = nums[i + n];
        ++index;
    }

    return ans;
}