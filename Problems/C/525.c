int findMaxLength(int* nums, int numsSize){
    int countDiff[numsSize + 1];
    int findMax[2 * numsSize + 1];
    int maxLength = 0;
    
    countDiff[0] = 0;
    
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == 0)
            countDiff[i + 1] = countDiff[i] + 1;
        else
            countDiff[i + 1] = countDiff[i] - 1;
    }
    
    for(int i = 0; i < 2 * numsSize + 1; i++)
        findMax[i] = -1;
    
    for(int i = 0; i < numsSize; i++)
        findMax[(countDiff[i + 1] + numsSize)] = i;
    
    for(int i = 0; i < numsSize; i++)
    {
        int target = countDiff[i];
        int length = findMax[target + numsSize] - i + 1;
        
        if(length > maxLength)
            maxLength = length;
    }
    
    return maxLength;
}
