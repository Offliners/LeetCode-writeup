# Day 14 - Perform String Shifts
You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

* direction can be 0 (for left shift) or 1 (for right shift). 
* amount is the amount by which string s is to be shifted.
* A left shift by 1 means remove the first character of s and append it to the end.
* Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.

Return the final string after all operations.

#### Example 1
```
Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation: 
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"
```

#### Example 2
```
Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"
Explanation:  
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"
```

### C
```C
char * stringShift(char * s, int** shift, int shiftSize, int* shiftColSize){
    int len = strlen(s);
    int total = 0;
    
    for(int i = 0; i < shiftSize; i++)
    {
        int direction = shift[i][0];
        int amount = shift[i][1];
        
        amount =  amount % len;
        if(direction == 1)
            amount = len - amount;
        
        total += amount;
    }
    
    total %= len;
    
    for(int i = 0; i < total; i++)
    {
        char temp = s[0];
        for(int j = 0; j < len - 1; j++)
            s[j] = s[j + 1];
        
        s[len - 1] = temp;
    }
    
    return s;
}
```
[code](C/perform-string-shifts.c)

#### Result
```
Runtime: 0 ms
Memory Usage: 5.7 MB
```

### Python
```python

```
[code](Python/perform-string-shifts.py)

#### Result
```

```
