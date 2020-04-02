# Day 1 - Single Number
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

#### Example 1
```
Input: [2,2,1]
Output: 1
```

#### Example 2
```
Input: [4,1,2,1,2]
Output: 4
```

### C
```C
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
}
```
[code](code/singleNumber.c)
#### Result
```
Runtime: 1184 ms
Memory Usage: 6.4 MB
```
