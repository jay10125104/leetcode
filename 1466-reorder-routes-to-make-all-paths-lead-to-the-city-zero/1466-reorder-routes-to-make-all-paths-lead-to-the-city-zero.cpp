class Solution {
public:
    int dfs(vector<pair<int,int>>adj[],int src,int parent){
        int ans=0;
        for(auto &it:adj[src]){
            if(it.first!=parent){
                ans+=it.second;
                ans+=dfs(adj,it.first,src);
            }
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>>adj[n];
        for(auto &i:connections){
            adj[i[0]].push_back({i[1],0});
            adj[i[1]].push_back({i[0],1});
        }
        int ans = dfs(adj,0,-1);
        return connections.size()-ans;
    }
};