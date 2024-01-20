class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = 9;
        int col = 9;
        
        for(int i = 0; i < row; i += 3)
        {
            for(int j = 0; j < col; j += 3)
            {
                vector<int> check_block(9, 0);
                for(int k = 0; k < 9; ++k)
                    if(board[i + k / 3][j + k % 3] != '.')
                        check_block[board[i + k / 3][j + k % 3] - '1']++;

                for(int k = 0; k < check_block.size(); ++k)
                    if(check_block[k] > 1)
                        return false;
            }
        }

        for(int i = 0; i < row; ++i)
        {
            vector<int> check_row(9, 0);
            for(int j = 0; j < col; ++j)
                if(board[i][j] != '.')
                    check_row[board[i][j] - '1']++;
            
            for(int k = 0; k < check_row.size(); ++k)
                if(check_row[k] > 1)
                    return false;
        }

        for(int j = 0; j < col; ++j)
        {
            vector<int> check_col(9, 0);
            for(int i = 0; i < row; ++i)
                if(board[i][j] != '.')
                    check_col[board[i][j] - '1']++;
            
            for(int k = 0; k < check_col.size(); ++k)
                if(check_col[k] > 1)
                    return false;
        }

        return true;
    }
};