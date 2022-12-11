class Solution {
public:
    int dp[42][1<<11];
    int mod = 1000000007;
    int ans(vector<vector<int>>&v,int mask,int idx){
        int t = __builtin_popcount(mask);
        if(t==v.size()){
            return 1;
        }
        else if(dp[idx][mask]!=-1){
            return dp[idx][mask];
        }
        else{
            int sol=0;
            for(int i=idx;i<=40;i++){
                for(int j=0;j<v.size();j++){
                    if((mask&(1<<j))==0 && v[j][i]==1){
                        sol = (sol%mod + ans(v,mask|(1<<j),i+1)%mod)%mod;
                    }
                }
            }
            return dp[idx][mask] = sol%mod;
        }
    }
    int numberWays(vector<vector<int>>& t) {
        int n=t.size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>v(n,vector<int>(41,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<t[i].size();j++){
                v[i][t[i][j]]=1;
            }
        }
        return (ans(v,0,1)+mod)%mod;
    }
};