# Search in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

#### Example 1
```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

#### Example 2
```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

### Python 3
```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        
        while left <= right:
            mid = (left + right) // 2
            
            if nums[mid] == target:
                return mid
            
            if nums[left] <= nums[mid]:
                if nums[left] <= target and target <= nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if nums[mid] < target and target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
                    
        return -1
```
[code](Python%203/33.py)

#### Result
```
Runtime: 44 ms, faster than 29.53% of Python3 online submissions for Search in Rotated Sorted Array.
Memory Usage: 14.2 MB, less than 6.29% of Python3 online submissions for Search in Rotated Sorted Array.
```

### C
```C
int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    int mid;
    
    while(left <= right)
    {
        mid = (left + right) / 2;
        
        if(nums[mid] == target)
            return mid;
        
        if(nums[left] <= nums[mid])
        {
            if((nums[left] <= target)&&(target <= nums[mid]))
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if((nums[mid] <= target)&&(target <= nums[right]))
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    
    return -1;
}
```
[code](C/33.c)

#### Result
```
Runtime: 4 ms, faster than 67.37% of C online submissions for Search in Rotated Sorted Array.
Memory Usage: 5.8 MB, less than 100.00% of C online submissions for Search in Rotated Sorted Array.
```
