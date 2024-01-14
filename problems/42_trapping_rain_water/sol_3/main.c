int trap(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int left_max = -1;
    int right_max = -1;

    int ans = 0;
    while(left < right)
    {
        left_max = left_max < height[left] ? height[left] : left_max;
        right_max = right_max < height[right] ? height[right] : right_max;

        if(left_max < right_max)
        {
            ans += left_max - height[left];
            ++left;
        }
        else
        {
            ans += right_max - height[right];
            --right;
        }
    }

    return ans;
}