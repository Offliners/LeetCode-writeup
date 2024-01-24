class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int left_sum = 0;
        int right_sum = 0;   

        for(int i = 0; i < nums.size(); ++i)
            right_sum += nums[i];
        
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i)
        {
            right_sum -= nums[i];
            ans.push_back(abs(left_sum - right_sum));
            left_sum += nums[i];
        }

        return ans;
    }
};