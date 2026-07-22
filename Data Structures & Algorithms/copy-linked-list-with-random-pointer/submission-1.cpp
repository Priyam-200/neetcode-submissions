/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* solve(Node* head,unordered_map<Node*,Node*>&mp){
        if(head==NULL){
            return NULL;
        }
        Node* newNode=new Node(head->val);
        mp[head]=newNode;
        newNode->next=solve(head->next,mp);
        if(head->random){
            newNode->random=mp[head->random];
        }
        return newNode;
    }
    Node* copyRandomList(Node* head) {
        Node* curr=NULL;
        unordered_map<Node*,Node*>mp;
        return solve(head,mp);
    }
};
