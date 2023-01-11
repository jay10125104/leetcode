class Solution {
public:
    int ans=0;
    int dfs(int src,vector<int>&visited,vector<int>adj[],vector<bool>&hasApple){
        visited[src]=1;
        int mid=0;
        for(auto &i:adj[src]){
            if(visited[i]==0){
                int t = dfs(i,visited,adj,hasApple);
                if(t){
                    ans+=2;
                }
                mid+=t;
            }
        }
        return hasApple[src]+mid;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>adj[n];
        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>visited(n);
        dfs(0,visited,adj,hasApple);
        return ans;
        
    }
};