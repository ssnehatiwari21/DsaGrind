class Solution {
public:
    void helper(int n,int open,int close,string s,vector<string> &ans){
        if(open==n && close==n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s.push_back('(');
            helper(n,open+1,close,s,ans);
            s.pop_back();
        }
        if(close<open){
            s.push_back(')');
            helper(n,open,close+1,s,ans);
            s.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        helper(n,0,0,s,ans);
        return ans;
    }
};