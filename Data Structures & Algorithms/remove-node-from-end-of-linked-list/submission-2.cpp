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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++) fast = fast->next;
        if (!fast) return head->next;
        while (fast->next) fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return head;
    }
};
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int len=0;
//         ListNode* temp=head;
//         while(temp){
//             len++;
//             temp=temp->next;
//         }
//         if(len==n){
//             ListNode* curr=head->next;
//             head->next=NULL;
//             return curr;
//         }
//         int x=len-n-1;
//         temp=head;
//         while(x>0){
//             temp=temp->next;
//             x--;
//         }

//         ListNode* curr=temp->next;
//         ListNode* curr1=curr==NULL?NULL:curr->next;
//         if(curr!=NULL){
//             curr->next=NULL;
//         }
//         temp->next=curr1;
//         return head;
//     }
// };
