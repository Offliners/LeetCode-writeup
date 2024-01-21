class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> table;
        cal_permute(0, nums, table);

        return table;
    }

    void cal_permute(int level, vector<int>& nums, vector<vector<int>>& table)
    {
        if(level == nums.size())
        {
            table.push_back(nums);
            return;
        }
        
        for(int i = level; i < nums.size(); ++i)
        {
            swap(nums[i], nums[level]);
            cal_permute(level + 1, nums, table);
            swap(nums[i], nums[level]);
        }
    }
};