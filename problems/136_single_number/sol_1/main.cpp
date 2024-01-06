class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums.front();
        for(int i = 1; i < nums.size(); ++i)
            ans ^= nums[i];
        
        return ans;
    }
};