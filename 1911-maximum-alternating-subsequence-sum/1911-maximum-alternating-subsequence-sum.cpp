class Solution {
public:
    long long maxAlternatingSum(vector<int>& v) {
        long long int dp[100001][2];
        memset(dp,0,sizeof(dp));
        dp[0][0]=v[0];
        dp[0][1]=0;
        int n=v.size();
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+v[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-v[i]);
        }
        return dp[n-1][0];
        
    }
};