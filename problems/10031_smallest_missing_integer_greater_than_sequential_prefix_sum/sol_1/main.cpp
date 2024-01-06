class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int candidate = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] == nums[i - 1] + 1)
                candidate += nums[i];
            else
                break;
        }
        
        while(std::find(nums.begin(), nums.end(), candidate) != nums.end())
            ++candidate;
        
        return candidate;
    }
};