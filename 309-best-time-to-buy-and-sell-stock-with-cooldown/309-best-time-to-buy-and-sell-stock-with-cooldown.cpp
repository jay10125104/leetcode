class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n=v.size();
        int dp[n+1][3];
        memset(dp,0,sizeof(dp));
        dp[0][0] = -1*v[0];
        for(int i=1;i<n;i++){
            int val = v[i];
            dp[i][0] = max(dp[i-1][2]-val,dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0]+val,dp[i-1][1]);
            dp[i][2] = dp[i-1][1];
        }
        return dp[n-1][1];
    }
};