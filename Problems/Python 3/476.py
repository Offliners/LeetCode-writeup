class Solution:
    def findComplement(self, num: int) -> int:
        mask = num
        i = 1
        
        while i <= 16:
            mask |= mask>>i
            i *= 2
        
        return num ^ mask
