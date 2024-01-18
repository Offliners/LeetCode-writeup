/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void copy_row(int **table, int table_row_index, int *row, int row_len)
{
    for(int i = 0; i < row_len; ++i)
        row[i] = table[table_row_index][i];
}

void free_table(int **table, int table_size)
{
    for(int i = 0; i < table_size; ++i)
        free(table[i]);

    free(table);
}

int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int **table = (int**)malloc(*returnSize * sizeof(int*));
    for(int i = 0; i < *returnSize; ++i)
        table[i] = (int*)malloc((i + 1) * sizeof(int));
    
    int *ans = (int*)malloc(*returnSize * sizeof(int));
    table[0][0] = 1;
    if(rowIndex == 0)
    {
        copy_row(table, rowIndex, ans, *returnSize);
        free_table(table, *returnSize);
        return ans;
    }
    
    table[1][0] = 1;
    table[1][1] = 1;
    if(rowIndex == 1)
    {
        copy_row(table, rowIndex, ans, *returnSize);
        free_table(table, *returnSize);
        return ans;
    }

    for(int i = 2; i < *returnSize; ++i)
    {
        table[i][0] = 1;

        int j;
        for(j = 1; j < i; ++j)
            table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
        
        table[i][j] = 1;
    }
    
    copy_row(table, rowIndex, ans, *returnSize);
    free_table(table, *returnSize);
    return ans;
}