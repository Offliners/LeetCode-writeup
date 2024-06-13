int abs(int n)
{
    return (n >= 0) ? n : -n;
}

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    int arr_size = 101;
    int *mismatch = (int*)malloc(arr_size * sizeof(int));
    for(int i = 0; i < arr_size; ++i)
        mismatch[i] = 0;
    
    for(int i = 0; i < seatsSize; ++i)
    {
        mismatch[seats[i]]++;
        mismatch[students[i]]--;
    }

    int move = 0;
    int diff = 0;
    for(int i = 0; i < arr_size; ++i)
    {
        move += abs(diff);
        diff += mismatch[i];
    }

    free(mismatch);
    return move;
}