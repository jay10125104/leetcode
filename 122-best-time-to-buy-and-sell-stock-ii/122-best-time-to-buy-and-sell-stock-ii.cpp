class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n=v.size();
        vector<vector<int>>dp(v.size(),vector<int>(2,0));
        dp[0][0]=-v[0];
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]-v[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+v[i]);
        }
        return dp[v.size()-1][1];
    }
};