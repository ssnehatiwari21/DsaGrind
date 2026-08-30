class Solution {
public:
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(vector<vector<int>>& land,vector<vector<int>>& vis,int &sr,int &sc,int &er,int &ec){
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        while(!q.empty()){
            int tr=q.front().first;
            int tc=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=tr+dir[i][0];
                int nc=tc+dir[i][1];

                if(nr>=0 && nc>=0 && nr<land.size() && nc<land[0].size() && vis[nr][nc]==0 && land[nr][nc]==1){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                    if(nr>er) er=nr;
                    if(nc>ec) ec=nc;
                }
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m=land.size();
        int n=land[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && land[i][j]==1){
                    int sr=i;
                    int sc=j;
                    int er=i;
                    int ec=j;
                    bfs(land,vis,sr,sc,er,ec);
                    ans.push_back({sr,sc,er,ec});
                }
            }
        }
        return ans;
    }
};