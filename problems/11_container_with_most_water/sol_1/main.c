int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;

    int max_area = 0;
    while(left < right)
    {
        int min_height = height[left] < height[right] ? height[left] : height[right];
        int cur_area = min_height * (right - left);
        max_area = max_area < cur_area ? cur_area : max_area;

        if(height[left] < height[right])
            ++left;
        else
            --right;
    }

    return max_area;
}