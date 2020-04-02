# Day 1 - Sinfle Number
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

#### Example 1
```
Input: [2,2,1]
Output: 1
```

#### Example 2
```
Input: [4,1,2,1,2]
Output: 4
```

### C
```C
int singleNumber(int* nums, int numsSize){
    for(int i = 0; i < numsSize; i++)
    {
        int count = 0;
        
        for(int j = 0; j < numsSize; j++)
            if(nums[j] == nums[i])
                count++;
        
        if(count == 1)
            return nums[i];
    }
    
    return -1;
}
```
[code](code/singleNumber.c)
#### Result
```
Runtime: 1276 ms
Memory Usage: 6.6 MB
```
