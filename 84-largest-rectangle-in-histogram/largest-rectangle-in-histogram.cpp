class Solution {
public:
    vector<int> nse(vector<int> & heights){
        int n=heights.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }else{
                nse[i]=st.top();
            }
            st.push(i);
        }
        return nse;
    }
    vector<int> pse(vector<int> &heights){
        int n=heights.size();
        stack<int> st;
        vector<int> pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i]=-1;
            }else{
                pse[i]=st.top();
            }
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> prev=pse(heights);
        vector<int> next=nse(heights);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(next[i]-prev[i]-1));
        }
        return ans;
    }

};