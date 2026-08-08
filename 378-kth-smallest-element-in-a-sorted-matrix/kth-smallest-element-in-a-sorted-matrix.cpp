class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];

        int ans=-1;
        while(low<=high){
            int guess=low+(high-low)/2;
            int count=0;
            int row=n-1;
            int col=0;
            while(row>=0 && col<n){
                if(matrix[row][col]<=guess) {
                    count+=row+1;
                    col++;
                }else{
                    row--;
                }
            }

            if(count>=k){
                ans=guess;
                high=guess-1;
            }else if(count<k){
                low=guess+1;
            }
        }
        return ans;
    }
};