int takeMax(int *counter, int upperBound)
{
    for(int i = upperBound; i > 0; i--)
    {
        if(counter[i] > 0)
        {
            counter[i]--;
            return i;
        }
    }
    
    return 0;
}

void insert(int *counter, int value)
{
    counter[value]++;
}

int lastStoneWeight(int* stones, int stonesSize){
    int counter[1001] = {0};
    int upperBound = 1000;
    
    for(int i = 0; i < stonesSize; i++)
        counter[stones[i]]++;
    
    while(true)
    {
        int y = takeMax(counter, upperBound);
        int x = takeMax(counter, upperBound);
        
        upperBound = y;
        
        if(x == 0)
            return y;
        if(x != y)
            insert(counter, y - x);
    }
    
    return 0;
}
