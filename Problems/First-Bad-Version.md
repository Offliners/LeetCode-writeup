# First Bad Version
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool `isBadVersion(version)` which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

#### Example
```
Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 
```

### Python 3
```python
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        first, last = 1, n+1
        mid = first + (last - first) // 2
        
        while not(isBadVersion(mid) and (not isBadVersion(mid-1))):
            if not isBadVersion(mid):
                first = mid + 1
            else:
                last = mid
            
            mid = first + (last - first) // 2
        
        return mid
```
[code](Python%203/278.py)

#### Result
```
Runtime: 24 ms, faster than 90.12% of Python3 online submissions for First Bad Version.
Memory Usage: 13.9 MB, less than 6.90% of Python3 online submissions for First Bad Version.
```

### C
```C
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    long long first = 1, last = (long long)n + 1;
    long long mid = first + (last - first) / 2;
    
    while(!((isBadVersion(mid))&&(!isBadVersion(mid-1))))
    {
        if(!isBadVersion(mid))
            first = mid + 1;
        else
            last = mid;
        
        mid = first + (last - first) / 2;
    }
    
    return mid;
}
```
[code](C/278.c)

#### Result
```
Runtime: 0 ms, faster than 100.00% of C online submissions for First Bad Version.
Memory Usage: 5.3 MB, less than 100.00% of C online submissions for First Bad Version.
```
