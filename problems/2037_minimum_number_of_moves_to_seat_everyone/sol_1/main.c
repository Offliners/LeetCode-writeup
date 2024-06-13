int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int abs(int n)
{
    return (n >= 0) ? n : -n;
}

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    qsort(seats, seatsSize, sizeof(int), cmp);
    qsort(students, studentsSize, sizeof(int), cmp);

    int move = 0;
    for(int i = 0; i < seatsSize; ++i)
        move += abs(seats[i] - students[i]);
    
    return move;
}