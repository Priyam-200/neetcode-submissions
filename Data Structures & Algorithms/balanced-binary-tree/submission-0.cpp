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
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=solve(root->left);
        int right=solve(root->right);
        int maxD=max(left,right)+1;
        return maxD;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int lh=solve(root->left);
        int rh=solve(root->right);
        bool ans=(abs(lh-rh)<=1);
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        if(ans && left && right){
            return true;
        }
        return false;
    }
};
