int singleNumber(int* nums, int numsSize){
    int n;
    
    numSort(nums, numsSize);
    n = nums[0];
    
    for(int i = 1; i < numsSize; i++)
        n ^= nums[i];
    return n;
}

void numSort(int list[],int n)
{
	int min;

	for(int i = 0;i < n;i++)
	{
		min = i;

		for(int j = i + 1;j < n;j++)
		{
			if(list[j] < list[min])
				min = j;
		}
		Swap(&list[i],&list[min]);
	}
}

void Swap(int *a,int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
