class Solution {
public:
    bool canDivide(vector<int>& candies, long long k,long long guess){
        int n=candies.size();
        long long children=0;
        for(int ele:candies){
            if(ele<guess) continue;
            
                children+=ele/guess;
            
        }
        return children>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        long long low=1;
        long long high=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            high+=candies[i];
        }
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(canDivide(candies,k,mid)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return (int)ans;
    }
};