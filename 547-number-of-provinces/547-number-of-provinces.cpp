class Solution {
public:
    void dfs(int src,vector<int>&visited,vector<int>adj[]){
        visited[src]=1;
        for(auto i:adj[src]){
            if(visited[i]==0){
                dfs(i,visited,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& v) {
        //number of connected components;
        int n=v.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j] && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        int count=0;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                count++;
                dfs(i,visited,adj);
            }
        }
        return  count;
    }
};