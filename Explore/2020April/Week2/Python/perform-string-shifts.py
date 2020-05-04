class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        strLen = len(s)
        total = 0
        
        for i in range(len(shift)):
            direction = shift[i][0]
            amount = shift[i][1]
            
            amount %= strLen;
            if direction == 1:
                amount = strLen - amount
                
            total += amount
            
        total %= strLen
        s = list(s)
        for _ in range(total):
            temp = s[0]
            for i in range(strLen-1):
                s[i] = s[i + 1]
                
            s[strLen - 1] = temp
        
        return "".join(s)
