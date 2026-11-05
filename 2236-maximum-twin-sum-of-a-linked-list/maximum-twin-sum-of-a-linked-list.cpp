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
    int pairSum(ListNode* head) {
        //using stack data structure
        stack<ListNode*> st;
        ListNode* temp=head;
        int n=0;
        int maxi=-1e9;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        temp=head;
        int i=0;
        while(i<=(n/2)-1){
            st.push(temp);
            temp=temp->next;
            i++;
        }
        while(temp!=NULL && !st.empty()){
            maxi=max(maxi,st.top()->val+temp->val);
            st.pop();
            temp=temp->next;
        }
        return maxi;
    }
};