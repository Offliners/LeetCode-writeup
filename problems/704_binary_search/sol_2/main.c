int search(int* nums, int numsSize, int target) {
    int front = 0;
    int end = numsSize - 1;

    while(front <= end)
    {
        int mid = front + (end - front) / 2;

        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            front = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}