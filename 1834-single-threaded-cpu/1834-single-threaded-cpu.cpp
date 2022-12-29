class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        map<pair<int,int>,queue<int>>m;
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p1;  
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>>p2;
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>>p1;
        int count=0;
        for(auto &i:tasks){
            p1.push({{i[0],i[1]},count});
            count++;
        }
        int time=0;
        vector<int>ans;
        
        while(p1.size()){
            // cout<<p2.size()<<" "<<time<<"*\n";
            while(p1.size() && p1.top().first.first<=time){
                auto x = p1.top();
                p2.push({{x.first.second,x.second},x.first.first});
                p1.pop();
            }
            if(p1.size() && p2.size()==0){
                time=p1.top().first.first;
            }
            else if(p2.size()){
                ans.push_back(p2.top().first.second);
                // m[p2.top()].pop();
                
                time = time + p2.top().first.first;
                // cout<<ans.back()<<" "<<time<<endl;
                
                p2.pop();
                
            }
        }
        while(p2.size()){
            // cout<<p2.top().first.first<<" "<<p2.top().first.second<<" "<<p2.top().second<<endl;
            ans.push_back(p2.top().first.second);
            // m[p2.top()].pop();    
            p2.pop();
        }
        return ans;
    }
};