class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != 0 && nums[slow] == 0)
            {
                int temp = nums[i];
                nums[i] = nums[slow];
                nums[slow] = temp;
            }
            
            if(nums[slow] != 0)
                ++slow;
        }
    }
};