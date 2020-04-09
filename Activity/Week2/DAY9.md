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

```
[code](Python/backspace-string-compare.py)
