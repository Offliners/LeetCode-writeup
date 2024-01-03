/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    for(int i = 0; i < numsSize; ++i)
        nums[i] += numsSize * (nums[nums[i]] % numsSize);
    
    for(int i = 0; i < numsSize; ++i)
        nums[i] /= numsSize;
    
    return nums;
}