class Solution {
public:
    int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        queue<pair<int,int>> q;
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        q.push({0,0});
        dis[0][0]=1;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int nr=r+dir[i][0];
                int nc=c+dir[i][1];
                if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==0 && dis[r][c]+1<dis[nr][nc]){
                    q.push({nr,nc});
                    dis[nr][nc]=dis[r][c]+1;
                }
            }
        }
        if(dis[n-1][n-1]==1e9) return -1;
        return dis[n-1][n-1];
    }
};