int trap(int* height, int heightSize) {
    int *table = (int*)malloc(heightSize * sizeof(int));
    int cur_max = 0;
    for(int i = 0; i < heightSize; ++i)
    {
        table[i] = cur_max;
        cur_max = cur_max > height[i] ? cur_max : height[i];
    }

    int ans = 0;
    cur_max = 0;
    for(int i = heightSize - 1; i >= 0; --i)
    {
        table[i] = table[i] < cur_max ? table[i] : cur_max;
        cur_max = cur_max > height[i] ? cur_max : height[i];
        
        if(table[i] > height[i])
            ans += table[i] - height[i];
    }

    free(table);
    return ans;
}