# Day 2 - Happy Number
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
int next(int num)
{
    int result = 0;
    int rem;
    
    while(num != 0)
    {
        rem = num % 10;
        num /= 10;
        result += rem * rem;
    }
    
    return result;
}

bool isHappy(int n){
    int num1 = n;
    int num2 = n;
    
    do
    {
        num1 = next(num1);
        num2 = next(next(num2));
    }while(num2 != num1);
    
    return num1 == 1;
}
```
[code](C/happyNumber.c)

#### Result
```
Runtime: 0 ms, faster than 100.00% of C online submissions for Happy Number.
Memory Usage: 5.2 MB, less than 100.00% of C online submissions for Happy Number.
```

### Python 3
```python
class Solution:
    def isHappy(self, n: int) -> bool:
        def nextNum(num):
            result = 0

            while(num != 0):
                rem = num % 10
                num //= 10
                result += rem * rem

            return result
        
        num1 = n
        num2 = n
        
        while True:
            num1 = nextNum(num1)
            num2 = nextNum(nextNum(num2))
            
            if num1 == num2:
                break
                
        return num1 == 1
```
[code](Python/happyNumber.py)

#### Result
```
Runtime: 32 ms, faster than 66.89% of Python3 online submissions for Happy Number.
Memory Usage: 13.6 MB, less than 5.26% of Python3 online submissions for Happy Number.
```
