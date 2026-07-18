class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int n=s.length();
        int x_cnt=0;
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!=x){
                ans+=s[i];
            }else{
                x_cnt++;
            }
            
        }
        for(int j=0;j<x_cnt;j++){
            ans+=x;
        }
        return ans;
    }
};