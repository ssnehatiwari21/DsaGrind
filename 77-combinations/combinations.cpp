class Solution {
public: 
    void helper(int n, int k, int start,vector<int> &level,vector<vector<int>> &ans){
        if(level.size()==k){
            ans.push_back(level);
            return;
        }
        for(int i=start;i<=n;i++){
            level.push_back(i);
            helper(n,k,i+1,level,ans);
            level.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> level;
        vector<vector<int>> ans;
        helper(n,k,1,level,ans);
        return ans;
    }
};