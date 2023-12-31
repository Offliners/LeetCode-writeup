class Solution:
    def search(self, nums: List[int], target: int) -> int:
        front = 0
        end = len(nums) - 1

        while front <= end:
            mid = front + (end - front) // 2

            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                front = mid + 1
            else:
                end = mid - 1
        
        return -1