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
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL || root->left == NULL || root->right == NULL){
            return -1;
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if(root->val == left->val){
            left->val =  findSecondMinimumValue(root->left);
        }
        if(root->val == right->val){
            right->val = findSecondMinimumValue(root->right);
        }
        if (left->val != -1 && right->val != -1){
            return min(left->val, right->val);
        }
        if(left->val == -1){
            return right->val;
        } else {
            return left->val;
        }
        
    }
};