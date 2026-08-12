class Solution {
    public int majorityElement(int[] nums) {
        int n=nums.length;
        int majorityEle=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(count==0){
                majorityEle=nums[i];
                count=1;
            }else{
                if(majorityEle==nums[i]) count++;
                else count--;
            }
        }
        count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==majorityEle) count++;
        }
        if(count>n/2) return majorityEle;
        return -1;
    }
}