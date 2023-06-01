class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int m=s.size();
        int n=t.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        int ans=0;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0){
                    dp[i][j]=1;
                }
                else if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                ans=max(ans,dp[i][j]);
            }
            
        }
        return ans-1;
    }
};