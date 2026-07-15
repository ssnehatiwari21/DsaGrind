class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        stack<char> st;
        string ans="";
        for(int i=0;i<n;i++){
            while(!st.empty() && k!=0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        //leading zeros
        int j=0;
        while(j<ans.length() && ans[j]=='0'){
            j++;
        }
        ans=ans.substr(j);

        //emptystring
        if(ans.empty()) return "0";
        return ans;
    }
};