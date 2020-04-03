# Day 3 - Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

#### Example 
```
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

### C
```C
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
```
[code](C/maximumSubarray.c)

#### Result
```
```

### Python 3
```python

```

#### Result
```

```
