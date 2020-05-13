# Flood Fill
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

#### Example 
```
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
```

### Python 3
```python
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        row, col = len(image), len(image[0])
        start = image[sr][sc]
        
        if start == newColor:
            return image
        
        stack = [(sr, sc)]
        
        while stack:
            i, j = stack.pop()
            
            if i < 0 or i >= row or j < 0 or j >= col:
                continue
            
            if image[i][j] != start:
                continue
                
            image[i][j] = newColor
            
            for dr, dc in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
                stack.append((i + dr, j + dc))
        
        return image
```
[code](Python%203/733.py)

#### Result
```
Runtime: 80 ms, faster than 61.49% of Python3 online submissions for Flood Fill.
Memory Usage: 13.8 MB, less than 5.56% of Python3 online submissions for Flood Fill.
```

### C
```C

```
[code](C/733.c)

#### Result
```

```
