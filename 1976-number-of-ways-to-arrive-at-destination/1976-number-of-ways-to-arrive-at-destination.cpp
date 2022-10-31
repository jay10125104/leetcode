class Solution {
public:
    int countPaths(int n, vector<vector<int>>& v) {
        vector<pair<long long int,long long int>>adj[n];
        for(int i=0;i<v.size();i++){
            adj[v[i][0]].push_back({v[i][2],v[i][1]});
            adj[v[i][1]].push_back({v[i][2],v[i][0]});
        }
        int mod = 1000000007;
        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>>q;
        q.push({0,0});
        vector<long long int>dis(n,1e15);
        int count=0;
        dis[0]=0;
        vector<long long int>dp(n,0);
        dp[0]=1;
        while(q.size()){
            auto x = q.top();
            q.pop();
            for(auto it:adj[x.second]){
                if(it.first+x.first<dis[it.second]){
                    dis[it.second] =  it.first+x.first;
                    dp[it.second] = dp[x.second];
                    q.push({it.first+x.first,it.second});
                }
                else if(it.first+x.first==dis[it.second]){
                    dp[it.second] = (dp[it.second]%mod + dp[x.second]%mod)%mod;
                }
            }
        }
        return dp[n-1];
    }
};