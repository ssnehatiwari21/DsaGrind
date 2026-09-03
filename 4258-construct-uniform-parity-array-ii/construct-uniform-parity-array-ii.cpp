class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       //sort
       int mini=INT_MAX;
       int odd=0;
       for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0) odd++;
            mini=min(mini,nums1[i]);
       }
       if(odd==0) return true;
       if(mini%2==0) return false;
       return true;
    } 
};