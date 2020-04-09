class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        def nextChar(str, index):
            delete = 0
            
            while index >=0 and (delete or str[index] == '#'):
                delete = delete + 1 if str[index] == '#' else delete - 1
                index -= 1
                
            return index
        
        indexS, indexT = len(S) - 1, len(T) - 1
        
        while True:
            indexS, indexT = nextChar(S, indexS), nextChar(T, indexT)
            
            if indexS == -1 and indexT == -1:
                return True
            
            if indexS == -1 or indexT == -1:
                return False
            
            if S[indexS] != T[indexT]:
                return False
            
            indexS, indexT = indexS - 1, indexT - 1
