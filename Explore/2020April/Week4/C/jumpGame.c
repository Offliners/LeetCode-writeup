bool canJump(int* nums, int numsSize){
    int target = 0;
    
    for(int i = 0; i < numsSize; i++)
    {
        if(i > target)
            return false;
        
        if(target < i + nums[i])
            target = i + nums[i];
    }
    
    return true;
}
