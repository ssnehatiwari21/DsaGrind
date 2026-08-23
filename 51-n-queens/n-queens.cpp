class Solution {
public:  
    bool isSafe(vector<string> &board,int row,int col,int n){

        //left
        int r=row;
        int c=col;
        while(c>=0){
            if(board[r][c]=='Q') return false;
            c--;
        }
        r=row;
        c=col;
        while(c>=0 && r>=0){
            if(board[r][c]=='Q') return false;
            r--;
            c--;
        }
        r=row;
        c=col;
        while(c>=0 && r<n){
            if(board[r][c]=='Q') return false;
            r++;
            c--;
        }
        return true;
    }
    void helper(int n,int col,vector<string> &board,vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(board,i,col,n)){
                board[i][col]='Q';
                helper(n,col+1,board,ans);
                board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        helper(n,0,board,ans);
        return ans;
    }
};