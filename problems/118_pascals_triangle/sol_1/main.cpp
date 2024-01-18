class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1)
            return {{1}};

        if(numRows == 2)
            return {{1}, {1, 1}};        

        vector<vector<int>> ans;
        ans.push_back({1});
        ans.push_back({1, 1});
        for(int i = 2; i < numRows; ++i)
        {
            vector<int> row;
            row.push_back(1);
            for(int j = 1; j < i; ++j)
                row.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            
            row.push_back(1);
            ans.push_back(row);
        }

        return ans;
    }
};