int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int heightChecker(int* heights, int heightsSize) {
    int *expected = (int*)malloc(heightsSize * sizeof(int));
    for(int i = 0; i < heightsSize; ++i)
        expected[i] = heights[i];

    qsort(expected, heightsSize, sizeof(int), cmp);
    
    int ans = 0;
    for(int i = 0; i < heightsSize; ++i)
        if(heights[i] != expected[i])
            ++ans;
    
    return ans;
}