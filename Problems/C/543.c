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
