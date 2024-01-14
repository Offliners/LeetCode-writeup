class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_table(height.size());
        int cur_max = 0;
        for(int i = 0; i < height.size(); ++i)
        {
            left_table[i] = cur_max;
            cur_max = max(cur_max, height[i]);
        }

        vector<int> right_table(height.size());
        cur_max = 0;
        for(int i = height.size() - 1; i >= 0; --i)
        {
            right_table[i] = cur_max;
            cur_max = max(cur_max, height[i]);
        }

        int ans = 0;
        for(int i = 0; i < height.size(); ++i)
            if(left_table[i] > height[i] && height[i] < right_table[i])
                ans += min(left_table[i], right_table[i]) - height[i];

        return ans;
    }
};