class Solution {
public:
    int visited[200001];
    
    int dfs(vector<int>adj[],int src,int parent){
        int ans=0;
        visited[src]=1;
        for(auto &i:adj[src]){
            if(visited[i]==0){
                ans+=(dfs(adj,i,src));
            }
        }
        return ans+1;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        // vector<int>visited(n);
        long long int total = 0;
        long long int ans=0;
        memset(visited,0,sizeof(visited));
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                int x = dfs(adj,i,-1);
                cout<<x<<" ";
                ans = ans + total*x;
                total+=x;
            }
        }
        cout<<endl;
        return ans;
    }
};