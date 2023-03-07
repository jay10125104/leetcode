class Solution {
public:
    long long int dp[100001];
    long long int up[100001];
    long long int ans=0;
    long long dfs(vector<int>adj[],int src,int parent,vector<int>& price){
        long long int x = 0;
        for(auto &i:adj[src]){
            if(i!=parent){
                dfs(adj,i,src,price);
                x = max(x,dp[i]);
            }
        }
        return dp[src] = price[src] + x;
    }
    void dfs2(vector<int>adj[],int src,int parent,vector<int>&price){
        multiset<long long int>m;
        for(auto &i:adj[src]){
            if(i!=parent){
                m.insert(dp[i]);
            }
        }
        for(auto &i:adj[src]){
            if(i!=parent){
                auto it = m.find(dp[i]);
                m.erase(it);
                up[i]=price[src]+up[src];
                long long int mx=0;
                if(m.size()!=0){
                   mx=*(--m.end());
                }
                // long long int mx = *(--m.end());
                
                // cout<<mx<<endl;
                up[i]=max(up[i],mx+price[src]);
                m.insert(dp[i]);
                dfs2(adj,i,src,price);
            }
        }
    }
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
       vector<int>adj[n];
        memset(dp,0,sizeof(dp));
        memset(up,0,sizeof(up));
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        ans = dfs(adj,0,-1,price)-price[0];
        dfs2(adj,0,-1,price);
        for(int i=0;i<n;i++){
            ans = max({ans,up[i],dp[i]-price[i]});
        }
       return ans;
    }
};