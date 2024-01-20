int *create_check()
{
    int *check = (int*)malloc(9 * sizeof(int));
    for(int i = 0; i < 9; ++i)
        check[i] = 0;
    
    return check;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int row = boardSize;
    int col = *boardColSize;

    for(int i = 0; i < row; i += 3)
    {
        for(int j = 0; j < col; j += 3)
        {
            int *check_block = create_check();
            for(int k = 0; k < 9; ++k)
                if(board[i + k / 3][j + k % 3] != '.')
                    check_block[board[i + k / 3][j + k % 3] - '1']++;
            
            for(int k = 0; k < 9; ++k)
            {
                if(check_block[k] > 1)
                {
                    free(check_block);
                    return false;
                }
            }
        }
    }

    for(int i = 0; i < row; ++i)
    {
        int *check_row = create_check();
        for(int j = 0; j < col; ++j)
            if(board[i][j] != '.')
                check_row[board[i][j] - '1']++;

        for(int k = 0; k < 9; ++k)
        {
            if(check_row[k] > 1)
            {
                free(check_row);
                return false;
            }
        }
    }

    for(int j = 0; j < col; ++j)
    {
        int *check_col = create_check();
        for(int i = 0; i < row; ++i)
            if(board[i][j] != '.')
                check_col[board[i][j] - '1']++;

        for(int k = 0; k < 9; ++k)
        {
            if(check_col[k] > 1)
            {
                free(check_col);
                return false;
            }
        }
    }

    return true;
}