int climbStairs(int n) {
    int *table = (int*)malloc(45 * sizeof(int));

    table[0] = 1;
    table[1] = 2;
    for(int i = 2; i < n; ++i)
        table[i] = table[i - 1] + table[i - 2];

    int ans = table[n - 1];
    free(table);

    return ans;
}