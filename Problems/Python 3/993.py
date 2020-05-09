# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        nodeVal = {root.val: root}
        nodeParent = {root: None}
        
        while True:
            xNode = nodeVal.get(x, None)
            yNode = nodeVal.get(y, None)
            
            if xNode is not None and yNode is not None:
                return nodeParent[xNode] != nodeParent[yNode]
            
            if xNode is not None or yNode is not None:
                return False
            
            newvalNode = {}
            
            for node in nodeVal.values():
                if node.left:
                    nodeParent[node.left] = node
                    newvalNode[node.left.val] = node.left
                    
                if node.right:
                    nodeParent[node.right] = node
                    newvalNode[node.right.val] = node.right
            
            nodeVal = newvalNode
