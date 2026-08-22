class Solution {
public: 
    void helper(int k, int n,int start,vector<int> &level,vector<vector<int>> &ans){
        if(level.size()==k && n==0){
            ans.push_back(level);
            return;
        }
        if(level.size()==k || n==0) return;
        for(int i=start;i<=9;i++){
            if(i<=n){
                level.push_back(i);
                helper(k,n-i,i+1,level,ans);
                level.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> level;
        vector<vector<int>> ans;
        vector<int> visited(10,0);
        int start=1;
        helper(k,n,start,level,ans);
        return ans;
    }
};