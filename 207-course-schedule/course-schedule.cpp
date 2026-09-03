class Solution {
public:
    bool cycle(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &path){
        vis[node]=1;
        path[node]=1;
        for(int nei:adj[node]){
            if(vis[nei]==0){
                if(cycle(nei,adj,vis,path)) return true;
            }else if(path[nei]==1){
                return true;
            }
        }
        path[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //using dfs
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses,0);
        vector<int> path(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            adj[b].push_back(a);
        }
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                if(cycle(i,adj,vis,path)) return false;
            }
        }
        return true;
    }
};