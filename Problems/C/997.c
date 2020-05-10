int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    int *trustNum = malloc(sizeof(int) * (N + 1));
    
    for(int i = 0; i < N + 1; i++)
        trustNum[i] = 0;
    
    for(int i = 0; i < trustSize; i++)
    {
        trustNum[trust[i][0]] -= 1;
        trustNum[trust[i][1]] += 1;
    }
    
    for(int i = 1; i < N + 1; i++)
        if(trustNum[i] == N - 1)
            return i;
    
    return -1;
}
