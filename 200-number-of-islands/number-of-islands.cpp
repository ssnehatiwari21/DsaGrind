class Solution {
public:
    int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    void bfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>> &vis){
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col]=1;
        while(!q.empty()){
            int toprow=q.front().first;
            int topcol=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newrow=toprow+dir[i][0];
                int newcol=topcol+dir[i][1];
                if(newrow>=0 && newcol>=0 && newrow<grid.size() && newcol<grid[0].size() && vis[newrow][newcol]==0 && grid[newrow][newcol]=='1'){
                    q.push({newrow,newcol});
                    vis[newrow][newcol]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};