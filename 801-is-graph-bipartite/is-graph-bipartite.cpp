class Solution {
public:
    bool dfs(int node,vector<vector<int>> &graph,vector<int>  &color){
        for(int nei:graph[node]){
            if(color[nei]==-1){
                //uncolored ones
                color[nei]=1-color[node];
                if(!dfs(nei,graph,color)) return false;
            }else if(color[nei]==color[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1); //uncolored
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(!dfs(i,graph,color)) return false;
            }
        }
        return true;
    }
};