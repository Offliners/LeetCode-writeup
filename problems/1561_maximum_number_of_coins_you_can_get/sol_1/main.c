int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int maxCoins(int* piles, int pilesSize) {
    qsort(piles, pilesSize, sizeof(int), cmp);

    int max_you = 0;
    int left = 0;
    int right = pilesSize - 1;
    while(left < right)
    {
        if(left < right)
            max_you += piles[right - 1];
        
        ++left;
        right -= 2;
    }

    return max_you;
}