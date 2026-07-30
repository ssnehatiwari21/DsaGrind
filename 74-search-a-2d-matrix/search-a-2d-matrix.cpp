class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        //binary seach for row calculation
        int row=-1;
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid][0]<=target){
                row=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        if(row==-1) return false;
        //binary search for column calculation
        int column=-1;
        low=0;
        high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[row][mid]==target) return true;
            else if(matrix[row][mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return false;
    }
};