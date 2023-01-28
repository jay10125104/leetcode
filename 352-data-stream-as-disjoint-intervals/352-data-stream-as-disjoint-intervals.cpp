class SummaryRanges {
public:
    vector<int>v;
    int mx=-1;
    SummaryRanges() {
        v.resize(10001);
    }
    
    void addNum(int x) {
        mx = max(mx,x);
        v[x]++;
    }
    
    vector<vector<int>> getIntervals() {
            vector<vector<int>>ans;
        int prev=-2;
        int prevv=-2;
        for(int i=0;i<=mx;i++){
            if((prev+1)==i && v[i]){
                prev=i;
            }
            else if(v[i]){
                if(prevv!=-2){
                    ans.push_back({prevv,prev});
                }
                prevv=i;
                prev=i;
            }
        }
        ans.push_back({prevv,prev});
        return ans;
        
    }
    
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */