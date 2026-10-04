class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<int> &vis,int node){
        vis[node]=1;
        for(auto nei:adj[node]){
            if(vis[nei]==0){
                dfs(adj,vis,nei);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //adjlist
        vector<vector<int>> adj(isConnected.size());
        vector<int> vis(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            if(vis[i]==0){
                count++;
                dfs(adj,vis,i);
            }
        }
        return count;
    }
};