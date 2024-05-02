int findMaxK(int* nums, int numsSize) {
    int neg_arr[1001] = {0};
    int pos_arr[1001] = {0};

    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] < 0)
            neg_arr[-nums[i]]++;
        else
            pos_arr[nums[i]]++;
    }

    int maxK = -1;
    for(int i = 0; i < 1001; ++i)
        if(neg_arr[i] > 0 && pos_arr[i] > 0)
            maxK = i;
    
    return maxK; 
}