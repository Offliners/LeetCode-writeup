int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int minimumCost(int* nums, int numsSize) {
    int min_cost = nums[0];

    nums = nums + 1;
    --numsSize;

    qsort(nums, numsSize, sizeof(int), cmp);
    min_cost += nums[0];
    min_cost += nums[1];

    return min_cost;
}