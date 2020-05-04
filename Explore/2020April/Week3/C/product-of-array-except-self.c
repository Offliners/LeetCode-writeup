/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int *result = malloc(sizeof(int) * numsSize);
    
    result[numsSize - 1] = 1;
    for(int i = numsSize - 2; i >= 0; i--)
        result[i] = result[i + 1] * nums[i + 1];
    
    int left = 1;
    for(int i = 0; i < numsSize; i++)
    {
        result[i] = left * result[i];
        left *= nums[i];
    }
    
    return result;
}
