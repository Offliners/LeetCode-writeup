# Find the Town Judge
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

* The town judge trusts nobody.
* Everybody (except for the town judge) trusts the town judge.
* There is exactly one person that satisfies properties 1 and 2.
You are given `trust`, an array of pairs `trust[i] = [a, b]` representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

#### Example 1
```
Input: N = 2, trust = [[1,2]]
Output: 2
```

#### Example 2
```
Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
```

#### Example 3
```
Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
```

#### Example 4
```
Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
```

#### Example 5
```
Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
```

### Python 3
```python
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        trustNum = [0] * (N + 1)
        
        for trustee, trusted in trust:
            trustNum[trusted] += 1
            trustNum[trustee] -= 1
            
        for people in range(1, N + 1):
            if trustNum[people] == N - 1:
                return people
        
        return -1
```
[code](Python%203/997.py)

#### Result
```
Runtime: 796 ms, faster than 56.66% of Python3 online submissions for Find the Town Judge.
Memory Usage: 18.1 MB, less than 10.00% of Python3 online submissions for Find the Town Judge.
```

### C
```C
int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    int *trustNum = malloc(sizeof(int) * (N + 1));
    
    for(int i = 0; i < N + 1; i++)
        trustNum[i] = 0;
    
    for(int i = 0; i < trustSize; i++)
    {
        trustNum[trust[i][0]] -= 1;
        trustNum[trust[i][1]] += 1;
    }
    
    for(int i = 1; i < N + 1; i++)
        if(trustNum[i] == N - 1)
            return i;
    
    return -1;
}
```
[code](C/997.c)

#### Result
```
Runtime: 164 ms, faster than 21.05% of C online submissions for Find the Town Judge.
Memory Usage: 16.1 MB, less than 100.00% of C online submissions for Find the Town Judge.
```
