class Solution {
public:  
    bool possible(int g,int col,vector<vector<int>> &adj,vector<int> &colors){
        for(int nei:adj[g]){
            if(colors[nei-1]==col) return false;
        }
        return true;
    }
    bool solve(int n,int g,vector<vector<int>> &adj,vector<int> &colors,vector<int> &ans){
        if(g==n+1){
            return true;
        }
        for(int col=1;col<=4;col++){
            if(possible(g,col,adj,colors)){
                colors[g-1]=col;
                ans.push_back(col);
                if(solve(n,g+1,adj,colors,ans)) return true;
                
            }
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        //adjacency list
        vector<vector<int>> adj(n+1);
        for(int i=0;i<paths.size();i++){
            int u=paths[i][0];
            int v=paths[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> colors(n,0);
        vector<int> ans;
        solve(n,1,adj,colors,ans);
        return ans;

    }
};