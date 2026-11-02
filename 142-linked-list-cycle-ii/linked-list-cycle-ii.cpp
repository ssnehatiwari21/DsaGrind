/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //bruteforce
        unordered_set<ListNode*> s;
        ListNode* temp=head;
        while(temp!=NULL){
            if(s.find(temp)==s.end()){
                s.insert(temp);
            }else{
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }
};