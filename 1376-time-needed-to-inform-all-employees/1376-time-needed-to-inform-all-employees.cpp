class Solution {
public:
    int dfs(vector<int>adj[],int src,int parent,vector<int>&time){
        int count=0;
        int ans=0;
        for(auto &i:adj[src]){
            if(i!=parent){
                count++;
                ans=max(ans,dfs(adj,i,src,time));
            }
        }
            return time[src]+ans;
        
            
    }
    int numOfMinutes(int n, int headID, vector<int>& v, vector<int>& time) {
        int src=-1;
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(v[i]!=-1){
                adj[v[i]].push_back(i);
                adj[i].push_back(v[i]);
            }
        }
        return dfs(adj,headID,-1,time);
    }
};