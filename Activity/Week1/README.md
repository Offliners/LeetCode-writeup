# Week 1: April 1st–April 7th
### Single Number
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
[code](singleNumber.c)

### Happy Number
```C

```
[code](happyNumber.c)
