class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        string ans="";
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < n; i++) {
            if (!st.empty() && s[i] == st.top())
                st.pop();
            else {
                st.push(s[i]);
            }
        }
        while (!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};