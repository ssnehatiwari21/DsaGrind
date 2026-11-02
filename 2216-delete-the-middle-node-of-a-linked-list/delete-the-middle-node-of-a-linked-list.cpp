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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return NULL;
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        ListNode *prev=NULL;
        temp=head;
        int i=0;
        while(i<n/2){
            prev=temp;
            temp=temp->next;
            i++;
        }
        while(temp->next!=NULL){
            temp->val=temp->next->val;
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        return head;
    }
};