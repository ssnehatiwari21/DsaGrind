class Solution {
public:
    bool isValid(vector<vector<char>> &board,int row,int col){
        char c=board[row][col];
        //check in row and in cols
        for(int i=0;i<9;i++){
            if((i!=row && board[i][col]==c )||(i!=col && board[row][i]==c)) return false;
        }
        int startrow=3*(row/3);
        int startcol=3*(col/3);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(startrow+i!=row && startcol+j!=col && board[startrow+i][startcol+j]==c) return false;
            }
        }
        return true;
    }
    bool solver(vector<vector<char>> &board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(isValid(board,i,j)==false){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return solver(board);
    }
};