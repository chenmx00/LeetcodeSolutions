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
// A very good question
class Solution {
public:
    int ret;
    int longestUnivaluePath(TreeNode* root) {
        ret = 0;
        uniValPath(root);
        return ret;
    }
    
    
    int uniValPath(TreeNode* root){
        if (root == NULL) return 0;
        int left = uniValPath(root->left);
        int right = uniValPath(root->right);
        int cur_left = 0;
        int cur_right = 0;
        if (root->left != NULL && root->val == root->left->val) {
            cur_left = left + 1;
        }
        if (root->right != NULL && root->val == root->right->val){
            cur_right = right + 1;
        }
        ret = std::max(ret, cur_left + cur_right);
        return std::max(cur_left, cur_right);
    }
};
