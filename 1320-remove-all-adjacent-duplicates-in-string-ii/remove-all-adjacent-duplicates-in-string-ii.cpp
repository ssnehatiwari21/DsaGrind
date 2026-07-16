class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.length();
        stack<pair<char,int>> st;
        string ans="";
        for(int i=0;i<n;i++){
           if(st.empty() || st.top().first!=s[i]) st.push({s[i],1});
           else{
            st.top().second++;
            if(st.top().second ==k) st.pop();
           } 
        }

        while(!st.empty()){
            ans.append(st.top().second,st.top().first);
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};