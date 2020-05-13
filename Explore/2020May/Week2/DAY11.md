# Day 11 - Flood Fill
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

### C
```C
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
    int color = image[sr][sc];
    *returnSize = imageSize;
    returnColumnSizes[0] = (int*)malloc(sizeof(int) * (*returnSize));
    
    for(int i = 0;i < *returnSize; i++)
        returnColumnSizes[0][i] = *imageColSize;
    
    const int ROWS = imageSize;
    const int COLS = imageColSize[0];

    if(color == newColor)
        return image;
    
    depthFirstSearch(image, ROWS, COLS, sr, sc, color, newColor);
    
    return image;
}

void depthFirstSearch(int **image, int ROWS, int COLS, int i, int j, int color, int newColor)
{   
    if((i < 0)||(j < 0)||(i >= ROWS)||(j >= COLS))
        return;
    
    if(image[i][j] != color)
        return;

    image[i][j] = newColor;
    depthFirstSearch(image, ROWS, COLS, i + 1, j, color, newColor);
    depthFirstSearch(image, ROWS, COLS, i - 1, j, color, newColor);
    depthFirstSearch(image, ROWS, COLS, i, j + 1, color, newColor);
    depthFirstSearch(image, ROWS, COLS, i, j - 1, color, newColor);
}
```
[code](C/floodFill.c)

#### Result
```
Runtime: 20 ms, faster than 85.15% of C online submissions for Flood Fill.
Memory Usage: 7.6 MB, less than 100.00% of C online submissions for Flood Fill.
```

### Python
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
[code](Python/floodFill.py)

#### Result
```
Runtime: 80 ms, faster than 61.49% of Python3 online submissions for Flood Fill.
Memory Usage: 13.8 MB, less than 5.56% of Python3 online submissions for Flood Fill.
```
