class Solution {
public:
    int maxDepth(string s) {
        int ans=INT_MIN;
        int count=0;
        int n=s.length();
        int open=0;
        int close=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') count++;
            if(s[i]==')') count--;
            ans=max(ans,count);
            
        }
        return ans;
    }
};