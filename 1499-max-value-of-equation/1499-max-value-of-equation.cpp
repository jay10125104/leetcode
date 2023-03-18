class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& p, int k) {
        vector<pair<int,int>>v;
        for(auto &i:p){
            v.push_back({i[1]-i[0],i[0]});
        }
        int ans=INT_MIN;
        priority_queue<pair<int,int>>q;
        for(auto &i:v){
            while(q.size() && (i.second - q.top().second)>k){
                q.pop();
            }
            if(q.size()){
                ans = max(ans,q.top().first+i.first+(2*(i.second)));
            }
            q.push(i);
        }
        return ans;
    }
};