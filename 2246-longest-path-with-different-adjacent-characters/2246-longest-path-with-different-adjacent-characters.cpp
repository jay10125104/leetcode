class Solution {
public:
    int ans=1;
    int dp[100001];
    int dfs(vector<int>adj[],string &s,int parent,int src,vector<int>&visited){
        visited[src]=1;
        int mx1=0;
        int mx2=0;
        for(auto &i:adj[src]){
            if(visited[i]==0){
                int t = dfs(adj,s,src,i,visited);
                    ans = max(ans,t);
                
                if(s[src]!=s[i]){
                    if(mx1<=t){
                        mx2=mx1;
                        mx1 = t;
                    }
                    else
                    mx2  = max(mx2,t);
                    // mx1=t;
                    ans = max(ans,mx1+mx2+1);
                }
            }
        }
        // cout<<src<<" "<<mx1<<" "<<mx2<<endl;
        return mx1+1;
    }
    int longestPath(vector<int>& v, string s) {
        memset(dp,-1,sizeof(dp));
        int n=v.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(v[i]!=-1){
            adj[i].push_back(v[i]);
            adj[v[i]].push_back(i);
            }
            
        }
        vector<int>visited(n);
        int t = dfs(adj,s,-1,0,visited);
        return max(ans,t);
    }
};