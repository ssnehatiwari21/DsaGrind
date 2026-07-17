class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans=0;
        stack<int> st;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b);
                st.push(a);
                st.push(a+b);
            }
            else if(operations[i]=="D"){
                if(!st.empty()){
                    int val=2*st.top();
                    st.push(val);
                }

            }else if(operations[i]=="C"){
                if(!st.empty()){
                    st.pop();
                }
            }else{
                st.push(stoi(operations[i]));
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};