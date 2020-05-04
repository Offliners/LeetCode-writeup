# Day 25 - Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

#### Example 1 
```
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

#### Example 2
```
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
```

### C
```C
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
```
[code](C/jumpGame.c)

#### Result
```
Runtime: 8 ms, faster than 89.69% of C online submissions for Jump Game.
Memory Usage: 6.5 MB, less than 100.00% of C online submissions for Jump Game.
```

### Python
```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        target = 0
        
        for i, num in enumerate(nums):
            if i > target:
                return False
            print(i, num, target)
            target = max(target, i + num)
            
        return True
```
[code](Python/jumpGame.py)

#### Result
```
Runtime: 124 ms, faster than 10.48% of Python3 online submissions for Jump Game.
Memory Usage: 16 MB, less than 7.14% of Python3 online submissions for Jump Game.
```
