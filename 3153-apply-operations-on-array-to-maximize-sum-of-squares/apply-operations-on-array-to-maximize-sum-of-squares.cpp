class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n=nums.size();
        int MOD=1e9+7;
        vector<int> bits(32,0);//store the total bits available for that position
        for(int num:nums){
            for(int b=0;b<32;b++){
                if((num&(1<<b))!=0){
                    bits[b]++;
                }
            }
        }
        long long ans=0;
        while(k!=0){
            long long count=0;
            for(int b=0;b<32;b++){
                if(bits[b]>0){
                    bits[b]--;
                    count=count|(1<<b);
                }
            }
            ans=(ans+(count*count)%MOD)%MOD;
            k--;
        }
        return ans;
    }
};