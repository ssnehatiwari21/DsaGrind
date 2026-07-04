class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=0;
        int ans=-1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        for(int i=0;i<n;i++){
            int right=sum-left-nums[i];
            if(left==right) return i;
            left+=nums[i];
        }

        return ans;
    }
};