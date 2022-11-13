class Solution {
public:
    int numDistinct(string s, string t) {
        double dp[1001][1001];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<=t.size();j++){
                if(j==0){
                    dp[i][j] = 1;
                }
                else if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[s.size()][t.size()];
    }
};