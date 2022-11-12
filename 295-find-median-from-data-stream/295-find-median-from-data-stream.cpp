class MedianFinder {
public:
    priority_queue<int>p1;
    priority_queue<int,vector<int>,greater<int>>p2;    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(p2.size()==p1.size()){
            p2.push(num);
            int x = p2.top();
            p2.pop();
            p1.push(x);
        }
        else{
            // int x = 
            p2.push(num);
            int x = p2.top();
            p2.pop();
            p1.push(x);
            x = p1.top();
            p1.pop();
            p2.push(x);
        }
    }
    
    double findMedian() {
        if(p1.size()!=p2.size()){
            return p1.top();
        }
        else{
            return (double)(p1.top()+p2.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */