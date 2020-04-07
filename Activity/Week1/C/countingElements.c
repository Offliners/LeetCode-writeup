int compare(const void *num1, const void *num2)
{
    return *(const int*)num1 - *(const int*)num2;
}

int countElements(int* arr, int arrSize){
    int count = 0;
    int number = 1;
    
    qsort(arr, arrSize, sizeof(int), compare);
    
    for(int i = 1; i <arrSize; i++)
    {
        if(arr[i] != arr[i-1])
        {
            if(arr[i] == arr[i-1] + 1)
                count += number;
            number = 1;
        }
        else
            number++;
    }
    
    return count;
}
