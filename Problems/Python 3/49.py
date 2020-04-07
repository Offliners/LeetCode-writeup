class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        result = defaultdict(list)
        
        for word in strs:
            charList = [char for char in word]
            charList.sort()
            wordSort = "".join(charList)
            result[wordSort].append(word)
            
        return list(result.values())
