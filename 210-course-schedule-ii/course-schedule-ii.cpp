class Solution {
public:
    bool dfs(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &path, vector<int> &ans){
        vis[node]=1;
        path[node]=1;
        for(int nei:adj[node]){
            if(vis[nei]==0){
                if(dfs(nei,adj,vis,path,ans)) return true;
            }else if(path[nei]==1){
                return true;
            }
        }
        path[node]=0;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //if there is cycle we can never finish all the courses and we can return empty array as soon as a cycle is detected in directed graph
        
        vector<vector<int>> adj(numCourses);

        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];

            adj[b].push_back(a);
        }
        vector<int> path(numCourses,0);
        vector<int> vis(numCourses,0);
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                if(dfs(i,adj,vis,path,ans)) return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};