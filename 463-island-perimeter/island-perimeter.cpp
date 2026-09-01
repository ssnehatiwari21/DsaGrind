class Solution {
public:
    
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(int sr,int sc,vector<vector<int>>& grid,int &perimeter,vector<vector<int>> &vis){
        queue<pair<int,int>> q;
        vis[sr][sc]=1;
        q.push({sr,sc});
        while(!q.empty()){
            int trow=q.front().first;
            int tcol=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newrow=trow+dir[i][0];
                int newcol=tcol+dir[i][1];

                if(newrow>=grid.size() || newcol>=grid[0].size() || newrow<0 || newcol<0 || grid[newrow][newcol]==0){
                    perimeter++;
                }else if(vis[newrow][newcol]==0){
                    q.push({newrow,newcol});
                    vis[newrow][newcol]=1;
                }
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        int perimeter=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    bfs(i,j,grid,perimeter,vis);
                }
            }
        }
        return perimeter;
    }
};