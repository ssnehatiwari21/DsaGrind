class Solution {
public:
    string getPermutation(int n, int k) {
        int fac=1;
        vector<int> ele;
        for(int i=1;i<n;i++){
            fac=fac*i;
            ele.push_back(i);
        }
        ele.push_back(n);
        k=k-1;
        string ans="";
        while(true){
            ans=ans+to_string(ele[k/fac]);
            ele.erase(ele.begin()+k/fac);
            if(ele.size()==0) break;
            k=k%fac;
            fac=fac/ele.size();
        }
        return ans;
    }
};