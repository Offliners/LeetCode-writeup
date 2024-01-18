class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> table;

        table.push_back({1});
        if(rowIndex == 0)
            return table[0];
        
        table.push_back({1, 1});
        if(rowIndex == 1)
            return table[1];

        for(int i = 2; i < rowIndex + 1; ++i)
        {
            vector<int> row;
            row.push_back(1);
            for(int j = 1; j < i; ++j)
                row.push_back(table[i - 1][j - 1] + table[i - 1][j]);
            
            row.push_back(1);
            table.push_back(row);
        }

        return table[rowIndex];
    }
};