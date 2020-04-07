# Day 7 - Counting Elements
Given an integer array arr, count element x such that x + 1 is also in arr.

If there're duplicates in arr, count them seperately.

#### Example 1
```
Input: arr = [1,2,3]
Output: 2
Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
```

#### Example 2
```
Input: arr = [1,1,3,3,5,5,7,7]
Output: 0
Explanation: No numbers are counted, cause there's no 2, 4, 6, or 8 in arr.
```

#### Example 3
```
Input: arr = [1,3,2,3,5,0]
Output: 3
Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.
```

#### Example 4
```
Input: arr = [1,1,2,2]
Output: 2
Explanation: Two 1s are counted cause 2 is in arr.
```

### C
```C
int compare(const void *num1, const void *num2)
{
    return *(const int*)num1 - *(const int*)num2;
}

int countElements(int* arr, int arrSize){
    int count = 0;
    int number = 1;
    
    qsort(arr, arrSize, sizeof(int), compare);
    
    for(int i = 1; i <arrSize; i++)
    {
        if(arr[i] != arr[i-1])
        {
            if(arr[i] == arr[i-1] + 1)
                count += number;
            number = 1;
        }
        else
            number++;
    }
    
    return count;
}
```
[code](C/countingElements.c)

#### Result
```
Runtime: 0 ms
Memory Usage: 5.6 MB
```

### Python 3
```python
class Solution:
    def countElements(self, arr: List[int]) -> int:
        count = 0
        number = 1
        
        arr.sort()
        
        for i in range(len(arr)):
            if(arr[i] != arr[i-1]):
                if(arr[i] == arr[i-1] + 1):
                    count += number
                number = 1
            else:
                number += 1
                
        return count
```
[ocde](Python/countingElements.py)

#### Result
```
Runtime: 24 ms
Memory Usage: 14 MB
```
