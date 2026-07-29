class Solution {
public:
    bool citedPapers(vector<int>& citations,int h){
        int n=citations.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(citations[i]>=h){
                count++;
            }
        }
        return count>=h;
    }
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int low=1;
        int high=n;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(citedPapers(citations,mid)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }

        }
        return ans;
    }
};