# Day 29 - Binary Tree Maximum Path Sum
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 

The path must contain at least one node and does not need to go through the root.

#### Example 1
```
Input: [1,2,3]

       1
      / \
     2   3

Output: 6
```

#### Example 2
```
Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
```

### C
```C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max3(int a, int b, int c)
{
    int max = a;
    
    if(max < b)
        max = b;
    
    if(max < c)
        max = c;
    
    return max;
}

int sumRoot(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    
    return max3(sumRoot(root->left) + root->val, 
                sumRoot(root->right) + root->val, 
                0);
}

int maxPathSum(struct TreeNode* root){
    if(root == NULL)
        return INT_MIN;
    
    return max3(
        sumRoot(root->left) + root->val + sumRoot(root->right), 
        maxPathSum(root->left), 
        maxPathSum(root->right));
}
```
[code](C/binary-tree-maximum-path-sum.c)

#### Result
```
Runtime: 384 ms, faster than 5.00% of C online submissions for Binary Tree Maximum Path Sum.
Memory Usage: 13.2 MB, less than 100.00% of C online submissions for Binary Tree Maximum Path Sum.
```

### Python
```python
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
```
[code](Python/binary-tree-maximum-path-sum.py)

#### Result
```
Runtime: 104 ms, faster than 20.92% of Python3 online submissions for Binary Tree Maximum Path Sum.
Memory Usage: 20.6 MB, less than 83.33% of Python3 online submissions for Binary Tree Maximum Path Sum.
```
