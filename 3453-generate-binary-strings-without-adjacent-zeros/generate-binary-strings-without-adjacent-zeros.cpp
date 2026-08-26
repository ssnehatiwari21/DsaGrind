class Solution {
public:
    void helper(int n,int index,string &binary,vector<string> &ans){

        if(index==n){
            ans.push_back(binary);
            return;
        }
        //choose 1
        binary.push_back('1');
        helper(n,index+1,binary,ans);
        binary.pop_back();

        //choose 0
        if(index==0 || binary.back()=='1'){
            binary.push_back('0');
            helper(n,index+1,binary,ans);
            binary.pop_back();
        }

    }
    vector<string> validStrings(int n) {
        string binary;
        vector<string> ans;
        helper(n,0,binary,ans);
        return ans;
    }
};