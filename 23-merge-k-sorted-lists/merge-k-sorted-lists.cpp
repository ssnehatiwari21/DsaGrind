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
    ListNode* mergeTwoLists(ListNode* list1,ListNode* list2){
        if(list1==NULL && list2==NULL) return NULL;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        if(list1->val<=list2->val){
            list1->next=mergeTwoLists(list1->next,list2);
            return list1;
        }else{
            list2->next=mergeTwoLists(list1,list2->next);
            return list2;
        }
        return NULL;
    }
    ListNode* PartitionandMerge(int low,int high,vector<ListNode*>& lists){
        if(low==high) return lists[low];
        int mid=low+(high-low)/2;
        ListNode* L1=PartitionandMerge(low,mid,lists);
        ListNode* L2=PartitionandMerge(mid+1,high,lists);

        return mergeTwoLists(L1,L2);

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        int low=0;
        int high=lists.size()-1;
        return PartitionandMerge(low,high,lists);
    }
};