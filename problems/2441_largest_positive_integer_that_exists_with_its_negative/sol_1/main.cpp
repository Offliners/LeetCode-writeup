class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int neg_arr[1001] = {0};
        int pos_arr[1001] = {0};

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] < 0)
                neg_arr[-nums[i]] += 1;
            else
                pos_arr[nums[i]] += 1;
        }

        int maxK = -1;
        for(int i = 0; i < 1001; ++i)
        {
            if(neg_arr[i] > 0 && pos_arr[i] > 0)
                maxK = i;
        }

        return maxK;
    }
};