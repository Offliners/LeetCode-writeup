# Check If It Is a Straight Line
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

#### Example 1
```
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
```

#### Example 2
```
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
```

### Python 3
```python
class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        if len(coordinates) < 3:
            return True
        
        xDiff = coordinates[1][0] - coordinates[0][0]
        yDiff = coordinates[1][1] - coordinates[0][1]
        
        for x, y in coordinates[2:]:
            dx = x - coordinates[0][0]
            dy = y - coordinates[0][1]
            
            if xDiff * dy != yDiff * dx:
                return False
        
        return True
```
[code](Python%203/1232.py)

#### Result
```
Runtime: 52 ms, faster than 98.32% of Python3 online submissions for Check If It Is a Straight Line.
Memory Usage: 13.9 MB, less than 100.00% of Python3 online submissions for Check If It Is a Straight Line.
```

### C
```C

```
[code](C/1232.c)

#### Result
```

```
