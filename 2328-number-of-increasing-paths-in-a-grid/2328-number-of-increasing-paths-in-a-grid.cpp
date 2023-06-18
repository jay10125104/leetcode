class Solution {
public:
    int dp[1001][1001];
    int mod=1000000007;
    int dfs(vector<vector<int>>&v,int i,int j){
        if(i<0||j<0||j==v[0].size()||i==v.size()){
            return 0;
        }
        else if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else{
            int ans=1;
            int m=v.size();
            int n=v[0].size();
            if((i-1)>=0 && v[i-1][j]>v[i][j]){
                ans = (ans%mod +  dfs(v,i-1,j)%mod)%mod;
            }
            if((i+1)<m && v[i+1][j]>v[i][j]){
                ans = (ans%mod +  dfs(v,i+1,j)%mod)%mod;
            }
            if((j-1)>=0 && v[i][j-1]>v[i][j]){
                ans = (ans%mod +  dfs(v,i,j-1)%mod)%mod;
            }
            if((j+1)<n && v[i][j+1]>v[i][j]){
                ans = (ans%mod +  dfs(v,i,j+1)%mod)%mod;
            }
            return dp[i][j]=ans;
        }
    }
    int countPaths(vector<vector<int>>& v) {
        int m=v.size();
        int ans=0;
        int n=v[0].size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==-1){
                    dfs(v,i,j);
                }
                ans = (ans%mod+dp[i][j]%mod)%mod;
            }
        }
        return ans;
    }
};