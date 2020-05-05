int cmp(const void *a, const void *b)
{
    return *(const char*)a - *(const char*)b;
}

bool canConstruct(char * ransomNote, char * magazine){
    int ransomNoteSize = strlen(ransomNote);
    int magazineSize = strlen(magazine);
    int i = 0, j = 0;
    
    qsort(ransomNote, ransomNoteSize, sizeof(char), cmp);
    qsort(magazine, magazineSize, sizeof(char), cmp);
    
    while((i != ransomNoteSize)&&(j != magazineSize))
    {
        if(ransomNote[i] == magazine[j])
        {
            i++;
            j++;
        }
        else if(ransomNote[i] < magazine[j])
            return false;
        else
            j++;
    }
    
    return i == ransomNoteSize;
}
