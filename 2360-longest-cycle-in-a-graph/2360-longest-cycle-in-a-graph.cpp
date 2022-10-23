class Solution {
public:
    void dfs(vector<int>adj[],int &count,vector<int>&visited,int src){
        visited[src]=1;
        count++;
        for(auto i:adj[src]){
            if(visited[i]==0)
            dfs(adj,count,visited,i);
        }
    }
    int longestCycle(vector<int>& v) {
        int n=v.size();
        vector<int>adj[n];
        vector<int>indegree(n);
        for(int i=0;i<v.size();i++){
            if(v[i]==-1){
                continue;
            }
            adj[i].push_back(v[i]);
            indegree[v[i]]++;
        }
        queue<int>q;
        vector<int>visited(n);
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
        int count=0;
        while(q.size()){
            int x = q.front();
            q.pop();
            count++;
            for(auto i:adj[x]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                int count=0;
                dfs(adj,count,visited,i);
                ans = max(ans,count);
            }
        }
    
        return ans;
        
    }
};