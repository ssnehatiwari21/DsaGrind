class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis){
        vis[node]=1;
        for(int nei:adj[node]){
            if(vis[nei]==0){
                dfs(nei,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //adj list from matrix representation
        int n=isConnected.size();
        vector<vector<int>> adj(n+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(isConnected[i-1][j-1]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count=0;
        vector<int> vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};