class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxPro=nums[0];
        int minPro=nums[0];
        int temp=0;
        int ans=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==0){
                maxPro=0;
                minPro=0;
            }else if(nums[i]>0){
                maxPro=max(nums[i],maxPro*nums[i]);
                minPro=min(nums[i],minPro*nums[i]);

            }else{
                temp=maxPro;
                maxPro=max(nums[i],minPro*nums[i]);
                minPro=min(nums[i],temp*nums[i]);
            }

            ans=max(ans,maxPro);
        }
        return ans;
    }
};