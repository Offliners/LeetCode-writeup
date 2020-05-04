class Solution:
    def isHappy(self, n: int) -> bool:
        def nextNum(num):
            result = 0

            while(num != 0):
                rem = num % 10
                num //= 10
                result += rem * rem

            return result
        
        num1 = n
        num2 = n
        
        while True:
            num1 = nextNum(num1)
            num2 = nextNum(nextNum(num2))
            
            if num1 == num2:
                break
                
        return num1 == 1
