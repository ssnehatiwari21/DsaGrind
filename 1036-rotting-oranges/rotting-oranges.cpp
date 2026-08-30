class Solution {
public:
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(vector<vector<int>> &grid,int &time,queue<pair<int,int>> &q,int &fresh){
        while(!q.empty() && fresh>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                int trow=q.front().first;
                int tcol=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int newrow=trow+dir[i][0];
                    int newcol=tcol+dir[i][1];
                    if(newrow>=0 && newcol>=0 && newrow<grid.size() && newcol<grid[0].size() && grid[newrow][newcol]==1){
                        q.push({newrow,newcol});
                        grid[newrow][newcol]=2;
                        fresh--;
                    }
                }
            }
            time++;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int time=0;
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1) fresh++;
            }
        }
        bfs(grid,time,q,fresh);
        if(fresh>0) return -1;
        return time;
    }
};