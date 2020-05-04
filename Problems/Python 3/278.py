# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        first, last = 1, n+1
        mid = first + (last - first) // 2
        
        while not(isBadVersion(mid) and (not isBadVersion(mid-1))):
            if not isBadVersion(mid):
                first = mid + 1
            else:
                last = mid
            
            mid = first + (last - first) // 2
        
        return mid
