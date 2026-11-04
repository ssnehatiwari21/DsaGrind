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
        ListNode* node1=NULL;
        ListNode* node2=NULL;
        
        while(temp!=NULL){
            if(node2!=NULL) node2=node2->next;
            k--;
            if(k==0){
                node1=temp;
                node2=head;
            }
            temp=temp->next;
            
        }
        swap(node1->val,node2->val);
        return head;
    }
};