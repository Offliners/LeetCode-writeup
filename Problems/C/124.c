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
