# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        
        self.result = 0
        
        def maxDepth(node):
            if not node:
                return -1
            
            maxLeft = maxDepth(node.left)
            maxRight = maxDepth(node.right)
            self.result = max(self.result, maxLeft + maxRight + 2)
            
            return max(maxLeft + 1, maxRight + 1)
        
        maxDepth(root)
        
        return self.result
