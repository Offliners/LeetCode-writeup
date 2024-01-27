class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left;
        vector<int> right;

        int pivot_count = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == pivot)
                ++pivot_count;
            else if(nums[i] < pivot)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        for(int i = 0; i < pivot_count; ++i)
            left.push_back(pivot);
        
        for(int i = 0; i < right.size(); ++i)
            left.push_back(right[i]);

        return left;
    }
};