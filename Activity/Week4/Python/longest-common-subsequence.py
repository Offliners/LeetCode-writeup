class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        len1, len2 = len(text1), len(text2)
        LCS = [0 for _ in range(len2 + 1)]
        
        for char1 in text1:
            newLCS = [0]
            
            for num ,char2 in enumerate(text2):
                if char1 == char2:
                    newLCS.append(1 + LCS[num])
                else:
                    newLCS.append(max(newLCS[-1], LCS[num + 1]))
                
            LCS = newLCS
                
        return LCS[-1] 
