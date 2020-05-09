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

