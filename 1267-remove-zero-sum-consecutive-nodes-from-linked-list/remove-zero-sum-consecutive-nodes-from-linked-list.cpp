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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next=head;
        unordered_map<int,ListNode*> map;
        map[0]=dummyNode;
        int prefixSum=0;
        while(head!=NULL){
            prefixSum+=head->val;
            if(map.find(prefixSum)!=map.end()){
                ListNode* start=map[prefixSum];
                ListNode* temp=start;
                int pSum=prefixSum;
                while(temp!=head){
                    temp=temp->next;
                    pSum+=temp->val;
                    if(map[pSum]!=start) map.erase(pSum);
                    
                }
                start->next=head->next;
            }else{
                map[prefixSum]=head;
            }
            head=head->next;
        }
        return dummyNode->next;
    }
};