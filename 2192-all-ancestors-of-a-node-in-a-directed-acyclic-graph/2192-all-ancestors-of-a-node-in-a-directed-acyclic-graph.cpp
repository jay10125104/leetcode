class Solution {
public:
    void dfs(vector<int>adj[],vector<int>&visited,vector<int>&ans,int i,int src){
        visited[i]=1;
        if(i!=src){
            ans.push_back(i);
        }
        for(auto it:adj[i]){
            if(visited[it]==0){
                dfs(adj,visited,ans,it,src);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>&v) {
        vector<int>adj[n];
        for(int i=0;i<v.size();i++){
            adj[v[i][1]].push_back(v[i][0]);
        }
        vector<vector<int>>sol;
        for(int i=0;i<n;i++){
            vector<int>ans;
            vector<int>visited(n);
            dfs(adj,visited,ans,i,i);
            sort(ans.begin(),ans.end());
            sol.push_back(ans);
        }
        return sol;
    }
};