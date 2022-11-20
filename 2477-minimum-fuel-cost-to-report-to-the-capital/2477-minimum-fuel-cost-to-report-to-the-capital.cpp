class Solution {
public:
    long long int ans=0;
    long long int dp[100001];
    long long int dfs(vector<int>adj[],int src,int k,int rsrc){
        if(dp[src]!=-1){
            return dp[src];
        }
        long long int sol=0;
        for(auto &i:adj[src]){
            if(i!=rsrc){
                int x = dfs(adj,i,k,src);
                ans+=(x/k);
                if(x%k){
                    ans++;
                }
                sol+=x;
            }
        }
        return dp[src] = sol+1;
    }
     long long minimumFuelCost(vector<vector<int>>& v, int k) {
        vector<int>adj[v.size()+1];
        for(auto &i:v){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        memset(dp,-1,sizeof(dp));
        int x = dfs(adj,0,k,0);
        return ans;
    }
};