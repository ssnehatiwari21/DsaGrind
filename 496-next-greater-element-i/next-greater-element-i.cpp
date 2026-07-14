class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        unordered_map<int,int> map;
        vector<int> ans(n1);
        stack<int> st;

        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                map[nums2[i]]=-1;
            }else{
                map[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }

        for(int j=0;j<n1;j++){
            ans[j]=map[nums1[j]];
        }
        return ans;
    }
};