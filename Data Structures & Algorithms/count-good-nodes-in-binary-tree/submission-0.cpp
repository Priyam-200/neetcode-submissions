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
    void solve(TreeNode* root,int maxi,int &count){
        if(root==NULL){
            return;
        }
        if(maxi<=root->val){
            count++;
        }
        solve(root->left,max(maxi,root->val),count);
        solve(root->right,max(maxi,root->val),count);
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        int maxi=INT_MIN;
        solve(root,maxi,count);
        return count;
    }
};
