#define PII pair<int,string>
class MaxCompare{
    public:
        bool operator()(pair<int,string>&a,pair<int,string>&b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        else{
            return a.first<b.first;
        }
    }
};
class MinCompare{
    public:
        bool operator()(pair<int,string>&a,pair<int,string>&b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        else{
            return a.first>b.first;
        }
    }
};
class SORTracker {
public:
    priority_queue<PII, vector<PII>, MaxCompare>q1;
    priority_queue<PII, vector<PII>, MinCompare>q2;
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        q2.push({score,name});
        q1.push(q2.top());
        cout<<q1.top().second<<endl;
        q2.pop();
    }
    
    string get() {
        auto x =  q1.top();
        q1.pop();
        q2.push(x);
        return x.second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */