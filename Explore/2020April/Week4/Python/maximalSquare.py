class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0
            
        row, col = len(matrix), len(matrix[0])
        result = 0
        side = [0] * col
        
        for i in range(row):
            newSide = [int(matrix[i][0])] + [0 for _ in range(col - 1)]
            
            for j in range(1, col):
                if matrix[i][j] == '1':
                    newSide[j] = 1 + min(newSide[j - 1], side[j], side[j - 1])
                    
            result = max(result, max(newSide))
            side = newSide
            
        return result**2
