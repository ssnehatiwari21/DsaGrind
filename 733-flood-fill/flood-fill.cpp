class Solution {
public: 
    int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
    void bfs(int sr,int sc,vector<vector<int>> &image,int color,int startcolor){
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty()){
            int trow=q.front().first;
            int tcol=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newrow=trow+dir[i][0];
                int newcol=tcol+dir[i][1];
                if(newrow>=0 && newcol>=0 && newrow<image.size() && newcol<image[0].size() && image[newrow][newcol]==startcolor){
                    q.push({newrow,newcol});
                    image[newrow][newcol]=color;
                }
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        if(image[sr][sc]==color) return image;
        bfs(sr,sc,image,color,image[sr][sc]);
        return image;
    }
};