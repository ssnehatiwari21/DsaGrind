class Solution {
public:
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> ans(m,vector<int>(n));
        int dis=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && isWater[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                    ans[i][j]=dis;
                }
            }
        }

        while(!q.empty()){
            int size=q.size();
            dis=dis+1;
            for(int i=0;i<size;i++){
                int tr=q.front().first;
                int tc=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=tr+dir[i][0];
                    int nc=tc+dir[i][1];

                    if(nr>=0 && nc>=0 && nr<m && nc<n && vis[nr][nc]==0 && isWater[nr][nc]==0){
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                        ans[nr][nc]=dis;
                    }
                }
            }
        }
        return ans;
    }
};