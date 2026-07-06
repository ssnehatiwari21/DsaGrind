class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        int res=0;
        int ones=0;
        int zeros=0;

        for(int i=0;i<n;i++){
            if(nums[i]==0) zeros++;
            else ones++;

            int diff=zeros-ones;

            if(diff==0) res=max(res,i+1);
            else if(m.find(diff)!=m.end()){
                res=max(res,i-m[diff]);
            }else{
                m[diff]=i;
            }
        }
        return res;
    }
};