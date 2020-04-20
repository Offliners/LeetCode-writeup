# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        self.topIndex = 0;
        
        def buildTree(max = float('inf')):
            if self.topIndex >= len(preorder) or preorder[self.topIndex] > max:
                return None
            
            root = TreeNode(preorder[self.topIndex])
            self.topIndex += 1
            root.left = buildTree(root.val)
            root.right = buildTree(max)
            
            return root
        
        return buildTree()
