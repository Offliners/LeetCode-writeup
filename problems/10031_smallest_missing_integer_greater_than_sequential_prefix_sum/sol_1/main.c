int missingInteger(int* nums, int numsSize) {
    int candidate = nums[0];
    for(int i = 1; i < numsSize; ++i)
    {
        if(nums[i] == nums[i - 1] + 1)
            candidate += nums[i];
        else
            break;
    }

    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] == candidate)
        {
            ++candidate;
            i = 0;
        }
    }

    return candidate;
}