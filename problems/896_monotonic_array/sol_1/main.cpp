class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool flag = false;
        int i;
        for(i = 1; i < nums.size(); ++i)
        {
            if(nums[i] != nums[i - 1])
            {
                flag = nums[i] > nums[i - 1] ? true : false;
                break;
            }
        }

        for(;i < nums.size(); ++i)
        {
            if(nums[i] > nums[i - 1] && !flag)
                return false;
            else if(nums[i] < nums[i - 1] && flag)
                return false;
        }

        return true;
    }
};