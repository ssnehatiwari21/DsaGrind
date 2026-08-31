class Solution {
public:
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int row,int col,vector<vector<char>> &board,vector<vector<int>> &vis){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int newrow=row+dir[i][0];
            int newcol=col+dir[i][1];
            if(newrow>=0 && newcol>=0 && newrow<board.size() && newcol<board[0].size() && vis[newrow][newcol]==0 && board[newrow][newcol]=='O'){
                dfs(newrow,newcol,board,vis);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        //starting dfs from all the boundry 'O' and marking all rechable 'O' to visted (not surrounded)
        for(int i=0;i<m;i++){
            if(vis[i][0]==0 && board[i][0]=='O'){
                dfs(i,0,board,vis);
            }
        }
        for(int i=0;i<m;i++){
            if(vis[i][n-1]==0 && board[i][n-1]=='O'){
                dfs(i,n-1,board,vis);
            }
        }
        for(int j=0;j<n;j++){
            if(vis[0][j]==0 && board[0][j]=='O'){
                dfs(0,j,board,vis);
            }
        }
        for(int j=0;j<n;j++){
            if(vis[m-1][j]==0 && board[m-1][j]=='O'){
                dfs(m-1,j,board,vis);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};