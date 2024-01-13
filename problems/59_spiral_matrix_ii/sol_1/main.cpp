class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 1)
            return {{1}};

        vector<vector<int>> ans(n, vector<int>(n, 0));
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int count = 1;
        while(top <= bottom && left <= right)
        {
            for(int i = left; i <= right; ++i)
            {
                ans[top][i] = count;
                ++count;
            }
            ++top;

            for(int j = top; j <= bottom; ++j)
            {
                ans[j][right] = count;
                ++count;
            }
            --right;

            if(top <= bottom)
            {
                for(int i = right; i >= left; --i)
                {
                    ans[bottom][i] = count;
                    ++count;
                }
                --bottom;
            }

            if(left <= right)
            {
                for(int j = bottom; j >= top; --j)
                {
                    ans[j][left] = count;
                    ++count;
                }
                ++left;
            }
        }

        return ans;
    }
};