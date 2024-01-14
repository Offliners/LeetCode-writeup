class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> table(height.size());
        int cur_max = 0;
        for(int i = 0; i < height.size(); ++i)
        {
            table[i] = cur_max;
            cur_max = max(cur_max, height[i]);
        }

        cur_max = 0;
        int ans = 0;
        for(int i = height.size() - 1; i >= 0; --i)
        {
            table[i] = min(table[i], cur_max);
            cur_max = max(cur_max, height[i]);

            if(table[i] > height[i])
                ans += table[i] - height[i];
        }

        return ans;
    }
};