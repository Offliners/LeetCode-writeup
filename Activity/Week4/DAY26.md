# Day 26 - Longest Common Subsequence
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. 

(eg, "ace" is a subsequence of "abcde" while "aec" is not). 

A common subsequence of two strings is a subsequence that is common to both strings.

#### Example 1
```
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
```

#### Example 2
```
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
```

#### Example 3
```
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
```

### C
```C
int longestCommonSubsequence(char * text1, char * text2){
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    int **cache = malloc((len1 + 1) * sizeof(int*));
    
    for(int i = 0; i <= len1; i++)
        cache[i] = calloc((len2 + 1), sizeof(int));
    
    for(int i = 0; i < len1; i++)
    {
        for(int j = 0; j < len2; j++)
        {
            if(text1[i] == text2[j])
                cache[i + 1][j + 1] = cache[i][j] + 1;
            else if(cache[i][j + 1] >= cache[i + 1][j])
                cache[i + 1][j + 1] = cache[i][j + 1];
            else
                cache[i + 1][j + 1] = cache[i + 1][j];
        }
    }
    
    int result = cache[len1][len2];
    
    for(int i = 0; i <= len1; i++)
        free(cache[i]);
    
    free(cache);
    
    return result;
}
```
[code](C/longest-common-subsequence.c)

#### Result
```
Runtime: 24 ms, faster than 13.73% of C online submissions for Longest Common Subsequence.
Memory Usage: 11.3 MB, less than 100.00% of C online submissions for Longest Common
```

### Python
```python

```
[code](Python/longest-common-subsequence.py)

#### Result
```

```
