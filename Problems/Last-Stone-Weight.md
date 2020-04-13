# Last Stone Weight
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

* If `x == y`, both stones are totally destroyed;
* If `x != y`, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.

At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

#### Example
```
Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
```

### Python 3
```python

```
[code](Python%203/1046.py)

#### Result
```

```

### C
```C
int takeMax(int *counter, int upperBound)
{
    for(int i = upperBound; i > 0; i--)
    {
        if(counter[i] > 0)
        {
            counter[i]--;
            return i;
        }
    }
    
    return 0;
}

void insert(int *counter, int value)
{
    counter[value]++;
}

int lastStoneWeight(int* stones, int stonesSize){
    int counter[1001] = {0};
    int upperBound = 1000;
    
    for(int i = 0; i < stonesSize; i++)
        counter[stones[i]]++;
    
    while(true)
    {
        int y = takeMax(counter, upperBound);
        int x = takeMax(counter, upperBound);
        
        upperBound = y;
        
        if(x == 0)
            return y;
        if(x != y)
            insert(counter, y - x);
    }
    
    return 0;
}
```
[code](1046.c)

#### Result
```
Runtime: 0 ms, faster than 100.00% of C online submissions for Last Stone Weight.
Memory Usage: 5.4 MB, less than 100.00% of C online submissions for Last Stone Weight.
```
