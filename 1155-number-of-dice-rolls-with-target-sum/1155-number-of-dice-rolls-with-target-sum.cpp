class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int dp[n+1][target+1];
        memset(dp,0,sizeof(dp));
        int mod = 1000000007;
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                for(int t=1;t<=k;t++){
                    if((j-t)>=0){
                        dp[i][j] = (dp[i][j]%mod + dp[i-1][j-t]%mod)%mod;
                    }
                }
                }
        }
        return (dp[n][target]+mod)%mod;
    }
};