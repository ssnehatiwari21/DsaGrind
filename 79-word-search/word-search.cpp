class Solution {
public:
    int directions[4][2] = {
    {-1, 0},  // up
    {1, 0},   // down
    {0, -1},  // left
    {0, 1}    // right
};
    bool solve(vector<vector<char>>& board, string word,int wordindex,int row,int col,string &ans,vector<vector<bool>> &vis){
        if(word.size()==wordindex){
            return true;
        }
        for(int i=0;i<4;i++){
            int newrow=row+directions[i][0];
            int newcol=col+directions[i][1];
            if(newrow>=0 && newcol>=0 && newrow<board.size() && newcol<board[0].size() && board[newrow][newcol]==word[wordindex] && vis[newrow][newcol]==false){
                ans.push_back(board[newrow][newcol]);
                vis[newrow][newcol]=true;
                if(solve(board,word,wordindex+1,newrow,newcol,ans,vis)) return true;
                ans.pop_back();
                vis[newrow][newcol]=false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        char firstletter=word[0];
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        string ans="";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==firstletter){
                    ans=firstletter;
                    vis[i][j]=true;
                    if(solve(board,word,1,i,j,ans,vis)) return true;
                    vis[i][j]=false;
                    ans="";
                }
            }
        }
        return false;
    }
};