int majorityElement(int* nums, int numsSize){
    int count = 0;
    int candidate;
    
    for(int i = 0; i < numsSize; i++)
    {
        if(count == 0)
            candidate = nums[i];
        
        if(candidate == nums[i])
            count++;
        else
            count--;
    }
    
    return candidate;
}
