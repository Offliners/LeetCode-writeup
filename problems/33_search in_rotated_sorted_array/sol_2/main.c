int search(int* nums, int numsSize, int target) {
    int front = 0;
    int end = numsSize - 1;

    while(front <= end)
    {
        int mid = front + (end - front) / 2;
        if(nums[mid] == target)
            return mid;
        else
        {
            if(nums[front] <= nums[mid])
            {
                if(nums[front] <= target && target <= nums[mid])
                    end = mid - 1;
                else
                    front = mid + 1;
            }
            else
            {
                if(nums[mid] <= target && target <= nums[end])
                    front = mid + 1;
                else
                    end = mid - 1;
            }
        }
    }

    return -1;
}