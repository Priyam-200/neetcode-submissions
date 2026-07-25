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
    bool solveLeft(TreeNode* root,int elem){
        if(root==NULL){
            return true;
        }
        bool ans=true;
        ans=ans&(root->val<elem);
        bool left=solveLeft(root->left,elem);
        bool right=solveLeft(root->right,elem);
        return (ans&&left&&right);
    }
    bool solveRight(TreeNode* root,int elem){
        if(root==NULL){
            return true;
        }
        bool ans=true;
        ans=ans&(root->val>elem);
        bool left=solveRight(root->left,elem);
        bool right=solveRight(root->right,elem);
        return (ans&&left&&right);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        bool ans1=solveLeft(root->left,root->val);
        bool ans2=solveRight(root->right,root->val);
        bool left=isValidBST(root->left);
        bool right=isValidBST(root->right);
        return ans1&&ans2&&left&&right;
    }
};
