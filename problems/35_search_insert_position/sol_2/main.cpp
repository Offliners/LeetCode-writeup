class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int front = 0;
        int end = nums.size() - 1;

        while(front <= end)
        {
            int mid = front + (end - front) / 2;

            if(nums[mid] < target)
                front = mid + 1;
            else
                end = mid - 1;
        }

        return front;
    }
};