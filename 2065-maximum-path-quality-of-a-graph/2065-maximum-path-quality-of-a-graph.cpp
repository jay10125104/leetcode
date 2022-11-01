class Solution {
public:
    int ans=0;
    void dfs(vector<pair<int,int>>adj[],vector<int>&v,vector<int>&visited,int src,int val,int time,int maxTime){
        if(time>maxTime){
            return;
        }
        if(visited[src]==0){
            val+=v[src];
        }
        if(src==0){
            ans = max(ans,val);
        }
        visited[src]++;
        for(auto it:adj[src]){
            dfs(adj,v,visited,it.first,val,time+it.second,maxTime);
        }
        visited[src]--;
    }
    int maximalPathQuality(vector<int>& v, vector<vector<int>>& edges, int maxTime) {
        int n=v.size();
        vector<pair<int,int>>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int>visited(n);
        dfs(adj,v,visited,0,0,0,maxTime);
        return ans;
    }
};