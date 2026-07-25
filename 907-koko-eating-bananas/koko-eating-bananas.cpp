class Solution {
public:
    long long timeToFinishBananas(vector<int> &piles,int speed){
        int n=piles.size();
        long long time_to_finish_bananas=0;
        for(int i=0;i<n;i++){
            time_to_finish_bananas+=piles[i]/speed;
            if(piles[i]%speed!=0){
                time_to_finish_bananas++;
            }
        }
        return time_to_finish_bananas;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int k=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long time_to_finish_bananas=timeToFinishBananas(piles,mid);
            if(time_to_finish_bananas<=h){
                k=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return k;
    }
};