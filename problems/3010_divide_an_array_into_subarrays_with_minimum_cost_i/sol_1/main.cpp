class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int min_cost = nums.front();
        nums.erase(nums.begin());
        sort(nums.begin(), nums.end());

        min_cost += nums[0];
        min_cost += nums[1];

        return min_cost;
    }
};