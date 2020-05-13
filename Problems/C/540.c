int singleNonDuplicate(int* nums, int numsSize){
    int left = 0;
    int right = numsSize;
    
    while(right - left != 1)
    {
        int mid = left + (right - left) / 2;
        
        if((nums[mid - 1] < nums[mid])&&(nums[mid] < nums[mid + 1]))
            return nums[mid];
        
        if((mid % 2 == 1)&&(nums[mid - 1] < nums[mid])&&(nums[mid] == nums[mid + 1]))
            right = mid;
        
        else if((mid % 2 == 0)&&(nums[mid - 1] == nums[mid])&&(nums[mid] < nums[mid + 1]))
            right = mid - 1;
        
        else if((mid % 2 == 0)&&(nums[mid - 1] < nums[mid])&&(nums[mid] == nums[mid + 1]))
            left = mid + 2;
        else if((mid % 2 == 1)&&(nums[mid - 1] == nums[mid])&&(nums[mid] < nums[mid + 1]))
            left = mid + 1;
    }
    
    return nums[left];
}
