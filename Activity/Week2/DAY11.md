# Day 11 - Diameter of Binary Tree
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
int maxDepth(struct TreeNode *root)
{
    if(root == NULL) 
        return 0;
    
    int maxLeft = maxDepth(root->left);
    int maxRight = maxDepth(root->right);
    
    if(maxLeft > maxRight)
        return maxLeft + 1;
    else
        return maxRight + 1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    if(root == NULL)
        return 0;
    
    int middle = maxDepth(root->left) + maxDepth(root->right);
    int left = diameterOfBinaryTree(root->left);
    int right = diameterOfBinaryTree(root->right);
    int max = middle;
    
    if(left > max)
        max = left;
    if(right > max)
        max = right;
    
    return max;
}
```
[code](C/Diameter-of-Binary-Tree.c)

#### Result
```
Runtime: 16 ms, faster than 23.13% of C online submissions for Diameter of Binary Tree.
Memory Usage: 7.6 MB, less than 100.00% of C online submissions for Diameter of Binary Tree.
```

### Python
```python

```
[code](Python/Diameter-of-Binary-Tree.py)

#### Result
```

```
