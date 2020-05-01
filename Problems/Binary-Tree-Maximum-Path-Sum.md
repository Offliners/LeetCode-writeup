# Binary Tree Maximum Path Sum
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

### Python 3
```python

```
[code](Python%203/124.py)

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
[code](C/124.c)

#### Result
```
Runtime: 384 ms, faster than 5.00% of C online submissions for Binary Tree Maximum Path Sum.
Memory Usage: 13.2 MB, less than 100.00% of C online submissions for Binary Tree Maximum Path Sum.
```
