# Day 7 - Cousins in Binary Tree
n a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

#### Example 1
```
Input: root = [1,2,3,4], x = 4, y = 3
Output: false
```

#### Example 2
```
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
```

#### Example 3
```
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
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
struct Info
{
    int depth;
    int parent;
};


struct Info getDepthandParent(struct TreeNode *root, int target, int parent)
{
    if(root == NULL)
        return (struct Info) {-1, 0};
    
    if(root->val == target)
        return (struct Info) {0, parent};
    
    struct Info left = getDepthandParent(root->left, target, root->val);
    struct Info right = getDepthandParent(root->right, target, root->val);
    
    if(left.parent != 0)
        return (struct Info) {left.depth + 1, left.parent};
    
    if(right.parent != 0)
        return (struct Info) {right.depth + 1, right.parent};
    
    return (struct Info) {-1, 0};
}

bool isCousins(struct TreeNode* root, int x, int y){
    struct Info xInfo = getDepthandParent(root, x, 0);
    struct Info yInfo = getDepthandParent(root, y, 0);
    
    return (xInfo.depth == yInfo.depth) && (xInfo.parent != yInfo.parent);
}

```
[code](C/cousins-in-binary-tree.c)

#### Result
```
Runtime: 0 ms, faster than 100.00% of C online submissions for Cousins in Binary Tree.
Memory Usage: 5.8 MB, less than 100.00% of C online submissions for Cousins in Binary Tree.
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
```
[code](Python/cousins-in-binary-tree.py)

#### Result
```
Runtime: 32 ms, faster than 63.00% of Python3 online submissions for Cousins in Binary Tree.
Memory Usage: 14 MB, less than 6.12% of Python3 online submissions for Cousins in Binary Tree.
```
