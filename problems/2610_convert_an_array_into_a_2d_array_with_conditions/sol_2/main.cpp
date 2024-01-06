class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> row(nums.size() + 1);
        vector<vector<int>> ans;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(row[nums[i]] >= ans.size())
                ans.push_back({});
            
            ans[row[nums[i]]].push_back(nums[i]);
            row[nums[i]]++;
        }

        return ans;
    }
};