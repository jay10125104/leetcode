class CustomStack {
public:
    int mx;
    stack<int>s;
    CustomStack(int maxSize) {
        mx = maxSize;
    }
    
    void push(int x) {
        if(s.size()<mx){
            s.push(x);
        }
    }
    
    int pop() {
        if(s.size()){
            int x = s.top();
            s.pop();
            return x;
        }
        else{
            return -1;
        }
    }
    
    void increment(int k, int val) {
        stack<int>st;
        k = min(k,(int)s.size());
        while(s.empty()==false){
            if(s.size()<=k){
                st.push(s.top()+val);
            }
            else{
                st.push(s.top());
            }
            s.pop();
        }
        while(st.empty()==false){
            s.push(st.top());
            st.pop();
        }
    }
};
