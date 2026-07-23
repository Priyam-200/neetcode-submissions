/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
        ListNode* dummy=new ListNode(0);
        ListNode* head=dummy;
        for(auto list:lists){
            pq.push(list);
        }
        while(!pq.empty()){
            ListNode* frontNode=pq.top();
            pq.pop();
            // ListNode* curr=frontNode;
            // frontNode=frontNode->next;
            // curr->next=NULL;
            // dummy->next=curr;
            // dummy=dummy->next;
            dummy->next=frontNode;
            dummy=dummy->next;
            if(frontNode->next){
                pq.push(frontNode->next);
            }
        }
        return head->next;
    }
};
