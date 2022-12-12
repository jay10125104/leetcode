class Solution {
public:
    int dp[50];
    int ans(int n,int dp[]){
        if(n<0){
            return 0;
        }
        else if(n==0){
            return 1;
        }
        else if(dp[n]!=-1){
            return dp[n];
        }
        else{
            return dp[n] = ans(n-1,dp) + ans(n-2,dp);
        }
    }
    int climbStairs(int n) {
        int dp[n+1];
      // vector<int>dp(n+1,0);
        memset(dp,-1,sizeof(dp));
        ans(n,dp);
        return dp[n];
        
    }
};