# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        return self.sumRoot(root)[0]
    
    def sumRoot(self, node):
        if not node:
            return float('-inf'), 0
        
        leftVia, leftDown = self.sumRoot(node.left)
        rightVia, rightDown = self.sumRoot(node.right)
        via = max(node.val + max(0, leftDown) + max(0, rightDown), leftVia, rightVia)
        down = node.val + max(0, leftDown, rightDown)
        
        return via, down
