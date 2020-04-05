int compare(int num1, int num2)
{
    if(num1 > num2)
        return num1;
    else
        return num2;
}

int maxSubArray(int* nums, int numsSize){
    int tempMax = nums[0];
    int max = nums[0];
        
    for(int i = 1 ; i < numsSize ; i++){
        tempMax = compare(nums[i], tempMax + nums[i]);
        max = compare(tempMax, max);
    }
        
    return max;
}
