class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                int one = j;
                int two = i-j;
                dp[i] = max({dp[i],one*dp[two],dp[one]*dp[two],two*dp[one],one*two});
            }
            cout<<dp[i]<<" ";
        }
        return dp[n];
    }
};