class Solution {
public:
    int FindRowIndex(vector<vector<int>>& mat,int col,int r,int c){
            int maxrow=0;
            int maxValue=mat[0][col];
            for(int i=1;i<r;i++){
                if(mat[i][col]>maxValue){
                    maxValue=mat[i][col];
                    maxrow=i;
                }
            }
        return maxrow;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int low=0;
        int high=col-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int maxrowIndex=FindRowIndex(mat,mid,row,col);
            int left=(mid==0)?-1:mat[maxrowIndex][mid-1];
            int right=(mid==col-1)?-1:mat[maxrowIndex][mid+1];
            if(mat[maxrowIndex][mid]>right && mat[maxrowIndex][mid]>left){
                return {maxrowIndex,mid};
            }
            if(mat[maxrowIndex][mid]<left) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};