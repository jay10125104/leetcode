class BrowserHistory {
public:
    stack<string>curr;
    stack<string>back1;
    BrowserHistory(string homepage) {
        curr.push(homepage);
    }
    
    void visit(string url) {
        curr.push(url);
        stack<string>neww;
        back1 = neww;
    }
    
    string back(int steps) {
        while(curr.size()!=1 && steps--){
            string t = curr.top();
            back1.push(t);
            curr.pop();
        }
        return curr.top();
    }
    
    string forward(int steps) {
        while(back1.size()&& steps--){
            string t = back1.top();
            curr.push(t);
            back1.pop();
        }
        return curr.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */