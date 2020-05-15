# Day 15 - Maximum Sum Circular Subarray
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

#### Example 1
```
Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
```

#### Example 2
```
Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
```

#### Example 3
```
Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
```

#### Example 4
```
Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
```

#### Example 5
```
Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
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

int maxSubarraySumCircular(int* A, int ASize){
    int chooseMiddle = maxSubArray(A, ASize);
    int total = 0;
    
    for(int i = 0; i < ASize; i++)
        total += A[i];
    
    for(int i = 0; i < ASize; i++)
        A[i] *= -1;
    
    int result = maxSubArray(A, ASize);
    
    if(result != -total)
    {
        int notChooseMiddle = total + result;
        
        if(chooseMiddle > notChooseMiddle)
            return chooseMiddle;
        
        return notChooseMiddle;
    }
    else
        return chooseMiddle;
}
```
[code](C/maximum-sum-circular-subarray.c)

#### Result
```
Runtime: 60 ms, faster than 75.00% of C online submissions for Maximum Sum Circular Subarray.
Memory Usage: 8.3 MB, less than 100.00% of C online submissions for Maximum Sum Circular Subarray.
```

### Python
```python
class Solution:
    def maxSubarraySumCircular(self, A: List[int]) -> int:
        if all(num <= 0 for num in A):
            return max(A)
        
        overallMax, overallMin = float('-inf'), float('inf')
        localMax, localMin = 0, 0
        
        for num in A:
            localMax = max(localMax, 0) + num
            localMin = min(localMin, 0) + num
            overallMax = max(overallMax, localMax)
            overallMin = min(overallMin, localMin)
        
        return max(overallMax, sum(A) - overallMin)
```
[code](Python/maximum-sum-circular-subarray.py)

#### Result
```
Runtime: 536 ms, faster than 86.79% of Python3 online submissions for Maximum Sum Circular Subarray.
Memory Usage: 18 MB, less than 100.00% of Python3 online submissions for Maximum Sum Circular Subarray.
```
