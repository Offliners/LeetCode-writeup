bool isMonotonic(int* nums, int numsSize) {
    bool flag = false;
    int i;
    for(i = 1; i < numsSize; ++i)
    {
        if(nums[i] != nums[i - 1])
        {
            flag = nums[i] > nums[i - 1] ? true : false;
            break;
        }
    }

    for(; i < numsSize; ++i)
    {
        if(nums[i] > nums[i - 1] && !flag)
            return false;
        else if(nums[i] < nums[i - 1] && flag)
            return false;
    }

    return true;
}