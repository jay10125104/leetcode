class Solution {
public:
    int count=0;
    void dfs(vector<int>adj[],int src,vector<int>&visited,map<int,int>&m){
        if(m[src]){
            return;
        }
        count++;
        visited[src]=1;
        for(auto it:adj[src]){
            if(visited[it]==0)
            dfs(adj,it,visited,m);
        }
    }
    int reachableNodes(int n, vector<vector<int>>& v, vector<int>& r) {
        vector<int>adj[n];
        for(auto &i:v){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>visited(n);
        map<int,int>m;
        for(auto &i:r){
            m[i]++;
        }
        dfs(adj,0,visited,m);
            return count;
    }
};