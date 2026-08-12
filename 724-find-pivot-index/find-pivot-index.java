class Solution {
    public int pivotIndex(int[] nums) {
        int n=nums.length;
        int leftsum=0;
        int rightsum=0;
        int index=-1;
        for(int i=0;i<n;i++){
            rightsum+=nums[i];
        }
        for(int i=0;i<n;i++){
            rightsum-=nums[i];
            if(leftsum==rightsum){
                return i;
            }
            leftsum+=nums[i];
        }
        return index;
    }
}