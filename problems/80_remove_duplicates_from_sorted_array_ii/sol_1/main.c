int removeDuplicates(int* nums, int numsSize) {
    if(numsSize < 2)
        return numsSize;
    
    int k = 2;
    for(int i = 2; i < numsSize; ++i)
    {
        if(nums[k - 2] != nums[i])
        {
            nums[k] = nums[i];
            ++k;
        }
    }

    return k;
}