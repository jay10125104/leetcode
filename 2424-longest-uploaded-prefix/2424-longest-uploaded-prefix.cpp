class LUPrefix {
public:
    priority_queue<int, vector<int>, greater<int> >q;
    stack<int>st;
    
    LUPrefix(int n) {
        st.push(0);
    }
    
    void upload(int x) {
        while((q.size() && st.size()) && q.top()==(st.top()+1) && q.size()){
            
            st.push(q.top());
            q.pop();
        }
        if(st.top()==(x-1)){
            st.push(x);
        }
        else{
            q.push(x);
        }
        while((q.size() && st.size()) && q.top()==(st.top()+1) && q.size()){
            
            st.push(q.top());
            q.pop();
        }
    }
    
    int longest() {
        return st.size()-1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */