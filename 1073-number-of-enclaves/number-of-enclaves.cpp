class Solution {
public:
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            if(vis[i][0]==0 && grid[i][0]==1){
                q.push({i,0});
                vis[i][0]=1;
            }
        }
        for(int i=0;i<m;i++){
            if(vis[i][n-1]==0 && grid[i][n-1]==1){
                q.push({i,n-1});
                vis[i][n-1]=1;
            }
        }
        for(int j=0;j<n;j++){
            if(vis[0][j]==0 && grid[0][j]==1){
                q.push({0,j});
                vis[0][j]=1;
            }
        }
        for(int j=0;j<n;j++){
            if(vis[m-1][j]==0 && grid[m-1][j]==1){
                q.push({m-1,j});
                vis[m-1][j]=1;
            }
        }

        while(!q.empty()){
            int tr=q.front().first;
            int tc=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=tr+dir[i][0];
                int nc=tc+dir[i][1];
                if(nr>=0 && nc>=0 && nr<m && nc<n && vis[nr][nc]==0 && grid[nr][nc]==1){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]==1) count++;
            }
        }
        return count;
    }
};