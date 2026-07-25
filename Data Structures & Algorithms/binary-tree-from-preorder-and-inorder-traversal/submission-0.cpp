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
    int findIndex(vector<int>&inorder,int &element){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==element){
                return i;
            }
        }
    }
    TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int &preOrderIndex,int s,int e){
        if(s>e){
            return NULL;
        }
        int element=preorder[preOrderIndex];
        TreeNode* root=new TreeNode(element);
        preOrderIndex++;
        int elementKaIndex=findIndex(inorder,element);
        root->left=solve(preorder,inorder,preOrderIndex,s,elementKaIndex-1);
        root->right=solve(preorder,inorder,preOrderIndex,elementKaIndex+1,e);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex=0;
        int s=0;
        int e=inorder.size()-1;
        return solve(preorder,inorder,preOrderIndex,s,e);
    }
};
