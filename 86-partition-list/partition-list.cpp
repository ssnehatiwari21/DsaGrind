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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallerhead=new ListNode(-1);
        ListNode* smallerpointer=smallerhead;
        ListNode* largerhead=new ListNode(-1);
        ListNode* largerpointer=largerhead;

        while(head!=NULL){
            if(head->val<x){
                smallerpointer->next=head;
                smallerpointer=smallerpointer->next;
            }else{
                largerpointer->next=head;
                largerpointer=largerpointer->next;
            }
            head=head->next;
        }
        smallerpointer->next=largerhead->next;
        largerpointer->next=NULL;
        return smallerhead->next;
    }
};