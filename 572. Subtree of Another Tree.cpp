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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s==NULL || t==NULL){
            return false;
        }
        
        return isIdentical(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
        
    }
    
    bool isIdentical(TreeNode* s, TreeNode* t) {
        if (s==NULL && t==NULL){
            return true;
        }
        if (s==NULL || t==NULL){
            return false;
        }
        if (s->val == t->val){
            return true && isIdentical(s->left, t->left) && isIdentical(s->right, t->right);
        }
        return false;
    }
};