# Day 21 - Leftmost Column with at Least a One
(This problem is an interactive problem.)

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a `BinaryMatrix` interface:

* `BinaryMatrix.get(x, y)` returns the element of the matrix at index `(x, y)` (0-indexed).
* `BinaryMatrix.dimensions()` returns a list of 2 elements `[n, m]`, which means the matrix is `n * m`.

Submissions making more than `1000` calls to `BinaryMatrix.get` will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix `mat` as input in the following four examples. You will not have access the binary matrix directly.

#### Example 1
```
Input: mat = [[0,0],[1,1]]
Output: 0
```

#### Example 2
```
Input: mat = [[0,0],[0,1]]
Output: 1
```

#### Example 3
```
Input: mat = [[0,0],[0,0]]
Output: -1
```

#### Example 4
```
Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1
```

### C
```C
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * struct BinaryMatrix {
 *     int (*get)(struct BinaryMatrix*, int, int);
 *     int* (*dimensions)(struct BinaryMatrix*);
 * };
 */

int leftMostColumnWithOne(struct BinaryMatrix* matrix) {
    int row = matrix->dimensions(matrix)[0];
    int col = matrix->dimensions(matrix)[1];
    int leftMost = col;
    
    for(int i = 0; i < row;i++)
    {
        while(matrix->get(matrix, i, leftMost - 1) == 1)
        {
            leftMost--;
            
            if(leftMost == 0)
                return 0;
        }
    }
    
    if(leftMost == col)
        return -1;
    
    return leftMost;
}
```
[code](C/leftmost-column-with-at-least-a-one.c)

#### Result
```
Runtime: 12 ms
Memory Usage: 6 MB
```

### Python 
```python

```
[code](Python/leftmost-column-with-at-least-a-one.py)

#### Result
```

```
