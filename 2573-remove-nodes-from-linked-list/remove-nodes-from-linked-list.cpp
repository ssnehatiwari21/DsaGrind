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
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp=head;
        stack<int> st;
        while(temp!=nullptr){
            st.push(temp->val);
            temp=temp->next;
        }
        ListNode* newhead=new ListNode(st.top());
        temp=newhead;
        int max=st.top();
        st.pop();
        while(!st.empty()){
            ListNode* newNode=new ListNode(st.top());
            
            if(newNode->val >=max){
                max=st.top();
                newNode->next=temp;
                temp=newNode;
            }
            st.pop();
        }
        return temp;
    }
};