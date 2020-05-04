/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct
{
    char *origin;
    char *sort;
}Pair;

int compareChar(const void *char1, const void *char2)
{
    return *(const char*)char1 - *(const char*)char2;
}

int comparePair(const void *Pair1, const void *Pair2)
{
    const Pair* P1 = (const Pair*)Pair1;
    const Pair* P2 = (const Pair*)Pair2;
    
    return strcmp(P1->sort, P2->sort);
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    Pair* pairs = malloc(sizeof(Pair) * strsSize);
    char *** result = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    
    for(int i = 0; i < strsSize; i++)
    {
        char *strSort = malloc(sizeof(char) * (strlen(strs[i]) + 1));
        strcpy(strSort, strs[i]);
        qsort(strSort, strlen(strs[i]), sizeof(char), compareChar);
        pairs[i].origin = strs[i];
        pairs[i].sort = strSort;
    }
    
    qsort(pairs, strsSize, sizeof(Pair), comparePair);
    
    for(int i = 0; i < strsSize; i++)
    {
        if((i == 0) || (strcmp(pairs[i].sort, pairs[i-1].sort) != 0))
        {
            int lastIndex = *returnSize;
            
            result = realloc(result, sizeof(char**) * (*returnSize + 1));
            result[lastIndex] = malloc(sizeof(char*) * 1);
            result[lastIndex][0] = pairs[i].origin;
            
            (*returnSize)++;
                
            *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * (*returnSize));
            (*returnColumnSizes)[lastIndex] = 1;
        }
        else
        {
            int lastIndex = *returnSize - 1;
            int lastSizes = (*returnColumnSizes)[lastIndex];
            
            result[lastIndex] = realloc(result[lastIndex], sizeof(char*) * (lastSizes + 1));
            result[lastIndex][lastSizes] = pairs[i].origin;
            (*returnColumnSizes)[lastIndex] = lastSizes + 1;
        }
    }
    
    return result;
}
