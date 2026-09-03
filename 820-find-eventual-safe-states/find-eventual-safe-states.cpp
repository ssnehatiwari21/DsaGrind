class Solution {
public:
   bool dfs(int node,vector<int> &vis,vector<int> &path,vector<vector<int>> &adj,vector<int> &ans){
        vis[node]=1;
        path[node]=1;
        for(int nei:adj[node]){
            if(vis[nei]==0){
                if(dfs(nei,vis,path,adj,ans)) return true;
            }else if(path[nei]==1){
                return true;
            }
        }
        path[node]=0;
        ans.push_back(node);
        return false;
   }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adj(graph.size());
        vector<int> ans;
        vector<int> vis(graph.size(),0);
        vector<int> path(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(int nei:graph[i]){
                adj[i].push_back(nei);
            }
        }

        for(int i=0;i<graph.size();i++){
            if(vis[i]==0){
                dfs(i,vis,path,adj,ans);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};