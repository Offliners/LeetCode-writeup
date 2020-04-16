# Day 16 - Valid Parenthesis String
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

* Any left parenthesis `(` must have a corresponding right parenthesis `)`.
* Any right parenthesis `)` must have a corresponding left parenthesis `(`.
* Left parenthesis `(` must go before the corresponding right parenthesis `)`.
* `*` could be treated as a single right parenthesis `)` or a single left parenthesis `(` or an empty string.
* An empty string is also valid.

#### Example 1
```
Input: "()"
Output: True
```

#### Example 2
```
Input: "(*)"
Output: True
```

#### Example 3
```
Input: "(*))"
Output: True
```

### C
```C
bool checkValidString(char * s){
    int min = 0;
    int max = 0;
    
    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] == '(')
        {
            min++;
            max++;
        }
        else if(s[i] == ')')
        {
            min--;
            max--;
        }
        else if(s[i] == '*')
        {
            min--;
            max++;
        }
        
        if(max < 0)
            return false;
        if(min < 0)
            min = 0;
    }
    
    return min == 0;
}
```
[code](C/valid-parenthesis-string.c)

#### Result
```
Runtime: 0 ms, faster than 100.00% of C online submissions for Valid Parenthesis String.
Memory Usage: 5.2 MB, less than 100.00% of C online submissions for Valid Parenthesis String.
```

### Python
```python

```
[code](Python/valid-parenthesis-string.py)

#### Result
```

```
