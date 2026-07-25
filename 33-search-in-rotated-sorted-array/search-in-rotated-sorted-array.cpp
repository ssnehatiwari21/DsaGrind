class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=-1;
        int min=-1;
        //find the minimum element -O(logn)
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[n-1]){
                low=mid+1;
            }else{
                min=mid;
                high=mid-1;
            }
        }

        //apply binary search to the right part-O(logn)
        low=0;
        high=min-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target){
                high=mid-1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                return mid;
            }
        }
        //apply binary seach to the left part-O(logn)
        low=min;
        high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target){
                high=mid-1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                return mid;
            }
        }
        return ans;
    }
};