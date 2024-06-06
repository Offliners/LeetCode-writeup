int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

bool find_successor(int* hand, int handSize, int groupSize, int index)
{
    int next = hand[index] + 1;
    hand[index] = -1;
    int count = 1;
    ++index;

    while(index < handSize && count < groupSize)
    {
        if(hand[index] == next)
        {
            next = hand[index] + 1;
            hand[index] = -1;
            ++count;
        }

        ++index;
    }

    return count == groupSize;
}

bool isNStraightHand(int* hand, int handSize, int groupSize) {
    if(handSize % groupSize != 0)
        return false;

    qsort(hand, handSize, sizeof(int), cmp);
    for(int i = 0; i < handSize; ++i)
        if(hand[i] >= 0 && !find_successor(hand, handSize, groupSize, i))
            return false;

    return true;    
}