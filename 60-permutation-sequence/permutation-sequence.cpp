class Solution {
public:
    void helper(int n,int index,string &permutations,vector<string> &ans,vector<int> &vis){
        if(index==n+1){
            ans.push_back(permutations);
            return;
        }
        for(int i=1;i<=n;i++){
            if(index==1 || vis[i]==0){
                permutations.push_back('0'+i);
                vis[i]=1;
                helper(n,index+1,permutations,ans,vis);
                permutations.pop_back();
                vis[i]=0;
            }
        }
    }
    string getPermutation(int n, int k) {
        string permutations;
        vector<string> ans;
        vector<int> vis(n+1,0);
        helper(n,1,permutations,ans,vis);
        return ans[k-1];
    }
};