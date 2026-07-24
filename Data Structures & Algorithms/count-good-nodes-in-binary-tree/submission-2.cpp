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
//     int solve(TreeNode* root,int maxi){
//         if(root==NULL){
//             return 0;
//         }
//         int ans=0;
//         ans=(root->val>=maxi?1:0);
//         maxi=max(maxi,root->val);
//         ans+=solve(root->left,maxi);
//         ans+=solve(root->right,maxi);
//         return ans;
//     }
//     int goodNodes(TreeNode* root) {
//         int maxi=INT_MIN;
//         return solve(root,maxi);
//     }
// };



class Solution {
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, -INT_MAX});

        while (!q.empty()) {
            auto [node, maxval] = q.front();
            q.pop();
            if (node->val >= maxval) {
                res++;
            }
            if (node->left) {
                q.push({node->left, max(maxval, node->val)});
            }
            if (node->right) {
                q.push({node->right, max(maxval, node->val)});
            }
        }
        return res;
    }
};
