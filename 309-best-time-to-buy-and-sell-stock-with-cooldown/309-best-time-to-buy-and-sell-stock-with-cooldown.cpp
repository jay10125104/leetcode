class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n=v.size();
        int dp[n+1][2];
        memset(dp,0,sizeof(dp));
        dp[1][0] = -1*v[0];
        for(int i=2;i<=n;i++){
            int val = v[i-1];
            dp[i][0] = max(dp[i-2][1]-val,dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0]+val,dp[i-1][1]);
        }
        return dp[n][1];
    }
};