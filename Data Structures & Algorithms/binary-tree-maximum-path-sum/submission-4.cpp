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

// class Solution {
// public:
//     int solve(TreeNode* root){
//         if(root==NULL){
//             return 0;
//         }
//         int left=root->val+solve(root->left);
//         int right=root->val+solve(root->right);
//         return max(left,right);
//     }
//     int maxPathSum(TreeNode* root) {
//         if(root==NULL){
//             return INT_MIN;
//         }
//         int ans=solve(root->left)+solve(root->right)+root->val;
//         int left=maxPathSum(root->left);
//         int right=maxPathSum(root->right);
//         return max({ans,left,right});
//     }
// };




class Solution {
public:
    int ans = INT_MIN;

    int helper(TreeNode* node) {
        if (!node) return 0;
        int left = max(helper(node->left), 0);
        int right = max(helper(node->right), 0);
        ans = max(ans, node->val + left + right);
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};
