class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low=1;
        int high=m*n;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            //guess the element smaller and equal to K
            int row=m;
            int col=1;
            int count=0;
            while(row>0 && col<=n){
                if(row*col<=mid){
                    count+=row;
                    col++;
                }else{
                    row--;
                }
            }
            if(count>=k){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};