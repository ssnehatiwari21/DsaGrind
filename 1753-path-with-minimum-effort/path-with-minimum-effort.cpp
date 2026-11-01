class Solution {
public:
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> res(m,vector<int>(n,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        res[0][0]=0;
        while(!pq.empty()){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            int dis=pq.top().first;
            pq.pop();
            for(int i=0;i<4;i++){
                int nr=r+dir[i][0];
                int nc=c+dir[i][1];
                
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    int ndis=max(dis,abs(heights[nr][nc]-heights[r][c]));
                    if(ndis<res[nr][nc]){
                        res[nr][nc]=ndis;
                        pq.push({ndis,{nr,nc}});
                    }
                }
            }
        }
        return res[m-1][n-1];        
    }
};