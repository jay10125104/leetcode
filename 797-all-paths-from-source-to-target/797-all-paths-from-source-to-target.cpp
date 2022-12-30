class Solution {
public:
    void ans(vector<vector<int>>&adj,vector<vector<int>>&sol,vector<int>&temp,int source,int destination,vector<int>&visited){
        if(source==destination){
            sol.push_back(temp);
            return;
        }
        visited[source]=1;
        for(auto i:adj[source]){
            if(visited[i]==0){
            temp.push_back(i);
            ans(adj,sol,temp,i,destination,visited);
            temp.pop_back();
            }
        }
        visited[source]=0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        vector<vector<int>>sol;
        vector<int>temp;
        int n=adj.size();
        vector<int>visited(n,0);
        temp.push_back(0);
        ans(adj,sol,temp,0,n-1,visited);
        return sol;
    }
};