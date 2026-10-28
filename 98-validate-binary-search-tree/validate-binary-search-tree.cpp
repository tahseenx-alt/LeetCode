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
    bool isValidBST(TreeNode* root) {
        return checktree(root,LONG_LONG_MIN,LONG_LONG_MAX);
    }
    bool checktree(TreeNode * root,long long lower,long long upper){
        if(root == nullptr){
            return true;
        }
        if(root->val<=lower || root->val >=upper){
            return false;
        }
        return checktree(root->left,lower,root->val) && checktree(root->right,root->val,upper); 
    }
};