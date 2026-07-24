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
    string preOrder(TreeNode* root) {
        if(root==NULL){
            return "NULL";
        }
        string s="^";
        s+=to_string(root->val);
        s+=preOrder(root->left);
        s+=preOrder(root->right);
        return s;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string fullTree=preOrder(root);
        string subTree=preOrder(subRoot);
        return fullTree.find(subTree)!=string::npos;
    }
};



// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p==NULL && q==NULL){
//             return true;
//         }
//         else if(p==NULL || q==NULL){
//             return false;
//         }
//         return ((p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
//     }
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         if(root==NULL){
//             return false;
//         }
//         bool ans=isSameTree(root,subRoot);
//         bool left=isSubtree(root->left,subRoot);
//         bool right=isSubtree(root->right,subRoot);
//         if(ans || left || right){
//             return true;
//         }
//         return false;
//     }
// };
