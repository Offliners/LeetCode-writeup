bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
    if(coordinatesSize < 3)
        return true;
        
    int xDiff = coordinates[1][0] - coordinates[0][0];
    int yDiff = coordinates[1][1] - coordinates[0][1];
        
    for(int i = 1; i < coordinatesSize; i++)
    {
        int dx = coordinates[i][0] - coordinates[0][0];
        int dy = coordinates[i][1] - coordinates[0][1];

        if(xDiff * dy != yDiff * dx)
            return false;
    }
        
    return true;
}
