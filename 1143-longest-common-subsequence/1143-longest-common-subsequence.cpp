class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int m=s.size();
        int n=t.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
               if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                ans=max(ans,dp[i][j]);
            }
            
        }
        return ans;
    }
};