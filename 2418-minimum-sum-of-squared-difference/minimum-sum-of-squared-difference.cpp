class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        int k=k1+k2;
        vector<int> diff(1e5+1,0);
        for(int i=0;i<n;i++){
            int res=abs(nums1[i]-nums2[i]);
            diff[res]++;
        }
        for(int i=1e5;i>0;i--){
            if(diff[i]!=0){
                int count=min(k,diff[i]);
                diff[i]-=count;
                diff[i-1]+=count;
                k-=count;
                if(k==0) break;
            }
        }
        long long sum=0;
        for(int i=0;i<=1e5;i++){
            long long x=diff[i];
            sum+=x*i*i;
        }
        return sum;
    }
};