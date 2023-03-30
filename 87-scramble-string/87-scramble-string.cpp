class Solution {
public:
    bool isScramble(string s, string t) {
        int n=s.size();
        int dp[n][n][n+1];
        memset(dp,0,sizeof(dp));
        for(int len=1;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                for(int j=0;j<=n-len;j++){
                    if(len==1){
                        dp[i][j][len]=(s[i]==t[j]);
                    }
                    else{
                        for(int part=1;part<len && !dp[i][j][len];part++){
                            dp[i][j][len]|=(dp[i][j][part] && dp[i+part][j+part][len-part]);
                            dp[i][j][len]|=(dp[i][j+len-part][part] && dp[i+part][j][len-part]);
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};