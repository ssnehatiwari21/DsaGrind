class Solution {
public:
    int minInsertions(string s) {
        int open=0;
        int close=0;
        int insertions=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                open++;
            }else{
                if(i<s.length()-1 && s[i+1]==')'){
                    i+=1;
                }else{
                    insertions++;
                }
                if(open>0) open--;
                else insertions++;
            }
        }
        return insertions+2*open;
    }
};