class Solution {
public:
    void dfs(vector<vector<int>> &adjlist,vector<int> &vis,int node){
        vis[node]=1;
        for(auto it:adjlist[node]){
            if(vis[it]==0){
                dfs(adjlist,vis,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adjlist(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjlist[i].push_back(j);
                }
            }
        }
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                count++;
                dfs(adjlist,vis,i);
            }
        }
        return count;
    }
};