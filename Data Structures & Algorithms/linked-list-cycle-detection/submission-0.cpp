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
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*,bool>mp;
        while(head!=NULL){
            if(mp.find(head)!=mp.end()){
                return true;
            }
            mp[head]=true;
            head=head->next;
        }
        return false;
    }
};
