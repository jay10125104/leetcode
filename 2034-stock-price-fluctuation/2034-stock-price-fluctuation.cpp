class StockPrice {
public:
    priority_queue<pair<int,int>>q1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q2;
    map<int,int>m;
    int t=0;
    int val=0;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        m[timestamp] = price;
        if(timestamp>t){
            t=timestamp;
        }
        q1.push({price,timestamp});
        q2.push({price,timestamp});
        
    }
    
    int current() {
        return m[t];
    }
    
    int maximum() {
        while(q1.size()){
            auto x = q1.top();
            int i=x.first;
            int j = x.second;
            // cout<<i<<" "<<j<<" "<<"first"<<endl;
            if(m[j]==i){
                break;
            }
            else{
                q1.pop();
            }
            
        }
        return m[q1.top().second];
        
    }
    
    int minimum() {
        while(q2.size()){
            auto x = q2.top();
            int i=x.first;
            int j = x.second;
            // cout<<i<<" "<<j<<" "<<"second"<<endl;
            if(m[j]==i){
                break;
            }
            else{
                q2.pop();
            }
        }
        return m[q2.top().second];
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */