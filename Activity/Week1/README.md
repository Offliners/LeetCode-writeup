# Week 1: April 1st–April 7th
## Single Number
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

## Happy Number
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the
squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which
does not include 1. Those numbers for which this process ends in 1 are happy numbers.

#### Example 
```
Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

### C
```C

```
[code](code/happyNumber.c)

#### Result
```
```
