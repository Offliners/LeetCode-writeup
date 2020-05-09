# Cousins in Binary Tree
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

### Python 3
```python

```
[code](Python%203/993.py)

#### Result
```

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
[code](C/993.c)

#### Result
```
Runtime: 0 ms, faster than 100.00% of C online submissions for Cousins in Binary Tree.
Memory Usage: 5.8 MB, less than 100.00% of C online submissions for Cousins in Binary Tree.
```
