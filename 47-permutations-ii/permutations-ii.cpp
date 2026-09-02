class Solution {
public: 
    void helper(int idx,vector<int> &nums,vector<int> &vis,vector<int> &path,set<vector<int>> &ans){
        if(idx==nums.size()){
            ans.insert(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i]==0){
                path.push_back(nums[i]);
                vis[i]=1;
                helper(idx+1,nums,vis,path,ans);
                path.pop_back();
                vis[i]=0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<int> vis(n,0);
        vector<int> path;
        set<vector<int>> s;
        vector<vector<int>> ans;
        helper(0,nums,vis,path,s);

        //set to vector;
        for(auto &it:s){
            ans.push_back(it);
        }
        return ans;
    }
};