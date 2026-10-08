class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        string ans="";
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='('){
                cnt++;
                if(cnt>=2) ans+='(';
            }else{
                cnt--;
                if(cnt>=1) ans+=')';
            }
        }
        return ans;
    }
};