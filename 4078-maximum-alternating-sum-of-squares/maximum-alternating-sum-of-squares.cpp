class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long totalsum=0;
        vector<int> alternating(n,0);
        for(int i=0;i<n;i++){
            long long x=1LL*nums[i]*nums[i];
            totalsum+=x;
            alternating[i]=x;
        }
        sort(alternating.begin(),alternating.end());
        for(int i=0;i<(n/2);i++){
            totalsum-=1LL*2*alternating[i];
        }
        return totalsum;
    }
};