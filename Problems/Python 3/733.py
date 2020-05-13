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
