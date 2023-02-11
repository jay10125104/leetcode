class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
        vector<pair<int,int>>adj[n];
        for(auto &i:r){
            adj[i[0]].push_back({i[1],0});
        }
        for(auto &i:b){
            adj[i[0]].push_back({i[1],1});
        }
        map<pair<int,int>,int>visited;
        vector<int>ans(n,-1);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        q.push({0,{0,1}});
        int counter =0;
        while(q.size()){
            int x = q.size();
            while(x--){
                auto it = q.front();
                q.pop();
                int color = !it.second.second;
                visited[{it.first,!color}] = 1;
                if(ans[it.first]==-1)
                ans[it.first] = counter;
                for(auto i:adj[it.first]){
                    if(visited[i]==0 && i.second==color){
                        q.push({i.first,{it.second.first+1,color}});
                    }
                }
            }
            counter++;
        }
        return ans;
    }
};