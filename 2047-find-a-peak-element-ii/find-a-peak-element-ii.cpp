class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int left=(j==0)?-1:mat[i][j-1];
                int top=(i==0)?-1:mat[i-1][j];
                int right=(j==n-1)?-1:mat[i][j+1];
                int bottom=(i==m-1)?-1:mat[i+1][j];

                if(mat[i][j]>left &&mat[i][j]>top && mat[i][j]>right && mat[i][j]>bottom) return {i,j};
            }
        }
        return {-1,-1};
    }
};