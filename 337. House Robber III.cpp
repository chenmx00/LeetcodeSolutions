/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;　
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        if (root==NULL) return 0;
        int val1 = root->val;
        if (root->left != NULL) val1 = val1 + rob(root->left->left) + rob(root->left->right);
        if (root->right != NULL) val1 = val1 + rob(root->right->left) + rob(root->right->right);
        int val2 = rob(root->left) + rob(root->right);
        return max(val1, val2);
    }
};