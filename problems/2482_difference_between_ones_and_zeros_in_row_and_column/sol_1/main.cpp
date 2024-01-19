class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> diff(row, vector<int>(col));
        for(int i = 0; i < row; ++i)
        {
            int onesRow = 0;
            int zerosRow = 0;
            for(int j = 0; j < col; ++j)
            {
                if(grid[i][j] == 0)
                    ++zerosRow;
                else
                    ++onesRow;
            }

            for(int j = 0; j < col; ++j)
                diff[i][j] = onesRow - zerosRow;
        }

        for(int j = 0; j < col; ++j)
        {
            int onesCol = 0;
            int zerosCol = 0;
            for(int i = 0; i < row; ++i)
            {
                if(grid[i][j] == 0)
                    ++zerosCol;
                else
                    ++onesCol;
            }

            for(int i = 0; i < row; ++i)
                diff[i][j] += onesCol - zerosCol;
        }

        return diff;
    }
};