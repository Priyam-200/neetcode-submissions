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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        ans.push_back({root->val});
        while(!q.empty()){
            int size=q.size();
            vector<int>temp;
            for(int i=0;i<size;i++){
                auto frontNode=q.front();
                q.pop();
                if(frontNode->left){
                    temp.push_back(frontNode->left->val);
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    temp.push_back(frontNode->right->val);
                    q.push(frontNode->right);
                }
            }
            if(temp.size()){
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
