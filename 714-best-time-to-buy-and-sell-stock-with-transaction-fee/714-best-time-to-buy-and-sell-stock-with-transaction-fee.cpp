class Solution {
public:
    int maxProfit(vector<int>& v, int fee) {
        
        int n=v.size();
        int dp[n][2];
        memset(dp,0,sizeof(dp));
        dp[0][0] = -1*v[0];
        for(int i=1;i<n;i++){
            dp[i][0] = max(-v[i]  + dp[i-1][1],dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0]+v[i]-fee,dp[i-1][1]);
        }
        return dp[n-1][1];
        
    }
};