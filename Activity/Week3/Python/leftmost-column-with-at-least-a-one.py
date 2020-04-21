# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
#class BinaryMatrix(object):
#    def get(self, x: int, y: int) -> int:
#    def dimensions(self) -> list[]:

class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        row, col = binaryMatrix.dimensions()
        leftMost = col
        
        for i in range(row):
            while binaryMatrix.get(i, leftMost - 1) == 1:
                leftMost -= 1
                
                if leftMost == 0:
                    return 0
                
        if leftMost == col:
            return -1
        
        return leftMost
