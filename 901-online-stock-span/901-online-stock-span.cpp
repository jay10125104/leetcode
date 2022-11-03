class StockSpanner {
public:
    stack<pair<int,int>>s;
    int count=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(s.size() && s.top().first<=price){
            s.pop();
        }
        int ans;
        if(s.size()){
            ans = s.top().second;
        }
        else{
            ans = -1;
        }
        s.push({price,count});
        count++;
        return count-ans-1;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */