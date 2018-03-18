/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int l, r;
    if (!root)
        return 0;
    else {
        l = maxDepth(root->left);
        r = maxDepth(root->right);
        return 1 + (l > r ? l : r);
    }
}
