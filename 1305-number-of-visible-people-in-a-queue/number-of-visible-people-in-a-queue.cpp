class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int> ans(n,0);
        stack<int> st;
        
        st.push(heights[n-1]);
        for(int i=n-2;i>=0;i--){
            int cnt=0;
            while(!st.empty() && st.top()<heights[i]){
                st.pop();
                cnt++;
            }
            if(!st.empty()) cnt++;
            ans[i]=cnt;
            st.push(heights[i]);
        }
        return ans;
    }
};