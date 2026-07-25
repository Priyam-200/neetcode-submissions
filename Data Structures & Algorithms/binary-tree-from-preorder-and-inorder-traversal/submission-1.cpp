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
    TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int &preOrderIndex,int s,int e,unordered_map<int,int>&mp){
        if(s>e){
            return NULL;
        }
        int element=preorder[preOrderIndex];
        TreeNode* root=new TreeNode(element);
        preOrderIndex++;
        int elementKaIndex=mp[element];
        root->left=solve(preorder,inorder,preOrderIndex,s,elementKaIndex-1,mp);
        root->right=solve(preorder,inorder,preOrderIndex,elementKaIndex+1,e,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex=0;
        int s=0;
        int e=inorder.size()-1;
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return solve(preorder,inorder,preOrderIndex,s,e,mp);
    }
};
