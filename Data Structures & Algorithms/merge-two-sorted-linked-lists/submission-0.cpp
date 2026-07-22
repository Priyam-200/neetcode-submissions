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
    void insertAtHead(ListNode* &head,ListNode* &tail,ListNode* &curr){
        if(head==NULL && tail==NULL){
            head=curr;
            tail=curr;
        }
        else{
            tail->next=curr;
            tail=curr;
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(list1!=NULL || list2!=NULL){
            bool ans1=(list1==NULL?false:true);
            bool ans2=(list2==NULL?false:true);
            if(ans1 && ans2){
                if(list1->val<list2->val){
                    ListNode* curr=list1;
                    list1=list1->next;
                    curr->next=NULL;
                    insertAtHead(head,tail,curr);
                }
                else{
                    ListNode* curr=list2;
                    list2=list2->next;
                    curr->next=NULL;
                    insertAtHead(head,tail,curr);
                }
            }
            else if(ans1){
                ListNode* curr=list1;
                list1=list1->next;
                curr->next=NULL;
                insertAtHead(head,tail,curr);
            }
            else if(ans2){
                ListNode* curr=list2;
                list2=list2->next;
                curr->next=NULL;
                insertAtHead(head,tail,curr);
            }
        }
        return head;
    }
};
