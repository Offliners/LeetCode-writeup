class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        if m == 0:
            return 0
        
        result = 0
        bit = int(log(n, 2))
        
        while bit >= 0 and ((m &  (1 << bit)) == (n & (1 << bit))):
            if (m & (1 << bit)):
                result += 2**bit
                
            bit -= 1
        
        return result
