# Day 9 - Backspace String Compare
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

#### Example 1
```
Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
```

#### Example 2
```
Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
```

#### Example 3
```
Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
```

#### Example 4
```
Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
```

### C
```C
char *backspaceProcess(char *str)
{
    int len = strlen(str);
    int index = 0;
    
    for(int i = 0; i < len; i++)
    {
        if(str[i] != '#')
        {
            str[index] = str[i];
            index++;
        }
        else
            if(index > 0)
                index--;
    }
    
    str[index] = '\0';
    
    return str;
}

bool backspaceCompare(char * S, char * T){
    return strcmp(backspaceProcess(S), backspaceProcess(T)) == 0;
}
```
[code](C/backspace-string-compare.c)

#### Result
```
Runtime: 0 ms, faster than 100.00% of C online submissions for Backspace String Compare.
Memory Usage: 5.4 MB, less than 100.00% of C online submissions for Backspace String Compare.
```

### Python 
```python
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        def nextChar(str, index):
            delete = 0
            
            while index >=0 and (delete or str[index] == '#'):
                delete = delete + 1 if str[index] == '#' else delete - 1
                index -= 1
                
            return index
        
        indexS, indexT = len(S) - 1, len(T) - 1
        
        while True:
            indexS, indexT = nextChar(S, indexS), nextChar(T, indexT)
            
            if indexS == -1 and indexT == -1:
                return True
            
            if indexS == -1 or indexT == -1:
                return False
            
            if S[indexS] != T[indexT]:
                return False
            
            indexS, indexT = indexS - 1, indexT - 1
```
[code](Python/backspace-string-compare.py)
