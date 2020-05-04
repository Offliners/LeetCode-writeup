class Solution:
    def countElements(self, arr: List[int]) -> int:
        count = 0
        number = 1
        
        arr.sort()
        
        for i in range(len(arr)):
            if(arr[i] != arr[i-1]):
                if(arr[i] == arr[i-1] + 1):
                    count += number
                number = 1
            else:
                number += 1
                
        return count
