# Single Element in a Sorted Array
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

#### Example 1
```
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
```

#### Example 2
```
Input: [3,3,7,7,10,11,11]
Output: 10
```

### C
```C
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
```
[code](C/single-element-in-a-sorted-array.c)

#### Result
```
Runtime: 4 ms, faster than 96.67% of C online submissions for Single Element in a Sorted Array.
Memory Usage: 6.4 MB, less than 100.00% of C online submissions for Single Element in a Sorted Array.
```

### Python
```python

```
[code](Python/single-element-in-a-sorted-array.py)

#### Result
```

```
