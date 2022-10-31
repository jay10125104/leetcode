class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& s, int start, int end) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],s[i]});
            adj[edges[i][1]].push_back({edges[i][0],s[i]});
        }
        vector<double>dis(n);
        priority_queue<pair<double,int>>q;
        q.push({1,start});
        while(q.size()){
            auto it = q.top();
            q.pop();
            // cout<<it.first<<" "<<it.second<<endl;
            if(dis[it.second]>=it.first){
                continue;
            }
            dis[it.second] = it.first;
            for(auto i:adj[it.second]){
                double mid = (double)(it.first*i.second);
                
                if((mid)>dis[i.first]){
                    q.push({mid,i.first});
                }
            }
        }
        return dis[end];
    }
};