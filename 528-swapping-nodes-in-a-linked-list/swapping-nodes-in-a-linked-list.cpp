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
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        ListNode* temp=head;
        int nodeval1=0;
        int nodeval2=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int i=0;
        temp=head;
        while(temp!=NULL){
            i++;
            if(i==k){
                nodeval1=temp->val;
            }
            if(i==n-k+1){
                nodeval2=temp->val;
            }
            temp=temp->next;
        }
        i=0;
        temp=head;
        while(temp!=NULL){
            i++;
            if(i==k){
                temp->val=nodeval2;
            }
            if(i==n-k+1){
                temp->val=nodeval1;
            }
            temp=temp->next;
        }
        return head;
    }
};