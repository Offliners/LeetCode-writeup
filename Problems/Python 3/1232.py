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
