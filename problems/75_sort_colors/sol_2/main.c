void sortColors(int* nums, int numsSize) {
    int num_zero = 0;
    int num_one = 0;

    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] == 0)
            ++num_zero;
        else if(nums[i] == 1)
            ++num_one;
    }

    for(int i = 0; i < numsSize; ++i)
    {
        if(i < num_zero)
            nums[i] = 0;
        else if(i < num_zero + num_one)
            nums[i] = 1;
        else
            nums[i] = 2;
    }
}