class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }else{
                if(st.empty()) return false;
                char top=st.top();
                if((top=='(' && s[i]!=')')||(top=='{' && s[i]!='}')||(top=='[' && s[i]!=']')) return false;
                st.pop();
            }
        }
        if(st.empty()) return true;
        return false;
    }
};