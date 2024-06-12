void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize) {
    int left = 0;
    int mid = 0;
    int right = numsSize - 1;

    while(mid <= right)
    {
        if(nums[mid] == 0)
        {
            swap(&nums[left], &nums[mid]);
            ++left;
            ++mid;
        }
        else if(nums[mid] == 1)
            ++mid;
        else
        {
            swap(&nums[mid], &nums[right]);
            --right;
        }
    }
}