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
    int solve(TreeNode* root,int maxi){
        if(root==NULL){
            return 0;
        }
        int ans=0;
        ans=(root->val>=maxi?1:0);
        maxi=max(maxi,root->val);
        ans+=solve(root->left,maxi);
        ans+=solve(root->right,maxi);
        return ans;
    }
    int goodNodes(TreeNode* root) {
        int maxi=INT_MIN;
        return solve(root,maxi);
    }
};
