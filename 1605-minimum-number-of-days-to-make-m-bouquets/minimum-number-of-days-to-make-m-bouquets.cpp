class Solution {
public:
    bool bouquet(vector<int>& bloomDay,int days,int m,int k){
        int count=0;
        int n=bloomDay.size();
        int adj=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=days){
                adj++;
                if(adj==k){
                    count++;
                    adj=0;
                }
            }else{
                adj=0;
            }
        }
        return count>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<(long long)m*k) return -1;
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(bouquet(bloomDay,mid,m,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};