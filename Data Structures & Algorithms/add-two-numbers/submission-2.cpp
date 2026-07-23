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

// class Solution {
// public:
//     ListNode* solve(ListNode* l1, ListNode* l2,int &carry){
//         if(l1==NULL && l2==NULL){
//             return NULL;
//         }
//         int sum=0;
//         sum+=(l1==NULL?0:l1->val);
//         sum+=(l2==NULL?0:l2->val);
//         sum+=carry;
//         carry=sum/10;
//         ListNode* head=new ListNode(sum%10);
//         if(l1==NULL){
//             head->next=solve(l1,l2->next,carry);
//         }
//         if(l2==NULL){
//             head->next=solve(l1->next,l2,carry);
//         }
//         if(l1!=NULL && l2!=NULL){
//             head->next=solve(l1->next,l2->next,carry);
//         }
//         return head;
//     }
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int carry=0;
//         ListNode* root=solve(l1,l2,carry);
//         if(carry){
//             ListNode* temp=root;
//             while(temp->next!=NULL){
//                 temp=temp->next;
//             }
//             ListNode* curr=new ListNode(carry);
//             temp->next=curr;
//             return root;
//         }
//         return root;
//     }
// };





class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int v1 = (l1 != nullptr) ? l1->val : 0;
            int v2 = (l2 != nullptr) ? l2->val : 0;
            int sum = v1 + v2 + carry;
            carry = sum / 10;
            int dig = sum%10;

            cur->next = new ListNode(dig);
            cur = cur->next;

            if (l1 != nullptr) { l1 = l1->next; }
            if (l2 != nullptr ) { l2 = l2->next;}
        }   
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
