int cmp(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

int numRescueBoats(int* people, int peopleSize, int limit) {
    qsort(people, peopleSize, sizeof(int), cmp);

    int i = 0;
    int count = 0;
    int people_size = peopleSize - 1;
    while(i <= people_size)
    {
        if(people[i] + people[people_size] <= limit)
            ++i;
        
        --people_size;
        ++count;
    }

    return count;
}
