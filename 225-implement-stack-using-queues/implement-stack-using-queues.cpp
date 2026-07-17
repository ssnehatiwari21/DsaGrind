class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        int ans=-1;
        while(!q2.empty()){

            
            ans=q2.front();
            q2.pop();
            
            if(q2.size()==0){
                return ans;
            }
            q1.push(ans);
        }
        return -1;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        if(q1.size()!=0) return false;
        return true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */