# Day 9 - Valid Perfect Square
Given a positive integer num, write a function which returns True if num is a perfect square else False.

#### Example 1
```
Input: 16
Output: true
```

#### Example 2
```
Input: 14
Output: false
```

### C
```C
bool isPerfectSquare(int num){
    int left = 0;
    int right = num;
    
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        long long square = mid * mid;
        
        if(square == num)
            return true;
        
        if(square < num)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return false;
}
```
[code](C/valid-perfect-square.c)

#### Result
```
Runtime: 0 ms, faster than 100.00% of C online submissions for Valid Perfect Square.
Memory Usage: 5.1 MB, less than 100.00% of C online submissions for Valid Perfect Square.
```

### Python
```python
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        left, right = 1, num
        
        while left <= right:
            mid = (left + right) // 2
            square = mid * mid
            
            if square == num:
                return True
            
            if square < num:
                left = mid + 1
            else:
                right = mid - 1
        
        return False
```
[code](Python/valid-perfect-square.py)

#### Result
```
Runtime: 32 ms, faster than 47.05% of Python3 online submissions for Valid Perfect Square.
Memory Usage: 13.8 MB, less than 10.00% of Python3 online submissions for Valid Perfect Square.
```
