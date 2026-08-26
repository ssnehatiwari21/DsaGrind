class Solution {
public:
    void helper(int n,int k,int i,string &happystring,vector<string> &ans){
        //option 1
        if(i==n){
            ans.push_back(happystring);
            return;
        }
        if(i==0 || happystring.back()!='a'){
            happystring.push_back('a');
            helper(n,k,i+1,happystring,ans);
            happystring.pop_back();
        }
        //option 2
        if(i==0 || happystring.back()!='b'){
            happystring.push_back('b');
            helper(n,k,i+1,happystring,ans);
            happystring.pop_back();
        }
        //option 3
        if(i==0 || happystring.back()!='c'){
            happystring.push_back('c');
            helper(n,k,i+1,happystring,ans);
            happystring.pop_back();
        }
        

    }
    string getHappyString(int n, int k) {
        string happystring;
        vector<string> ans;
        helper(n,k,0,happystring,ans);
        if(ans.size()<k) return "";
        return ans[k-1];
    }
};