class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        left, right = 0, len(nums)
        
        while right - left != 1:
            mid = left + (right - left) // 2
            
            if (nums[mid - 1] < nums[mid]) and (nums[mid] < nums[mid + 1]):
                return nums[mid]
            
            if (mid % 2 == 1) and (nums[mid - 1] < nums[mid]) and (nums[mid] == nums[mid + 1]):
                right = mid
            elif (mid % 2 == 0) and (nums[mid - 1] == nums[mid]) and (nums[mid] < nums[mid + 1]):
                right = mid - 1
            elif (mid % 2 == 0) and (nums[mid - 1] < nums[mid]) and (nums[mid] == nums[mid + 1]):
                left = mid + 2
            elif (mid % 2 == 1) and (nums[mid - 1] == nums[mid]) and (nums[mid] < nums[mid + 1]):
                left = mid + 1
    
        return nums[left]
