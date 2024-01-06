int cmp(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    
    int count = 0;
    int g_index = 0;
    int s_index = 0;

    while(g_index < gSize && s_index < sSize)
    {
        if(g[g_index] <= s[s_index])
        {
            ++count;
            ++g_index;
        }

        ++s_index;
    }

    return count;
}