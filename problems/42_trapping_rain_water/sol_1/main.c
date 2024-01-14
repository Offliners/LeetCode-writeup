int trap(int* height, int heightSize) {
    int *left_table = (int*)malloc(heightSize * sizeof(int));
    int cur_max = 0;
    for(int i = 0; i < heightSize; ++i)
    {
        left_table[i] = cur_max;
        cur_max = cur_max > height[i] ? cur_max : height[i];
    }

    int *right_table = (int*)malloc(heightSize * sizeof(int));
    cur_max = 0;
    for(int i = heightSize - 1; i >= 0; --i)
    {
        right_table[i] = cur_max;
        cur_max = cur_max > height[i] ? cur_max : height[i];
    }

    int ans = 0;
    for(int i = 0; i < heightSize; ++i)
    {
        if(left_table[i] > height[i] && height[i] < right_table[i])
        {
            int min_height = left_table[i] < right_table[i] ? left_table[i] : right_table[i];
            ans += min_height - height[i];
        }
    }

    free(left_table);
    free(right_table);
    return ans;
}