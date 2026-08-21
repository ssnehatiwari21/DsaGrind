class Solution {
public: 
    string letters[10]  = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    void helper(string digits, int index, string &s,vector<string> &ans){
        if(index==digits.size()){
            ans.push_back(s);
            return;
        }
        for(char ch: letters[digits[index]-'0']){
            s.push_back(ch);
            helper(digits,index+1,s,ans);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string s;
        vector<string> ans;
        helper(digits,0,s,ans);
        return ans;
    }
};