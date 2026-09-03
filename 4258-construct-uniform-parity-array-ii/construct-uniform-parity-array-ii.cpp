class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       //sort
       sort(nums1.begin(),nums1.end());
       int odd=0;
       for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0) odd++;
       }
       if(odd==0) return true;
       if(nums1[0]%2==0) return false;
       return true;
    } 
};