class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        magazineCount = Counter(magazine)
        ransomNoteCount = Counter(ransomNote)
        
        for c in ransomNoteCount:
            if c not in ransomNoteCount or magazineCount[c] < ransomNoteCount[c]:
                return False
            
        return True
