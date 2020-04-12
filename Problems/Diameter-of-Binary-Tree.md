# Diameter of Binary Tree
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 

This path may or may not pass through the root.

#### Example
```
          1
         / \
        2   3
       / \     
      4   5
```
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

### Python 3
```python
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
```
[code](Python%203/543.py)

#### Result
```
Runtime: 52 ms, faster than 16.07% of Python3 online submissions for Diameter of Binary Tree.
Memory Usage: 15.9 MB, less than 51.72% of Python3 online submissions for Diameter of Binary Tree.
```

### C
```C

```
[code](C/543.c)

#### Result
```

```
