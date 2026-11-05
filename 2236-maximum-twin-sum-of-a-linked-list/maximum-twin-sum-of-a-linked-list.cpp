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
    ListNode* reverse(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* newHead = reverse(head->next);

        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
    int pairSum(ListNode* head) {
        int res=-1e9;
        //find the mid node
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=reverse(slow);
        ListNode* start=head;
        while(mid!=NULL){
            res=max(res,start->val+mid->val);
            start=start->next;
            mid=mid->next;
        }
        return res;
    }
};